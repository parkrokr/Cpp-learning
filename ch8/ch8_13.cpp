 //익명 anonymous 객체

//r-vlaue 처럼 작동함,한번 쓰고 사라지기(소멸자 호출) 때문에 재사용 못함

#include <iostream>
using namespace std;

class A
{
public:
	A()	
	{
		cout << "constructor" << endl;
	}

	~A()
	{
		cout << "destructor" << endl;
	}

	void print()
	{
		cout << "Hello" << endl;
	}
};

class B
{
public:
	int m_value;


	B(const int& input)
		:m_value(input)
	{
		cout << "constructor" << endl;
	}

	~B()
	{
		cout << "destructor" << endl;
	}

	void print()
	{
		cout << "Hello" << m_value << endl;
	}
};


class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	int getCents() const { return m_cents; }  //member variable 을 바꾸지 않는 const 함수
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents()); //두개의 합을 멤버로 갖는 Cents 를 만들어 return
}

int main()
{
	//print() 를 하기 위해 이렇게 하는게 번거로울 수 있음
	//a 는 print() 말고는 더이상 사용하지 않음
	
	A a;
	a.print();
	a.print();
	//생성자와 소멸자가 한번씩만 호출됨
	

	A().print();  //A() 가 r-vlaue 처럼 작동함,한번 쓰고 사라지기(소멸자 호출) 때문에 재사용 못함
	A().print();
	//생성자와 호출자가 두번씩 호출됨


	//member variable 가 있을 경우
	B b(1);
	b.print();

	B(1).print();




	//add() 가 Cents 를 return 하기 때문에 .getCents() 를 사용 가능
	cout << add(Cents(6), Cents(8)).getCents() << endl;

	cout << int(6) + int(8) << endl;	//연산자 오버로딩과 유사성

	return 0;
}