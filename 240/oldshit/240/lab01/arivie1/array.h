#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>


class array
{
 public:
 	array():data(nullptr),numElements(0){}
	//array(int sz):data(new int[maxSz]),numElements(maxSz){}
	array(int sz):numElements(sz),data(new int[sz]){}
	int sumData();
	int size() const;
	void reSize(const unsigned int sz);
	int& operator[](const int index) const;
	array(array &lhs); //copy constructor
	array& operator+(const array &rhs);
	friend std::ostream& operator<<(std::ostream &out, const array &rhs);
	~array();
  
 private:
  int *data;
  int numElements;
  //std::ostream& out;

};

//std::ostream& operator<<(std::ostream &out, const array &arr);



#endif