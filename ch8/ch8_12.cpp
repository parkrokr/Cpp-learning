// 친구(friend) 함수와 클래스

//여러가지 class 복잡하게 상호작용하는 경우 깔끔하게 정리하는게 어려울 수 있음
//객체지향의 기본원칙인 캡슐화를 위해 여러가지 방법 사용

//연산자 오버로딩에서 friend 를 가장 많이 씀

#include<iostream>
using namespace std;

class B; //forward declaration  디버그할때 정의가 어디있는지 찾아야 하는 번거로움이 있지만 어쩔 수 없음

class A
{
private:
	int m_value = 1;

	//doSomething() 를 class A 의 친구로 만들기,B의 친구로도 만들기, class B 가 A 보다 밑에 있음(전방선언 필요)
	friend void doSomething(A& a, B& b); 
};

//class 가 두개일때 함수가 두개 모두 접근하는 방법
class B
{
private:
	int m_value = 2;

public:
	friend void doSomething(A& a, B& b);
};


void doSomething(A& a, B& b)  //doSomething() 를 class A 의 친구로 만들기, class B 의 친구로도 만들기
{
	cout << a.m_value << endl;
	//m_value 를 public 로 할수있지만 캡슐화의 원칙을 푸는것
	//class A의 friend 가 되면 private member 에도 접근할 수 있음
}




//다른 class 를 private member 에 접근하게 해주기
class C;  //C 안에 doSomething()이 있다는걸 class C 가 알 방법이 없음, 전방선언만으로 부족


class D
{
private:
	int m_value = 4;

public:
	void doSomething(C& c); // prototype 만 남기기

};

class C 
{
private:
	int m_value = 3;

	//friend class D; //class D 를 친구로 만들기
	friend void D::doSomething(C& c); //D 안에 들어있는 doSomething 에게만 열어주겠다
};


void D::doSomething(C& c)
{
	cout << c.m_value << endl;
}


int main()
{
	//함수를 친구로 만들기
	A a;
	B b;
	doSomething(a,b);


	//class 를 친구로 만들기
	C c;
	D d;
	d.doSomething(c);

	//class A 가 class B 나 class B의 멤버함수를 friend 하려는 경우(멤버함수의 정의는 class B 에 있음)

	//class B를 friend 하는 경우
	//A 가 앞에 있고 B 가 뒤에 있는 경우		: B를 전방선언
	//B 가 앞에 있고 A 가 뒤에 있는 경우		: A를 전방선언, 멤버함수 prototype 만 남기고 body 는 A 뒤로 보내기


	//class B 의 멤버함수를 friend 하려는 경우
	//A 가 앞에 있고 B 가 뒤에 있는 경우		: 불가능
	//B 가 앞에 있고 A 가 뒤에 있는 경우		: A를 전방선언, 멤버함수 prototype 만 남기고 body 는 A 뒤로 보내기



	return 0;
}