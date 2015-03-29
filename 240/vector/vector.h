#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <limits>
#include <cmath>
#include <cstring>

template <class T>
class vector {

	public:
		vector():currentSize(0),maxSize(0),growthRate(5),array(nullptr){}
		vector(unsigned int mxSize, unsigned int growRate = 5)
			:currentSize(0),maxSize(mxSize),growthRate(growRate),array(new T[mxSize]){memset(array,0,sizeof(T)*mxSize);}
		vector(vector<T> &rhs);
		vector& operator=(vector<T> rhs);
		~vector();

		void swap(vector<T> &other);
		const unsigned int size() const;
		unsigned int maximumSize();
		void setGrowthRate(unsigned int grRate);
		void resize(int incArraySize = 0);
		void pushBack(T value);
		T popBack();
		void pushFront(T value);
		T popFront();
		T& front();
		T& back();
		void insert(T value, unsigned int position);
		T maxSumSubArray();

		bool operator ==(const vector &rhs);
		bool operator !=(const vector &rhs);
		T& operator[](const int index) const;

		template <class T1>
		friend std::ostream& operator<<(std::ostream &out, const vector<T> &vct);

	private:
		unsigned int currentSize;
		unsigned int maxSize;
		unsigned int growthRate;
		T* array;

};

#include "vector.cpp"

#endif
