#include "bst.h"

void bst::insert(double dta) {
	if (root==nullptr)
	{
		node* newNode = new node(dta);
		root = newNode;
	}
	else
	{

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
