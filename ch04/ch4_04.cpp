// Auto 키워드와 자료형 추론(Type Inference)

#include<iostream>

int add(int x, int y)
{
	return x + y;
}

// 함수 return type도 auto를 쓸 수 있음
auto add(double x, int y) -> double //trailing 자취를 남길 수 있음		//람다함수 표현식에서 사용
{
	return x + (double)y;
}

/*
int		 add(int x, int y);			  이거보단
double	 add(int x, int y);		

auto add(int x, int y) -> int;
auto add(int x, int y) -> double;     이게 보기 편함

*/


//auto add(auto x, auto y) 처럼 auto를 parameter type에는 쓸 수 없다


//template을 사용하면 가능, 여러개의 return 값을 반환할 수 있음



int main()
{
	using namespace std;

	//int a = 123; //123 은 정수이기 때문에 a는 정수형이 될 것이다, 즉 한줄에 정보가 두개가 있다
	
	auto a = 123; //자료형을 상황에 따라서 스스로 추론하게 하는걸 형추론 Type Inference 이라고 하고 auto 키워드를 사용함

	// 초기화를 하지 않으면 auto를 사용할 수 없음

	auto d = 123.0; //double
	auto c = 1 + 2.0; //double

	// 계산 결과가 어떤 자료형일지 프로그래머가 알고 있어야함

	// 함수 return type 도 auto를 쓸 수 있음
	auto result = add(1, 2);
	cout << result << endl;
	

	return 0;
}
