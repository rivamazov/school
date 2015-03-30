#include "avl.h"

int main()
{
	avl a;
	a.insert(24);
	a.insert(15);
	a.insert(28);
	a.insert(45);
	a.insert(46);
	std::cout << a.balanceFactor();
	a.height();

  return 0;
}
