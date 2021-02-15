//정적(static) 멤버 함수

//static 멤버 함수는 특정 instace 와 상관없이 사용될수 있음(포인터 포함), this 를 사용 못함
//non-static 멤버 함수는 특정 instace 에 종속되어서 사용됨
//static 멤버 변수는 생성자에서 초기화를 못함(c++ 에선 생성자를 static 으로 못함)
//inner class 를 사용하면 static 멤버 변수 초기화 가능
//멤버 함수의 포인터는 형변환을 해주지 않음, 따라서 함수 포인터 대입과 다르게 &를 반드시 붙여줘야함

#include <iostream>

using namespace std;

class Something
{
	
public:
	class _init  //inner class 를 사용하면 static 멤버 변수 초기화 가능
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};

private:
	static int s_value;  //같은 class 의 모든 instance 에서 접근이 가능(공유)
	int m_value;

	//inner class 를 사용하면 static 멤버 변수 초기화 가능
	static _init s_initializer;

public:
	Something()
		:m_value(123)  //s_value(1024) //static 멤버 변수는 생성자에서 초기화를 못함
	{}

	//static 멤버 변수가 생성자에서 초기화 되려면 생성자가 static 이면 되지만 c++에선 불가능함
	//inner class 를 사용하면 가능
	


	static int getValue()
	{
		return s_value; 

		//주의할점
		//return this->s_value;		//this 를 못씀
		//return m_value;			//this 를 못쓴다는것은 this로 접근해야되는 모든걸 못씀( m_value)
	}

	
	//일반적인 멤버 함수
	int temp()
	{
		return this->s_value; //this 를 사용한다는 것은 특정 instace 의 주소를 받아서 사용
	}
};

int Something::s_value = 1024;  //초기화, private: 는 static 멤버변수에 대한 접근은 안막음
Something::_init Something::s_initializer;  //1234 로 다시 초기화

int main()
{
	//cout << Somthing::s_value << endl; // private : 라 접근 못함

	Something s1;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl; // private : 라 접근 못함
	
	//Somthing 의 instace 가 만들어지기 전에도 접근이 가능하고 선언후 만들어진 instace 의
	//s_value 와 같은 주소값이 나옴


	//특정 instance 와 상관없이 멤버에 접근하는 기능을 만들고 싶을때
	//getValue() 를 static 으로 선언하면 가능
	cout << Something::getValue() << endl;


	//멤버함수의 주소를 가져올 수 있음
	//Member Funcion Pointer
	Something s2;


	//non-static member function		//특정 instace와 연결되어야 실행시킬 수 있는 포인터 형태

	//int (Somthing:: * fptr1)() = s1.temp;  안됨
	//&s1.temp; &(s1.temp);, (s1.temp) 도 안됨							


	//m_value 는 s1 과 s2 가 서로 주소가 다르지만 함수는 같음

	//Member Funcion Pointer		
	int (Something:: * fptr1)() = &Something::temp;  

	//멤버 함수의 포인터는 형변환을 해주지 않음, 따라서 함수 포인터 대입과 다르게 &를 반드시 붙여줘야함

	//사용
	cout <<(s2.*fptr1)() << endl;
	//멤버함수의 포인터는 실행시킬때 실행시킬때 s2라는 instance의 포인터를 함께 넣어줘야 실행 가능

	//non-static 멤버 함수는 instance 에 종속되어 있기 때문에 intance 의 this 포인터가 있어야 작동가능
	//cout<<(*fptr1)()<<endl; 불가능



	//static member function		//특정 instace 와 상관없이 실행시킬 수 있는 포인터 형태

	//int (Somthing:: * fptr2)() = &Somthing::getValue;   //안됨
	int (*fptr2)() = &Something::getValue; //특정 instace 와 상관없이 실행시킬 수 있는 포인터 형태, 일반 함수포인터처럼 사용가능

	cout << fptr2() << endl;  //특정 instace 와 연결안해도 실행이 됨






	return 0;
}
