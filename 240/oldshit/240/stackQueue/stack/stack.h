#ifndef STACK_H_
#define STACK_H_

#include "dlinklist.h"

#include <iostream>

template <class T>
class stack : public dlinklist<T>
{
 public:
 stack():numElements(0){}
  ~stack(){}
  void push(T data);
  void pop();
  T& top();
  bool empty();
  unsigned int size();
  template <class U>
    friend std::ostream& operator<< (std::ostream &out,stack<U> &stk);
 private:
  unsigned int numElements;

};

#include "stack.cpp"

#endif
