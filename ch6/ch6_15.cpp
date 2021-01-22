//참조(Reference) 와 const

//const X & 와 X const & 는 의미상 차이 없음

#include <iostream>

using namespace std;

//포인터로 넣으면 변수 복사가 일어나지만 const ref로 넣으면 복사가 일어나지 않음
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

	doSomething(a); //const 가 있으나 없으나 상관 없음
	doSomething(1); // const int ref 로 함수에서 선언했기 때문에 literal 을 바로 넣을 수 있음
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}
