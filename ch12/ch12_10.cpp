//동적 형변환 Dynamic Casting

//static_cast 는 컴파일타임에 체크하고 런타임에선 체크하지 않지만
//dynamic_cast 는 런타임에 체크하기 때문에 문제를 잡아 줄 수 있음

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base* base = &d1;

	//d1에 직접 접근을 못할때
	//Base 에는 없고 Derived1에만 있는거에는 접근을 못함
	d1.m_j; //d1 에선 m_j 에 접근이 가능하지만
	//base->m_j;  //Base 에선 접근을 못함

	//설계를 잘해서 이런 경우가 없도록 하는게 좋지만 어떤 경우에 어쩔 수 없이 
	//Base 를 Derived1 type 으로 바꿔야만 할 때가 있음
	//그런 경우에 dynamic_cast 를 사용할 수 있음

	//base 를 Derived1 으로 동적 형변환을 할 수 있음
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);  //auto 가 class Derived1 으로 잡음
	//auto* base_to_d1 = static_cast<Derived1*>(base); //static_cast 도 가능


	//m_j 에 접근 할 수 있음
	cout << base_to_d1->m_j << endl;	//1024
	
	//이런게 가능하긴 함
	base_to_d1->m_j = 256;
	cout << d1.m_j << endl;				//256

	//이건게 가능하긴 하지만 가급적 안쓰는게 좋음, 코드 읽기도 힘들고 디버그도 힘들지만 특별한 경우 필요함
	//가상함수를 이용해서 해결하는게 좋음


	//d1을 base 에 넣었다가 Derived2 로 강제 형변환?
	auto* base_to_d2 = dynamic_cast<Derived2*>(base);
	//auto* base_to_d2 = static_cast<Derived2*>(base);

	//dynamic_cast 는 casting 에 실패하면 null pointer 를 넣어버림
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl;
	else
		cout << "Failed" << endl;
	//Failed 출력, casting 실패

	//static_cast 는 casting 이 가능함
	//static_cast 는 할수있는한 최대한 다함
	//대신에 runtime 에서 error check(type check) 를 안함,compile time 에 체크함
	//어떤 경우엔 안되야 할것도 되는일이 있음, 이게 좋은지 않좋은지는 애매함
	

	//dynamic_cast 는 run time 에 error check 를 함

	//static_cast 는 컴파일타임에 체크하고 런타임에선 체크하지 않지만
	//dynamic_cast 는 런타임에 체크하기 때문에 문제를 잡아 줄 수 있음



	//문제가 안생기는 경우
	// d1을 base 로 바꿨다가 다시 d1으로 바꾸는 경우(메모리에 저장되어있는건 d1) 둘다 상관없지만
	//문제가 생기는 경우
	// d1을 base 로 바꿨다가 d2으로 바꾸는 경우 dynamic_cast 는 runtime 에 check 를 해서
	//아니면 nullpointer 를 넣어서 맞춰주지만 static_cast 는 그냥 밀어붙임


	//일반적으로 동적캐스팅을 안쓰자는 말도 많음
	//최근에는 funcional 이나 ramda function 을 쓰는 추세
	//있다는걸 알아두면 객체지향구조나 다향성을 이해하기에 좋음
	//실제로 쓰기 전에는 한번더 생각해보고 쓰기
	//static_cast 와 차이점 알고 쓰기

	return 0;
}