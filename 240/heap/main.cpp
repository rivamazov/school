#include "heap.h"
#include "generator.h"

int main()
{
	generator gen(0,1000);
	heap<int> miheap;
	miheap.setMaxSize(10000);
	std::vector<std::pair<double, int> > vec;
	std::pair<double, int> pear;
	for (int i=0;i<10000;i++) {
		pear.first=i;
		pear.second=gen();
		vec.push_back(pear);
		vec.erase(std::unique(vec.begin(),vec.end()), vec.end());
	}

	while (!vec.empty()) {
		miheap.insert(vec.back());
		vec.pop_back();
	}

	std::cout << miheap.kLargestVals(4);



  return 0;
}
