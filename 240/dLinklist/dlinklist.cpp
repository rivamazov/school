#include "dlinklist.h"
#include <assert.h>\

template <class T>
dlinklist<T>::~dlinklist()
{
  if (head==nullptr)
  {
    assert(tail==nullptr);
    return;
  }
  node<T>* prev=nullptr;
  while (head != nullptr)
  {
    prev = head;
    head = head->getNext();
    delete prev;
  }
}


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
		head->setPrev(nn);
    nn->setNext(head);
		head = nn;
	}
}

template <class T>
void dlinklist<T>::add_back(T value)
{
  node<T> *nn = new node<T> (value);
  if (head==nullptr)
  {
    assert(tail==nullptr);
    head = tail = nn;
  }
  else
  {
    tail->setNext(nn);
    nn->setPrev(tail);
    tail = nn;
  }
}

template <class T>
void dlinklist<T>::remove_front()
{
  if (head==nullptr)
  {
    assert(tail==nullptr);
    return;
  }
  else if (head==tail)
  {
    delete head;
    head=tail=nullptr;
    return;
  }
  node<T>* newHead=head->getNext();
  head->getNext()->setPrev(nullptr);
  delete head;
  head = newHead;
}

template <class T>
void dlinklist<T>::remove_back()
{
  if (head==nullptr) return;
  else if (head==tail)
  {
    delete tail;
    head=tail=nullptr;
    return;
  }
  node<T>* newTail=tail->getPrev();
  tail->getPrev()->setNext(nullptr);
  delete tail;
  tail = newTail;

}

template <class T>
unsigned int dlinklist<T>::size()
{
  if (head==nullptr)
  {
    assert(tail==nullptr);
    return 0;
  }
  node<T>* itr=head;
  unsigned int count = 1;
  while (itr->getNext() != nullptr)
  {
    itr=itr->getNext();
    count++;
  }
  return count;
}

template <class T>
bool dlinklist<T>::empty()
{
  if (head==nullptr)
  {
    assert(tail==nullptr);
    return true;
  }
  else return false;
}

template <class U>
std::ostream& operator<< (std::ostream &out, dlinklist<U> &dl)
{
  node<U>* tmp = dl.head;
  while (tmp != nullptr)
  {
    out << *tmp;
    tmp = tmp->getNext();
  }
  return out;
}
