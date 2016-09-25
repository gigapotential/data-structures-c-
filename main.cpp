#include "SingleNode.hpp"
#include "SingleList.hpp"
#include "DoubleNode.hpp"
#include "DoubleList.hpp"

#include <iostream>
#include <random>

using namespace std;

int N = 10;

// Generate S1 sequence using singly linked list 
void S1(SingleList<int>& singleList) {
  for(int i = N; i >= 1; --i) {
    singleList.insert(i);
  }
}

// Generate S1 sequence using doubly linked list
void S1(DoubleList<int>& doubleList) {
  for(int i = 1; i <= N; ++i) {
    doubleList.insert(i);
  }
}

// Generate S2 sequence using singly linked list
void S2(SingleList<int>& singleList) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(1, 100);

  for(int i = N; i >= 1; --i) {
    singleList.insert(dist(mt));
  }
}

// Generate S2 sequence using doubly linked list
void S2(DoubleList<int>& doubleList) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(1, 100);

  for(int i = 1; i <= N; ++i) {
    doubleList.insert(dist(mt));
  }
}

// These test functions have same number as test cases in Home Work document
void test_1() {
  SingleList<int> singleList;
  S1(singleList); 
  cout << "\n[Test Case 1]\n ***** Before the operation *****" << endl;
  singleList.print();
  singleList.team_of_n(4);
  cout << "\n[Test Case 1]\n ***** After the team of four operation *****" << endl;
  singleList.print();
}

void test_2() {
  DoubleList<int> doubleList;
  S1(doubleList); 
  cout << "\n[Test Case 2]\n ***** Before the operation *****" << endl;
  doubleList.print();
  doubleList.team_of_n(4);
  cout << "\n[Test Case 2]\n ***** After the team of four operation *****" << endl;
  doubleList.print();
}

void test_3() {
  SingleList<int> singleList;
  S2(singleList); 
  cout << "\n[Test Case 3]\n ***** Before the operation *****" << endl;
  singleList.print();
  singleList.team_of_n(4);
  cout << "\n[Test Case 3]\n ***** After the team of four operation *****" << endl;
  singleList.print();
}

void test_4() {
  DoubleList<int> doubleList;
  S2(doubleList); 
  cout << "\n[Test Case 4]\n ***** Before the operation *****" << endl;
  doubleList.print();
  doubleList.team_of_n(4);
  cout << "\n[Test Case 4]\n ***** After the team of four operation *****" << endl;
  doubleList.print();
}

void test_5() {
  SingleList<int> singleList;
  S1(singleList); 
  cout << "\n[Test Case 5]\n ***** Before the operation *****" << endl;
  singleList.print(); 
  singleList.reverse();
  cout << "\n[Test Case 5]\n ***** After the reverse operation *****" << endl;
  singleList.print();
}

void test_6() {
  DoubleList<int> doubleList;
  S1(doubleList);
  cout << "\n[Test Case 6]\n ***** Before the operation *****" << endl;
  doubleList.print(); 
  doubleList.reverse();
  cout << "\n[Test Case 6]\n ***** After the reverse operation *****" << endl;
  doubleList.print();
}

void test_7() {
  SingleList<int> singleList;
  S2(singleList);
  cout << "\n[Test Case 7]\n ***** Before the operation *****" << endl;
  singleList.print();
  singleList.reverse();
  cout << "\n[Test Case 7]\n ***** After the reverse operation *****" << endl;
  singleList.print();
}

void test_8() {
  DoubleList<int> doubleList;
  S2(doubleList);
  cout << "\n[Test Case 8]\n ***** Before the operation *****" << endl;
  doubleList.print();
  doubleList.reverse();
  cout << "\n[Test Case 8]\n ***** After the reverse operation *****" << endl;
  doubleList.print();
}


void test_9() {
  SingleList<int> singleList;
  S1(singleList);
  cout << "\n[Test Case 9]\n ***** Before the operation *****" << endl;
  singleList.print();
  singleList.shuffle();
  cout << "\n[Test Case 9]\n ***** After the shuffle operation *****" << endl;
  singleList.print();
}

void test_10() {
  DoubleList<int> doubleList;
  S1(doubleList);
  cout << "\n[Test Case 10]\n ***** Before the operation *****" << endl;
  doubleList.print();
  doubleList.shuffle();
  cout << "\n[Test Case 10]\n ***** After the shuffle operation *****" << endl;
  doubleList.print();
}

void test_11() {
  SingleList<int> singleList;
  S2(singleList);
  cout << "\n[Test Case 11]\n ***** Before the operation *****" << endl;
  singleList.print();
  singleList.shuffle();
  cout << "\n[Test Case 11]\n ***** After the shuffle operation *****" << endl;
  singleList.print();
}

void test_12() {
  DoubleList<int> doubleList;
  S2(doubleList);
  cout << "\n[Test Case 12]\n ***** Before the operation *****" << endl;
  doubleList.print();
  doubleList.shuffle();
  cout << "\n[Test Case 12]\n ***** After the shuffle operation *****" << endl;
  doubleList.print();
}


int main() {
  test_1();
  test_2();
  test_3(); 
  test_4();
  test_5(); 
  test_6();
  test_7();
  test_8();  
  test_9(); 
  test_10();
  test_11(); 
  test_12();
}
