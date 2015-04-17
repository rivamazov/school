#include "trie.h"


int main()
{
	trie trye;
	trye.insert("bat");
	trye.insert("balls");
	std::cout << trye.search("franx") << std::endl;
	std::cout << trye.search("ball") << std::endl;
	std::cout << trye.search("balls") << std::endl;
	trye.inOrder();



  return 0;
}
