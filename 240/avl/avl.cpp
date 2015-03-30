#include "avl.h"

void avl::insert(double dta) {
  if(root == nullptr) {
      node *nd = new node(dta);
      root = nd;
  }
  else insert (root, dta);
}

//update height, get balance factor, rotate if needed
void avl::insert(node *nd,double dta) {
  if(dta > nd->data) {
    if(nd->right == nullptr) {
      node *newNode = new node(dta);
      nd->right = newNode;
      newNode->parent = nd;
    }
    else insert(nd->right, dta);
  }
  else {
    if(nd->left == nullptr) {
      node *newNode = new node(dta);
      nd->left = newNode;
      newNode->parent = nd;
    }
    else insert(nd->left, dta);
  }
}

int avl::balanceFactor() {
  if (root->left || root->right) balanceFactor(root);
  else return 0;
}

int avl::balanceFactor(node* nd) {
  int lft = (nd->left==nullptr) ? 0 : nd->left->height;
  int rht = (nd->right==nullptr) ? 0 : nd->right->height;
  return rht-lft;
}

avl::~avl() {
  cleanAvl(root);
}

void avl::cleanAvl(node* nd) {
  if (nd!=nullptr) {
    cleanAvl(nd->right);
    cleanAvl(nd->left);
    delete nd;
  }
}