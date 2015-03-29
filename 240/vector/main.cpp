#include "vector.h"
#include "generator.h"
#include <iostream>

int main()
{
  vector<int> vct;
  generator gen(-35,40);

  for (int i=0;i<45;i++)
  {
    vct.pushBack(gen());
  }

  std::cout << "max sum subarray = " << vct.maxSumSubArray() 
    << std::endl;
  
  /*
  vector<double> vct;
  vct.pushFront(1.1);
  vct.pushFront(2.2);
  vct.pushFront(3.3);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  vct.pushFront(4.4);
  
  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";
  vct.popBack();
  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";
  vct.popBack();

  std::cout << "size " << vct.size() << " max size " << vct.maximumSize() << "\n";

/*
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
  std::cout << "sizec " << vct.size() << " max size " << vct.maximumSize() << "\n";

  vector<double> vc2;
  vector<double> vc3;
  vc3.pushBack(23);
  vc2=vct;
  bool hold = vc2!=vct;
  std::cout << hold;
  hold = vc2!=vc3;
  std::cout << hold << std::endl;
  std::cout << vct << std::endl;
  std::cout << vct[3];
  vct.insert(666, 21);
  std::cout << vct;
  vct.insert(667, 22);
  std::cout << vct;
  vct.insert(668, 23);
  vct.insert(669, 24);
  std::cout << "\nvct sizex " << vct.size() << "vct maxSize " << vct.maximumSize() << std::endl;
  vct.insert(670, 25);
  std::cout << vct;
  std::cout << "\nvct sizez " << vct.size() << "vct maxSize " << vct.maximumSize() << std::endl;
  vct.insert(254,99);
  std::cout << vct;
  std::cout << "\nvct size " << vct.size() << "vct maxSize " << vct.maximumSize() << std::endl;
  
  std::cout << vct << std::endl;
  vector<double> vc2(vct);
  std::cout << vc2 << std::endl;
  vector<double> vc3;
  vc3.pushBack(3);
  vc3.pushBack(6);
  vc3.pushBack(4);
  std::cout << vc3 << std::endl;
  vc3.swap(vc2);
  std::cout << vc2 << std::endl;
  std::cout << vc3 << std::endl;
  vc2=vc3;
  std::cout << vc2 << std::endl;
  vector<int> vc4;
  vc4.pushBack(-2);
  vc4.pushBack(-3);
  vc4.pushBack(4);
  vc4.pushBack(-1);
  vc4.pushBack(-2);
  vc4.pushBack(1);
  vc4.pushBack(5);
  vc4.pushBack(-3);
  std::cout << vc4;
  std::cout << vc4.maxSumSubArray() << std::endl;
  vector<int> vc5;
  vc5.maxSumSubArray(); 
  */

  return 0;
}
