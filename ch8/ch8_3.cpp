//생성자 Constructors


//생성자는 선언과 동시에 작동됨
//주의사항 : Fraction frac; 에서 생성자의 parameter 가 하나도 없을 경우에만 frac() 에서 항상 () 를 빼도록 되어있음
//생성자가 하나도 없을때는 아무일도 안하는 default 생성자 Fraction() {} 가 하나 숨어있음
//대신 하나라도 있으면 기본생성자는 생성이 안됨
//parameter 가 있는 생성자라도 dafault value 가 모두 설정되어 있으면 기본생성자 기능을 함

#include <iostream>

using namespace std;

//분수를 나타내는 class
class Fraction
{
private:
	int m_numerator;		//분모    = 1; 해서 기본값을 만들수도 있음, 나중에 바꾸려면 또 문제 발생
	int m_denominator;		//분모


public:
	//생성자
	//생성자가 variable 같은 instance 를 만드는게 아니고 그냥 이름이 생성자,
	//construction 될때 호출이 되는 함수라고 생각하면 됨

	//return 값이 없고 class 이름과 동일하면 생성자
	//외부에서 호출하려고 쓰는게 아님
	//main() 에서 선언과 동시에 실행이 됨

	//기본생성자

	//생성자가 하나도 없을때는 아무일도 안하는 default 생성자 Fraction() {} 가 하나 숨어있음
	//대신 하나라도 있으면 기본생성자는 생성이 안됨
	/*Fraction() // default 생성자, 주석이 있어도 없어도 똑같음
	{
		m_numerator = 2; //이렇게 하면 일반적인 함수 오버로딩과 비슷한 애매한(ambiguos) 문제 발생
		m_denominator = 1;
	}*/


	//parameter 를 넣을 수 있음, daflult value 넣을 수 있음
	Fraction(const int& num_in = 1, const int& den_in = 1)  
	{
		m_numerator = num_in;
		m_denominator = den_in;

		cout << "Fraction() constructor" << endl;
	}


	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}

 };

//class 가 여러개 있는 경우
class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};


int main()
{
	//Fraction frac;

	//frac.print(); //초기화가 안되어서 쓰레기 값이 나옴

	//class 내 member variable 을 public: 으로 바꾼후
	//Fraction frac({0, 1}; 또는
	//frac.m_numerator = 0;
	//frac.m_denominator = 1;

	//member variable 을 public: 으로 바꾼게 부담스러움



	//생성자는 main() 에서 선언과 동시에 작동됨
	//Fraction frac; 이 선언되면 print() 가 실행되기 전에 내부적으로 들어가서 생성자가 실행됨
	//Fraction frac;
	//frac.print();

	//Fraction frac; 에서 생성자의 parameter 가 하나도 없을 경우에만 frac() 에서 항상 () 를 빼도록 되어있음


	//생성자에도 parameter 를 넣을 수 있음
	Fraction one_thirds(1, 3);
	one_thirds.print();

	//defautl value 도 넣을 수 있음
	Fraction one_one(1);
	one_one.print();


	//Fraction frac; 생성자가 없으면 에러가 안남, 대신 print() 하면 이상한 값이 나옴
	//생성자가 하나도 없을때는 아무일도 안하는 default 생성자 fraction() {} 가 하나 숨어있음
	//대신 하나라도 있으면 기본생성자는 생성이 안됨
	//그래서 Fraction frac;이 에러나는 이유는 parameter 가 없는 생성자가 없기 때문이다
	//Fraction frac; 이 에러가 안나기 위해 parameter 가 없는 생성자가 있는경우 Fraction frac(); 가 
	//되어야 할것 같지만 c++ 의 문법적인 한계 때문에(함수와 혼동될까봐) Fraction frac;으로 써야함

	//Fraction frac; 에러 안나기 위한 두가지 방법
	//기본 생성자를 그냥 만드는 방법,
	//생성자의 오버로딩을 이용해서 parameter 를 받는 생성자에 default 값을 넣는 방법
	//parameter 가 있는 생성자라도 dafault value 가 모두 설정되어 있으면 기본생성자 기능을 함
	Fraction frac;
	frac.print(); // 1 / 1 출력됨



	//일반적인 함수 오버로딩과 비슷한 애매한(ambiguos) 문제 발생할 수도 있음


	//copy initialization 도 가능
	//Fraction one_thirds = Fraction{ 1,3 }; 권장하진 않음, 
	Fraction one_thirds{ 1,3 };// 이렇게 줄여서 쓸 수 있음


	//uniform initialization 과 copy initialization 의 차이
	//대부분의 경우 둘다 비슷하지만 uniform initialization 이 더 최근에 나왔고 
	//더 엄격하기 때문에 자주 쓰임

	//uniform initialization	Fraction one_thirds{ 1,3 };
	//멤버들이 public 일때는 생성자 없이 초기화 할 수 있음, private 일때는 안됨
	//맴버들이 private 이고 생성자가 있으면 생성자를 호출함
	//암시적 형변환 허용 안됨
	//Fraction one_thirds{ 1.0 ,3 }; 하면 컴파일 안됨

	//copy initialization		Fraction one_thirds(1, 3);
	//암시적 형변환 허용 됨
	//Fraction one_thirds(1.0 ,3 ); 하면 경고만 뜨고 컴파일은 됨







	//class 가 여러개 있는 경우(class 안에 class 가 있는 경우)
	First fir;
	//Second 가 먼저 만들어지고 그 다음에 First 가 만들어짐

	//생성자는 class 안의 멤버가 먼저 초기화되어 되어야 그거에 대해 작업을 해줄 수 있음

	//한 class 가 다른 class 를 자신의 멤버 variable 로 사용을 할 경우
	//멤버 variable 의 생성자가 먼저 호출이 된다

	
	//생성자가 private 일 경우 main() 에서 생성자를 호출 못함
	//이를 이용한 프로그래밍 기법이 있음



	return 0;
}