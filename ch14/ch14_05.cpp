//함수 try

//클래스의 생성자에서 발생하는 예외를 처리하는것도 중요함
//이때 initializer list 에서 발생하는 예외를 처리할때 function try 를 많이 사용함

//함수 try 를 이용해 생정자에서 예외를 잡고 re-throw 를 직접 하지 않아도 하는것처럼  작동해
//밖 (main()) 에서 한번 더 잡음

//생정자에서 예외가 발생(객체가 제대로 생성이 안되고 있음)해 예외처리를 해줘도 객체를 선언한 곳으로 
//한번 더 예외를 던져줌
//객체가 제대로 생성이 되지 못했다는 사실을 객체를 선언한 곳에 알려줘야 한다고 추측?


#include <iostream>

using namespace std;




void doSomething()
{
	try
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Catch in doSomething()" << endl;
	}
}

//function try
//함수 body 전체에 대해서 try catch 를 붙일 수 있음
//많이 쓰진 않지만 작동은 함
void doSomething_new()
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething_new()" << endl;
}

//많이 쓰는건 생정자에서 예외가 발생할 경우 잡기 위해 많이 사용함
class A
{
private:
	int m_x;
public:
	//A의 생성자에서 예외를 던지고 있음
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw - 1;
	}
};

class B :public A
{
public:
	B(int x)
		:A(x)
	{}

	//예외를 main() 이 아니라 여기서 (B의 생성자) 잡고 싶음, 이때 function try 를 사용함
	B(int x)try : A(x)
	{
		// do initialization
	}
	catch (...)  //위에서 발생하는 예외들을 전부 catch 함
	{
		cout << "Catch in B constructor " << endl;
		
		//throw;	//re-throw 를 주석처리해도 main() 에 있는 catch 에서 한번 더 잡음,없지만 있는것처럼 작동함
	}

	/* 여기에 대해서 전부 try를 함
	: A(x)
	{
		// do initialization
	}
	*/
};

int main()
{
	try
	{
		doSomething();
	}
	catch(...)
	{
		cout << "Catch in main()" << endl;
	}
	//doSomething() 에서 잡히고 main() 에서 잡히지 않음

	try
	{
		doSomething_new();
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	//doSomething() 에서 잡히고 main() 에서 잡히지 않음


	//A의 생성자에서 예외를 던지고 있음
	try
	{
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	//지금은 main() 에서 catch 하고 있지만 어떤 경우엔 B의 생성자에서 바로 catch 를 하고싶음
	//그떄 함수 try 문법을 사용함
	//B의 생성자에서 잡혔지만 throw;키워드가 없어도 re-thorw 한것처럼 main() 에서 한번 더 잡힘
	//함수 try 를 생성자에서 사용할때 중요한 특징

	return 0;
}