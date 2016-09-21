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
    void reverse();
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
void SingleList<T>::reverse() {
  SingleNode<T> *h = head;
  SingleNode<T> *newlist = 0;
  while(h != 0) {
    SingleNode<T> *next = h->next;
    h->next = newlist;
    newlist = h;   
    h = next;
  } 
  head = newlist;  
}

template <typename T>
void SingleList<T>::print() {
  SingleNode<T>* h = head;
  while(h) {
    cout << h->data << " ";
    h = h->next;
  }
  cout << endl;
}

#endif
