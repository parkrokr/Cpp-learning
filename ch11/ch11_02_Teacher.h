#pragma once


//#include <string>  // 놔둬도 상관 없긴 함,없으면 깔끔함
#include"Ch11_02_Person.h" //string 은 Person 에 있고 부모 클래스인 Person 을 include 하면 됨

class Teacher : public Person
{
private:
	//std::string m_name;  //Person class 에 m_name 이 있음
	

public:
	Teacher(const std::string& name_in = "No Name")
		: Person(name_in)
	{
	}

	// m_name 을 너무 건드리는 곳이 많음, setName() 과 getName() 이 Teacher 과 Student 에서 겹침
	//Person 으로 옮김
	/*void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}
	*/
	

	void teach()
	{
		std::cout << getName() << " is teaching " << std::endl;
	}

	friend std::ostream& operator <<(std::ostream& out, const Teacher& teacher)
	{
		//out << teacher.m_name;  //Person 에서 private 으로 막혀있기 때문에 직접 접근을 못함
		//m_name 을 public 이나 protected 로 구현해서 접근을 할 수는 있음

		out << teacher.getName();
		//Teacher 가 const 로 들어오고 있기 때문에 부모클래스인 Person 의 getName() 이 const 이면 됨
		return out;
	}




};