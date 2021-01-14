#include "Calc.h"  //보통 처음 하는일이 class 헤더파일을 인클루드 해줌

using namespace std; //다른 cpp 파일에 영향 안주기 때문에 편하게 써도 됨


//생성자도 같이 옮길 수 있음
Calc::Calc(int init_value) 
	:m_value(init_value)
{}

Calc& Calc::add(int value) //Calc::를 통해 add() 가 Calc 의 멤버라는걸 알려줘야 함
{
	m_value += value;
	return *this;
}

//직접 옮기지 않고 Quick Actions and Refactorings 의 Move Definition Location 사용
//일반적으로 class 안의 멤버 함수의 definition 을 다 적었을 경우 inlining 하고 싶다고 컴파일러가 간주함
//inline Calc& Calc::sub(int value)
Calc& Calc::sub(int value)
{
	m_value -= value;
	return *this;
}

Calc& Calc::mult(int value)
{
	m_value *= value;
	return *this;
}

void Calc::print()
{
	
	cout << m_value << endl;
}
