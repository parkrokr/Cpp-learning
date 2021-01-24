//정적 static 멤버 변수

//static 멤버 변수는 class 안에서 초기화 못함, 외부 파일로 뺄때는 cpp 파일에 정의, 헤더에 두면 재정의 에러 발생
//static const 멤버 변수는 class 밖에서 초기화 못함

#include <iostream>

using namespace std;

//함수가 하나씩 호출될때마다 s_id 가 1씩 증가
//고유넘버를 생성할때 많이 사용하는 방식
int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

class Something
{
public:
	int m_value = 1;
	
	static int s_value; //static 멤버 변수는 static int m_value_static = 1; 방식으로 초기화 못함
	
	static const int s_value_const = 1; //class 밖에서 초기화 못함, 밖에서 값을 못바꿈
	
	static constexpr int s_value_constexpr = 1; //constexpr은 compile time 에 결정되어야 함

};

int Something::s_value = 1; //외부로 뺄때 define in cpp, 헤더에 두면 컴파일 에러 발생
//헤더에 있으면 중복선언 문제가 발생

//int Something::s_value_const = 1;  //const 이기 때문에 값을 못바꿈

int main()
{
	//함수
	cout << generateID() << endl; //1
	cout << generateID() << endl; //2
	cout << generateID() << endl; //3


	//멤버 변수
	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;


	
	//static 멤버 변수

	//s_value 가 instance 가 없어도 주소가 있음
	cout << &Something::s_value << " " << Something::s_value << endl;


	st1.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;

	//주소와 s_value 의 값이  st1, st2 둘다 같음


	cout << &Something::s_value << " " << Something::s_value << endl;
	
	Something::s_value = 1024; //문법상 이렇게 바꿀 수 있음

	cout << &Something::s_value << " " << Something::s_value << endl;


	//s_value 는 instance 가 없어도 직접 접근이 가능함 (static 이기 때문에)


	return 0;
}