#ifndef NODE_H_
#define NODE_H_
#include <iostream>

template <class T>
class node
{
 public:
 node():next(nullptr){}
 node(T d):next(nullptr),data(d){}
  void setNext(node *nextNode){next = nextNode;}
  node* getNext(){return next;}
  void setPrev(node *prevNode){prev = prevNode;}
  node* getPrev(){return prev;}
  T& getData(){return this->data;}
  
  template <class U>
  friend std::ostream& operator<< (std::ostream &out,node<U> &n);
 private:
  node* prev;
  node* next;
  T data;
};

#include "node.cpp"

#endif
