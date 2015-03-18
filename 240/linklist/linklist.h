#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "node.h"


class linklist
{
 public:
 linklist():head(nullptr){}
 void add_front(double value);
 void add_back(double value);
 void remove_front();
 void remove_back();
 ~linklist();
 node* find(double value);
 node* getHead(){return head;}   
 void clear();
 bool empty(); 
 void reverse();
 bool isLoopPresent(); 
 unsigned int size(); 
 void findRemove(double value);
 void operator+=(double value);

 friend std::ostream& operator<<(std::ostream &out, linklist &ll);


 private:
  node* head;

};


#endif
