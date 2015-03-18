#ifndef NODE_H_
#define NODE_H_
#include <iostream>


class node
{
 public:
 node():next(nullptr),data(0){};
 node(double d):next(nullptr),data(d){};
 void setNext(node *nextNode) {next = nextNode;};
 node* getNext(){return next;}
 double getData(){return data;}
 bool operator==(const double value);
 bool operator!=(const double value);
 friend std::ostream& operator<<(std::ostream &out, node &n);

 private:
  node* next;
  double data;


};

#endif
