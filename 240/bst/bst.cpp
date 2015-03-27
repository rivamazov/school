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