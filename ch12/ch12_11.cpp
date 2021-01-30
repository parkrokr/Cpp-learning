//유도 클래스에서 출력 연산자 사용하기

//friend 함수는 오버라이딩을 못함(멤버함수만 오버라이등을 할 수 있음)
//멤버로 만들 수 없는 함수를 오버라이딩 한것처럼 사용하기 위해서 
//기능을 위임받은 일반함수를 가상함수를 만들고 자식클래스에서 오버라이딩 하는 방법도 있음

//어떤 기능을 사용을 할때 가상함수 여러개를 일부러 조합해서 원하는 방식으로 자식클래스에서 사용하는
//방식도 가끔 사용이 됨

#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	//frined funciton 은 멤버가 아님
	//멤버가 아니니 직접  오버라이딩을 못함
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out); //멤버 함수 print() 를 만들어서 맡김
	}

	//가상화 한후 자식클래스에서 오버라이딩 함
	virtual std::ostream& print(std::ostream& out)const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	//얼핏보면 ouput operator 를 오버라이드 한것 같지만 자세히 보면 그냥 print() 임
	virtual std::ostream& print(std::ostream& out) const override 
	{
		out << "Derived";
		return out;
	}

	//자식 클래스에서는 연산자 오버로딩 함수를 가지고 있을 필요가 없음
};

int main()
{
	Base b;
	cout << b << '\n'; //Base
	

	Derived d;
	cout << d << '\n'; //Derived

	Base& bref = d;
	cout << bref << '\n';  //Derived
	//부모 클래스에 있는 연산자 함수에 오버 로딩으로 들어감
	//자식 클래스의 참조가 부모클래스의 참조로 변환되서 들어오기 때문에 다형성, 가상함수가 호출됨
	//자식 클래스의 print() 로 들어간후 실행하고 종료됨

	return 0;
}