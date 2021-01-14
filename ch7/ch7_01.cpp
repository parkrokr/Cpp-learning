//매개변수 (Parameter)와 인자(Argument)의 구분


//매개변수는 함수가 어떤 기능을 하는지를 조절해주는 기능
//arguments (actual parameters)  인자 , 실 매개변수, 실 인자

#include <iostream>

using namespace std;


int foo(int x, int y);

int foo(int x, int y) //x와 y 는 마치 지역 변수 선언 
{
	return x + y;
}// x and y are destroyed here


int main()
{
	int x = 1, y = 2;

	//함수가 작동할때 필요한건 x,y 에 들어오는 '값' 이 필요함

	foo(6, 7); //6, 7 : arguments (actual parameters)  인자 , 실 매개변수, 실 인자
	// foo 의 x y에는 '값'이 들어가면 되기 때문에 6,7이 들어갈 수 있음
	
	foo(x, y + 1);
	//x 안에 들어있는 1이라는 값이 argument로 foo() 의 매개변수 x로 전달됨
	//3이라는 값이 argumnet 로 foo()의 매개변수 y로 전달됨

	//항상 x나 y 에 있는 값만 전달이 되는건 아님
	//값에 의한 전달,주소에 의한 전달,참조에 의한 전달 이 있음

	return 0;
}