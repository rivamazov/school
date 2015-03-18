#include "linklist.h"
#include "node.h"
#include "linklist.cpp"
#include "node.cpp"

#define hasOstream

int main(int argc,char *argv[])
{
  
	bool passed = true;
	linklist ll;
  	ll.add_front(1.2);
 	ll.add_front(2.3);
	ll.add_back(19.8);
	ll.add_back(22.1);
	ll.add_front(8.9);
	if(ll.size() != 5)
	{
		passed = false;
		std::cout<<"failed first size test, should be 5 was " + ll.size()<<std::endl;
	}

	node* exists = ll.find(19.8);
	node* doesntExist = ll.find(1.1);
	if(exists == nullptr)
	{
		passed = false;
		std::cout<<"failed find test when exists"<<std::endl;
	}
	if(doesntExist != nullptr)
	{
		passed = false;
		std::cout<<"failed find test when doesnt exist"<<std::endl;
	}

	#ifdef hasOstream
	std::cout<<"Before referse:\n"<< ll <<std::endl;
	#endif

	ll.reverse();

	#ifdef hasOstream
	std::cout<<"After reverse:\n"<<ll<<std::endl;
	#endif

	if(ll.empty())
	{
		passed = false;
		std::cout<<"failed empty test after reverse"<<std::endl;
	}
	if(ll.size() != 5)
	{
		passed = false;
		std::cout<<"failed size test after reverse"<<std::endl;
	}

	if(ll.isLoopPresent())
	{
		passed = false;	
		std::cout<<"failed loop test should be false was true"<<std::endl;
	}

	ll.remove_back();
	ll.remove_front();

	if(ll.size() != 3)
	{
		passed = false;
		std::cout<<"failed size test after removing front and back, should be 3 was " << ll.size() << std::endl;
	}

	ll.findRemove(88.9);
	ll.findRemove(19.8);
	if(ll.size() != 2)
	{
		passed = false;
		std::cout<<"failed find remove test, size did not change"<<std::endl;
	}

	ll += -11.9;
	if(ll.size() != 3)
	{
		passed = false;
		std::cout<<"failed size after += should be 3 was "<< ll.size() <<std::endl;
	}

	#ifdef hasOstream
  	std::cout << ll <<std::endl;
	#endif

  	ll.remove_front(); ll.remove_front(); ll.remove_back();
	if(ll.size() != 0)
	{
		passed = false;
		std::cout<<"failed size for 0 elements"<<std::endl;
	}
	if(!ll.empty())
	{
		passed = false;
		std::cout<<"failed empty should be true was false"<<std::endl;
	}
	ll.remove_front(); ll.remove_back();
	
	linklist ll2;
	ll2.add_back(1.1);
	ll2.add_front(1.2);
	ll2.add_back(1.3);
	ll2.remove_back(); ll.remove_back(); ll.remove_front();
	ll2.add_front(19.9);
	ll2.add_back(20.1);
	ll2.clear();
	if(ll2.size() != 0 || !ll2.empty())
	{
		passed = false;
		std::cout<<"failed either size or empty or both after clear"<<std::endl;
	}
	


	if(passed)
	{
		std::cout<<"ALL TESTS PASSED"<<std::endl;
	}
	else
	{
		std::cout<<"FAILED ONE OR MORE TESTS"<<std::endl;
	}

  return 0;
}