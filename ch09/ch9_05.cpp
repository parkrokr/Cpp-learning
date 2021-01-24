// 증감 연산자 ( ++, -- ) 오버로딩하기

//전위 연산자(prefix) 는 단순한 산술식이지만 후위 연산자(postfix) 임시(Temp) 객체 생성, 초기화, 전위형 증강연산자
//호출등의 추가 처리가 필요하기 때문에 전위형이 더 효율적이고 속도도 빠름( for 문에서 ++i 를 추천하는 이유(유의미한 차이 x))

//전위형은 레퍼런스로 return 한다(chaining을 위해)
//후위형의 경우 전위형과의 구분을 위해 dummy int 를 사용한다
//값을 먼저 return 하고 바꿔야 하므로 객체 자체를 return 하지 못하고 값만 return 한다(참조를 반환하면 경고)


//			멤버 함수				전역 함수
//전위형		Digit& operator ++()	Digit &operator ++ (T &t)
//후위형		Digit operator ++(int)	Digit operator ++ (T &t, int)

#include<iostream>

using namespace std;

//이 예제는 0~9 만 가능함, 9에 1을 더하면 0, 0에서 1을 빼면 9로 돌아감
class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit) {}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}

	//전위형 prefix
	Digit& operator ++ ()
	{
		++m_digit;

		return *this;
	}

	//후위형 postfix
	//prefix 와 구분하기 위해 parameter 로 dummy 로 int 하나 넣어줌
	Digit operator ++ (int)  //const Digit operator ++ (int) 가능
	{
		//일단 return 을 하고 값을 바꿔줘야함
		Digit temp(m_digit);

		++(*this);	//++m_digit; 이렇게 할수도 있지만 ++를 위에서 만들었으니

		return temp;
	}

};

int main()
{
	int a = 10;

	cout << ++a << endl;  //전위형 : 계산을 먼저 하고 출력함
	cout << a << endl;
	cout << a++ << endl;  //후위형 : 출력을 먼저 하고 계산함
	cout << a << endl;


	//prefix
	Digit d(5);

	cout << ++d << endl;
	cout << d << endl;


	//postfix
	cout << d++ << endl;
	cout << d << endl;
	return 0;
}