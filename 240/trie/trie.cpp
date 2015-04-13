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
			tmp = tmp->array[arrayPos];
		}
	}
	tmp->wordEnd = true;
}

int trie::getPos(char val)
{
	return (int)val - (int)'a';
}

trie::~trie()
{
	
}
