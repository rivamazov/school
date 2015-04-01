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
  node* find(double dta);
  void rotate();
  int balanceFactor();
  int height();
  int height(node* nd);
  void printBreadthFirst();
  void printDepthFirst();
  ~avl();
  friend std::ostream& operator<<(std::ostream &out,avl &willow);
 private:
  void insert(node* nd,double dta);
  void rotate(node* nd);
  node* find(node* nd, double dta);
  int balanceFactor(node* nd);
  void cleanAvl(node* nd);
  node* root;
};


#endif
