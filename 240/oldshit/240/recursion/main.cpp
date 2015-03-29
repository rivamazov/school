#include <iostream>
#include <vector>
#include <limits>

int rec(int value);
int findMin(std::vector<int> &array, int currentPos);
int binarySearch(int* array, int start, int end, int value);

int main(int argc, char* argv[])
{
	int x = rec(5);
	std::cout << x << std::endl;

	return 0;
}

int rec(int value)
{
	if (value<=0) return value+1;
	int i = value + rec(value-1);
	return i;
}

int binarySearch(int* array, int start, int end, int value)
{
	int middle = (end+start)/2;
	if (start > end) return -1;
	if (array[middle] ==value)
		return middle;
	else if (array[middle]<value)
		return binarySearch(array, middle+1, end, value);
	else
		return binarySearch(array,start,middle,value);
}

int findMin(std::vector<int> &array, int currentPos)
{
	if (array.size() == currentPos) return std::numeric_limits<int>::max();
	int returnVal = findMin(array, currentPos+1);
	std::cout << "currentPos" << currentPos << "returnVal" << returnVal << 
		"arrayVal" << array[currentPos] << std::endl;
	if (returnVal < array[currentPos])
		return returnVal;
	else
		return array[currentPos];
}