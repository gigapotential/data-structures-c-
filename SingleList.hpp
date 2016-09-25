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
    SingleNode<T>* _sort(SingleNode<T> *h);
    SingleNode<T>* _max(SingleNode<T> *h);
    void _remove(SingleNode<T>** p_h, SingleNode<T> *n);
  public:
    SingleList():head(0) {}
    void insert(T t); 
    void print(); 
    void reverse();
    void shuffle();
    void sort();
    void team_of_n(int n);
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
void SingleList<T>::sort() {
  head = _sort(head);
}

template <typename T>
SingleNode<T>* SingleList<T>::_max(SingleNode<T>* hd) {
  SingleNode<T>* maxnode = 0;
  T maxvalue = numeric_limits<T>::min();
  while(hd != 0) {
    if(hd->data > maxvalue) {
      maxvalue = hd->data;
      maxnode = hd;
    }
    hd = hd->next;
  }
  return maxnode;
}

template <typename T>
void SingleList<T>::_remove(SingleNode<T> **p_hd, SingleNode<T>* remove) {
  if(p_hd == 0 || remove == 0 ) return;

  SingleNode<T>* hd = *p_hd;
  
  // first element
  if( hd == remove) {
    SingleNode<T>* next = hd->next;
    hd->next = 0;
    *p_hd = next;    
  } else {
    SingleNode<T> *prev;
    while(hd != remove && hd != 0) {
      prev = hd;
      hd = hd->next;
    }
    
    if(hd == remove) {
      prev->next = hd->next;
      hd->next = 0;
    }
  }
    
}


template <typename T>
SingleNode<T>* SingleList<T>::_sort(SingleNode<T>* h) {
  SingleNode<T>* sorted = 0;
  while(h != 0) {
    SingleNode<T>* maxnode = _max(h);
    _remove(&h, maxnode);
    maxnode->next = sorted; 
    sorted = maxnode; 
  }    
  return sorted; 
}

template <typename T>
void SingleList<T>::team_of_n(int n) {
  SingleNode<T> *h = head, *next, *prev, *newhead= 0, *prev_list_end = 0 ;
  
  while(h != 0) {
    int count = 1;
    prev = 0;
    next = h;
    while(count <= n && next != 0) {
      prev = next;
      next = next->next;
      ++count;
    }  
        
    if(prev != 0) prev->next = 0;
    h = _sort(h); 
    if(newhead == 0) newhead = h;
    
    if(prev_list_end == 0) {
      while(h->next != 0) h = h->next;  
      prev_list_end = h;
    } else {
      prev_list_end->next = h;
      while(h->next != 0) h = h->next;
      prev_list_end = h;
    } 
     
    h = next;
  }
  
  head = newhead; 
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
