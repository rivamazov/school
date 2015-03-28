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
		std::cout << nd->data << std::endl;
		return nd->data;
	}
	return sumLeaves(nd->right)+sumLeaves(nd->left);
	//return 0;
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
	//return numLeaves(nd->left) + numLeaves(nd->right);

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
	/*if(nd->left!=nullptr && nd->right!=nullptr) {
		std::swap(nd->left,nd->right);
		reverse(nd->left);
		reverse(nd->right);
	}
	if (nd->left==nullptr && nd->right != nullptr)
	{
		nd->left = new node(nd->right->data);
		nd->left->left = nd->right->left;
		nd->left->right = nd->right->right;
		delete nd->right;
		nd->right=nullptr;
		reverse(nd->left);
	}
	else if (nd->right==nullptr && nd->left != nullptr)
	{
		nd->right = new node(nd->left->data);
		nd->right->left = nd->left->left;
		nd->right->right = nd->left->right;
		delete nd->left;
		nd->left=nullptr;
		reverse(nd->right);
	}
	*/
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
	// /abs(nd->data - k)
	//double min = (abs(nd->data - k) < closestToK(nd->left)) ?  
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

int bst::balanceFactor()
{

}

void bst::maxHeight(node* nd)
{
	int right = nd->right->data;
	int left = nd->left->data;

	//nd->height = std::max(left,right)+1;
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