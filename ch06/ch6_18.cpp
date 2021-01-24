//void 포인터

#include <iostream>

using namespace std;

//void pointer 는 generic pointer 라고도 불린다 (포괄적)

enum Type
{
	INT,
	FLOAT,
	CHAR
};


int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr;

	//주소이기 때문에 type 에 상관없이 문제 없음
	//대신 void type 이기 때문에 무슨 type 인지 모름
	ptr = &i;
	ptr = &f;
	//ptr = &c;  //문자열로 인식

	//주소는 동일하게 찍힘
	cout << &f << " " << ptr << endl;

	//de-referencing 불가능
	//cout << *ptr << endl;
	cout << *static_cast<float*>(ptr) << endl; //캐스트 하면 de-referencing 가능


	//int 형 포인터인 경우 포인터 연산을 사용할 수 있음
	int* ptr_i = &i;

	cout << ptr_i << endl;
	cout << ptr_i + 1 << endl;


	//void 포인터는 포인터 연산이 불가능
	//+1 이 몇 바이트인지 모르기 때문
	//cout<<ptr + 1 << endl;


	//어쩔 수 없이 사용해야 하는 경우가 있음
	Type type = FLOAT;

	if (type == FLOAT)
		cout << *static_cast<char*>(ptr) << endl;
	else if (type == INT)
		cout << *static_cast<int*>(ptr) << endl;

	//최근 c++ 문법에선 이렇게 안해도 되는 문법이 생김

	return 0;
}