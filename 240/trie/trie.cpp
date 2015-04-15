#include "trie.h"

/* an n-ary "trie" (retrieve) tree 
* 26 children usually associated with words. used to make dicts in c/c++
* 
*
*
*/

trie::trie()
{
  root = new node(ALPHA);
}

void trie::insert(std::string word)
{
	node* tmp = root;
	for (auto let : word)
	{
		int arrayPos = getPos(let);
		if (tmp->array[arrayPos] == nullptr)
		{
			node* newNode = new node(ALPHA);
			tmp->array[arrayPos] = newNode;
		}
		tmp = tmp->array[arrayPos];
	}
	tmp->wordEnd = true;
}

node* tmp = someNode
for (auto ptr : array) {
	if (ptr!=nullptr)
	{
		
	}
}
bool trie::search(std::string word)
{
	node* tmp = root;
	for (auto letter : word)
	{
		int arrayPos = getPos(letter);
		if (arrayPos==nullptr) return false;
		tmp=tmp->
	}
	return true;

}

int trie::getPos(char val)
{
	return (int)val - (int)'a';
}

void trie::wipeTrie(node* nd) 
{
	if (nd==nullptr) return;
	for (auto letter : nd->array) {
		wipeTrie(letter);
	}
	delete nd;
}

trie::~trie()
{
	if (root==nullptr) return;
	wipeTrie(root);
	
}
