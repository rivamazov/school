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
  double sumLeaves();
  int numLeaves();
  void reverse();
  int size();
  node* find(double dta);
  node* closestToK(double k);
  node* min();
  node* max();
  void printDepthFirst();
  void printBreadthFirst();
  bool isBinarySearchTree();
  int balanceFactor();
  void maxHeight(node* nd);
  void cleanBst();
  ~bst();

 private:
  node* root;
  void insert(node* nd, double dta);
  void inorder(node* nd);
  void preorder(node* nd);
  void postorder(node* nd);
  double sumLeaves(node* nd);
  int numLeaves(node* nd);
  void reverse(node* nd);
  int size(node* nd);
  node* find(node* nd, double dta);
  node* closestToK(node* nd, double k);
  node* min(node* nd);
  node* max(node* nd);
  bool isBinarySearchTree(node* nd, double min, double max);
  void cleanBst(node* nd);

};

#endif
