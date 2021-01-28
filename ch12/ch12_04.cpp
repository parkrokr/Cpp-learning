//가상 소멸자

//생성자는 자식클래스에서 보통 자신의 생성자를 사용했지만 소멸자는 가상 소멸자를 사용하는것이 좋음
//자식 클래스에서 동적할당을 할 경우 소멸자에서 메모리를 반납해야 하고
//부모 클래스는 하나고 자식 클래스는 여러가지일 수 있기 때문에 다형성의 장점을 살려
//지울때 부모클래스를 이용해서 지우는게 일반적(부모클래스만 지우면 자식 클래스도 같이 지워지게)

#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	~Derived() override // ~Base() 앞에 virtual 을 지우면 override 를 못붙임
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
	Derived derived1(5);

	//자식 클래스의 소멸자가 먼저 호출되고 그다음에 부모클래스의 소멸자가 호출됨
	//생성자 호출 순서 반대


	//다형성을 사용하는 경우
	//자식클래스가 무엇으로부터 만들어졌는지 모르는 경우가 대부분
	//지울때도 base 포인터를 이용해서 지우는것을 시도하는 경우가 많음
	//base class 는 하나지만 derived class 는 대부분 여러가지임

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;

	//가상화를 하지 않을 경우 base 의 소멸자만 호출되고 derived 의 소멸자는 호출이 되지 않기
	//때문에 momory leak 이 일어날 수 있음

	return 0;
}