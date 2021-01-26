//유도된 ( Derived ) 클래스들의 생성과 초기화

#include <iostream>
using namespace std;

class Mother
{
private:
	int m_i;

public:
	Mother(const int& i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction " << endl;
	}

};

class Child : public Mother
{
public:
	float m_d; 
	//double m_d;
	//int m_temp;


public:
	Child()
		:m_d(1.0f), Mother(1024)
	{
		cout << "Child construcion" << endl;
	}
};



class A
{
public:
	A(int a)
	{
		cout << "A : " << a << endl;
	}

	~A()//소멸자는 생성자랑 비슷하지만 ~가 붙고 parameter 가 붙음
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		:A(a) //없으면 A의 기본생성자가 없어서 에러
	{
		cout << "B : " << b << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C :public B
{
public:
	C(int a, double b, char c)
		:B(a,b)
	{
		cout << "C : " << c << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};



int main()
{
	//클래스의 사이즈 찍어보기
	Child c1;

	cout << sizeof(Mother) << endl;  //4 : int 하나 들어있어서
	cout << sizeof(Child) << endl;   //8 : Mother 로부터 물려받은 4 + 자기가 가진 float( 4 )

	//패딩 ( Padding )
	//패딩 비트 때문에 m_d 가 double 인 경우 Child 의 크기는 8+4= 12 가 아닌 8 + 8 인 16 이 나옴
	//Child 에 int 형 변수를 하나 더 추가하면 8 + 8 + 8 해서 24 가 나옴
	

	//Child class가 메모리 할당을 받을때는 Mother class 에 들어있는것도 다 받기 위해 크게 받음

	//상속이 여러번 된 경우 Grand Child 는 Grand Mother 의 생성자를 직접 호출 할 수 없음


	C c(1024, 3.14, 'a'); //C c 는 선언불가능, 기본생성자가 지금 없기 때문

	//생성 순서(생성자 호출 순서) 는 A, B, C 
	//소멸 순서(소멸자 호출 순서) 는 C, B, A


	return 0;
}