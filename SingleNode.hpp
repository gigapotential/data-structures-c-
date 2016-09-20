#ifndef SINGLE_NODE_HPP
#define SINGLE_NODE_HPP

template <typename T>
class SingleList;

template <typename T>
class SingleNode {
  private:
    // data stored in this node
    T data;
    // pointer to next node in the list
    SingleNode<T> *next;
  public:
    SingleNode(T t, SingleNode<T>* nxt):data(t), next(nxt) {}
    SingleNode(T t):SingleNode<T>(t,0) {}

  // so that SingleList can do pointer manipulation directly
  friend class SingleList<T>;

};

#endif
