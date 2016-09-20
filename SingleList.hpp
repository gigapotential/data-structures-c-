#ifndef SINGLE_LIST_HPP
#define SINGLE_LIST_HPP

#include "SingleNode.hpp"
#include <iostream>

using namespace std;


template <typename T>
class SingleList {
  private:
    SingleNode<T>* head;

  // copy constructor & assignement operator should be priveate due to pointer as memeber variable
  
  public:
    SingleList():head(0) {}
    void insert(T t); 
    void print(); 
};

template <typename T>
void SingleList<T>::insert(T t) {
  if(head == 0) {
    head = new SingleNode<T>(t);
  } else {
    SingleNode<T>* newnode = new SingleNode<T>(t, head);
    head = newnode;
  }
}

template <typename T>
void SingleList<T>::print() {
  SingleNode<T>* h = head;
  while(h) {
    cout << h->data << " ";
    h = h->next;
  }
}

#endif
