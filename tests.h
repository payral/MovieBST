//Peter Ayral

#ifndef TESTS_H
#define TESTS_H

#include "movies.h"
#include <cassert>
#include <iostream>
using namespace std;

void runAll();
void test_emptymovie();
void test_movie();
void test_BST();
void test_Depth();



void assertEquals(string expected, string actual, string testDescription){
	if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(double expected, double actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

#endif