#include "SingleNode.hpp"
#include "SingleList.hpp"
#include "DoubleNode.hpp"
#include "DoubleList.hpp"

#include <iostream>
#include <random>

using namespace std;

int N = 10;

void S1(SingleList<int>& singleList) {
  for(int i = N; i >= 1; --i) {
    singleList.insert(i);
  }
}

void S1(DoubleList<int>& doubleList) {
  for(int i = 1; i <= N; ++i) {
    doubleList.insert(i);
  }
}

void S2(SingleList<int>& singleList) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(1, 100);

  for(int i = N; i >= 1; --i) {
    singleList.insert(dist(mt));
  }
}

void S2(DoubleList<int>& doubleList) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(1, 100);

  for(int i = 1; i <= N; ++i) {
    doubleList.insert(dist(mt));
  }
}

void test_1() {
  SingleList<int> singleList;
  S1(singleList); 
  singleList.print();
  singleList.team_of_n(4);
  singleList.print();
}

void test_2() {
  DoubleList<int> doubleList;
  S1(doubleList); 
  doubleList.print();
  doubleList.team_of_n(4);
  doubleList.print();
  doubleList.print_reverse();
}

void test_3() {
  SingleList<int> singleList;
  S2(singleList); 
  singleList.print();
  singleList.team_of_n(4);
  singleList.print();
}

void test_4() {
  DoubleList<int> doubleList;
  S2(doubleList); 
  doubleList.print();
  doubleList.team_of_n(4);
  doubleList.print();
  doubleList.print_reverse();
}

void test_5() {
  SingleList<int> singleList;
  S1(singleList); 
  singleList.print(); 
  singleList.reverse();
  singleList.print();
}

void test_6() {
  DoubleList<int> doubleList;
  S1(doubleList); 
  doubleList.print(); 
  doubleList.reverse();
  doubleList.print();
  doubleList.print_reverse();
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

void test_10() {
  DoubleList<int> doubleList;
  S1(doubleList);
  doubleList.print();
  doubleList.shuffle();
  doubleList.print();
  doubleList.print_reverse();
}

void test_11() {
  SingleList<int> singleList;
  S2(singleList);
  singleList.print();
  singleList.shuffle();
  singleList.print();
}

void test_12() {
  DoubleList<int> doubleList;
  S2(doubleList);
  doubleList.print();
  doubleList.shuffle();
  doubleList.print();
  doubleList.print_reverse();
}


int main() {
//  test_1();
  test_2();
//  test_3(); 
  test_4();
//  test_5(); 
//D  test_6();
/*  test_7();  
  test_9(); */
//D  test_10();
/*
  test_11(); */
  test_12();
}
