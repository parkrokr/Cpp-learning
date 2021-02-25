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



	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)	//들어온 두 숫자를 곱하는 함수
	{
		auto prod1 = lhs * rhs;

		//lhs 와 rhs 가 data type 이 다를 수 있음 
		//prod1 의 data type 이 뭐가 될지 알기 어려움(명확 하지 않음)


		//lhs* rhs가 어떤 type 일지 data type 을 return 하는 함수
		//typedef typeof(lhs* rhs) product_type;	//c++11 이전 '일부' 컴파일러에서 제공
		typedef decltype(lhs* rhs) product_type;	//공식적으로 사용

		//decltype 안에서 lhs* rhs 은 실제로 수행(계산)되지 않고 추론만 함

		product_type prod2 = lhs * rhs;


		decltype(lhs * rhs) prod3 = lhs * rhs;	//datatype 을 저장하지 않아도 바로 쓸 수 있음
	}


	//함수의 return type 에도 decltype 을 사용할 수 있음
	template<typename T, typename S>
	auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)	//trailing
	{
		return lhs * rhs;
	}

	//decltype(lhs* rhs) func_ex8(T lhs, S rhs)		//decltype 을 바로 return type 자리에는 쓸 수 없음
	//컴파일러가 코드를 읽는 순서상 decltype(lhs* rhs)가 먼저 읽히는데 lhs* rhs가 뭔지 아직 안나옴


	void ex7_8()
	{
		func_ex7(1.0, 345);		//double
		func_ex8(1.2, 345);		//double
	}



	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();


		auto a = x;			//int
		auto b = cx;		//int
		auto c = crx;		//int		, const & 는 떼어짐
		auto d = p;			//const S*	, 포인터랑 const 따라옴
		auto e = p->m_x;	//int		, p 가 const 라 m_x 도 수정할 수 없지만
							//e가 const 가 아니어도 e 에 m_x 를 복사 할 수 있음


		typedef decltype(x)		x_type;		//int
		typedef decltype(cx)	cx_type;	//const int			auto 와 다름
		typedef decltype(crx)	crx_type;	//const int &		const, & 그대로 다 가지고 옴
		typedef decltype(p->m_x)m_x_type;	//int				m_x 가 int 로 선언되어서 declared type 그대로 가져옴

		typedef decltype((x))	x_with_parens_type;		//int &			,add reference to l values
		typedef decltype((cx))	cx_with_parens_type;	//const int &
		typedef decltype((crx))	crw_with_parens_type;	//const int &	,& 가 하나 더 붙진 않음, 유지함
		typedef decltype((p->m_x)) m_x_with_parens_type;//const int &	,const 도 같이 붙음!
	}



	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		std::vector<int> vect = { 42,43 };

		auto a = foo();		//S
		typedef decltype(foo()) foo_type;	//const S		const 가 유지됨

		auto b = foobar();	//int		,const 와 & 떼버림
		typedef decltype(foobar()) foobar_type;	//const int &		,const 와 & 둘다 유지함


		auto itr = vect.begin();						//std::vector itreator
		typedef decltype(vect.begin())	iterator_type;	//std::vector itreator

		auto first_element = vect[0];					//int
		decltype(vect[1]) second_element = vect[1];		//int &

		//std::vector 에 overloading 되어있는 [] 연산자가 return 할때 & 로 return 함
		//decltype 으로 받으면 이 reference 가 유지됨
	}



	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y) prod_xy_type;		//int
		auto a = x * y;								//int

		typedef decltype(cx* cy) prod_cxcy_type;	//int		result is prvalue(pure r value)
		auto b = cx * cy;							//int


		typedef decltype(d1 < d2 ? d1 : d2)	cond_type;	//result is lvalue. & is added	d1 과 d2 가 같은 type
		auto c = d1 < d2 ? d1 : d2;						//double

		typedef decltype(x < d2 ? x : d2)	cond_type_mixed;	//double	promotion of x to double
		auto d = x < d2 ? x : d2;								//double


		//std::min 은 입력되는 두 변수가 같은 type 일때만 작동함, 다르면 error
		//auto d = std::min(x,d1);	//error
	}


	//data type 과 상관없이 작동하는 min
	//floating point min(boost lib)

	//잘못된 방법
	template<typename T, typename S>
	auto fpmin_wrong(T x, S y)->decltype(x < y ? x : y)			
	{
		return x < y ? x : y;
	}


	//T 와 S 의 data type 이 같은 경우 return type 에 & 가 붙음
	//remove_reference	: &가 제거된 data type 을 사용	(앞에 typename 붙어있음)
	template<typename T, typename S>
	auto fpmin(T x, S y)->
		typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}


	void ex12()
	{
		int i = 42;
		double d = 45.1;
		//auto a = std::min(i,d);	//error : 'std::min' : no mathching overloaded function found
		auto a = std::min(static_cast<double>(i), d);	//std::min 을 사용하기 위해서는 casting 을 해줘야됨

		int& j = i;


		typedef decltype(fpmin_wrong(d, d)) fpmin_return_type;		//double &
		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type1;		//double		,&가 사라짐
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type2;		//double		,&가 사라짐

		//그때그때 달라지는것도 문제고, reference 로 return 하면 문제가 생길 수 있음
		//대부분의 경우 권장하지 않음


		//std::remove_reference 사용	:	&를 제거한 type 을 사용하겠다
		typedef decltype(fpmin(d, d)) fpmin_return_type3;		//double 
		typedef decltype(fpmin(i, d)) fpmin_return_type4;		//double		
		typedef decltype(fpmin(j, d)) fpmin_return_type5;		//double		
	}


	void ex13()
	{
		std::vector<int> vect; //cect is empty

		typedef decltype(vect[0]) integer;

		//vect 는 비어있기 때문에 [] 연산자를 이용하여 vect[0] 을 하면 런타임에러가 발생하지만
		//decltype 은 실제로 실행하지 않기 때문에(compile time 에 체크함) 가능함
	}


	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor(){}

		//result_type 을 return 하는 functor, 객체를 함수처럼 사용할 수 있음
		result_type operator() ()
		{
			return R();
		}
	};


	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type inteager;		//nested type
		//decltype(func) 를 통해 SomeFunctor<int> 를 가져오고 거기서 result_type ( int ) 을 가져옴
		//class 안에 있는 nested type도 decltype 을 통해 간편하게 접근할 수 있음
	}


	//lambda 도 decltype 을 통해 data type 을 찾아낼 수 있음
	void ex15()
	{
		auto lambda = []() {return 42; };		//auto 가 lambda class 로 data type 을 잡음
		decltype(lambda) lambda2(lambda);		//lambda 와 같은 기능을 하는 lambda2 가 생김
		decltype((lambda)) lambda3(lambda);		//lambda3 는 reference

		cout << "Lambda functions" << endl;
		cout << &lambda << " " << &lambda2 << endl;		//주소가 다름
		cout << &lambda << " " << &lambda3 << endl;		//주소가 같음
	}


	//generic lambda
	void ex16()
	{
		//함수에서 parameter 로 auto 를 쓰지 못하지만 lambda 에선 쓸 수 있음

		auto lambda = [](auto x, auto y)
		{
			return x + y;
		};

		cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.4, 2.2) << endl;
		//	double		int		double
	}


};

int main()
{
	Examples examples;
	
	examples.ex1();
	examples.ex2();
	examples.ex3();
	examples.ex4();
	examples.ex5();
	examples.ex6();
	examples.ex7_8();
	examples.ex9();
	examples.ex10();
	examples.ex11();
	examples.ex12();
	examples.ex13();
	examples.ex14();
	examples.ex15();
	examples.ex16();


	return 0;
}