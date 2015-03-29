#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <algorithm>
#include <utility>
#include <iterator>

template <class T>
class array {
 public:
 array():data(nullptr),numElements(0){}
 array(int sz):data(new T[sz]{}),numElements(sz){}
  ~array();
 void resize(unsigned int nextSize);
 void sorted();
 T& operator[](const unsigned int index);
 bool operator== (array<T> &rhs);

 template <class U>
 	friend std::ostream& operator<< (std::ostream &out, array<U> &arr);


 private:
  T* data;
  int numElements;
};

#include "array.cpp"

#endif
