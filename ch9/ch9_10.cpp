//변환 생성자 ( Converting constructor ) , explict, delete

#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_deniminator;


public:
	//기본값이 두개라 parameter 가 하나만 들어와도 생성이 가능함
	explicit Fraction(int num = 0, int den = 1)  //explicit 키워드가 붙으면 변환 생성을 막음
		: m_numerator(num), m_deniminator(den)
	{
		assert(den != 0); 
	}

	//delete
	Fraction(char) = delete;  //char 로 못바꾸게 막음


	//copy constructor 
	Fraction(const Fraction& fraction)
		:m_numerator(fraction.m_numerator), m_deniminator(fraction.m_deniminator)
	{
		cout << "copy constructor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_deniminator << endl;
		return out;
	}

};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);//기본값이 두개라 parameter 가 하나만 들어와도 생성이 가능함

	doSomething(frac);
	doSomething(Fraction(7)); //조금더 간결하게 쓰고 싶을때 익명 객체 사용
	
	//copy constructor
	//doSomething(7);

	//이렇게 해도 가능,  이렇게 자동으로 바꿔주는걸 converting constructor 라고 함
	//함수 입장에서 받아들일수 있는게 Fraction 밖에 없으면 생성자처럼 자동으로 바꿔줌
	//explicit 키워드가 붙으면 변환 생성을 막음, doSomething(7); 불가능



	//delete
	//Fraction frac2('c');  //deleted funcion

	//char 로 받을시 막아버림
	//버전업을 하면서 예전 방식으로 쓰지 못하게 막기 위해 사용
	//자동 변환 되거나 casting 되는걸 막기 위해 사용

}