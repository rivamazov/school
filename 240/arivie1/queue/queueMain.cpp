#include "queue.h"
#include <iostream>

//#define testRoman
//#define testPalindrome

int main()
{
	bool passed = true;

	queue<int> i;
        i.push(1);
        i.push(2);
        i.push(3);
        i.push(19);
        i.push(20);
        i.push(100);
        if(i.size() != 6)
        {
                passed = false;
                std::cout<<"failed size test after adding, should be 6 was "<<i.size()<<std::endl;
        }
        std::cout<<"printing queue with five elements added 1 2 3 19 20 100:\n"<<i<<std::endl;
        i.pop(); i.pop();
        if(i.size() != 4)
        {
                passed = false;
                std::cout<<"failed size test after two pops should be 4 was "<<i.size()<<std::endl;
        }
        if(i.empty())
        {
                passed = false;
                std::cout<<"failed empty with four elements"<<std::endl;
        }
        std::cout<<"printing stack after popping two shoudl be 3 19 20 100:\n"<<i<<std::endl;
        i.pop();
        i.pop();
        i.pop();
        i.pop();
        if(i.size() != 0)
        {
                passed = false;
                std::cout<<"failed size test after popping all, should be 0 was "<<i.size()<<std::endl;
        }
        if(!i.empty())
        {
                passed = false;
                std::cout<<"failed empty test should be true was false"<<std::endl;
        }
        i.pop();
        std::cout<<"printing empty int queue:\n"<<i<<std::endl;

        queue<double> d;
        d.push(19.9);
        d.push(20.1);
        d.push(20.2);
        if(d.size() != 3)
        {
                passed = false;
                std::cout<<"failed size test for 3 elements with double was "<<d.size()<<std::endl;
        }
        std::cout<<"printing double queue:\n"<<d<<std::endl;
        d.pop();
        if(d.size() != 2)
        {
                passed = false;
                std::cout<<"failed double test should be 2 was "<<d.size()<<std::endl;
        }
        std::cout<<"printing queue after popping one:\n"<<d<<std::endl;


	#ifndef testRoman
        queue<char> r, r2, r3;
        if(r.getNumeralAmount('X') != 10)
        {
                passed = false;
                std::cout<<"failed roman numeral test, returned "<<r.getNumeralAmount('X')<<" for 10"<<std::endl;
        }
	else
	{
		std::cout<<"passed roman numeral 10"<<std::endl;
	}
        if(r.getNumeralAmount('I') != 1)
        {
                passed = false;
                std::cout<<"failed roman numeral test 2, returned "<<r.getNumeralAmount('I')<<" for 1"<<std::endl;
        }
	else
	{
		std::cout<<"passed roman numeral 1"<<std::endl;
	}
        r2.push('X');
        r2.push('V');
        r2.push('I');
        int romanNumber1 = r.romanNumber(r2);
        if(romanNumber1 != 16)
        {
                passed = false;
                std::cout<<"failed conversion to roman number, should be 16 was "<<romanNumber1<<std::endl;
        }
	else
	{
		std::cout<<"passed roman function 16"<<std::endl;
	}
        r3.push('I');
        r3.push('X');
        int romanNumber2 = r.romanNumber(r3);
        if(romanNumber2 != 9)
        {
                passed = false;
                std::cout<<"failed second conversion to roman number, should be 9 was "<<romanNumber2<<std::endl;
        }	
	else
	{
		std::cout<<"passed roman numeral 9"<<std::endl;
	}
	#endif

	#ifndef testPalindrome
	queue<char> p1, p2, p3, p4;
        dlinklist<char> d1, d2;
        d1.add_front('a');
        d1.add_front('b');
        d1.add_front('c');
        d1.add_front('b');
        d1.add_front('a');
        if(!p1.isPalindrome(d1, p3))
        {
                passed = false;
                std::cout<<"failed palindrome test, should be true was false"<<std::endl;
        }
	else
	{
		std::cout<<"passed palindrome"<<std::endl;
	}
        d2.add_back('a');
        d2.add_back('b');
        d2.add_back('b');
        if(p2.isPalindrome(d2, p4))
        {
                passed = false;
                std::cout<<"failed palindrome test, should be zfalse was true"<<std::endl;
        }
	else
	{
		std::cout<<"passed non palindrome"<<std::endl;
	}
	#endif

	if(passed)
	{
		std::cout<<"passed all tests"<<std::endl;
	}
	else
	{
		std::cout<<"failed one or more tests"<<std::endl;
	}

	return 0;
}
