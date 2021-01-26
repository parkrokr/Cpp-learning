#pragma once

//class 를 따로 만드는 툴이 없는 경우 Class Wizard 가 꽤 쓸모 있음
//class wizard 의 Add Class... 의 MFC Class... 는 MFC library 를 쓰는거라(UI 만들때 사용함), 윈도우 전용
//Base class: 는 부모(Mother) class 를 의미함, Class declaration 은 부모 클래스를 의미함 
//나중에는 클래스들을 만들때 부모 클래스를 먼저 만들게 됨


#include <string>
#include <iostream>
//헤더에선 using namspace std; 를 안쓰는게 좋음
//cpp 파일로 뺀 경우엔 using namespace std;를 써도 됨
//자식 클래스에서 부모 클래스를 include 하기 때문에 std 들은 부모클래스에 주로 많이 있음

class Person
{
	
private: //public: 은 class 밖 뿐만 아니라 자식 클래스에서도 접근을 못하게 막음
	//Teacher class 와 Student class 의 m_name 이 겹침
	std::string m_name;

	//m_name 을 관리하는 1차 책임은 Person 에 있음
	//생성자 호출 순서상 Student 가 생성이 되는 상황에서 m_name 은 아직 정리가 안되어 있음
	//그래서 생성자는 부모 클래스인 Person 에서 담당해줘야 함
	//private: 으로 생성자를 만드는 경우는 아예 쓰지 못하게 하려고 막아버린 경우거나
	//디자인 패턴중 싱글톤 패턴에서 private 으로 생성자를 호출 못하게 막아버린 경우도 있음

public:
	Person (const std::string &name_in = "No Name") //해결 방법 2 : 생성자에  default 값으로 넣어줌
		:m_name(name_in)
	{}
	//상속을 하든말든 상속을 받는쪽에서 m_name 을 받아서 사용을 할 수 있다고 한들 
	//관리 책임은 부모 클래스인 Person 이 가지고 있음


	//Student 의 생성자에서 "No Name" 이 default constructor 가 없어서 문제가 생김
	//parameter 가 있는 constructor 를 만들어서 default constructor 이 생성이 안됨

	//해결 방법 1 : parameter 가 없는 default constrtuctor 를 하나 만듬
	/*Person()
		:m_name("No Name")
	{}*/



	// m_name 을 너무 건드리는 곳이 많음, setName() 과 getName() 이 Teacher 과 Student 에서 겹침
	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}


	//Teacher 와 Student 의 <<오버로딩에서 각각 클래스들을 const 로 받고 있기 때문에 getName() 도 const 로 바꾸기
	//똑같은 문제가 Teacher 와 Student 에서 일어나는데 Person 에서만 고쳐주면 해결됨
	std::string getName() const
	{
		return m_name;
	}


	//새로운 기능
	void doNothing() const
	{
		std::cout << m_name << " is doing nothing " << std::endl;
	}
	

};
