//클래스 템플릿 특수화 Specialization

// template<>
// class A<char>

//실제로는 다른 클래스를 그냥 하나 구현하는것과 비슷함(작업량도)
//부분적으로 구현하고 싶은 경우 ch13_04 의 멤버 함수 특수화와 섞어 사용하면 됨

//상속과 다름, 문법상 다른 클래스를 구현하는것임, 사용할때 일반적인 template 의 instantiation 인것처럼 
//사용할수 있어서 편리할 뿐임

//paramter 만으로 구분이 가능한 경우 arguments 를 뺄 수 있음( C++17 에선 컴파일 오류가 발생하지 않음 )

#include <iostream>
#include <array>
#include "ch13_05_Storage8.h"

using namespace std;

template<typename T>
class A 
{
public:

	//생정자를 잘 구현하면 A<int> 처럼 쓰지 않아도 됨
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


//char type 에 대해 specialization 
//실제로는 다른 클래스를 그냥 하나 구현하는것과 비슷함(작업량도)
template<>
class A<char>
{
public:
	//생정자를 잘 구현하면 A<char> 로 선언하지 않아도 됨
	A(const char & temp)
	{}

	A() {}

	void doSomething()
	{
		//doSomething() 도 내용을 조금 바꿈
		cout << "Char type specialization " << endl;
	}
};

int main()
{
	
	A<int>		a_int;
	A<double>	a_double;
	A<char>		a_char;	//char type 에 대하여 specialization

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();


	//실제로는 다른 클래스를 그냥 하나 구현하는것과 비슷함(작업량도)
	
	//주의사항 : 결국은 다른 클래스라고 봐도 됨
	//class A 에는 test() 멤버함수를 넣어뒀고 char type specialization 에는 안 넣어둠
	a_int.test();
	a_double.test();
	//a_char.test()

	//a_char 에선 test() 에 접근 못함
	//상속과 다름, 문법상 다른 클래스를 구현하는것임, 사용할때 template 의 instantiation 인것처럼 
	//사용할수 있어서 편리할 뿐임


	//생정자를 잘 구현하면 A<int> 처럼 쓰지 않아도 됨
	A<int>		a_int_new(1);
	A<double>	a_double_new(3.14);
	A<char>		a_char_new('a');

	//paramter 만으로 구분이 가능한 경우 arguments 를 뺄 수 있음( C++17 에선 컴파일 오류가 발생하지 않음 )
	//A			a_int_new_(1);
	//A			a_double_new_(3.14);
	//A			a_char_new_('a');



	//한 datatype 을 8개 저장하는 클래스
	//bool 에 대해서 특수화 하기
	//bool 은 1 byte(1 bit) 만 사용해도 가능하기 때문에 특수화

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