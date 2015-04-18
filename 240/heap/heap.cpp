#include "heap.h"


template <class T>
void heap<T>::insert(std::pair<double,T> item) {
	if (maxSize==0) return;
	else if (currentSize==maxSize) return;
	else if (currentSize==0) {
		array.resize(maxSize);
		array[0] = item;
		currentSize++;
		return;
	}
	if (item.second > array[0].second) {
		//std::cout << "swap and perc down on " << array[currentSize-1].first;
		std::pair<double, T> placeHolder = array[0];
		array[0] = item;
		perculateDown(0);
		item = placeHolder;
	}
	array[currentSize] = item;
	currentSize++;
	perculateUp(currentSize-1);
	if (currentSize==maxSize) {
		for (int i=0;i<maxSize;i++) {
			if (!comp(0, i)) {
				std::cout << "error " << std::endl;
				return;
			}
		}	
	}
}

template <class T>
T heap<T>::kLargestVals(int k){
	std::vector<T> kLargestVec;

	for (int i=0;i<currentSize;i++) {
		kLargestVec.push_back(array[i].second);
	}
	std::sort(kLargestVec.begin(), kLargestVec.end());
	T sum;
	for (int i=currentSize-k;i<currentSize;i++) {
		sum+=kLargestVec[i];
	}
	return sum;
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
	if (left(pos) > currentSize && right(pos) > currentSize) return; //if leaf return
	if (array[left(pos)].second > array[pos].second || array[right(pos)].second > array[pos].second) {
		if (array[left(pos)].second > array[right(pos)].second) { //right smaller than left
			std::swap(array[pos],array[right(pos)]);
			perculateDown(right(pos));
		}
		else {
			std::swap(array[pos],array[left(pos)]);
			perculateDown(left(pos));
		}
	}

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

template <class U>
std::ostream& operator<<(std::ostream &out, heap<U> &hp)
{
	for (int i=0;i<hp.maxSize;i++) {
		out << hp.array[i].first << " " << hp.array[i].second << std::endl; 
	}

}