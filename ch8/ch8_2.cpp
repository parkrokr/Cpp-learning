//캡슐화 Encapsulation , 접근 지정자 Access Specifiers, 접근 함수 Access Functions

//뛰어난 프로그래머는 복잡한걸 단순하게 보이도록 정리를 잘하고 연결관계를 깔끔하게 정리하는 사람


//같은 class 안에 있는 멤버는 다른 멤버에 접근 할 수 있음


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
//public:  //  access specifier 접근 지정자, 없으면 main() 같은 class 밖에서 member 에 접근 못함

	//private : 로 하면 밖에서 접근 못함
	//아무것도 쳐주지 않으면 private : 가 기본

	//private : 일때는 밖에서 접근할때 접근 함수(Access Functions )라는 특별한 방법을 통해 접근해 줘야함
	//장기적으로 그때그때 접근 함수들을 구현해주는게 좋음
	//오픈소스, 회사 코드 에선 private를 엄격하게 지키는경우가 많음
	//오픈소스에선 private 이 안보이는 코드도 많음, 기본이 private 이기 때문에

	int m_month;
	int m_day;
	int m_year;


	//access function

	//같은 class 의 멤버라면 자기자신이 public 이라도 private 에 접근할 수 있음
public:

	//setters
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}


	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	void setDay(const int& day_input)
	{
		m_day = day_input;
	}

	void setYear(const int& year_input)
	{
		m_year = year_input;
	}


	//출력하기 위해 보통 get() 도 만들어줌
	//value 복사를 막기 위해 reference , get() 이 값을 바꾸는걸 막기 위해 const
	//이렇게 값을 얻기 위한 get() 들을 getters 라고 부름
	const int& getDay()
	{
		return m_day;
	}

	const int& getMonth()
	{
		return m_month;
	}

	const int& getYear()
	{
		return m_year;
	}



	//값을 복사하는 함수
	//자기 자신을 parameter 로 받음, 변경 못하게 const
	void copyfrom(const Date& original)
	{
		// original 의 멤버는 original 안에서 private 지만 
		//다른 instance 의 멤버함수에서 접근하고 할 수있음
		
		//today 와 copy 는 같은 Date 라는 class 로부터 만들어지긴 했지만
		//다른 메모리 주소를 가지고 있는 다른 존재, instace 임
		//다른 메모리라도 같은 class 에서 나왔으면 가져다 쓸 수 있음
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}

	//그냥 메모리 통째로 복사하는 방법등 더 쉬운 방법들이 있지만 이렇게 수동으로 하는 이유는
	//보통 class 를 만드는 이유는 복잡한걸 만들기 위함인데 그때 실수하는걸 방지하고자 하는것

};

int main()
{
	Date today; //{ 1,12,2021 };

	//public : 을 class 안에 쳐주지 않으면  main() 에서 class Date 에 접근할 수 없음
	/*today.m_month = 1;
	today.m_day = 12;
	today.m_year = 2021;*/

	today.setDate(1, 12, 2021);
	today.setMonth(2);

	//출력하기 위해 보통 get() 도 만들어줌
	cout << today.getDay() << endl;

	//today 를 복사하고 싶음
	Date copy;

	//copy.setDate(today.getMonth(), today.getDay(), today.getYear()); // 이렇게 치긴 너무 복잡함

	//copyfrom() 을 만들거나 setDate 를 오버로딩해서 만들어도 됨
	copy.copyfrom(today);




	//getter(), setter() 를 만들어야 멤버 관리가 편함
	//멤버 변수명을 바꿔도 access function 만 밖에서 바꿀 수 있게 만들어두면
	//class 안에서 해결이 가능함
	//Encapsulation를 해두지 않고 다 public 로 선언하면 나중에 이곳저곳에서 고쳐야함
	//Visual Studio 의 rename 기능도 완벽하지 않음


	return 0;
}