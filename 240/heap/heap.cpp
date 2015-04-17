#include "heap.h"


template <class T>
void heap<T>::perculateUp(unsigned int position) {
	if (position > 1) {
		if (array[(parent(position))] > array[position]) {
			swap(array[position],array[parent(position)]);
			perculateUp(array[parent(position)]);
		}
	}
}

template <class T>
void heap<T>::insert(std::pair<double,T> item) {
	
}

/* for min heap
* if leaf stop
* look at two children figure out which is the smallest
* then find the smallest one and swap parent with smallest
* perculate down on the child you swapped with
* dont have to do recursive function unless you actually need
* to do a swap.
*/

template <class T>
void heap<T>::perculateDown(unsigned int pos) {
	//if ()
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
