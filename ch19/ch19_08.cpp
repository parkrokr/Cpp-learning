//자료형 추론 (Type Inference)  auto 와 decltype

#include <iostream>
#include <vector>
#include <algorithm>	//std::min

//Referecne : http://thbecker.net/articles/auto_and_decltype/section_01.html

using namespace std;

class Examples
{
public:

	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr = vect.begin(); itr != vect.end(); itr++)
			cout << *itr;

		for (auto itr : vect)	//for (const auto & itr : vect)
			cout << itr;
	}

	void ex2()
	{
		int x = int();

		auto auto_x = x;	//int 로 잡음


		const int& crx = x;

		auto auto_crx1 = crx;	//crx 는 const int & 이지만 auto 는 const, reference 를 떼어서 int 로 잡음

		const auto& auto_crx2 = crx;	//const int & 로 쓰고 싶으면 auto 자체를 const, reference 로 지정


		volatile int vx = 1024;		//volatile 은 값이 자주 변하니 최적화 할때 빼달라 라는 의미
		//multi threading 을 할때 사용할 수 있음 

		auto avx = vx;	//volatile 떼버리고 int 로 잡음

		volatile auto vavx = vx;	//volatile 같이 사용하고 싶으면 voliatile auto 사용


		//auto 는 가장 기본적인 자료형(ex int) 만 추론해주고 나머지 수식어(const, reference, volitile ) 는 뗴어버림
		//사용자가 추가하고 싶으면 추가해줘야 함
	}


};

int main()
{
	Examples examples;
	
	examples.ex1();


	return 0;
}