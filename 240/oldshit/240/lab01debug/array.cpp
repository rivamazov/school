#include "array.h"

#include <iostream>


int array::sumData() {
	int sum = 0;
	for (auto i = 0; i < size(); i++) {
		sum += data[i];
	}
	return sum;
}

int array::size() const{
	return this->numElements;
}

void array::reSize(const unsigned int sz) {
	if (data == nullptr) {
		data = new int[sz];
		numElements = sz;
	} 
	//check sz was not initialized to 0
	//else if (data != nullptr && numElements == 0) std::cout << "wtf";
	else if (data != nullptr && numElements >= 0) {
		std::cerr << "entering reSize" << std::endl;
		auto dataBuff = new int[sz];
		if (sz > numElements) {
			for (auto i = 0; i < sz; i++) {
				//check if beyond data[numElements-1]
				if (i >= numElements && sz != 0);//dataBuff[i] = 0;
				else dataBuff[i] = data[i];
			}
		}
		else if (sz <= numElements) {
			for (auto i = 0; i < numElements; i++) {
				dataBuff[i] = data[i];
			}
		}
		delete[] data;
		this->data = dataBuff;
		numElements = sz;
	}
}

array::~array() {
	if(data != nullptr) {
			delete[] data;
		}
}

array& array::operator+(const array &rhs) {
	if(this->numElements != rhs.numElements) return *this;
	//array tmp(this->numElements);
	for (auto i = 0; i < this->numElements; i++) {
		this->data[i] += rhs.data[i];
		//tmp[i] = this->data[i] + rhs.data[i];
	}
	return *this;
	//return tmp;
}

//return reference to integer at index, or last integer
//if index > numElements.
int& array::operator[](const int index) const {
	if (index < numElements && (index > 0)) return data[index];
	return data[numElements-1];
}

std::ostream& operator<<(std::ostream &out, const array &rhs) {
	out << rhs.numElements << std::endl;
	for (auto i = 0; i < rhs.numElements; i++) {
		out << rhs.data[i] << std::endl;
	}
	return out;
}