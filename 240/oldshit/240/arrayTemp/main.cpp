#include "generator.h"
#include "array.h"

#include <iostream>

int main()
{
  generator gen(-30,30);
  array<int> bla(10);

  for(int i=0;i<10;i++)
  	bla[i] = gen();
  bla.sorted();
  std::cout << bla << std::endl;

  return 0;


}
