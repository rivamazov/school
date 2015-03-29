#include "array.h"

array::~array()
{
	if(data != nullptr)
		{
			delete[] data;
		}

}

int array::size()
{
	return numElements;
}
