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
 void clear(); //TODO should be in same state when initialized
 bool empty(); //TODO return true if elements no if none
 void reverse(); //TODO cannot create new linked list to do so. linear
 /*A loop is present if you never reach null when traversing from the head of the 
 linklist. This function must be complete in linear time complexity.*/
 bool isLoopPresent(); 
 unsigned int size(); //count number of elements and return
 /*If the value is found, then remove it from the linklist. If the value is not present, 
 then do nothing. When removing a node, be sure that you set the pointers correclty*/
 void findRemove(double value);
 void operator+=(double value);//create a new node and add it to the end

 friend std::ostream& operator<<(std::ostream &out, linklist &ll);


 private:
  node* head;

};


#endif
