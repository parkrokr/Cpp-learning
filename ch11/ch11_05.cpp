//상속과 접근 지정자

#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;

};


class Derived : public Base
{
public:
	Derived()
	{
		m_public = 123;
		m_protected = 123;
		//m_private = 123; 불가능
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		Derived::m_public;
	}
};

int main()
{
	Base base;


	//자식클래스와 부모클래스의 접근지정자중 더 접근이 제한된쪽으로 감

	//			부모클래스	public		protected		private	
	//자식클래스	
	//public				public		protected		private
	//protected				protected	protected		pirvate
	//private				private		private			private

	//자식클래스와 부모클래스의 접근지정자가 만나서 private 가 된 경우 손자클래스에서도 접근 못함
	//(private 이 된 경우 자식클래스에서 접근 못한는 거랑 같음)

	base.m_public = 123; 
	//불가능
	//base.m_protected = 123;
	//base.m_private = 123;

	//Derived class
	Derived derived;
	derived.m_public = 1024;
	//불가능
	//derived.m_protected;  //자식클래스에서 public, 두 접근지정자가 만나 protected 상태
	//derived.m_private;

	return 0;
}