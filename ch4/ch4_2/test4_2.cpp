#include<iostream>

// �� cpp ���Ͽ����� include �� �� ����
#include"MyConstants4_2.h"

extern int b = 123;


void doSomething()
{
	using namespace std;

	cout << "Hello" << endl;
	cout << "In test.cpp " << Constants::pi <<" " << &Constants::pi << endl;// �� cpp ���Ͽ����� pi�� ����� �� ����
}