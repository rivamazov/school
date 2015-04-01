#include "avl.h"

int main()
{
	avl a;
	a.insert(24);
	a.insert(15);
	a.insert(28);
	a.insert(42);
	a.insert(40);
	a.insert(41);
	std::cout << a.balanceFactor();
	std::cout<< a.height() << std::endl;
	std::cout << a.height(a.find(28)) << std::endl;


  return 0;
}
