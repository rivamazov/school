#ifndef AVL_H_
#define AVL_H_

#include <iostream>

#include "node.h"

class avl
{
 public:
   avl():root(nullptr){}
  void insert(double dta);
  friend std::ostream& operator<<(std::ostream &out,avl &willow);
 private:
  void insert(node* nd,double dta);
  node* root;
};


#endif
