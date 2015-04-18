#include "avl.h"
#include "stopWatch.h"
#include "generator.h"
#include "bst.h"

int main()
{
	avl mavl;
	bst mbst;
  generator gen(0,1000);
  std::vector<double> array;
  int max = 5000;
  for(int i = 0; i < max; i++)
    array.push_back(gen());

	stopWatch watch;
  watch.start();
  for (int i = 0; i < max; i++)
  	mbst.insert(array[i]);
  watch.stop();
  std::cout << "bst insert " << watch;

  stopWatch watch2;
  watch2.start();
  for (int i = 0; i < max; i++)
  	mavl.insert(array[i]);
  watch2.stop();
  std::cout << "avl insert " << watch2;
  
  stopWatch watch3;
  watch3.start();
  for (int i = 0; i < max; i++)
  	mbst.find(array[i]);
  watch3.stop();
  std::cout << "bst search " << watch3;

  stopWatch watch4;
  watch4.start();
  for (int i = 0; i < max; i++)
  	mavl.find(array[i]);
  watch4.stop();
  std::cout << "avl search " << watch4;
  
  std::sort(array.begin(),array.end(),[](int a,int b){return a < b;});

  stopWatch watch5;
  watch5.start();
  for (int i = 0; i < max; i++)
  	mbst.find(array[i]);
  watch5.stop();
  std::cout << "bst sorted search " << watch5;

  stopWatch watch6;
  watch6.start();
  for (int i = 0; i < max; i++)
  	mavl.find(array[i]);
  watch6.stop();
  std::cout << "avl sorted search " << watch6;



  //for(auto i: array)
  //  std::cout << i << std::endl;


  return 0;
}
