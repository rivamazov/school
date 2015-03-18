#ifndef RECUR_H_
#define RECUR_H_

template <class T>
class recur
{
  public:
    void cartesianProduct(std::vector< std::vector< char> > &inputSet,
      int position,std::vector< std::vector< char> > &outSet);
    int findMin(std::vector< std::vector< int > > &inputSet, std::pair< int,int> &position);
    void replaceLimit(std::vector< std::vector < int> > &inputSet,std::pair< int,int> 
      &position, int limit);

};

#include "recur.cpp"

#endif;