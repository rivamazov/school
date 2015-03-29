#include "array.h"

#include <iostream>
//using namespace std;

int main()
{
	array a(5);
	array b(3);
	//a.reSize(4);
	b[0] = 5;
	b[1] = 3;
	a[2] = 4;

	std::cout << "a is \n" << a;
	std::cout << "b is \n" << b;
	//a.reSize(0);
	//b.reSize(6);
	std::cout << "a is \n" << a;
	std::cout << "b is \n" << b;
	//a.reSize(4);
	//b.reSize(2);
	std::cout << "a is \n" << a;
	std::cout << "b is \n" << b;

  return 0;

}
