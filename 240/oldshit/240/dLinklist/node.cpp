#include "node.h"

template <class U>
std::ostream& operator<< (std::ostream &out,node<U> &n)
{
  out << n.data << std::endl;
  return out;
}
