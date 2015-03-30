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
      nd->height = height(nd);
      std::cout << nd->right->data << " nodes height is" << nd->height << std::endl;
      return;
    }
    else {
      insert(nd->right, dta);
      return;
    }
  }
  else {
    if(nd->left == nullptr) {
      node *newNode = new node(dta);
      nd->left = newNode;
      newNode->parent = nd;
      nd->height = height(nd);
      std::cout << nd->left->data << " nodes height is" << nd->height << std::endl;
      return;
    }
    else {
      insert(nd->left, dta);
      return;
    }
  }
  std::cout << nd->data << " nodes height is" << height(nd) << std::endl;
  if (balanceFactor() > 2) ;// calculate me
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

int avl::height()
{
  return height(root);
}

int avl::height(node* nd) {
  if (nd==nullptr) return -1;
  int left = height(nd->left);
  int right = height(nd->right);

  return std::max(left,right)+1;
}

void avl::printDepthFirst() {
  std::stack <node*> stk;
  node* tmp = root;
  stk.push(root);
  while (!stk.empty()) {
    tmp = stk.top();
    stk.pop();
    if (tmp->right!=nullptr) stk.push(tmp->right);
    if (tmp->left!=nullptr) stk.push(tmp->left);
    std::cout << tmp->data << std::endl;
  }
}

void avl::printBreadthFirst()
{
  std::queue <node*> que;
  node* tmp = root;
  que.push(root);
  while (!que.empty()) {
    tmp = que.front();
    que.pop();
    if (tmp->left!=nullptr) que.push(tmp->left);
    if (tmp->right!=nullptr) que.push(tmp->right);
    std::cout << tmp->data << std::endl;
  }
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