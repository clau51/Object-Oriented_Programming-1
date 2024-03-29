/***********************************************************************
// OOP244 Workshop 6 p1: tester program
//
// File  main.cpp
// Version 1.0
// Date  2022/10/1
// Author  Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Numbers.h"
using namespace sdds;
using namespace std;
void startTest(int n) {
   cout << "Test";
   for (int i = 0; i < 30; i++) cout << " " << n;
   cout << endl;
}
void endTest(int n) {
   cout << "End Test";
   for (int i = 0; i < 28; i++) cout << " " << n;
   cout << endl;
}

void resetFile(const char* fname) {
   ofstream f(fname);
   f.setf(ios::fixed);
   f.precision(2);
   f << 6.00 << endl << 12.20 << endl << 3.00 << endl << 34.10 << endl;
}
void displayFile(const char* fname) {
   ifstream f(fname);
   char ch;
   cout << endl << "Content of \"" << fname << "\"" << endl
      << "*****************************************************************" << endl;
   while (f.get(ch)) {
      cout << ch;
   }
   cout << "*****************************************************************" << endl;
}
void displayList(Numbers N) {
   cout << "Add a number to the list: ";
   cin >> N;
   cout << N << endl;
}
void test1() {
   startTest(1);
   Numbers N("numbers.txt");
   N += 34.56;
   cout << N << endl;
   displayList(N);
   endTest(1);
}
void test2() {
   startTest(2);
   Numbers N("numbers.txt");
   Numbers M(N);
   Numbers L;
   Numbers BAD("BadFileName.txt");
   cout << N << endl << M << endl << L << endl << BAD <<endl;
   cout << "Ascending:" << endl << +N << endl << "Descending:" << endl << -N << endl;
   M += 1000;
   L = M;
   N = L;
   cout << N << endl << M << endl << L << endl;
   cout << "Ascending:" << endl;
   cout << +N << endl << +M << endl << +L << endl;
   cout << "Descending: "<< endl;
   cout << -N << endl << -M << endl << -L << endl;
   endTest(2);
}
void test3() {
   startTest(3);
   cout << endl << "In this test we use your insertion and extraction operators to do" << endl
      << "File IO. This makes sure your implementation is done correctly" << endl 
      << "using the reference of istream and ostream and NOT cin and cout" << endl << endl;
   ifstream addnum("add.txt");
   ofstream output("output.txt");
   Numbers N("numbers.txt");
   addnum >> N;
   addnum >> N;
   addnum >> N;
   output << N << endl << +N << endl << -N << endl;
   endTest(3);
}
int main() {
	//Numbers N = "hello.txt";
	//N = "bello.txt";
   resetFile("numbers.txt");
   test1();
   displayFile("numbers.txt");
   test2();
   displayFile("numbers.txt");
   test3();
   displayFile("numbers.txt");
   displayFile("add.txt");
   displayFile("output.txt");
   return 0;
}