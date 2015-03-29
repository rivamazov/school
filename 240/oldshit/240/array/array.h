#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>


class array
{
 public:
  array():data(nullptr),numElements(0){}
	array(int maxSz):data(new int[maxSz]),numElements(maxSz){}
	int size();
	~array();
  
 private:
  int *data;
  int numElements;

};

#endif
