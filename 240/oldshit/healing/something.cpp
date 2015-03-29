#ifndef SOMETHING_CPP
#define SOMETHING_CPP

#include <iostream>

std::size_t numberOfDigits(int number) {
		std::size_t digitsSoFar = 1;
		while ((number /= 10)!=0) ++ digitsSoFar;
		return digitsSoFar;
};

int main() {

	std::size_t x;
	x = numberOfDigits(213);
	std::cout << x << endl;

	return 0;
};

#endif
