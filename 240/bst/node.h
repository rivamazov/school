#ifndef NODE_H_
#define NODE_H_

struct node
{
  node* right;
  node* left;
  double data;
  node():right(nullptr),left(nullptr),data(0){}
  node(double dta):right(nullptr),left(nullptr),data(dta){}
};


#endif
