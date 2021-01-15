// 선언과 정의의 분리 Declaration Definition

#include <iostream>

using namespace std;

int add(int a, int b); // forward declaration 전방 선언
int multiply(int a, int b);
int subtract(int a, int b);
//Peek Definition, GO To Definition, Go To Declaration 

int main()
{
	cout << add(1, 2) << endl;
	cout << subtract(1, 2) << endl;

	return 0;
}


//definition
int add(int a, int b) // prototype
{
	return a * b;
}


int multiply(int a, int b)
{
	return a * b;
}


int subtract(int a, int b)
{
	return a - b;
}


