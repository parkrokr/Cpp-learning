//함수 템플릿 (Templates)

//템플릿은 여러가지 자료형에 대해서 비슷한 코드의 작성을 방지해줌

#include <iostream>
#include "ch13_01_Cents.h"

using namespace std;

//정수 두개를 받아 큰걸 반환하는 함수
/*int getMax(int x, int y)
{
	return (x > y) ? x : y;
}*/

//double 형도 만들고 싶음
/*double getMax(double x, double y)
{
	return (x > y) ? x : y;
}*/

//float 형도 만들고
/*float getMax(float x, float y)
{
	return (x > y) ? x : y;
}*/

//char 타입을 반환하는 것도 만들고
//int 를 받는대신에 int & 로 받는것도 만들다 하다보면
//고치는 작업이 반복되고 있음(패턴이 반복되고 있음)
//자동으로 생성하고 싶어짐



//template

//typename 으로 보통 T를 많이씀, 자료형이 들어갈 곳에 T를 넣으면 됨
//typename 대신에 class 를 넣어도 되지만 늬앙스가 좀 차이날뿐 문법상 큰 차이는 없음
//template<class T> 
template<typename T> 
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

//double...float...char... 이런걸 구현안해도 됨


int main()
{
	cout << getMax(1, 2) << endl;			//int
	cout << getMax(3.14, 1.592) << endl;	//double
	cout << getMax(1.0f, 3.4f) << endl;		//float
	cout << getMax('a', 'c') << endl;		//char

	//T 자리에 뭐가 들어갈지 컴파일러가 찾아내고 만들어서 컴파일할때
	//함수 오버로딩처럼 바꿔서 사용할 수 있게 해줌


	//user defined type 도 사용할 수 있음
	cout << getMax(Cents(5), Cents(9)) << endl;
	//템플릿 관련되기 시작하면 에러메시지가 많아짐
	//출력 연산자 오버로딩 해줘야함
	//비교 연산자 오버로딩 해줘야함

	//템플릿 구현은 쉽지만 템플릿으로 구현해주기 위해선 필요한 기능들이 다 구현되어 있어야 함



	//일반적인 T 말고 특정한 정의에 대해서 실제로 만드는 것을 instantiation 이라고 함
	//T가 int 일때 int 에 대한 instance(예시) 가 되는것임

	return 0;
}