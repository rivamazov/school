#include "dlinklist.h"


int main()
{
	bool passed = true;

	dlinklist<int> dint;
	dint.add_front(20);
	dint.add_front(19);
	dint.add_back(21);
	dint.add_back(22);
	if(dint.size() != 4)
	{
		passed = false;
		std::cout<<"failed size test for int should be 4 was "<<dint.size()<<std::endl;
	}
	if(dint.front() != 19)
	{
		passed = false;
		std::cout<<"failed front for int should be 19 was "<<dint.front()<<std::endl;
	}
	if(dint.back() != 22)
	{
		passed = false;
		std::cout<<"failed back for int should be 22 was "<<dint.back()<<std::endl;
	}
	if(dint.empty())
	{
		passed = false;
		std::cout<<"failed empty for int should be false was true"<<std::endl;
	}
	dint.remove_front(); dint.remove_back();
	if(dint.size() != 2)
	{
		passed = false;
		std::cout<<"failed second size test for int should be 2 was "<<dint.size()<<std::endl;
	}
	dint.remove_front(); dint.remove_back();
	if(!dint.empty() || dint.size()!=0)
	{
		passed = false;
		std::cout<<"failed empty or size test for int with no elements"<<std::endl;
	}

	dlinklist<double> dfloat;
	dfloat.add_front(1.1);
	dfloat.add_front(1.6);
	dfloat.add_front(88.1);
	dfloat.add_back(1.2);
	dfloat.add_back(19.1);
	if(dfloat.front() != 88.1)
	{
		passed = false;
		std::cout<<"failed front for float, should be 88.1 was "<<dfloat.front()<<std::endl;
	}
	if(dfloat.back() != 19.1)
	{
		passed = false;
		std::cout<<"failed back for float, should be 19.1 was "<<dfloat.back()<<std::endl;
	}
	if(dfloat.size() != 5)
	{
		passed = false;
		std::cout<<"failed size for float, should be 6 was "<<dfloat.size()<<std::endl;
	}
	if(dfloat.empty())
	{
		passed = false;
		std::cout<<"failed empty for float should be false was true"<<std::endl;
	}
	dfloat.remove_front(); dfloat.remove_back();
	if(dfloat.size() != 3)
	{
		passed = false;
		std::cout<<"failed size for float after removing, should be 4 was "<<dfloat.size()<<std::endl;
	}
	dfloat.remove_front(); dfloat.remove_front(); dfloat.remove_back(); dfloat.remove_back();	
	dfloat.add_back(19.19);
	dfloat.remove_front();
	if(dfloat.size() != 0)
	{
		passed = false;
		std::cout<<"failed size test for float when empty, should be 0 was "<<dfloat.size()<<std::endl;
	}
	if(!dfloat.empty())
	{
		passed = false;
		std::cout<<"failed empty test for float, should be true was false"<<std::endl;
	}
	


	if(passed)
	{
		std::cout<<"PASSED ALL TESTS"<<std::endl;
	}
	else
	{
		std::cout<<"FAILED ONE OR MORE TESTS"<<std::endl;
	}


  return 0;


}
