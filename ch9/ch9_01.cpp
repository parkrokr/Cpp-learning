//산술 연산자 오버로딩 Overloading 하기


// +, -, *, / 같은거 다 연산자 오버로딩 할 수 있음
	// 우선순위는 그대로임(직관적인것들만 오버로딩 하는것이 좋음)
	// ^ 는 우선순위가 매우 낮기 때문에 ()로 싸서 써야하고 그냥 오버로딩 안하는게 편함

	//불가능한 연산자들
	// ?:		삼항연산자
	// ::		scope 연산자
	// sizeof	연산자
	// .		member selection 연산자
	// .*		member pointer 연산자
	// #		문자열 전처리기 변환
	// ##		전처리기 연결

	//member function 으로만 가능한 연산자들
	// = , [] , () ,->

	//friend function 으로만 가능한것
	// << 


//연산자 오버로딩을 멤버 함수로 하는 경우 첫번째 parameter 는 this 를 이용해야함


#include<iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; } //sum 때문에 기본값 넣어주기
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }  //참조로 반환해야 l value 가 되어 c_out.getCents() 에서 수정이 가능해짐


	//.getCents() 를 안쓰기 위해 friend 하기
	//friend Cents operator + (const Cents& c1, const Cents& c2) 
	//{
	//	return Cents(c1.m_cents + c2.m_cents);
	//};



	//freind 하지 않고 멤버 함수로 만들어버리기
	//too many parameters : + 함수라 parameter 두개만 있으면 됨

	Cents operator + (const Cents& c2) //왼쪽 parameter 는 this 로 바꿔야함
	{
		return Cents(this->m_cents + c2.m_cents);
	};
};



//c_out 을 참조 parameter 로 받아서 output 으로 쓰기
//void add(const Cents& c1, const Cents& c2, Cents& c_out)
//{
//	c_out.getCents() = c1.getCents() + c2.getCents();
//}



//ouput 을 return type 으로 받기(최근 경향)
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}



//add() 를 쓰기 싫을때(연산자 오버로딩)
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}



//c1.getCents() 에서 getCents() 를 쓰기 싫을때, 함수를 friend 하기
//class 안으로 넣어버리기
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.m_cents + c2.m_cents);
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	//더하고 싶을때
	//add() 만들기
	/*Cents sum;
	add(cents1, cents2, sum);*/

	//cout << sum.getCents() << endl;
	//cout << sum << endl; //ch9_02


	//정수로 작업할때
	int i = 6, j = 8; cout << i + j << endl;	//편하고 깔끔함


	//output 을 return type 으로 받기
	cout << add(cents1, cents2).getCents() << endl;  //.getCents() 를 반드시 붙여줘야함


	//연산자 오버로딩
	cout << (cents1 + cents2).getCents() << endl;
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;  //익명 객체를 사용하여 Cents(6) 까지 더하기


	//getCents() 를 안쓰고 싶음
	//함수를 friend 해서 c1.getCents() 하지 않고 바로 m_value 에 접근할수 있게 friend 하기
	cout << (cents1 + cents2).getCents() << endl;  //출력할땐 써야함


	// +, -, *, / 같은거 다 연산자 오버로딩 할 수 있음
	// 우선순위는 그대로임(직관적인것들만 오버로딩 하는것이 좋음)
	// ^ 는 우선순위가 매우 낮기 때문에 ()로 싸서 써야하고 그냥 오버로딩 안하는게 편함

	//불가능한 연산자들
	// ?:		삼항연산자
	// ::		scope 연산자
	// sizeof	연산자
	// .		member selection 연산자
	// .*		member pointer 연산자

	//member function 으로만 해야 가능한 연산자들
	// = , [] , () ,->

	return 0;
}
