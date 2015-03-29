#include "vector.h"
#include <iostream>

int main()
{
  vector vct;
  vct.pushBack(1.1);
  vct.pushBack(2.2);
  vct.pushBack(3.3);
  vct.pushBack(4.4);
  vct.pushBack(4.4);

  std::cout << vct.popBack() << " " << vct.size() << " " << vct.maximumSize() << std::endl; 
  std::cout << vct.front() << std::endl;
  std::cout << "back " << vct.back() << std::endl;
  std::cout << vct << std::endl;
  vct.insert(-17,3);
  std::cout << vct << std::endl;
  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";
  std::cout << vct.popFront() << std::endl << std::endl;
  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";
  std::cout << vct << std::endl;
  vct.pushBack(5.5);
  vct.insert(666,5);
  std::cout << vct << std::endl;
  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";
  vct.pushFront(5.5);
  std::cout << "size ----------" << vct.size() << " max size " << vct.maximumSize() << "\n";
  std::cout << vct << std::endl;
  vct.popBack();
  std::cout << vct << std::endl;
  vct.popFront();
  std::cout << vct << std::endl;
  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";

  vector vc2;
  vector vc3;
  vc3.pushBack(23);
  vc2=vct;
  bool hold = vc2!=vct;
  std::cout << hold;
  hold = vc2!=vc3;
  std::cout << hold << std::endl;
  std::cout << vct << std::endl;
  std::cout << vct[3];

  return 0;
}
