#ifndef QUEUE_H_
#define QUEUE_H_

#include "dlinklist.h"
#include <iostream>
#include <string>

template <class T>
class queue : public dlinklist<T>
{
 public:
 queue():numElements(0){}
  ~queue(){}
  T& front();
  void pop();
  void push(T data);
  int size();
  bool empty();


  bool isPalindrome(dlinklist<T> &dll,queue<T> &que);
  unsigned int romanNumber(queue<T> &que);
  unsigned int getNumeralAmount(char let);

  template <class U>
  friend std::ostream& operator<< (std::ostream &out,queue<U> &que);
 private:
  unsigned int numElements;

};

#include "queue.cpp"

#endif
