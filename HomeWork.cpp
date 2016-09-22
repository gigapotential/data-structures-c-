#include "SingleNode.hpp"
#include "SingleList.hpp"

#include <iostream>
#include <random>

using namespace std;

void S1(SingleList<int>& singleList) {
  for(int i = 100; i >= 1; --i) {
    singleList.insert(i);
  }
}

void S2(SingleList<int>& singleList) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(1, 100);

  for(int i = 100; i >= 1; --i) {
    singleList.insert(dist(mt));
  }
}

void test_5() {
  SingleList<int> singleList;
  S1(singleList); 
  singleList.print(); 
  singleList.reverse();
  singleList.print();
}

void test_7() {
  SingleList<int> singleList;
  S2(singleList);
  singleList.print();
  singleList.reverse();
  singleList.print();
}

void test_9() {
  SingleList<int> singleList;
  S1(singleList);
  singleList.print();
  singleList.shuffle();
  singleList.print();
}

void test_11() {
  SingleList<int> singleList;
  S2(singleList);
  singleList.print();
  singleList.shuffle();
  singleList.print();
}

int main() {
  test_5();
  test_7();  
  test_9();
  test_11();
}
