#include "avl.h"

void avl::insert(double dta)
{
  if(root == nullptr)
    {
      node *nd = new node(dta);
      root = nd;
    }
  else
    {
      insert(root,dta);
    }
}

void avl::insert(node *nd,double dta)
{
  if(dta > nd->data)
    {
      if(nd->right == nullptr)
	{
	  node *newNode = new node(dta);
	  nd->right = newNode;
	  newNode->parent = nd;
	}
      else
	{
	  insert(nd->right,dta);
	}
    }
  else
    {
      if(nd->left == nullptr)
	{
	  node *newNode = new node(dta);
	  nd->left = newNode;
	  newNode->parent = nd;
	}
      else
	{
	  insert(nd->left,dta);
	}
    }

}
