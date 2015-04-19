#include "heap.h"

#define root array[0];

template <class T>
void heap<T>::insert(const std::pair<double,T> item) {
	if (maxSize==0) return;
	else if (currentSize==maxSize) return;
	else if (currentSize==0) {
		array.resize(maxSize);
		array[0] = item;
		currentSize++;
		return;
	}
	if (item.second > array[0].second && currentSize!=1) {
		std::pair<double, T> treeRoot = array[0];
		array[0] = item;
		perculateDown(0);
		array.insert(array.begin(), treeRoot);
		currentSize++;
		checkHeap();
		return;
	}
	array[currentSize] = item;
	currentSize++;
	perculateUp(currentSize-1);
	assert(array[currentSize-1].second>0);
	checkHeap();
}

template <class T>
void heap<T>::checkHeap() {
	if (currentSize==maxSize) {
		for (int i=0;i<maxSize;i++) {
			if (!comp(0, i)) {
				std::cout << "error " << array[i].first << ":" << array[i].second << std::endl;
				//return;
			}
		}	
	}
}

template <class T> 
void heap<T>::perculateUp(unsigned int position) {
	if (position >= 1) {
		if (array[parent(position)].second > array[position].second) {
			std::swap(array[position],array[parent(position)]);
			perculateUp(parent(position));
		}
	}
}

template <class T>
void heap<T>::perculateDown(unsigned int pos) {
	if (left(pos) >=currentSize && right(pos) >= currentSize) 
		return; //if leaf
	else if (left(pos) < currentSize && right(pos) >= currentSize) {
		if (array[pos].second > array[left(pos)].second) std::swap(array[pos],array[left(pos)]);
	}
	else if (array[left(pos)].second < array[pos].second || array[right(pos)].second < array[pos].second) { //both leaves then swap with the smaller one
		if (array[left(pos)].second < array[right(pos)].second) { //left less than right
			std::swap(array[pos],array[left(pos)]);
			perculateDown(left(pos));
		}
		else {
			std::swap(array[pos],array[right(pos)]);
			perculateDown(right(pos));
		}
	}
	else return;
}

	/*
	if (array[left(pos)].second < array[pos].second 
		|| array[right(pos)].second < array[pos].second) {
		if (array[right(pos)].second < array[right(pos)].second) { //left less than right
			std::swap(array[pos],array[left(pos)]);
			perculateDown(left(pos));
		}
		else {
			std::swap(array[pos],array[right(pos)]);
			perculateDown(right(pos));
		}
	}*/

template <class T>
T heap<T>::kLargestVals(int k){
	std::vector<T> kLargestVec;

	for (int i=0;i<currentSize;i++) {
		kLargestVec.push_back(array[i].second);
	}
	std::sort(kLargestVec.begin(), kLargestVec.end());
	T sum =0;
	for (int i=currentSize-k;i<currentSize;i++) {
		sum+=kLargestVec[i];
	}
	return sum;
}

template <class T>
bool heap<T>::comp(int pnt, int pos)
{
	if (array[pnt].second <= array[pos].second) return true;
	else return false;
}

template <class T>
T* heap<T>::operator[] (int index)
{
	if (index < currentSize) return &array[index].second;
}
template <class T>
unsigned int heap<T>::right(unsigned int i) {
	return 2*i+2;
}

template <class T>
unsigned int heap<T>::left(unsigned int i) {
	return 2*i+1;
}

template <class T>
unsigned int heap<T>::parent(unsigned int i) {
	return std::floor((i-1)/2.0);
}

template <class T>
void heap<T>::printChildren() {
	for (auto i=0;i<parent(currentSize-1);i++) {
		std::cout << "node " << array[i].second << " " << array[left(i)].second
			<< " " << array[right(i)].second << std::endl;
	}
}

template <class U>
std::ostream& operator<<(std::ostream &out, heap<U> &hp)
{
	for (int i=0;i<2;i++) {
		out << "fuck";
		//out << hp.array[i].first << " " << hp.array[i].second << std::endl; 
	}
}