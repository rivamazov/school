#include "bst.h"


int main()
{
	bst mapple;
	mapple.insert(15);
	mapple.insert(13);
	mapple.insert(16);
	mapple.insert(17);
	mapple.insert(234);
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
  std::cout << mapple.find(17) << std::endl;
  std::cout << mapple.max() << std::endl;


  return 0;
}
