// 지역 변수의 범위(Scope)와 지속기간(Duration)
//블록(복합문), 명칭 공간, 이름 충돌, 이름 숨기기

#include<iostream>

//함수는 선언과 정의가 분리될 수 있기 때문에 선언은 여러곳에 등장해도 되지만 정의는 한번만 있어야함
// paremeter 가 다른 경우 다른 함수로 취급하기 때문에 충돌이 일어나지 않음
// 충돌을 피하기 위해 namespace를 사용함
// namespace 안에 namespace 를 또 사용할 수 있음

namespace work1
{
	int a = 1;
	void doSomething() 
	{
		a += 3;
	}
}

namespace work2
{
	int a = 1;
	void doSomething()
	{
		a += 5;
	}
}


// { } 여러개 싸는 방식 대신에 c++ 17부터 사용 가능한 문법, Properties\C/C++\Language 에서 c++17로 올려줘야함
namespace work11::work111::work1111
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

int main()
{
	using namespace std;

	int apple = 5;
	
	cout << apple << endl;


	//현대적인 프로그래밍에서는 변수선언시 가급적 duration을 줄이려고 함

	// { } 를 통해서 블록을 지정
	{	
		// 더 큰 영역에서 선언된 변수는 안에 있는 영역에서 볼수도 있고 사용할 수도 있음

		int apple = 1;// 블록이 끝나는 순간 사라짐, 이름은 같지만 위에 변수와 다름, 그래서 가급적 이름 다르게 짓기
		cout << apple << endl;
	}

	cout << apple << endl;

	
	
	// :: 영역, 범위 결정 연산자  scope resolution operator
	//class 와 namespace 에서 쓰임

	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	// c++ 17부터 사용 가능한 문법, Properties\C/C++\Language 에서 c++17로 올려줘야함
	work11::work111::work1111::doSomething();

	return 0;
}

//apple = 1; 메모리가 반납되어서 쓸 수가 없음
