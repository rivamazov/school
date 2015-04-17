#include "trie.h"

/* an n-ary "trie" (retrieve) tree 
* 26 children usually associated with words. used to make dicts in c/c++
* 
*
*
*/

void trie::inOrder()
{
	if (root==nullptr) return;
	else inOrder(root);
}

void trie::inOrder(node* nd) {
	if (nd->wordEnd) std::cout << word << std::endl;
	for (int i=0;i<ALPHA;i++) {
		if (nd->array[i]) {
			char letter = getLetter(i);
			word+=letter;
			inOrder(nd->array[i]);
			word.erase(word.end()-1);
		}
	}
}

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

/*
node* tmp = someNode;
for (auto ptr : array) {
	if (ptr!=nullptr)
	{
		
	}
}
*/
bool trie::search(std::string word)
{
	node* tmp = root;
	for (auto letter : word)
	{
		int arrayPos = getPos(letter);
		if (tmp->array[arrayPos]==nullptr) return false;
		tmp=tmp->array[arrayPos];
	}
	if (tmp->wordEnd) return true;

}


int trie::getPos(char val)
{
	return (int)val - (int)'a';
}

char trie::getLetter(int val)
{
	return (char)(val+(int)'a');
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
