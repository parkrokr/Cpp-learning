//값에 의한 인수 전달  Passing Arguments by Value ( Call by Value)

#include<iostream>

using namespace std;

void doSomething(int y)
{
	cout << "In func " << y << " " << &y << endl;
}

int main()
{
	//값에 의한 전달
	//함수 호출을 하면 int y 가 선언되고 5라는 literal 값 하나가 함수의 y 로 복사가 되 초기화가 됨
	doSomething(5);

	//변수를 사용하는 경우
	int x = 6;

	cout << "In main " << x << " " << &x << endl;

	doSomething(x);
	doSomething(x + 1);
	//실제로 전달되는건 변수 x에 들어있는 6이라는 값(value)만 arguments 로서 함수 parameter에 전달됨
	//x가 복사되었으면 주소도 x와 같아야 하지만 실제로 주소를 출력해보면 다른 것을 알 수 있음
	//x+1 도 7이라는 값만 전달되는 것임


	//값에 의한 전달 장단점
	//함수 y랑 x의 주소가 다르기 때문에 함수에서 밖에 영향을 줄 수 없음
	//코드가 복잡해지면 함수가 자기일만 하는게 깔끔함
	//어떤 상황에선 외부에 영향을 끼쳐야 할 수도 있지만 값에 의한 전달은 못함



	return 0;
}