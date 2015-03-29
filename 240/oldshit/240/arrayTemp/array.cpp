#include "array.h"

template <class T>
array<T>::~array()
{
  if(this->data != nullptr)
    delete[] this->data;
}

template <class T>
void array<T>::resize(unsigned int nextSize)
{
	if (data == nullptr)
	{
		data = new T[nextSize]{}; //default constructor (anull 0's)
		numElements = nextSize;
	}
	else
	{
		T* tmp = new T[nextSize]{};
		for (unsigned int i=0;i<(nextSize<numElements ? nextSize : numElements);i++)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		numElements = nextSize;
	}
}

template <class T>
void array<T>::sorted()
{
	std::sort(data,data+numElements,[&](T &a, T &b){return a>b;});
}

template <class T>
bool array<T>::operator== (array<T> &rhs)
{
	if (this->numElements != rhs.numElements) 
		return false;
	for (unsigned int i=0;i<rhs.numElements;i++)
	{
		if (this->data[i] != rhs.data[i]) 
			return false;
	}
	return true;
}

template <class T>
T& array<T>::operator[](const unsigned int index)
{
	return data[index];
}

template <class U>
std::ostream& operator<< (std::ostream& out, array<U> &arr)
{
	out << "shit" << arr.numElements << std::endl;
	for (int i=0;i<arr.numElements;i++)
	{
		out << arr[i] << std::endl;
	}
}
