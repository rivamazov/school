#include "dlinklist.h"

template <class T>
void dlinklist<T>::add_front(T value)
{
	node<T> *nn = new node<T> (value);

	if (head==nullptr)
	{
		assert(tail==nullptr);
		head = tail = nn;
	}
	else
	{
		//perhaps is this
		nn = next;
		head->prev = next = nn;
		head = nn;
	}
	//create new node check if list is empty
	//if empty create it
	//if it is not empty set nn = next
	//head->prev = next = nn
	//head =nn
}


