#include "bst.h"

int main()
{
	bst mapple;
	mapple.insert(15);
	mapple.insert(13);
  mapple.insert(14);
  mapple.insert(12);
	mapple.insert(16);
	mapple.insert(17);
	mapple.insert(234);
  mapple.insert(2);
	mapple.inorder();
	std::cout << mapple.numLeaves() << std::endl;
	std::cout << mapple.sumLeaves() << std::endl;
  //mapple.reverse();
  mapple.inorder();
  std::cout << mapple.size() << std::endl;
  //std::cout << mapple.find(365) << std::endl;
  std::cout << mapple.find(0) << std::endl;
  std::cout << mapple.find(13) << std::endl;
  std::cout << mapple.min() << std::endl;
  std::cout << "closest to k " << mapple.closestToK(12.5)->data << std::endl;
  mapple.printBreadthFirst();
  std::cout << std::endl;
  mapple.printDepthFirst();
  std::cout << mapple.isBinarySearchTree() << std::endl;
  mapple.reverse();
  std::cout << mapple.isBinarySearchTree() << std::endl;



  return 0;
}
