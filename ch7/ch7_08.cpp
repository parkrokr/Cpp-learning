//매개변수의 기본값  Default Parameters

//매개변수가 여러개가 있을떄 매번 모든 매개변수의 값을 넣어주는게 번거로울 수 있음
//default 값을 설정해 원하는 경우 인자를 설정하는 것을 생략하는 과정

// 왼쪽에 기본매개변수가 있으면 그 오른쪽엔 반드시 기본매개변수가 있어야함
// 선언과 정의중를 분리할 경우 한곳에서만 기본매개변수설정을 해야함
// dafault 값이 함수 오버로딩할때도 영향을 줌

#include <iostream>
#include <string>

using namespace std;

//x에 값을 넣지 않으면 0을 넣음
void print(int x = 0)  //Default Parameters, Optional parameter, Default arguments 
{
	cout << x << endl;
}


//여러개도 설정할 수 있음
//그러나 왼쪽에 기본매개변수가 있으면 그 오른쪽엔 반드시 기본매개변수가 있어야함

//void print_new(int x, int y = 10, int z)  //불가능
//void print_new(int x, int y, int z = 3)  //가능
void print_new(int x = 10, int y = 20 , int z = 3)
{
	cout << x << " " << y << " " << z << endl;
}


//선언과 정의를 분리한경우(헤더에 선언이 있는 경우 포함)
//선언과 정의중 한곳에서만 기본매개변수설정을 해야함(보통 선언에서 설정함(주로 헤더파일에 가있는))
//각각 따로 정의되었을때 발생하는 모호한 문제를 원천봉쇄 하고자 컴파일러가 막음

//void print_new(int x = 10, int y = 20, int z = 3)		//declaration에서 정의가 되어있다면

//void print_new(int x, int y, int z)					//definition 에선 빼줘야 함
//{
//	cout << x << " " << y << " " << z << endl;
//}



//함수 오버로딩과 연관된 경우
void print_other(std::string str) {}
void print_other(char ch = ' ') {} // default parameter 가 있음

//난감한 경우
void function(int x){}  //ambiguos
void function(int x, int y = 20) {}

int main()
{
	print(10);	// 10
	print();	// 0, default parameter를 설정하지 않으면 컴파일 에러 발생

	//기본매개변수가 여러개인 경우
	print_new();
	print_new(100);				//x 만 출력
	print_new(100, 200);		//x, y 만 출력
	print_new(100, 200, 300);	//x, y, z 출력


	//함수 오버로딩과 연관된 경우
	print_other(); //ch 가 기본매개변수가 설정되었기 때문에 char 타입의 매개변수가 들어가는 오버로딩된 함수를 선택

	//난감한 경우
	//function(10); //ambiguous call to overloaded function

	//y의 기본매개변수 설정을 해제하면 가능함
	//y에 기본매개변수를 설정하고 싶으면 앞에있는 기본매개변수가 없는 변수를 가지고 있는
	//다른 함수를 오버로딩할 수 없음

	return 0;
}