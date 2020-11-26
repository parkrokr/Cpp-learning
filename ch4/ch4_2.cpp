// 전역 변수(Global Variable), 정적변수(Static Variable), 내부 연결(Internal Linkage), 외부 연결(External Linkage)


/*
	int g_x; // 초기화를 안하고 정의만 하는경우 external linkage 로 쓸 수 있음
	static ing g_x; // internal likage 다른 cpp파일에서 접근할 수 없다 초기화가 되어있지 않은 정적변수다
	const int g_x(0); //초기화가 반드시 필요함, 값을 이후에 안바꿈

	extern int g_z; // forward declartion 인 경우 extern
	extern const int g_z;// 다른곳 어디서 한곳에서만 값을 초기화 해줘야함

	int g_y(1); //external linkage고 초기화가 된 전역변수
	static int g_y(1);//다른곳에서 접근이 불가능한 정적 전역 변수를 초기화
	const int g_y(1); //같은 파일 안에서만 접근 가능한 값을 바꿀수 없는 변수

	extern int g_w(1);// 초기화한 다른 cpp파일에서 접근 가능한 전역변수
	extern const int g_w(1);// 초기화 되었고 값을 못바꾸고 다른 cpp파일에서 접근 가능
	초기화를 한번 해주면 다른곳에서 초기화를 하면 안된다.
*/


// 전역변수 가급적 사용 안해야함, 프로그램이 커지면 관리가 힘들어짐

#include<iostream>
#include "MyConstants4_2.h"

using namespace std;

int value = 123;

//int a = 1;

// 전역변수에 static을 붙이면 다른 cpp파일에서 접근,사용이 불가능함
static int g_a = 1;


//forward declaration
void doSomething();// 앞에 extern 이라는 키워드는 생략되어있음
extern int b; //extern 이기 때문에 프로그램 전체에서 같은 이름을 가진 변수가 하나여야 함, 다른값으로 초기화 하면 충돌남


void doSomething_()
{
	// static 이란 a가 os로부터 받은 메모리가 static 이다, 같은 메모리를 재사용한다
	// static 변수가 선언될때 같은 메모리를 사용하고 초기화를 한번만함, 초기화가 반드시 필요함
	// 함수가 몇번 호출되었는지 사용하는 식으로 debuging 시 유용함

	static int a = 1; // static 변수라 메모리는 고정되어 있지만 지역 변수이기 때문에 다른곳에서 볼 수는 없음
	//int a = 1; 과 비교
	++a;
	cout << a << endl;
}


int main(void)
{
	// value 는 지금 global
	cout << value << endl;
	
	// local variable 지역변수
	// 선언한 순간부터 사용가능, 영역을 벗어난 순간 사용,접근 못함,scope 제한,duration 제한
	int value = 1;// 변수 이름이 같기 문에 namehiding 이 적용됨

	cout << value << endl;
	cout << ::value << endl;//:: 영역 연산자 Global scope operator 사용하여 다른 영역에 정의된 변수 사용

	// a 가 static 일때, global 일때 비교
	// 전역변수 a는 이 cpp가 한번 실행되기 때문에 static가 유사하게 작동함
	// 전역변수를 남발하면 변수관리가 힘들기 때문에 힘들어진다
	// 함수가 int a를 받는식으로 잘 설계하는 방법, 전역변수는 g_를 붙이는 식으로 이름을 다르게 해 구별 하는 방법이 있다
	// 가장 좋은건 객체지향을 통해 전역변수 사용을 최소화
	doSomething_();
	doSomething_();
	doSomething_();
	doSomething_();

	
	//local variable 은 다른 파일에 있는 무언가와 연결 될 일이 없음
	
	//Internal linkage 는 개별 cpp 파일에서만 전역으로 작동하는 전역변수
	//External linkage 는 다른 cpp 파일에서도 전역변수를 사용할 수 있다

	doSomething();// 전방 선언이 필요함
	cout << b << endl;//처음 선언된 test4_2.cpp에서 초기화



	cout << "In ch4_2.cpp file " << Constants::pi << " " << &Constants::pi << endl; //& 앞에 붙이면 주소
	doSomething();
	// 헤더파일에서 선언만 해주고 MyConstants4_2에서 초기화를 해주면 pi가 같은 주소를 사용함


	
	return 0;
}
