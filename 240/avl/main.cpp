#include "avl.h"

int main()
{
	avl a;
	a.insert(24);
	a.insert(15);
	a.insert(28);
	a.balanceFactor();

  return 0;
}
