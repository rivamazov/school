#include "array.h"

#include <iostream>

int main()
{
	array a;
	array b;
	array c(0);
	a.reSize(4);
	b.reSize(3);
	for (auto i = 0; i < a.size(); i++) {
		a[i] = i;
	}
	b[0] = 5;
	b[1] = 3;
	std::cout << b.sumData() << std::endl;
	std::cout << a.sumData() << std::endl;
	std::cout << "a is \n" << a;
	std::cout << "b is \n" << b;
	std::cout << "c is \n" << c;
	a.reSize(0);
	b.reSize(6);
	c.reSize(3);
	std::cout << "a is \n" << a;
	std::cout << "b is \n" << b;
	std::cout << "c is \n" << c;
	a.reSize(4);
	b.reSize(2);
	c.reSize(1);
	std::cout << "a is \n" << a;
	std::cout << "b is \n" << b;
	std::cout << "c is \n" << c;

  return 0;

}
