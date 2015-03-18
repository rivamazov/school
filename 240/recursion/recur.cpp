#include "recur.h"

//turn back to vector of chars instead of vector of vectors
//and just print it out
void cartesianProduct(std::vector< std::vector< char> > &inputSet,
      int position, std::vector<char> &outSet) {
	if (inputSet.size() == outSet.size())
	{
		for (auto let : outSet)
			std::cout << let << " ";
		std::cout << std::endl;
		return;
	}
	for (auto setData : inputSet[position])
	{
		outSet.push_back(setData);
		cartesianProduct(inputSet, position+1, outSet);
		outSet.pop_back();
	}

}

int findMin(std::vector< std::vector< int > > &inputSet, 
  std::pair< int,int> &position) {

}

//only positive numbers
void replaceLimit(std::vector< std::vector < int> > &inputSet,
  std::pair< int,int> &position, int limit) {

}
