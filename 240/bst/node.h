#ifndef NODE_H_
#define NODE_H_
#include <algorithm>

struct node
{
  node* right;
  node* left;
  double data;
  int height;
  node():right(nullptr),left(nullptr),data(0){}
  node(double dta):right(nullptr),left(nullptr),data(dta){}
  //height(){return std::max(left->height,right->height)+1;}
};


#endif
