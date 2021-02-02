// 멤버 함수를 한번 더 템플릿화하기 Templatize

//어떤 클래스가 이미 템플릿화가 되어있는 경우에도 멤버함수에 추가적인 템플릿을 적용할 수 있음

#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		:m_value(input)
	{
	}


	//TT 는 doSomething() 에서만 사용되는 template paramtert
	template<typename TT>
	void doSomething()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	template<typename TT>
	void doSomething(const TT& intput)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	//casting 할때도 사용할 수 있음
	template<typename TT>
	void doSomething_cast(const TT& intput)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;

		cout << (TT)m_value << endl; //m_value 를 TT 로 casting
	}

	//parameter 가 없는 경우에도 직접 instantiation 을 할 수 있음
	template<typename TT>
	void doSomething_cast()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;

		cout << (TT)m_value << endl; //m_value 를 TT 로 casting
	}

	void print()
	{
		cout << m_value << endl;
	}


};

int main()
{
	A<int> a_int(123);
	a_int.print();

	//TT 를 float 로(paramter 가 없는 경우)
	a_int.doSomething<float>();

	//flaot type 인 TT 에 대하여 instantiation 이 되어있음
	//거기에 double 을 넣으니 truncatoin 이 된다고 경고 발생
	a_int.doSomething<float>(123.4);

	//parameter 로 구분을 할수 있는 경우에는 <float> 가 필요없음
	a_int.doSomething(123.4);

	a_int.doSomething('a');  //doSomthing() 이 char type 에 대해서 추가적으로 템플릿화 되어있음

	//casting 할때도 사용할 수 있음
	A<char> a_char('A');
	a_char.print();

	a_char.doSomething_cast(1);  //char type 'A' 를 1(int type ) 으로 casting 하려고 함
	a_char.doSomething_cast(int()); //멤버함수의 instantiation 을 구분하기 위해 이렇게 하기도 함

	//parameter 가 없는 경우에도 직접 instantiation 을 할 수 있음
	a_char.doSomething_cast<int>();

	return 0;
}