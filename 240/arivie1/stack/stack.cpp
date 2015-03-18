#include "stack.h"
#include <string>

using namespace std;

template <class T>
void stack<T>::push(T data)
{
	numElements++;
	dlinklist<T>::add_front(data); //must specify type
}

template <class T>
void stack<T>::pop()
{
	if (numElements ==0) return;
	numElements--;

	dlinklist<T>::remove_front();
}

template <class T>
T& stack<T>::front()
{
	return dlinklist<T>::front();
}

template <class T>
bool stack<T>::empty()
{
	if (numElements == 0) return true;
	else return false;

}

template <class T>
unsigned int stack<T>::size()
{
	return numElements;
}

template <class T>
bool stack<T>::isPalindrome(dlinklist<T> &dll,stack<T> &stk)
{
  string palVal = "";
  stack<T> tmp;
  while(!stk.empty())
  {
    palVal.insert(0, stk.front());
    tmp.push(stk.front());
    stk.pop();
  }
  while (!tmp.empty())
  {
    stk.push(tmp.front());
    tmp.pop();
  }
  string revPal(palVal.rbegin(), palVal.rend());
  if (revPal==palVal) return true;
  else return false;
}

template <class T>
unsigned int stack<T>::romanNumber(stack<T> &stk)
{
	string romanVal = "";
	unsigned int decVal =0 ;
	stack<T> tmp;
	while(!stk.empty())
	{
		romanVal.insert(0, stk.front());
		tmp.push(stk.front());
		stk.pop();
	}
	while (!tmp.empty())
	{
		stk.push(tmp.front());
		tmp.pop();
	}
	int index = 0;
	for (auto& iter : romanVal)
	{
		decVal+=getNumeralAmount(iter);
		if (index!=0 && iter!='I' && romanVal[index-1] == 'I'
      && romanVal[index-2] != 'I')
      decVal-=2;
    if (index!=0 && iter!='X' && romanVal[index-1] == 'X'
      && romanVal[index-2] != 'X')
      decVal-=20;
    if (index!=0 && iter!='C' && romanVal[index-1] == 'C'
      && romanVal[index-2] != 'C')
      decVal-=200;
    index++;
	}
	return decVal;

}

template <class T>
unsigned int stack<T>::getNumeralAmount(char let)
{
  switch(let)
  {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
  }
}

template <class U>
std::ostream& operator<< (std::ostream &out,stack<U> &stk)
{
	stack<U> tmp;
	while(!stk.empty())
	{
		out << stk.front() << std::endl;
		tmp.push(stk.front());
		stk.pop();
	}
	while (!tmp.empty())
	{
		stk.push(tmp.front());
		tmp.pop();
	}
	return out;
}
