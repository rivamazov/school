#ifndef DLINKLIST_H_
#define DLINKLIST_H_

#include <iostream>

#include "node.h"

template <class T>
class dlinklist
{
 public:
  dlinklist():head(nullptr),tail(nullptr){}
  ~dlinklist();
  
  void add_front(T value);
  void add_back(T value);
  void remove_front();
  void remove_back();
  T& front(){return head->getData();}
  T& back(){return tail->getData();}
  unsigned int size();
  bool empty();
  node<T>* getHead(){return head;}
  template <class U>
  friend std::ostream& operator<< (std::ostream &out, dlinklist<U> &dl);
 
 private:
  node<T> *head;
  node<T> *tail;
};

#include "dlinklist.cpp"

#endif
