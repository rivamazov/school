#include "linklist.h"


int main(int argc,char *argv[])
{
	linklist ll;
	ll.add_front(1.2);
	linklist ll2;
	ll2.add_front(1.2);
	ll.add_front(2.3);
	ll.add_back(4.4);
	ll.remove_front();
	ll.remove_back();
	//ll.clear();
	ll.add_front(1.2);
	ll.add_front(2.3);
	ll.add_front(3.4);
	ll.add_front(4.5);


	std::cout << ll << std::endl;
	ll.reverse();
	std::cout << ll << std::endl;
  return 0;
}
