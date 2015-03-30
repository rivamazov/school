#ifndef AVL_H_
#define AVL_H_

#include <iostream>
#include <stack>
#include <queue>

#include "node.h"

class avl
{
 public:
   avl():root(nullptr){}
  void insert(double dta);
  void rotate();
  int balanceFactor();
  int height();
  void printBreadthFirst();
  void printDepthFirst();
  ~avl();
  friend std::ostream& operator<<(std::ostream &out,avl &willow);
 private:
  void insert(node* nd,double dta);
  void rotate(node* nd);
  int balanceFactor(node* nd);
  int height(node* nd);
  void cleanAvl(node* nd);
  node* root;
};


#endif
