#include "stack.h"

#include <iostream>

int main()
{
  stack<int> s;
  s.push(3);
  s.push(4);
  std::cout << s << std::endl;
  s.pop();
  std::cout << s << std::endl;
  s.pop();
  s.push(5);
  s.push(6);
  s.push(7);
  std::cout << s.front() << "is empty " << s.empty() 
    << "size: " << s.size() << std::endl;
  stack<string> rom;
  rom.push("M");
  rom.push("M");
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

  std::cout << rom.romanNumber(rom) << std::endl;

  stack<string> pal;
  pal.push("a");
  pal.push("b");
  pal.push("a");
  dlinklist<string> dll;
  std::cout << pal.isPalindrome(dll, pal);


  return 0;
}
