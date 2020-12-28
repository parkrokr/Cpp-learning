//참조(Reference) 와 const

#include <iostream>

using namespace std;

void doSomething(const int& x)
{
	cout << x << endl;
}

int main()
{
	int x = 5;
	int& ref_x = x;

	//가능
	//int x = 5;
	//const int& ref_x = x;

	//불가능
	//const int x = 5;
	//int& ref_x = x;

	//가능
	//const int x = 5;
	//const int& ref_x = x;

	//const int& ref_2 = ref_x;


	//가능
	//int x = 5;
	//const int& ref_x = x;

	//const int& ref_2 = ref_x;


	//가능
	//int x = 5;
	//int& ref_x = x;

	//const int& ref_2 = ref_x;


	//ref는 선언할때 '주소'가 있어야함
	//int &ref_x = 5; 불가능

	//하지만 const ref 에서는 가능
	//const int &ref_x = 3 + 4;

	//값과 주소도 찍을 수 있음
	//cout <<ref_x <<endl;
	//cout<<&ref_x<<endl;



	//const int ref_x = 5; 와 const int &ref_x = 5; 의 차이
	//함수 parameter 에 레퍼런스로 넣을때 아래 예제가 다 가능함

	int a = 1;

	doSomething(a);
	doSomething(1);
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}