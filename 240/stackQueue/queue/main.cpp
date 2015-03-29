#include "queue.h"
#include <iostream>

int main()
{
  queue<int> q;
  q.push(3);
  q.push(4);
  std::cout << q << std::endl;
  q.pop();
  std::cout << q << std::endl;
  q.pop();
  q.push(5);
  q.push(6);
  q.push(7);
  std::cout << q.front() << "iq empty " << q.empty() 
    << "qize: " << q.size() << std::endl;

  queue<string> rom;
  //rom.push("X");
  //rom.push("L");
  
  rom.push("M");
  /*rom.push("M");
  rom.push("M");
  rom.push("D");
  rom.push("C");
  rom.push("C");
  rom.push("C");
  rom.push("L");
  rom.push("X");
  rom.push("X");
  rom.push("X");
  rom.push("V");
  rom.push("I");
  rom.push("I");
  rom.push("I");
  /*
  rom.push("L");
  rom.push("X");
  rom.push("X");
  rom.push("X");
  rom.push("V");
  rom.push("I");
  rom.push("I");
  rom.push("I");*/

  std::cout << rom.romanNumber(rom) << std::endl;

  queue<string> pal;
  pal.push("a");
  pal.push("b");
  pal.push("b");
  dlinklist<string> dll;
  std::cout << pal.isPalindrome(dll, pal);
  
  return 0;


}
