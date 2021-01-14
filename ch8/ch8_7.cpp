//this 포인터와 연쇄 호출 Chaining Member Functions

//각 instance 들이 자기들의 포인터를 가지고 있고 그 포인터를 보기 위해 this 라는 키워드를 사용
//this 들은 생략되어 있음

#include<iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);	
		//this->setID(id); 와 같이 this-> 숨어있음, 현재 주소를 가지고 있는 instance 에서 setID() 를 사용한다
		//(&this).setID(id) 와 같은 표현, 이렇게 잘 쓰진 않음

		//this 를 이용하여 member variable 접근
		this->m_id; //현재 주소를 가지고 있는 this의 주소 안에 들어있는 m_id 에 접근

		
		//생성될때 자기 자신의 주소 찍어보게 하기
		cout << this << endl; //this 키워드를 사용하면 자기 자신의 주소를 class 안에서 볼 수 있음
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }

};

//Chaining Member Functions
//계산하는 함수
class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		:m_value(init_value)
	{}

	//void add(int value) { m_value += value; }  // 더하기 함수
	//void sub(int value) { m_value -= value; }  // 빼기 함수
	//void mult(int value) { m_value *= value; }  // 곱하기 함수
	
	//Chaining Member Functions
	//자기 자신을 reference 로 return
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }


	void print()
	{
		cout << m_value << endl;
	}
};
int main()
{
	Simple s1(1), s2(2);

	s1.setID(2);
	s2.setID(4);

	//setID() 같은 함수들은 각각 따로 만들어둔게 아니라 하나를 만들어두고 중복해서 사용함
	// Simple::setID()가 어딘가에 저장되어 있고 호출이 될때 Simple::setID(&s1, 1) 와 같이 
	//s1의 포인터와 필요한 인자를 넣어줌,  문법상 Simple::setID(&s1, 1)이렇게 쓸 순 없음

	//마찬가지로 s2 도 Simple::setID(&s2, 4)와 s2.setID(4) 는 동일하지만 문법상 오른쪽만 사용가능

	//s1 과 s2 를 구별하는 방법 : 주소찍기
	cout << &s1 << " " << &s2 << endl;


	//각 instance 들이 자기들의 포인터를 가지고 있고 그 포인터를 보기 위해 this 라는 키워드를 사용
	



	//Chaining Member Functions
	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2);

	cal.print();
	//이렇게 치기가 번거로움

	Calc cal1(10);
	cal1.add(10).sub(1).mult(2).print();  //동일한 결과나옴
	
	Calc(10).add(10).sub(1).mult(2).print(); //이것도 가능

	//아래와 동일
	Calc cal2(10);
	Calc& temp1 = cal2.add(10);
	Calc& temp2 = temp1.sub(1);
	Calc& temp3 = temp2.mult(2);
	temp3.print();


	//실용성에 대해선 논란이 있음( c++ 입장에서)
	

	return 0;
}
