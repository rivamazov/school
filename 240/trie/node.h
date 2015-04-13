#ifndef NODE_H_
#define NODE_H_

#include <cstring>
#include <vector>
#include <iostream>

struct node
{
  std::vector<node*> array;
  bool wordEnd;
  node(int size):wordEnd(false){array.resize(size,nullptr);}
};
#endif
