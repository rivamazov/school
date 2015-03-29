#include "stack.h"

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
T& stack<T>::top()
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

template <class U>
std::ostream& operator<< (std::ostream &out,stack<U> &stk)
{
	stack<U> tmp;
	while(!stk.empty())
	{
		out << stk.top() << std::endl;
		tmp.push(stk.top());
		stk.pop();
	}
	while (!tmp.empty())
	{
		stk.push(tmp.top());
		tmp.pop();
	}
	return out;
}
