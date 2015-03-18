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
		head = nn;
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
	else if (head->getNext() == nullptr) //if only one element
	{
		delete head;
		head=nullptr;
		return;
	}

	node *prev = head;
	head = head->getNext();
	delete prev;
}

void linklist::remove_back()
{
	if (head == nullptr) return;
	else if (head->getNext() == nullptr) //if only one element
	{
		delete head;
		head=nullptr;
		return;
	}

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
	head = nullptr;
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
  if (head==nullptr) return false;
  else if (head->getNext()==head) return true;
	node* itr = head->getNext();
	while(itr != nullptr)
	{
		if (itr == head) return true;
		itr=itr->getNext();
	}
	return false;
}

unsigned int linklist::size()
{
	if (head == nullptr) return 0;
	node* itr=head;
	int count = 1;
	while (itr->getNext() != nullptr)
	{
		itr=itr->getNext();
		count++;
	}
	return count;
}

void linklist::findRemove(double value)
{
	node* findResult = this->find(value);
	if (findResult && size() != 1)
	{
		node* itr=head;
		node* newNext=nullptr;
		while (itr->getNext() != findResult)
		{
			itr=itr->getNext();
		}
		newNext=itr->getNext()->getNext();
		delete itr->getNext();
		itr->setNext(newNext);
	}
	else if (findResult) //if only 1 element
	{
		remove_back();
		return;
	}
	else return;
}

void linklist::operator+=(double value)
{
	add_back(value);
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