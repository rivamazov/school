#ifndef FLOATX_H_
#define FLOATX_H_

/* ----------------------------------------------------------------------------------------------------------

	A floatx number is an IEEE floating point numbert defined by two parameters:
		a) The total number of bits tot_bits
		b) The number of bits in the exponent, exp_bits

 	For convenience, these two parameters are packed into a floatxDef struct.

 	This file also defines the floatx type, as well as two functions:
 		number_to_floatx
 		floatx_to_doublediff

 ----------------------------------------------------------------------------------------------------------------*/

typedef struct {
  unsigned tot_bits;    	/* total # of bits in a floatx */
  unsigned exp_bits;    /* # of bits in biased exponent */
} floatxDef;

typedef unsigned long floatx;

/* Return floatx representation which best  approximates value * (2**exp2) */
floatx number_to_floatx(const floatxDef *def, int value, int exp2);

/* Return C double with value which best approximates floatx fx */
double floatx_to_double(const floatxDef *def, floatx fx);

#endif //ifndef FLOATX_H_
