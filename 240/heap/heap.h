#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>


enum type {MINHEAP,MAXHEAP};

template <class T>
class heap
{
 public:
  heap():currentSize(0),maxSize(0),version(MINHEAP){}
  heap(unsigned int maxSz,type vsn = MINHEAP);
  void insert(std::pair<double,T> item);
  unsigned int size(){return currentSize;}
  void setMaxSize(int maxSz);
  template <class U>
  friend std::ostream& operator<<(std::ostream &out,heap<U> &hp);
  T* operator[] (int index);
  
 private:
  std::vector<std::pair<double,T> > array;
  unsigned int currentSize;
  unsigned int maxSize;
  type version;
 
  
  bool comp(int pnt,int pos);
  void perculateUp(unsigned int pos);
  void perculateDown(unsigned int pos);
  unsigned int right(unsigned int i);
  unsigned int left(unsigned int i);
  unsigned int parent(unsigned int i);

  
};

#include "heap.cpp"


#endif
