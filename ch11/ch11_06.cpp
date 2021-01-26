//유도된 ( Derived ) 클래스에 새로운 기능 추가하기

#include <iostream>
using namespace std;

class Base
{
//private:
protected:
	int m_value;

public:
	Base(int value)
		:m_value(value)
	{

	}

};


class Derived : public Base
{
public:
	Derived(int value)
		:Base(value)
	{
	}

	//Base 에 있는 값을 건드리려고 할때
	//protected 로 바꿔주기
	void setValue(int value)
	{
		Base::m_value = value; //이것만 있을경우 여기에 구현할 필요가 없음
		//do some work with the variables defined in Derived
	}
};


int main()
{
	//자식 클래스에서 부모 클래스의 멤버변수를 건드리고 싶은 경우
		//1. 멤버변수를 protected: 로 해서 접근할 수 있게 해주기
		//2. private: 으로 그대로 두고 getters() 를 만들어서 접근하기 
			// 2번의 경우 상위클래스의 함수를 한번 거쳐야 되기 때문에 퍼포먼스가 좀 떨어질 수 있음
			// 아주 많이 사용할 경우 코딩하는게 복잡해져 번거로울 수 있음

	//그때그때 상황에 맞춰 잘 구현하기

	return 0;
}
