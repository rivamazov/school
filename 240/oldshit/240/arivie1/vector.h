#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <limits>
#include <cmath>
#include <cstring>

class vector {
	public:
		vector():currentSize(0),maxSize(0),growthRate(5),array(nullptr){}
		vector(const int sz):currentSize(sz),array(new double[sz]){}
		vector(unsigned int mxSize, unsigned int growRate = 5)
			:currentSize(0),maxSize(mxSize),growthRate(growRate),array(new double[mxSize]){memset(array,0,sizeof(double)*mxSize);}
		vector(vector &rhs);
		vector& operator=(vector rhs);
		~vector();
		void swap(vector &other);
		unsigned int size();
		unsigned int maximumSize();
		void setGrowthRate(unsigned int grRate);
		void resize(int incArraySize = 0);
		void pushBack(double value);
		double popBack();
		void pushFront(double value);
		double popFront();
		double& front();
		double& back();
		void insert(double value, unsigned int position);
		bool operator ==(const vector &rhs);
		bool operator !=(const vector &rhs);
		double& operator[](const int index) const;

		friend std::ostream& operator<<(std::ostream &out, const vector &vct);


	private:
		unsigned int currentSize;
		unsigned int maxSize;
		unsigned int growthRate;
		double* array;

};

#endif
