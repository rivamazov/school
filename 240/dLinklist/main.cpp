#include "dlinklist.h"


int main()
{
	dlinklist<int> dl;
  dl.add_front(3);
  dl.add_front(4);
  dl.add_back(5);
  std::cout << dl.size() << std::endl;
  dl.remove_front();
  dl.remove_back();
  std::cout << dl << std::endl;
  std::cout << dl.front() << std::endl << dl.back() << std::endl;
  std::cout << dl.size() << std::endl;
  dl.remove_front();
  std::cout << dl.size() << std::endl;
  std::cout << dl.empty() << std::endl;
  dl.add_back(4);
  std::cout << dl.size() << std::endl;
  dl.remove_back();
  std::cout << dl.empty() << std::endl;

  return 0;


}
