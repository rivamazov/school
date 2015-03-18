#include "linklist.h"


int main(int argc,char *argv[])
{
	linklist ll;
	ll.add_front(1.2);
	linklist ll2;
	ll2.add_front(1.2);
	ll.add_front(2.3);
	ll.add_back(4.4);
	std::cout << ll << std::endl;
	ll.clear();
	std::cout << ll << std::endl;
	ll.add_back(1.2);
	std::cout << ll << std::endl;
	ll.add_back(2.3);
	ll.add_back(3.4);
	ll.add_back(4.5);
	std::cout << ll << std::endl;
	ll.reverse();
	std::cout << ll << std::endl;
	ll.findRemove(2.3);
	std::cout <<  ll << std::endl;
	ll.remove_front();
	ll.remove_front();
	ll.findRemove(1.2);
	std::cout << ll;
	ll.add_back(2.4);
	ll.add_back(3.3);
	ll.findRemove(3.3);
	ll.findRemove(2.4);



  return 0;
}
