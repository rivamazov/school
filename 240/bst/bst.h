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
  void inorder();
  void preorder();
  void postorder();
  int numLeaves();

 private:
  node* root;
  void insert(node* nd, double dta);
  void inorder(node* nd);
  void preorder(node* nd);
  void postorder(node* nd);
  int numLeaves(node* nd);

};

#endif
