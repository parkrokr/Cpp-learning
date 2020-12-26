// 참조 변수 Reference Variable

//특정 경우에 포인터보다 사용하기 편함
//포인터는 null 이 허용되지만 ref는 null이 허용되지 않음(반드시 초기화)
//포인터는 할당할때 참조 대상에 대하여 &을 통해 주소값을 할당(간접 참조)
//ref는 참조대상을 그대로 할당(직접 참조)
//함수에 parameter 로 인자 전달시 포인터는 값 복사(->메모리 소모), ref는 값복사x(->메모리 소모x)

#include <iostream>

using namespace std;

//밖에 영향을 못줌
void doSomething(int n) 
{
	n = 10;
	cout << "In doSomething" << n << endl;
}

//밖에 영향을 줌
void doSomething_ref(int& n) //(const int& n)  //입력을 넣는 값을 함수에서 고치고 싶지 않을 경우 const 사용
{
	cout << &n << endl;

	n = 10;  //(const int& n)로 막아버리면 값을 고치지 못함
	cout << "In doSomething" << n << endl;
}

//배열을 ref로 받는 함수
void printElements(/*const*/ int(&arr)[5]) //함수에 ref로 넘길때는 elements 개수가 필요함
{
	for (int i = 0; i << 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;

	//포인터 사용
	int* ptr = nullptr;
	ptr = &value;

	//참조 사용
	int& ref = value; // 5

	cout << ref << endl;

	ref = 10;  //*ptr = 10; 처럼 작동함

	cout << value << " " << ref << endl;  //10 10


	//주소 찍어보기
	cout << &value << endl;
	cout << &ref << endl;   //&value 와 같음
	cout << ptr << endl;    //&value 와 같음
	cout << &ptr << endl;


	//ref 는 value 와 값도 같고 주소도 같음 ->value 의 다른 이름처럼 사용

	//ref는 반드시 초기화 필요 <-별명이기 때문에 원래 이름이 필요
	//int &ref; 불가능

	//ref에는 반드시 변수,lvalue 가 들어가야함, literal 은 못들어감
	//int &ref = 104; 불가능

	//const 문제
	/*
	//가능
	int x = 5;
	int &ref = x; 
	
	//불가능
	const int y = 5;
	int &ref = y;

	//가능
	const int y = 5;
	const int &ref = y;
	*/


	//re-assign
	int value1 = 5;
	int value2 = 10;

	int& ref1 = value1;

	cout << ref1 << endl;  //5

	ref1 = value2;

	cout << ref1 << endl;  //10



	//ref
	int n = 5;

	cout << n << endl;  //5

	doSomething(n);  //10

	cout << n << endl;  //5

	//n에 있는 5를 함수 n 에 복사하고 바꿔져도 원래 있던 n 의 값 5는 변하지 않음

	//ref 사용하기
	cout << n << endl;  //5

	cout << &n << endl;

	doSomething_ref(n);  //10   , 같은 주소값이 나옴

	cout << n << endl;  //10

	
						
	//ref를 쓰게 되면 변수 자체가 넘어가는 개념
	//포인터를 사용하면 변수의 주소를 한번 복사하지만 ref는 주소 복사 없이 변수 자체가 넘어감->효율이 더 높음

	//입력을 넣는 값을 함수에서 고치고 싶지 않을 경우 const 사용


	//배열을 함수에 넣어줄때도 ref 사용 가능
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };
	
	printElements(arr); //함수에 ref로 넘길때는 elements 개수가 필요함



	//struct 를 쓸때 편함
	Other ot;

	//v1에 접근 하고 싶은 경우   
	//ot.st.v1 = 1;   //->길고 번거로워짐

	//ref 사용  
	int& v1 = ot.st.v1;
	v1 = 1;
	//v1이 여려번 쓰이는 경우 ref로 하면 편하고 효율이 좋음



	//ref와 포인터 비교  (ref 도 내부적으론 포인터로 구현되어 있음)
	int value3 = 5;
	int* const ptr3 = &value3;
	int& ref3 = value3;

	//int* const ptr3 = &value3; 와 int& ref3 = value3; 는 기능상 동일

	//동일한 기능
	*ptr3 = 10;
	ref3 = 10;
	
	//대신 포인터는 포인터 연산이 가능

	return 0;
}