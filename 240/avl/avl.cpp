#include "avl.h"

void avl::insert(double dta) {
  if(root == nullptr) {
      node *nd = new node(dta);
      root = nd;
      root->height = 1;
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
      nd->height = height(nd); //try nd->height++ for speed
      if (std::abs(balanceFactor()) == 2) 
        rotate(nd->parent);
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
      nd->height = height(nd); //try nd->height++ for speed
      if (std::abs(balanceFactor()) == 2) {
        rotate(nd->parent);
      }
      return;
    }
    else {
      insert(nd->left, dta);
      return;
    }
  }
}

node* avl::find(double dta)
{
  if (root==nullptr) return nullptr;
  return find(root, dta);
}

node* avl::find(node* nd, double dta)
{
  if (nd==nullptr) return nullptr;
  if (nd->data==dta) return nd;
  else if (dta < nd->data) return find(nd->left, dta);
  else return find(nd->right, dta);
  return nullptr;
}

void avl::rotate() {
  if (root==nullptr) return;
  rotate(root);
}


void avl::rotate(node* nd) {
  std::cout << "entering rotate " << nd->data << balanceFactor(nd) << std::endl;
  if (balanceFactor(nd)==2) { //right heavy
    std::cout << "semi-success";
    if (balanceFactor(nd->right)==1)
      rotateLeft(nd);
    else {
      rotateRight(nd);
      rotateLeft(nd);
    }   
  }
  else if (balanceFactor(nd)==-2) { //left heavy
    if (balanceFactor(nd->left)==-1) {
      std::cout << "rotating right\n";
      rotateRight(nd);
    }
    else {
      std::cout << "double right!" << std::endl;
      node* tpm = rotateLeft(nd);
      rotateRight(nd);
    }
  }
}

node* avl::rotateLeft(node* nd) {
  node* oldRight = nd->right;
  nd->right = nd->right->left;
  if (nd->parent == nullptr)
    root = oldRight;
  else if (nd->parent->right == nd)
    nd->parent->right = oldRight;
  else
    nd->parent->left = oldRight;
  oldRight->left = nd;
  return nd->parent;
}


node* avl::rotateRight(node* nd) {
  node* oldLeft = nd->left;
  nd->left = nd->left->right;
  if (nd->parent == nullptr)
    root = oldLeft;
  else if (nd->parent->left == nd)
    nd->parent->left = oldLeft;
  else
    nd->parent->right = oldLeft;
  oldLeft->right = nd;
  return nd->parent;
}

int avl::balanceFactor() {
  if (root->left!=nullptr || root->right!=nullptr) balanceFactor(root);
  else return 0;
}

int avl::balanceFactor(node* nd) {
  int lft = (nd->left==nullptr) ? 0 : height(nd->left);
  int rht = (nd->right==nullptr) ? 0 : height(nd->right);
  return rht-lft;
}

int avl::height() {
  return height(root);
}

int avl::height(node* nd) {
  if (nd==nullptr) return 0;
  return std::max(height(nd->left),height(nd->right))+1;
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

std::ostream& operator<<(std::ostream &out,avl &willow) {
  std::queue <node*> que;
  node* tmp = willow.root;
  que.push(willow.root);
  while (!que.empty()) {
    tmp = que.front();
    que.pop();
    if (tmp->left!=nullptr) que.push(tmp->left);
    if (tmp->right!=nullptr) que.push(tmp->right);
    out << tmp->data << std::endl;
  }
}