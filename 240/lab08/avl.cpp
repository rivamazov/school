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
      if (std::abs(balanceFactor()) == 2) {
        rotate(nd->parent);
      }
      else nd->height=height(nd);
      return;
    }
    else {
      insert(nd->right, dta);
      return;
    }
  }
  else if (dta < nd->data) {
    if(nd->left == nullptr) {
      node *newNode = new node(dta);
      nd->left = newNode;
      newNode->parent = nd;
      if (std::abs(balanceFactor()) == 2) {
        rotate(nd->parent);
        nd->height = height(nd);
      }
      else nd->height=height(nd);
      return;
    }
    else {
      insert(nd->left, dta);
      return;
    }
  }
  return;
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
  if(nd==nullptr) return;
  if (balanceFactor(nd)==2) { //right heavy
    if (balanceFactor(nd->right)==1)
      rotateLeft(nd);
    else { //double left
      rotateRight(nd->parent);
      rotateLeft(nd);
    }   
  }
  else if (balanceFactor(nd)==-2) { //left heavy
    if (balanceFactor(nd->left)==-1) {
      rotateRight(nd);
    }
    else { //double right
      rotateLeft(nd->left);
      rotateRight(nd);
    }
  }
  if (balanceFactor()>1 || balanceFactor()<-1)
    return;
  //rotate(nd->parent->parent);
}

void avl::rotateLeft(node* nd) {
  node* tmp = nd->right;
  nd->right = tmp->left;
  if (tmp->left != nullptr)
    tmp->left->parent = nd; //reset left child parent
  if (nd->parent == nullptr) {
    root = tmp;
    tmp->parent = nullptr;
  }
  else if (nd->parent->left == nd) //if was the left child of its parent
    nd->parent->left = tmp; //make tmp new left child
  else
    nd->parent->right = tmp; //make tmp the new right child
  tmp->left = nd;
  nd->parent = tmp;
}


void avl::rotateRight(node* nd) {
  node* tmp = nd->left;
  nd->left = tmp->right;
  if (tmp->right != nullptr)
    tmp->right->parent = nd; //reset right child parent
  if (nd->parent == nullptr) {//if nd is root
    root = tmp;
    tmp->parent = nullptr;
  }
  else if (nd->parent->left == nd) //if was the left child of its parent
    nd->parent->left = tmp; //make tmp new left child
  else
    nd->parent->right = tmp; //make tmp the new right child

  tmp->right = nd; //move n to right child of tmp
  nd->parent = tmp;
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