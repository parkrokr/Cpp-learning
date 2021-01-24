#include <iostream>
using namespace std;

//class 를 friend 하고 멤버함수 정의가 뒤에 있는 경우
class B;

class A
{
private:
	int m_value = 1;

	friend class B;
};

class B
{
private:
	int m_value = 2;

public:
	void doSomething(A& a)
	{
		cout << a.m_value << endl;
	}

};


//class 를 friend 하고 멤버함수 정의가 앞에 있는 경우
//class A;
//
//class B
//{
//private:
//	int m_value = 2;
//
//public:
//	void doSomething(A& a);
//	
//};
//
//class A
//{
//private:
//	int m_value = 1;
//
//	friend class B;
//};
//
//void B::doSomething(A& a)
//{
//	cout << a.m_value << endl;
//}



//멤버 함수를 friend 하고 멤버함수 정의가 앞에 있는 경우
//class A;
//
//class B
//{
//private:
//	int m_value = 2;
//
//public:
//	void doSomething(A& a);
//	
//};
//
//class A
//{
//private:
//	int m_value = 1;
//
//	friend void B::doSomething(A& a);
//};
//
//void B::doSomething(A& a)
//{
//	cout << a.m_value << endl;
//}


//멤버 함수를 friend 하고 멤버함수 정의가 뒤에 있는 경우  불가능
//class B;
//
//class A
//{
//private:
//	int m_value = 1;
//
//	friend void B::doSomething(A& a);
//};
//
//class B
//{
//private:
//	int m_value = 2;
//
//public:
//	void doSomething(A& a)
//	{
//		cout << a.m_value << endl;
//	}
//
//};



int main()
{
	A a;
	B b;
	b.doSomething(a);

}