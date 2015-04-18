#include "bst.h"

void bst::insert(double dta) {
	if (root==nullptr)
	{
		node* newNode = new node(dta);
		root = newNode;
	}
	else
	{
		bst::insert(root, dta);
	}
}

void bst::insert(node* nd, double dta) {
	if (nd->data < dta)
	{
		if (nd->right == nullptr)
		{
			node* newNode = new node(dta);
			nd->right = newNode;
			return;
		}
		else
		{
			insert(nd->right,dta);
			return;
		}
	}
	else
	{
		if (nd->left == nullptr)
		{
			node* newNode = new node(dta);
			nd->left = newNode;
			return;
		}
		else
		{
			insert(nd->left,dta);
			return;
		}
	}
	return;
}

void bst::inorder()
{
	if (root==nullptr) return;
	inorder (root);
}

void bst::inorder(node* nd)
{
	if (nd==nullptr) return;
	inorder(nd->left);
	std::cout << nd->data << std::endl;
	inorder(nd->right);
}

void bst::preorder()
{
	if (root==nullptr) return;

	preorder(root);
}

void bst::preorder(node* nd)
{
	if (nd==nullptr) return;
	std::cout << nd->data << std::endl;
	inorder(nd->left);
	inorder(nd->right);
}

void bst::postorder()
{
	if (root==nullptr) return;
	postorder(root);
}

void bst::postorder(node* nd)
{
	if (nd==nullptr) return;
	inorder(nd->left);
	inorder(nd->right);
	std::cout << nd->data << std::endl;
}

double bst::sumLeaves()
{
	if (root==nullptr) return 0;
	return sumLeaves(root);
}

double bst::sumLeaves(node* nd)
{
	if (nd==nullptr) return 0;
	if (nd->right==nullptr && nd->left==nullptr)
	{
		return nd->data;
	}
	return sumLeaves(nd->right)+sumLeaves(nd->left);
}

int bst::numLeaves()
{
	if (root==nullptr) return 0;
	return numLeaves(root);
}

int bst::numLeaves(node* nd)
{
	if (nd==nullptr) return 0;
	if (nd->right==nullptr && nd->left==nullptr) return 1;
	int right = numLeaves (nd->right);
	int left = numLeaves(nd->left);
	return left+right;
}

void bst::reverse()
{
	if (root==nullptr) return;
	reverse(root);
}

void bst::reverse(node* nd)
{
	if (nd==nullptr) return;
	std::swap(nd->left,nd->right);
	reverse(nd->left);
	reverse(nd->right);
}

int bst::size()
{
	if (root==nullptr) return 0;
	return size(root);
}

int bst::size(node* nd)
{
	if (nd==nullptr) return 0;
	return 1+size(nd->right)+size(nd->left);
}

node* bst::find(double dta)
{
	if (root==nullptr) return nullptr;
	return find(root, dta);
}

node* bst::find(node* nd, double dta)
{
	if (nd==nullptr) return nullptr;
	if (nd->data==dta) return nd;
	else if (dta < nd->data) return find(nd->left, dta);
	else return find(nd->right, dta);
	return nullptr;
}

node* bst::closestToK(double k)
{
	if (root==nullptr) return nullptr;
	return closestToK(root, k);
}

node* bst::closestToK(node* nd, double k)
{
	if (nd==nullptr) return nullptr;
	if (nd->data == k) return nd;
	if (nd->data > k) {
		if (nd->left==nullptr)
			return nd;
		node* tmp = closestToK(nd->left, k);
		return abs(tmp->data-k) > abs(nd->data-k) ? nd : tmp;
	}
	else if (nd->data < k) {
		if (nd->right==nullptr)
			return nd;
		node* tmp = closestToK(nd->right, k);
		return abs(tmp->data-k) >= abs(nd->data-k) ? nd : tmp;
	}
}

node* bst::min()
{
	if (root==nullptr) return nullptr;
	return min(root);
}

node* bst::min(node* nd)
{
	if (nd->left == nullptr) return nd;
	else min(nd->left);
}

node* bst::max()
{
	if (root==nullptr) return nullptr;
	return max(root);
}

node* bst::max(node* nd)
{
	if (nd->right==nullptr) return nd;
	else max(nd->right);
}

void bst::printDepthFirst()
{
	std::stack <node*> stk;
	node* tmp = root;
	stk.push(root);
	while (!stk.empty())
	{
		tmp = stk.top();
		stk.pop();
		if (tmp->right!=nullptr) stk.push(tmp->right);
		if (tmp->left!=nullptr) stk.push(tmp->left);
		std::cout << tmp->data << std::endl;
	}
}

void bst::printBreadthFirst()
{
	std::queue <node*> que;
	node* tmp = root;
	que.push(root);
	while (!que.empty())
	{
		tmp = que.front();
		que.pop();
		if (tmp->left!=nullptr) que.push(tmp->left);
		if (tmp->right!=nullptr) que.push(tmp->right);
		std::cout << tmp->data << std::endl;
	}
}

bool bst::isBinarySearchTree(){
	if (root==nullptr) return false;
	return isBinarySearchTree(root, std::numeric_limits<double>::min(), 
		std::numeric_limits<double>::max());
}

bool bst::isBinarySearchTree(node* nd, double min, double max)
{
	if (nd==nullptr) return true;
	if (nd->data > min 
		&& nd->data < max 
		&& isBinarySearchTree(nd->right, nd->data, max) 
		&& isBinarySearchTree(nd->left,min,nd->data))
		return true;
	else return false;
}

int bst::maxHeight()
{
	return maxHeight(root);
}

int bst::maxHeight(node* nd)
{
	if (nd==nullptr) return -1;
	int left = maxHeight(nd->left);
	int right = maxHeight(nd->right);

	return std::max(left,right)+1;
}

void bst::cleanBst(node* nd)
{
	if (nd != nullptr)
	{
		cleanBst(nd->left);
		cleanBst(nd->right);
		delete nd;
	}
}

bst::~bst()
{
	cleanBst(root);
}