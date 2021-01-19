//복사 생성자, 복사 초기화, RVO (Return Value Optimization)

//복사 생성자는 복사 초기화에 같이 사용됨
//복사 생성자는 경우에 따라 호출이 될수도 있고, 컴파일러가 최적화를 위해 생략을 할 수도 있음
//복사 생성자가 private: 에 있는경우 밖에서 사용을 못함(복사를 못함)


#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_deniminator;


	//복사 생성자가 private: 에 있는경우 밖에서 사용을 못함(복사를 못함)
	/*Fraction(const Fraction& fraction)
		:m_numerator(fraction.m_numerator), m_deniminator(fraction.m_deniminator)
	{
		cout << "copy constructor called" << endl;
	}*/



public:
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_deniminator(den)
	{
		assert(den != 0);  //분모가 0 이면 안된다는 조건
	}


	//copy constructor  자기랑 똑같은게 들어오는것
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


Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}


int main()
{
	Fraction frac(3, 5);

	//copy
	Fraction fr_copy(frac);
	
	//Fraction fr_copy = frac;  //copy initialization 의 경우도 copy constructor 이 호출됨
	
	//Fraction fr_copy(Fraction(3, 10));
	//이 경우 복사생자가 호출되지 않음, 컴파일러가 Fraction fr_copy(3,10); 으로 바꿈


	cout << frac << " " << fr_copy << endl;


	//RVO
	Fraction result = doSomething(); 
	cout << &result << endl;
	cout << result << endl;

	//debug 모드에선 result 에 copy initialization 을 할때 copy constructor 이 호출됨
	//temp와 result 의 주소를 찍어보면 주소가 다름, 다르기 때문에 복사를 했어야 함

	//release 모드에선 copy constructor 이 생성되지 않음
	//return value 가 함수를 벗어나면 유지될 이유가 없기 때문에 result 로 옮겨버림
	//temp 와 result 의 주소를 찍어보면 주소가 같음, 같기 때문에 복사를 할 필요가 없음
	//컴파일러가 최적화를 해주는것임(release 모드에서만)

	return 0;
}
