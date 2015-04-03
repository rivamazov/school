#include "avl.h"
#include "stopWatch.h"
#include "generator.h"
#include "bst.h"

int main()
{
  generator gen(-100,100);
  std::vector<double> array;
  int max = 5000;
  for(int i = 0; i < max; i++)
    array.push_back(gen());

  
  std::sort(array.begin(),array.end(),[](int a,int b){return a < b;});

  for(auto i: array)
    std::cout << i << std::endl;


  return 0;
}
