//유도된 ( Derived ) 클래스들의 생성 순서

#include <iostream>
using namespace std;

class Mother
{
public:
	int m_i;
	
	//유도된 class 가 생성되는 순서를 알아보기 위해 생성자가 언제 호출되는지를 보는게 편함
	//기본 생성자랑 형태가 비슷함(parameter 가 없음)
	//의도적으로 호출하지 않아도 내부적으로 자동으로 호출 할 수 있음
	//없으면 스스로 만들어서라도 호출함
	//parameter 가 있는 생성자를 구현했을경우 자동으로 구현되는 기본생성자도 직접 구현해 줘야함

	Mother(const int & i_in = 0) //const int & i_in 까지만 있으면 기본생성자 역할을 못함,전에는 따로 구현함
		:m_i(i_in)
	{
		cout << "Mother construction" <<endl;
	}
};

class Child :public Mother
{
public:
	double m_d;

public:
	Child()
		//:m_d(1.0)  //, m_i(1024) 는 초기화는 안됨
		//: Mother(), m_d(1.0)  //사실 앞에 Mother() 이 숨어있음
		//: m_d(1.0), Mother(1024)  //순서가 바뀌어도 Mother 의 생성자를 먼저 호출함
		: Mother(1024), m_d(1.0) //Mother() 에 숫자를 넣어서 초기화 하고 싶음 -> 가능
	{
		
		//유도된 class 가 생성되는 순서를 알아보기 위해 생성자가 언제 호출되는지를 보는게 편함
		cout << "Child construcion " << endl;


		//m_i 는 Mother 를 상속받았기 때문에 자유롭게 접근해서 마치 자기것처럼 사용할 수 있음
		this->m_i = 10;
		Mother::m_i = 1023;
		this->Mother::m_i = 1024;
	}

};


//class 가 깊이가 있는 경우(여러번 상속)
class A
{
public:
	A()
	{
		cout << "A construcotor " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constuctor " << endl;
	}
};

class C :public B
{
public:
	C()
	{
		cout << "C constructor " << endl;
	}
};

int main()
{
	//유도된 class 가 생성되는 순서를 알아보기 위해 생성자가 언제 호출되는지를 보기
	Child c1;
	//Mother construction 이 먼저 일어남(자동으로라도 해줌)
	//그 다음에 Child construction 이 일어남

	//Mother 에 있는걸 모두 초기화 한후 Child 를 초기화

	//디버거로 찍어보면 c1의 선언된 후 c1의 생성자로 들어온후 Mother 의 생성자로 가서 
	//멤버 이니셜라이저를 통해 m_i 를 초기화 하고 "Mother construction" 을 출력하고
	//child의 생성자로 돌아온후 멤버 이니셜라이저를 통해 m_d를 초기화 하고 "Child construcion " 를 출력


	//Child  생성자의 멤버 이니셜라이저 리스트, m_d의 메모리만 잡아둠 //m_i는 아직 메모리조차 잡히지 않았기 때문에 에러
	//Mother 의 생성자로 이동
	//Mother 생성자의 멤버 이니셜라이저 리스트, m_i 의 메모리만 잡아둠
	//Mother 생성자의 body, m_i 의 메모리에 값을 넣어 초기화 
	//Child  의 생성자로 이동
	//Child  생성자의 body, m_d 의 메모리에 값을 넣어 초기화 //여기서 m_i 에 값을 넣을 순 있음



	//class 가 깊이가 있는 경우(여러번 상속)
	C c;
	//A, B, C 순서로 호출됨

	B b;
	//A, B 순서로 호출됨
	
	A a;
	//A 만 호출됨

	//소멸자는 생성자 호출 순서의 반대로 호출됨
	return 0;
}