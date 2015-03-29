#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <utility>
#include <algorithm>

#include "node.h"

class bst
{
 public:
  bst():root(nullptr){}
  void insert(double dta);
  void inOrder();

 private:
  node* root;
  void insert(node* nd, double dta);
  void inOrder(node* nd);

};

#endif
