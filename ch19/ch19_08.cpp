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


	template<class T>
	void func_ex3(T arg)
	{}

	/*template<class T>
	void func_ex3(const T& arg)
	{}*/

	void ex3()
	{
		const int& crx = 123;
		 
		func_ex3(crx);	//const 와 & 를 떼고 int 만 남음

		//const int reference 로 넣고 싶으면  void func_ex3(const T& arg) 사용
	}

	
	void ex4()
	{
		const int c = 0;
		auto& rc = c;		//rc 가 const int reference

		//rc = 123; 을 시도하면 compile error 가 발생

		//reference 로 받아오는데 c 가 const 이기 때문에 받는 rc 도 const 여야함, auto 가 잘 추론을 해줌
	}


	void ex5() //amendament(개정, 수정)
	{
		int i = 42;
		auto&& ri_1 = i;	// l value (amendament(개정, 수정))
		auto&& ri_2 = 42;	// r value

		//auto&&는 r vlaue reference 로 선언하고 싶다는 의도, l value 가 들어오면 & 로 바뀜
		//r value 가 들어오면 &&(r value reference) 로 잡힘
	}


	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;		//p2 는 const int * 로 잘 잡힘

		//auto 가 포인터도 가져오고 const 도 가져옴, auto 가 반드시 필요한 경우 (옛날엔 힘들었다 함)
		//*p2 = 43; const 라 error
	}






};

int main()
{
	Examples examples;
	
	examples.ex1();


	return 0;
}