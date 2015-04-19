#include "heap.h"
#include "generator.h"

int main()
{

	generator gen(1,20);
	heap<int> miheap;
	miheap.setMaxSize(24);
	std::vector<std::pair<double, int> > vec;
	std::pair<double, int> pear;
	std::pair<double, int> pear2;
	std::pair<double, int> pear3;
	std::vector<int>ints = {};
	for (int i=0;i<24;i++) {
		pear.first=i;
		pear.second=gen();
		vec.push_back(pear);
		//vec.erase(std::unique(vec.begin(),vec.end()), vec.end());
	}

	for (auto i=0;i<vec.size();i++) {
		std::cout << vec[i].first << ":" << vec[i].second << ", ";
	}


	while (!vec.empty()) {
		miheap.insert(vec.back());
		vec.pop_back();
	}


	//std::cout << miheap << std::endl;
	miheap.printChildren();




  return 0;
}
