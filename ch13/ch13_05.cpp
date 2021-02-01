//Ŭ���� ���ø� Ư��ȭ Specialization

// template<>
// class A<char>

//�����δ� �ٸ� Ŭ������ �׳� �ϳ� �����ϴ°Ͱ� �����(�۾�����)
//�κ������� �����ϰ� ���� ��� ch13_04 �� ��� �Լ� Ư��ȭ�� ���� ����ϸ� ��

//��Ӱ� �ٸ�, ������ �ٸ� Ŭ������ �����ϴ°���, ����Ҷ� �Ϲ����� template �� instantiation �ΰ�ó�� 
//����Ҽ� �־ ���� ����

//paramter ������ ������ ������ ��� arguments �� �� �� ����( C++17 ���� ������ ������ �߻����� ���� )

#include <iostream>
#include <array>
#include "ch13_05_Storage8.h"

using namespace std;

template<typename T>
class A 
{
public:

	//�����ڸ� �� �����ϸ� A<int> ó�� ���� �ʾƵ� ��
	A(const T& input)
	{}

	A() {}

	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};


//char type �� ���� specialization 
//�����δ� �ٸ� Ŭ������ �׳� �ϳ� �����ϴ°Ͱ� �����(�۾�����)
template<>
class A<char>
{
public:
	//�����ڸ� �� �����ϸ� A<char> �� �������� �ʾƵ� ��
	A(const char & temp)
	{}

	A() {}

	void doSomething()
	{
		//doSomething() �� ������ ���� �ٲ�
		cout << "Char type specialization " << endl;
	}
};

int main()
{
	
	A<int>		a_int;
	A<double>	a_double;
	A<char>		a_char;	//char type �� ���Ͽ� specialization

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();


	//�����δ� �ٸ� Ŭ������ �׳� �ϳ� �����ϴ°Ͱ� �����(�۾�����)
	
	//���ǻ��� : �ᱹ�� �ٸ� Ŭ������� ���� ��
	//class A ���� test() ����Լ��� �־�װ� char type specialization ���� �� �־��
	a_int.test();
	a_double.test();
	//a_char.test()

	//a_char ���� test() �� ���� ����
	//��Ӱ� �ٸ�, ������ �ٸ� Ŭ������ �����ϴ°���, ����Ҷ� template �� instantiation �ΰ�ó�� 
	//����Ҽ� �־ ���� ����


	//�����ڸ� �� �����ϸ� A<int> ó�� ���� �ʾƵ� ��
	A<int>		a_int_new(1);
	A<double>	a_double_new(3.14);
	A<char>		a_char_new('a');

	//paramter ������ ������ ������ ��� arguments �� �� �� ����( C++17 ���� ������ ������ �߻����� ���� )
	//A			a_int_new_(1);
	//A			a_double_new_(3.14);
	//A			a_char_new_('a');



	//�� datatype �� 8�� �����ϴ� Ŭ����
	//bool �� ���ؼ� Ư��ȭ �ϱ�
	//bool �� 1 byte(1 bit) �� ����ص� �����ϱ� ������ Ư��ȭ

	// Define a Storgae for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		std::cout << intStorage.get(count) << '\n';

	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;

	
	// Define a Storage for bool
	Storage8 <bool> boolStorage;
	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);

	for (int count = 0; count < 8; ++count)
		std::cout<< boolStorage.get(count) << '\n';

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
}