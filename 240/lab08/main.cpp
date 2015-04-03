#include "avl.h"
#include "stopWatch.h"
#include "generator.h"
#include "bst.h"

int main()
{
	avl mavl;
	bst mbst;
	stopWatch watch2;
  generator gen(-100,100);
  std::vector<double> array;
  int max = 5000;
  for(int i = 0; i < max; i++)
    array.push_back(gen());
  watch2.start();
  for (int i = 0; i < max; i++)
  	mavl.insert(array[i]);
  watch2.stop();
  std::cout << watch2;

  
  //std::sort(array.begin(),array.end(),[](int a,int b){return a < b;});

  //for(auto i: array)
  //  std::cout << i << std::endl;


  return 0;
}
