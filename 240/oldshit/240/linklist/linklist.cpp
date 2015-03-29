#ifndef LINKLIST_CPP_
#define LINKLIST_CPP_
#include "linklist.h"

void linklist::add_front(double value)
{
	node* nn = new node(value);
	nn->setNext(head);
	head = nn;
}

void linklist::add_back(double value)
{
	node *itr = head;
	node *nn = new node(value);
	if (head == nullptr)
	{
		head == nn;
	}
	else
	{
		while(itr->getNext() != nullptr)
		{
			itr=itr->getNext();
		}
		itr->setNext(nn);
	}
}

void linklist::remove_front()
{
	if (head == nullptr) return;

	node *prev = head;
	head = head->getNext();
	delete prev;
}

void linklist::remove_back()
{
	if (head == nullptr) return;

	node *itr = head;
	while (itr->getNext()->getNext() != nullptr)
	{
		itr=itr->getNext();
	}
	delete itr->getNext();
	itr->setNext(nullptr);
}

linklist::~linklist()
{
	node* prev = nullptr;
	while (head != nullptr)
	{
		prev = head;
		head = head->getNext();
		delete prev;
	}
}

node* linklist::find(double value)
{
	node *itr = head;
	while(itr != nullptr)
	{
		if ( (*itr) == value) return itr;
		itr = itr->getNext();
	}
	return nullptr;
}

void linklist::clear()
{
	node* prev = nullptr;
	while (head != nullptr)
	{
		prev = head;
		head = head->getNext();
		delete prev;
	}
}

bool linklist::empty()
{
	if (head == nullptr) return true;
	else return false;
}

void linklist::reverse()
{
	if (head == nullptr) return;
	node* prev = nullptr;
	while (head != nullptr)
	{
		node* next = head->getNext();
		head->setNext(prev);
		prev = head;
		head = next;
	}
	head = prev;
}

bool linklist::isLoopPresent()
{
	node* itr = head->getNext();
	while(itr!=head && itr->getNext() != nullptr)
	{
		if (itr == head) return true;
		itr=itr->getNext();
	}
	return false;
}

std::ostream& operator<< (std::ostream &out, linklist &ll)
{
	node* tmp = ll.getHead();
	while (tmp != nullptr)
	{
		out << *tmp;
		tmp = tmp->getNext();
	}
	return out;
}

#endif

