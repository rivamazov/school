#include "queue.h"
#include <string>

using namespace std;

template <class T>
void queue<T>::push(T data)
{
  numElements++;
  dlinklist<T>::add_back(data); //must specify type
}

template <class T>
void queue<T>::pop()
{
  if (numElements ==0) return;
  numElements--;

  dlinklist<T>::remove_front();
}

template <class T>
T& queue<T>::front()
{
  return dlinklist<T>::front();
}

template <class T>
bool queue<T>::empty()
{
  if (numElements == 0) return true;
  else return false;

}

template <class T>
unsigned int queue<T>::size()
{
  return numElements;
}

template <class T>
bool queue<T>::isPalindrome(dlinklist<T> &dll,queue<T> &que)
{
  string palVal = "";
  queue<T> tmp;
  while(!que.empty())
  {
    palVal+=que.front();
    tmp.push(que.front());
    que.pop();
  }
  while (!tmp.empty())
  {
    que.push(tmp.front());
    tmp.pop();
  }
  string revPal(palVal.rbegin(), palVal.rend());
  cout << revPal;
  cout << palVal;
  if (revPal==palVal) return true;
  else return false;


}

template <class T>
unsigned int queue<T>::romanNumber(queue<T> &que)
{
  string romanVal = "";
  unsigned int decVal =0 ;
  queue<T> tmp;
  while(!que.empty())
  {
    romanVal+=que.front();
    tmp.push(que.front());
    que.pop();
  }
  while (!tmp.empty())
  {
    que.push(tmp.front());
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
unsigned int queue<T>::getNumeralAmount(char let)
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
std::ostream& operator<< (std::ostream &out,queue<U> &que)
{
  queue<U> tmp;
  while(!que.empty())
  {
    out << que.front() << std::endl;
    tmp.push(que.front());
    que.pop();
  }
  while (!tmp.empty())
  {
    que.push(tmp.front());
    tmp.pop();
  }
  return out;
}