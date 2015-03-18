#include "vector.h"
#include <iostream>
#include <algorithm>
#include <utility>

template <class T>
vector<T>::vector(vector<T> &rhs):currentSize(rhs.currentSize),maxSize(rhs.maxSize),growthRate(rhs.growthRate),
	array( (rhs.maxSize ? new T[rhs.maxSize] : nullptr) )
{
	for (int i=0;i<rhs.maxSize;i++)
	{
		array[i] = rhs.array[i];
	}
}

template <class T>
vector<T>& vector<T>::operator=(vector<T> rhs)
{
	vector<T> tmp(rhs);
	swap(rhs);
	return *this;
}

template <class T>
vector<T>::~vector()
{
	if (array!=nullptr)
		delete[] array;
}

template <class T>
void vector<T>::swap(vector<T> &other)
{
	std::swap(currentSize,other.currentSize);
	std::swap(maxSize,other.maxSize);
	std::swap(growthRate,other.growthRate);
	std::swap(array,other.array);
}

template <class T>
const unsigned int vector<T>::size() const
{
	return currentSize;
}

template <class T>
unsigned int vector<T>::maximumSize()
{
	return maxSize;
}

template <class T>
void vector<T>::setGrowthRate(unsigned int grRate)
{
	growthRate = grRate;
}

template <class T>
void vector<T>::resize(int incArraySize)
{
	T *tmp = nullptr;

	if (incArraySize == 0)
	{
		tmp = new T[maxSize+growthRate];
		maxSize+=growthRate;
	}
	else
	{
		tmp = new T[maxSize+incArraySize];
		maxSize+=incArraySize;
	}
	currentSize = (currentSize > maxSize ? maxSize : currentSize);
	for (int i = 0; i < currentSize; i++)
	{
		tmp[i] = array[i];
	}
	if (array != nullptr) delete[] array;
	array = tmp;
	
}

template <class T>
void vector<T>::pushBack(T value)
{
	if (currentSize == maxSize) {
		resize();
	}

	array[currentSize] = value;
	currentSize++;
}

template <class T>
T vector<T>::popBack()
{
	if (currentSize == 0)
		return -(std::numeric_limits<T>::max());
	currentSize--;
	T tmp = array[currentSize];
	array[currentSize] = 0;

	if (maxSize-currentSize>growthRate)
		resize(-growthRate);
	return tmp;
}

template <class T>
void vector<T>::pushFront(T value)
{
	if (currentSize == maxSize)
		resize();

	T *tmp = nullptr;
	tmp = new T[maxSize];
	for (int i=0;i<currentSize;i++)
	{
		tmp[i+1] = array[i];
	}
	tmp[0] = value;
	delete[] array;
	array = tmp;
	currentSize++;
}

template <class T>
T vector<T>::popFront()
{
	if (currentSize == 0)
		return -(std::numeric_limits<T>::max());
	currentSize--;
	T tmp = array[0];
	for (int i=0;i<currentSize;i++) 
	{	
		array[i]=array[i+1];
	}
	array[currentSize] = 0; //clear repeat of last value
	if (maxSize-currentSize>growthRate) 
		resize(-growthRate);
	return tmp;

}

template <class T>
void vector<T>::insert(T value, unsigned int position)
{
	if (position < 0) return;
	if (position>maxSize)
	{
		if (position-maxSize<growthRate)
		{
			resize();
		}
		else 
		{
			unsigned int timesToResize; //times to resize by growthRate
			timesToResize = (position-maxSize)/growthRate;
			//if remainder do an extra resize
			if ((position-maxSize)-1%growthRate > 0) timesToResize++;
			while (timesToResize != 0)
			{
				resize();
				timesToResize--;
			}
			for (auto i=currentSize;i<maxSize;i++)
			{
				array[i] = 0; //zero out array
			}
		}
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
		T *tmp = nullptr;
		tmp = new T[currentSize+1];
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

template <class T>
T& vector<T>::front()
{
	if (array != nullptr) return array[0];
}

template <class T>
T& vector<T>::back()
{
	if (array != nullptr) return array[currentSize-1];
}

template <class T>
T vector<T>::maxSumSubArray() //Kadane's algorithm
{
	T maxEndingHere = 0;
	T maxSoFar = 0;
	for (auto i=0;i<size();i++)
	{
		maxEndingHere = std::max(0, maxEndingHere+array[i]);
		maxSoFar = std::max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}

template <class T>
bool vector<T>::operator ==(const vector<T> &rhs)
{
	if (maxSize==rhs.maxSize && currentSize==rhs.currentSize)
	{
		for (int i=0;i<currentSize;i++)
		{
			if (array[i]!=rhs.array[i]) return false;
		}
		return true;
	}
	else return false;
}

template <class T>
bool vector<T>::operator !=(const vector<T> &rhs)
{
	if (maxSize != rhs.maxSize && maxSize != rhs.currentSize) return true;
	else
	{
		for (int i=0;i<currentSize;i++)
		{
			if (array[i] != rhs.array[i]) return true; 
		}
		return false;
	}
}

template <class T>
T& vector<T>::operator[](const int index) const
{
	if (array != nullptr) return array[index];
}


template <class T>
std::ostream& operator<< (std::ostream &out, const vector<T> &vct)
{
	for (auto i=0;i<vct.size();i++)
	{
		out << vct[i] << std::endl;
	}
	return out;
}

