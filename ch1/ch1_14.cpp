// ��ó������� ù ���� Preprocessor

//Defines the entry point for th console applocation

#include <iostream>
#include <algorithm>

using namespace std;

#define MY_NUMBER "Hello, World" //define �� ������ �� ���� �ȿ�����

#define MAX(a, b) (((a)>(b)) ? (a) : (b))

#define LIKE_APPLE 

void doSomething();


int main()
{
	cout << MY_NUMBER << endl;
	cout << MAX(1 + 3, 2) << endl;

	cout << std::max(1 + 3, 2) << endl;

	doSomething();

	return 0;
}