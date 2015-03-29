#include "vector.h"
#include <iostream>
#include <algorithm>
#include <utility>


vector::vector(vector &rhs):currentSize(rhs.currentSize),maxSize(rhs.maxSize),growthRate(rhs.growthRate),
array( (rhs.maxSize ? new double[rhs.maxSize] : nullptr) )
{
	for (int i=0;i<rhs.maxSize;i++)
	{
		array[i] = rhs.array[i];
	}
}

vector& vector::operator=(vector rhs)
{
	vector tmp(rhs);
	swap(rhs);
	return *this;
}

vector::~vector()
{
	if (array!=nullptr)
		delete[] array;
}

void vector::swap(vector &other)
{
	std::swap(currentSize,other.currentSize);
	std::swap(maxSize,other.maxSize);
	std::swap(growthRate,other.growthRate);
	std::swap(array,other.array);
}

unsigned int vector::size()
{
	return currentSize;
}

void vector::setGrowthRate(unsigned int grRate)
{
	growthRate = grRate;
}

unsigned int vector::maximumSize()
{
	return maxSize;
}

void vector::resize(int incArraySize)
{
	if(incArraySize < 0) {
		return;
	}

	double *tmp = nullptr;
	if (incArraySize == 0)
	{
		tmp = new double[maxSize+growthRate];
		maxSize+=growthRate;
	}
	else
	{
		tmp = new double[maxSize+incArraySize];
		maxSize=incArraySize;
	}
	currentSize = (currentSize > maxSize ? maxSize : currentSize);
	for (int i = 0; i < currentSize; i++)
	{
		tmp[i] = array[i];
	}
	if (array != nullptr) delete[] array;
	array = tmp;
	
}

void vector::pushBack(double value)
{
	if (currentSize == maxSize) {
		resize();
	}

	array[currentSize] = value;
	currentSize++;
}

double vector::popBack()
{
	if (currentSize == 0)
		return -(std::numeric_limits<double>::max());
	currentSize--;
	double tmp = array[currentSize];
	array[currentSize] = 0;

	if (currentSize == maxSize - growthRate){
		resize(-growthRate);
	}

	return tmp;
}

void vector::pushFront(double value)
{
	if (currentSize == maxSize)
		resize();

	double *tmp = nullptr;
	tmp = new double[maxSize];
	for (int i=0;i<currentSize;i++)
	{
		tmp[i+1] = array[i];
	}
	tmp[0] = value;
	delete[] array;
	array = tmp;
	currentSize++;
}

double vector::popFront()
{
	if (currentSize == 0)
		return -(std::numeric_limits<double>::max());
	currentSize--;
	double tmp = array[0];
	for (int i=0;i<currentSize;i++) 
	{	
		array[i]=array[i+1];
	}
	array[currentSize] = 0; //clear repeat of last value
	if (maxSize-currentSize>growthRate) 
		resize(currentSize);
	return tmp;

}

void vector::insert(double value, unsigned int position)
{
	if (position < 0) return;
	if (position>maxSize)
	{
		resize(position);
		//special case current size to insert after all the zeros
		currentSize=position+1;
	}
	else if (position==0) { //insert position 1
		pushFront(value);
		return;
	}
	else if (position==currentSize) { //insert in back
		pushBack(value);
		return;
	}
	else {
		if (currentSize==maxSize)
			resize();
		double *tmp = nullptr;
		tmp = new double[currentSize+1];
		for (int i=0;i<position;i++)
		{	
			tmp[i] = array[i];			
		}
		for (int i=position;i<currentSize;i++)
		{
			tmp[i+1] = array[i];
		}
		delete[] array;
		array = tmp;
		currentSize++;
	}
	array[position] = value;
}

double& vector::front()
{
	if (array != nullptr) return array[0];
}

double& vector::back()
{
	if (array != nullptr) return array[currentSize-1];
}

bool vector::operator ==(const vector &rhs)
{
	if (maxSize==rhs.maxSize)
	{
		for (int i=0;i<currentSize;i++)
		{
			if (array[i]!=rhs.array[i]) return false;
		}
		return true;
	}
	else return false;
}

bool vector::operator !=(const vector &rhs)
{
	if (maxSize != rhs.maxSize) return true;
	else
	{
		for (int i=0;i<currentSize;i++)
		{
			if (array[i] != rhs.array[i]) return true; 
		}
		return false;
	}
}

double& vector::operator[](const int index) const
{
	if (array != nullptr) return array[index];
}

std::ostream& operator<< (std::ostream &out, const vector &vct)
{
	for (unsigned int i=0;i<vct.currentSize;i++)
	{
		out << vct.array[i] << std::endl;
	}
	return out;
}

