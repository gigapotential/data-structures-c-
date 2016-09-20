#include "SingleNode.hpp"
#include "SingleList.hpp"

#include <iostream>

using namespace std;

void S1(SingleList<int>& singleList) {
  for(int i = 100; i >= 1; --i) {
    singleList.insert(i);
  }
}


void test_1() {
  SingleList<int> singleList;
  S1(singleList); 
  singleList.print(); 
}

int main() {
  test_1();
  
}
