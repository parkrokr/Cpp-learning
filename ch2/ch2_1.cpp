// 기본 자료형 소개 Fundamental Data Types

#include <iostream>
#include <bitset>

//int main()
//{
//	using namespace std;
//
//	int j = 3;
//	int i = -1;
//	int k = 123;
//	char a = 'H';
//
//	cout << (uintptr_t)static_cast<void*>(&a) << endl;
//	cout << (uintptr_t)static_cast<void*>(&i) << endl;
//
//	return 0;
//}

int main()
{
	using namespace std;

	//변수선언과 기능하는부분이 근처에 있어야 디버그,리팩토링 하기가 쉬움


	//int a = 123;  // copy	   initialization
	//int a(123);   // direct  initialization
	//int a{ 123 }; // uniform initialization

	//int b(3.14);    // warning message :possible loss of data, "casting/형변환"
	//int b{ 3.14 };  // error   message

	int k = 0, l(123), m{ 456 }; //,를 사용할때는 같은 데이터 형에만 

	bool bValue = false;
	char chValue = 65;   //'A';
	float fValue = 3.141592f;  //float 는 뒤에 f 를 붙임
	double dValue = 3.141592;  //f 가 없으면 double 형 literal

	auto aValue = 3.141592;  //auto 는 컴파일할때 자료형 자동으로 잡아줌
	auto aValue2 = 3.141592f;

	cout << bValue <<(bValue ? 1 : 0) << endl;
	cout << chValue << " " << (int)chValue << endl;
	cout << fValue << endl;
	cout << dValue << endl;
	cout << aValue << " " << sizeof(aValue) << endl;
	cout << aValue2 << " " << sizeof(aValue2) << endl;

	cout << sizeof(bool) << endl;
	cout << sizeof(bValue) << endl;

	return 0;
}