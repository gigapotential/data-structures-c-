#ifndef SINGLE_LIST_HPP
#define SINGLE_LIST_HPP

#include "SingleNode.hpp"
#include <iostream>
#include <math.h>

using namespace std;


template <typename T>
class SingleList {
  private:
    SingleNode<T>* head;

  // copy constructor & assignement operator should be priveate due to pointer as memeber variable
    SingleNode<T>*  _reverse(SingleNode<T> *h); 
  public:
    SingleList():head(0) {}
    void insert(T t); 
    void print(); 
    void reverse();
    void shuffle();
    int size();
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
SingleNode<T>* SingleList<T>::_reverse(SingleNode<T> *hd) {
  SingleNode<T> *h = hd;
  SingleNode<T> *newlist = 0;
  while(h != 0) {
    SingleNode<T> *next = h->next;
    h->next = newlist;
    newlist = h;   
    h = next;
  } 
  return newlist;  
}

template <typename T>
void SingleList<T>::reverse() {
  head = _reverse(head);
}

template <typename T>
void SingleList<T>::shuffle() {
  int sze = size();
  int firstSize = ceil(((float)sze)/2);
  int secondSize = sze - firstSize; 
  SingleNode<T> *firstList = head;
  SingleNode<T> *secondList = 0;
  SingleNode<T> *h = head, *prev = 0;
  int counter = firstSize;

  while(counter > 0) {
    prev = h;
    h = h->next;
    --counter;
  }

  if(prev) prev->next = 0;
  secondList = h;  
  
  SingleNode<T> *nl = 0; 
  
  int who = 0;  
  while( firstList != 0 || secondList != 0 ) { 
    SingleNode<T> *node;  
    if(who % 2 == 0 ) { //first
       node = firstList;
       firstList = firstList->next;
       if(nl == 0) {
          nl = node;
          nl->next = 0;
       }
        else {
          node->next = nl;
          nl = node;  
       }
       
    } else { // second
       node = secondList;
       secondList = secondList->next;
       node->next = nl;
       nl = node; 
    }
    who++;
  }   
   
  head = _reverse(nl); 
}

template <typename T>
int SingleList<T>::size() {
  SingleNode<T> *h = head;
  int size = 0;
  while(h != 0) {
    size++;
    h = h->next;
  }
  return size;
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
