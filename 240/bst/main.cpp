#include "bst.h"


int main()
{
	bst mapple;
	mapple.insert(15);
	mapple.insert(13);
	mapple.insert(16);
	mapple.insert(17);
	mapple.inorder();
	std::cout << mapple.numLeaves() << std::endl;
	std::cout << mapple.sumLeaves();

  return 0;
}
