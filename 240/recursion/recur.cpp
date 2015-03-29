#include "recur.h"

//turn back to vector of chars instead of vector of vectors
//and just print it out
void cartesianProduct(std::vector< std::vector< char> > &inputSet,
      int position, std::vector<char> &outSet) {
	if (inputSet.size() == outSet.size()) {
		for (auto let : outSet) {
      std::cout << let << std::endl;
    }
		std::cout << std::endl;
		return;
	}
	for (auto setData : inputSet[position]) {
    outSet.push_back(setData);
		cartesianProduct(inputSet, position+1, outSet);
		outSet.pop_back();
	}

}

int findMin(std::vector< std::vector< int > > &inputSet, 
  std::pair< int,int> &position)
{
  int min;
	if (position.first==inputSet.size()) {
		min = std::numeric_limits<int>::max();
    return min;
	}
	for (auto setData : inputSet[position.first]) {
    position.first++;
    min = findMin(inputSet, position);

		(min < setData) ? min : setData;
    return min;
    //return ((setData < findMin(inputSet, position)) ? setData : inputSet[position.second+1]);
	}



}

//only positive numbers
void replaceLimit(std::vector< std::vector < int> > &inputSet,
  std::pair< int,int> &position, int limit) {
  //if (position.first = 

}
