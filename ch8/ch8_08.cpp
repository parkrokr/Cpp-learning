//클래스 코드와 헤더 파일

#include <iostream>

#include "Calc.h"  //헤더로 빼기

using namespace std;

//이렇게 코드가 길어지면 관리가 어려워짐
//class Calc 
//{
//private:
//	int m_value;
//
//public:
//	Calc(int init_value)
//		:m_value(init_value)
//	{}
//
//	Calc& add(int value)
//	{
//		m_value += value;
//		return *this;
//	}
//
//	Calc& sub(int value) 
//	{
//		m_value -= value;
//		return *this; 
//	}
//
//	Calc& mult(int value) 
//	{
//		m_value *= value;
//		return *this; 
//	}
//
//	void print()
//	{
//		cout << m_value << endl;
//	}
//};

//class 를 헤더로 보냄
//보통 헤더 이름이랑 class 이름이랑 같게 함


int main()
{
	//class 의 멤버함수를 분리를 위해 밖으로 뺐을때 함수가 class 의 멤버라는걸 알려주기 위해 Calc:: 를 붙여야함

	//익숙해지면  main() 위에서 만들고 옮기는게 아니라 헤더파일을 바로 만들고 거기서 작업하기

	//어떤 경우엔 헤더에 body 를 두는걸 권장하기도 함
	//template 을 구현할때

	return 0;
}