// �⺻ �ڷ��� �Ұ� Fundamental Data Types

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

	//��������� ����ϴºκ��� ��ó�� �־�� �����,�����丵 �ϱⰡ ����


	//int a = 123;  // copy	   initialization
	//int a(123);   // direct  initialization
	//int a{ 123 }; // uniform initialization

	//int b(3.14);    // warning message :possible loss of data, "casting/����ȯ"
	//int b{ 3.14 };  // error   message

	int k = 0, l(123), m{ 456 }; //,�� ����Ҷ��� ���� ������ ������ 

	bool bValue = false;
	char chValue = 65;   //'A';
	float fValue = 3.141592f;  //float �� �ڿ� f �� ����
	double dValue = 3.141592;  //f �� ������ double �� literal

	auto aValue = 3.141592;  //auto �� �������Ҷ� �ڷ��� �ڵ����� �����
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