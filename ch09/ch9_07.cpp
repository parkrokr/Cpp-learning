//괄호 연산자 ( () parenthesis ) 오버로딩과 함수 객체 Function object ( Functor )

//member function 으로만 가능한 연산자들
// = , [] , () ,->
//괄호연산자를 오버로딩하면 함수가 객체인것처럼 , Functor 인것처럼 사용할 수 있음


#include<iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator() (int i) { return (m_counter += i); }
	

	//chaining 구현
	/*Accumulator& operator() (int i)
	{
		m_counter += i;
		return *this;
	}*/
	
	int getAccumulator()
	{
		return m_counter;
	}
};


int main()
{
	Accumulator acc;
	cout << acc(10) << endl;  //10
	cout << acc(20) << endl;  //30

	//함수로 기능을 구현할 수도 있지만 객체를 함수를 호출하는것처럼 사용함(이런 방법을 functor 라고 함)
	//chaining 구현 가능

	cout << acc(acc(10)) << endl;

	//cout << acc(10).getnumber() << endl;
	//cout << acc(10)(10).getnumber() << endl;

	return 0;
}
