//상속받은 함수 ( Inherited Functions ) 를 감추기

//상속받은걸 사용하지 않도록 막기

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		:m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}

	friend std::ostream& operator <<(std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d = 0;
public:
	Derived(int value)
		:Base(value)
	{}

	//Base 에선 protected 인 m_i 가 이렇게 하면 Derived 에선 public 가 되어버림
	using Base::m_i;


	//Base 의 print() 를 밖에서 못쓰게 막아버리기
	//delete 하기
	void print() = delete;

	//private: 에서 using 하기
private:
	//using Base::print;  //이때는 이름만 있으면 되기 때문에 ()를 치면 안됨
};

int main()
{
	Base base(5);
	Derived derived(7);
	
	//m_i 는 Base 에 protected 로 선언되었기 때문에 밖에서 접근 못함
	//Derived class 에서 using Base::m_i; 를 하면 가능
	derived.m_i = 1024;

	//Derived 가 Base 로부터 상속받은 print() 를 밖에서 못쓰게 막아버릴 수 있음
	//derived.print();  //막혀버림
	base.print();		//이건 가능(자식에서만 막았기 때문에 부모에서는 접근 가능)

	return 0;
}