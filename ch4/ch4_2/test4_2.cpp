#include<iostream>

// 이 cpp 파일에서도 include 할 수 있음
#include"MyConstants4_2.h"

extern int b = 123;


void doSomething()
{
	using namespace std;

	cout << "Hello" << endl;
	cout << "In test.cpp " << Constants::pi <<" " << &Constants::pi << endl;// 이 cpp 파일에서도 pi를 출력할 수 있음
}