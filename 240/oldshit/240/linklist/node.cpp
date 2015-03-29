#include "node.h"


std::ostream& operator<<(std::ostream &out, node &n)
{
	out << n.data << std::endl;
	return out;
}

bool node::operator==(const double value)
{
	if (data == value) return true;
	return false;
}





