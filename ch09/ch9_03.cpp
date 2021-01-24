// 단항 연산자 ( + , - , ! ) 오버로딩하기

#include<iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out,const Cents& cents)
	{
		out << cents.m_cents;
		return out;	
	}

	Cents operator - () const
	{
		return Cents(-m_cents);
		//return this->m_cents;
	}

	//not operator(!) 은 return type 이 bool
	bool operator! () const
	{
		//문맥상 적절한걸 return 해야함

		// Cents 가 0 이면 !Cents() 가 true 를 return 하는 코드
		//if 문 을 쓸수도 있고 conditional operator 을 쓸수도 있음

		return (m_cents == 0) ? true : false;
	}

};

int main()
{
	
	int a = 3;
	cout << -a << endl;	//단항연산자 -
	cout << !a << endl;	//0


	Cents cents1(6);
	Cents cents2(0);

	// - operator
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(10) << endl;


	// !(not) operator
	auto temp = !cents1;  //temp 가 bool 로 잘 잡힘
	cout << cents1 << " " << cents2 << endl;
	cout << !cents1 << " " << !cents2 << endl;



	return 0;
}