#include <iostream>
#include "generator.h"
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>


int rec(int value);
int fib(int n);

int findMin(std::vector<int> &array,int currentPos);

int main(int argc,char* argv[])
{
  generator gen(-100,100);
  std::vector<int> array;
  int max = 10;
  for(int i = 0; i < max; i++)
    array.push_back(gen());

  
  std::sort(array.begin(),array.end(),[](int a,int b){return a < b;});

  for(auto i: array)
    std::cout << i << std::endl;

  std::pair<int,int> point = std::make_pair(1,2);
  std::cout << point.first << "   " << point.second << std::endl;
  point.first+=1;
  std::cout << point.first << "   " << point.second << std::endl;

  std::vector<std::pair<int,int> > pointSet;
  for(int i = 0; i < 10; i++)
    pointSet.push_back(std::make_pair(gen(),gen() ) );

  std::sort(pointSet.begin(),pointSet.end(),[](std::pair<int,int> a,std::pair<int,int> b){return a.first < b.first;});

  for(auto i :pointSet)
    std::cout << i.first << "   " << i.second << std::endl;



  //declare the 2d Matrix that has a 100 elements or 10 by 10
  std::vector<std::vector<int> > matrix;

  //declare the numbers of rows
  int numberOfRows = 10;
  matrix.resize(numberOfRows);

  //declare the number of columns
  int numberOfColumns = 10;
  //set number of columns for each row
  for(int i =0; i < numberOfRows; i++)
    {
      matrix[i].resize(numberOfColumns);
    }


  //now you can access any element in the matrix

  //element 0,0
  matrix[0][0] = 100;
  //element 9,9 or the 100 element in the matrix
  matrix[9][9] = 5;
  
  //fill all elements with 1
  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{
	  matrix[i][j] = 1;
	}
    }
  
  //use a std::pair to get elements
  std::pair<int,int> pnt = std::make_pair(4,5);

  matrix[pnt.first][pnt.second] = -1;


  return 0;
}

int findMin(std::vector<int> &array,int currentPos)
{
  if(array.size() == currentPos)return std::numeric_limits<int>::max();
  int returnVal = findMin(array,currentPos+1);
  std::cout << "currentPos: " << currentPos << " returnVal " << returnVal << " array Value: " << array[currentPos]<<std::endl;
  if(returnVal < array[currentPos])
    return returnVal;
  else
    return array[currentPos];
}


int fib(int n)
{
  if(n == 0)return 1;
  if(n == 1)return 1;
  return fib(n-1)+fib(n-2);
}
int rec(int value)
{
  if(value <= 0)return value+1;
  int i = rec(value-1)+value;
  return i;
}
