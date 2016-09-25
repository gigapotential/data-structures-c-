#ifndef DOUBLE_LIST_HPP
#define DOUBLE_LIST_HPP

#include "DoubleNode.hpp"
#include <iostream>
#include <math.h>

using namespace std;


template <typename T>
class DoubleList {
  private:
    DoubleNode<T>* head;
    DoubleNode<T>* tail;

  // Since memeber are pointers, copy constructor & assignment operator should be made private
    DoubleNode<T>*  _reverse(DoubleNode<T> *h); 
    void _sort(DoubleNode<T> **h, DoubleNode<T> **t);
    DoubleNode<T>* _max(DoubleNode<T> *h);
    void _remove(DoubleNode<T>** p_h, DoubleNode<T> **p_t, DoubleNode<T> *n);
  public:
    DoubleList():head(0), tail(0) {}
    void insert(T t); 
    void print(); 
    void print_reverse(); 
    void reverse();
    void shuffle();
    void sort();
    void team_of_n(int n);
    int size();
};



template <typename T>
void DoubleList<T>::insert(T t) {
  if(head == 0) {
    head = tail =  new DoubleNode<T>(t);
  } else {
    DoubleNode<T>* newnode = new DoubleNode<T>(t, tail, 0);
    tail->next = newnode;
    tail = newnode;
  }
}

template <typename T>
DoubleNode<T>* DoubleList<T>::_reverse(DoubleNode<T> *hd) {
  DoubleNode<T> *h = hd;
  DoubleNode<T> *newlist = 0;
  while(h != 0) {
    DoubleNode<T> *next = h->next;
    h->next = newlist;

    if(newlist) newlist->prev = h;

    newlist = h;   
    newlist->prev = 0;
    h = next;
  } 
  return newlist;  
}

template <typename T>
void DoubleList<T>::reverse() {
  tail = head;
  head = _reverse(head);
}

template <typename T>
void DoubleList<T>::shuffle() {
  int sze = size();
  int firstSize = ceil(((float)sze)/2);
  int secondSize = sze - firstSize; 
  DoubleNode<T> *firstList = head;
  DoubleNode<T> *secondList = 0;
  DoubleNode<T> *h = head, *prev = 0;
  int counter = firstSize;

  while(counter > 0) {
    prev = h;
    h = h->next;
    --counter;
  }

  if(prev) prev->next = 0;
  secondList = h;  
  
  DoubleNode<T> *newlistbegin = 0;
  DoubleNode<T> *nl = 0;  // points to new list end
  
  int who = 0;  
  while( firstList != 0 || secondList != 0 ) { 
    DoubleNode<T> *node;  
    if(who % 2 == 0 ) { //first
       node = firstList;
       firstList = firstList->next;
       if(nl == 0) {
          newlistbegin = node;
          nl = node;
          nl->next = 0;
          nl->prev = 0;
       }
        else {
          nl->next = node;
          node->prev = nl;
          node->next = 0;
          nl = node;  
       }
       
    } else { // second
       node = secondList;
       secondList = secondList->next;
       nl->next = node;
       node->prev = nl;
       node->next = 0;
       nl = node; 
    }
    who++;
  }   
   
  head = newlistbegin;
  tail = nl; 
}

template <typename T>
void DoubleList<T>::sort() {
  _sort(&head, &tail);
}

template <typename T>
DoubleNode<T>* DoubleList<T>::_max(DoubleNode<T>* hd) {
  DoubleNode<T>* maxnode = 0;
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
void DoubleList<T>::_remove(DoubleNode<T> **p_hd, DoubleNode<T> **p_t, DoubleNode<T>* remove) {
  if(p_hd == 0 || p_t == 0 || remove == 0 ) return;

  DoubleNode<T>* hd = *p_hd;
  DoubleNode<T>* ta = *p_t;
  
  // only one element
  if(hd == remove && ta == remove) {
    *p_hd = *p_t = 0;
    remove->next = remove->prev = 0;    
  } else if( hd == remove ) { // head removal
    DoubleNode<T> *next = hd->next;
    hd->next = 0;
    next->prev = 0;
    *p_hd = next;
  } else if( ta == remove) { // tail removal
    DoubleNode<T> *prev = ta->prev;
    prev->next = 0;
    ta->prev = 0;
    *p_t = prev;
  } else { // remove node somewhere in between
    remove->prev->next = remove->next;  
    remove->next->prev = remove->prev;
    remove->next = remove->prev = 0;
  }
    
}


template <typename T>
void DoubleList<T>::_sort(DoubleNode<T> **p_h, DoubleNode<T> **p_t) {
  if(p_h == 0 || p_t == 0) return;

  DoubleNode<T>* sorted = 0;
  DoubleNode<T>* newtail = 0;
  DoubleNode<T>* h = *p_h;

  while(h != 0) {
    DoubleNode<T>* maxnode = _max(h);
    _remove(&h, p_t,  maxnode);
    if(newtail == 0) newtail = maxnode;
    maxnode->next = sorted; 
    if(sorted) sorted->prev = maxnode;
    maxnode->prev = 0;
    sorted = maxnode; 
  }    
  
  *p_h = sorted; 
  *p_t = newtail;
}

template <typename T>
void DoubleList<T>::team_of_n(int n) {
  DoubleNode<T> *h = head, *next, *prev, *newhead= 0, *prev_list_end = 0 ;
  
  while(h != 0) {
    int count = 1;
    prev = 0;
    next = h;
    while(count <= n && next != 0) {
      prev = next;
      next = next->next;
      ++count;
    }  
        
    if(prev) prev->next = 0;
    if(next) next->prev = 0;

    if(prev)
      _sort(&h, &prev); 

    if(newhead == 0) newhead = h;
    
    if(prev_list_end == 0) {
      while(h->next != 0) h = h->next;  
      prev_list_end = h;
    } else {
      prev_list_end->next = h;
      h->prev = prev_list_end;
      while(h->next != 0) h = h->next;
      prev_list_end = h;
    } 
     
    h = next;
  }
 
  tail = prev_list_end; 
  head = newhead; 
}

template <typename T>
int DoubleList<T>::size() {
  DoubleNode<T> *h = head;
  int size = 0;
  while(h != 0) {
    size++;
    h = h->next;
  }
  return size;
}

template <typename T>
void DoubleList<T>::print() {
  DoubleNode<T>* h = head;
  while(h) {
    cout << h->data << " ";
    h = h->next;
  }
  cout << endl;
}

template <typename T>
void DoubleList<T>::print_reverse() {
  DoubleNode<T>* t = tail;
  while(t) {
    cout << t->data << " ";
    t = t->prev;
  }
  cout << endl;
}

#endif
