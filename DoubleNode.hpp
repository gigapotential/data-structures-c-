#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

template <typename T>
class DoubleList;

template <typename T>
class DoubleNode {
  private:
    // data stored in this node
    T data;
    
    // pointer to next node in the list
    DoubleNode<T> *next;
  
    // pointer to prev node in the list
    DoubleNode<T> *prev;

  public:
    DoubleNode(T t, DoubleNode<T> *p, DoubleNode<T> *n):data(t), next(n), prev(p) {}
    DoubleNode(T t):DoubleNode(t, 0, 0) {}

  friend class DoubleList<T>;
};

#endif
