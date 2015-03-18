#include "floatx.h"

#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define FLOATX_SIZE 64
#define MSB 0x8000000000000000
#define TRUE 1
#define FALSE 0

/* Return floatx representation which best  approximates value * (2**exp2) */
floatx number_to_floatx(const floatxDef *def, int value, int exp2) {
	bool isNegative = FALSE;
	unsigned int padding = (FLOATX_SIZE - def->tot_bits);
	unsigned int bias = (pow(2, def->exp_bits-1)-1);	
	unsigned long mask = MSB;
	if (value < 0) //check if negative 
	{
		isNegative = TRUE;
		value = -value;
	}
	else if (value == 0 || value == -0) //check if 0
		return 0;
	floatx result = value*(pow(2, exp2));
	if ((value != 0 && exp2 !=0) && result == 0) //indicates overflow of pow
	{
		result = pow(2, def->exp_bits)-1;
		result = result << (def->tot_bits-def->exp_bits-1);
		//set sign bit if negative inf 
		return (isNegative ? result |= (floatx)(pow(2, (FLOATX_SIZE-padding-1))) : result);
	}
	int binExponent = 0;
	for (int i=63;i>=0;i--)	//binExponent is place of dot ie 1.1101 x 2^4
	{
		if (mask & result)
		{
			binExponent = i;
			break;
		}
		mask = mask >> 1;
	}
	floatx biasedForm = 0;
	biasedForm = bias+binExponent; //calculate biased form value
	biasedForm <<= (def->tot_bits-def->exp_bits-1); //put in correct position
	result <<= (FLOATX_SIZE-binExponent); //clear top bit
	result >>= (padding+def->exp_bits+1); //put mantissa in correct place
	result |= biasedForm; //completed floatx without sign bit
	//adds sign bit if necessary
	if (isNegative) result |= (floatx)(pow(2, (FLOATX_SIZE-padding-1)));
	return result;
}

/* return double value of floatx */
double floatx_to_double(const floatxDef *def, floatx fx) {
	if (fx == 0) return 0;
	unsigned int bias = (pow(2, def->exp_bits-1)-1);
	unsigned int padding = (FLOATX_SIZE - def->tot_bits);
	char signBit = 0;
	int exponent = 0;
	double significand = 1; //implied bit is 1
	signBit = (fx >> (def->tot_bits-1)); //get sign bit
	fx <<= padding+1; //clear sign bit
	fx >>= padding+1; 
	exponent = (fx >> (def->tot_bits - def->exp_bits-1) ); //get exponent
	exponent -= bias; //calculate decoded exponent
	fx <<= (padding+def->exp_bits+1);	//clear everything
	fx >>= (padding+def->exp_bits+1);	//except significand
	//mask set to where significand starts
	unsigned long mask = (pow(2, (FLOATX_SIZE-padding-def->exp_bits-2)));
	for (float i=0.5;mask!=0;i/=2.0)
	{
		if (mask & fx) {
			significand += i;
		}

		mask >>= 1;
	}
	if (exponent > bias) 
		if (significand==1 && !signBit) return INFINITY;
		else if (significand==1 && signBit) return -INFINITY;
		else return NAN;
	else if (!signBit) return significand * pow(2, exponent);
	else return -(significand * pow(2, exponent));
}

