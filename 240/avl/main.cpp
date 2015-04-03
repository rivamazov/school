#include "avl.h"

int main()
{
	avl a;
	a.insert(1);
	a.insert(3);
  a.insert(2);
  //a.insert(13);
	//a.insert(28);
	//a.insert(13);
  
	//a.insert(13);
	//a.insert(41);
	std::cout << "bfctor" << a.balanceFactor() << std::endl;
	std::cout<< "tree height" << a.height() << std::endl;
	std::cout << "height" << a.height(a.find(42)) << std::endl;
  std::cout << a;


  return 0;
}
