#pragma once

//#include <iostream>
//#include <string>
#include "Ch11_02_Person.h"

class Student : public Person
{
private:
	//std::string m_name; 
	//Student 와 Teacher 의 m_name 이 중복되고 있어서 일반화 시켜서 Pesrson 에 뽑았기 때문에 빼도 됨
	
	
	int m_intel;  //intelligence
	int m_happy = 0;  //happiness

	

public:
	//m_name 을 관리하는 1차 책임은 Person 에 있음
	//생성자 호출 순서상 Student 가 생성이 되는 상황에서 m_name 은 아직 정리가 안되어 있음
	//그래서 생성자는 부모 클래스인 Person 에서 담당해줘야 함
	//결국은 Student의 생성자 에서 Person 의 생성자를 호출해서 간접적으로 초기화함


	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		//: m_name(name_in), m_intel(intel_in) //m_name 을 직접 초기화 하려고 하니 에러 발생
		: Person(name_in), m_intel(intel_in) //"No Name" 이 default constructor 가 없어서 문제가 생김
	{}

	
	// m_name 을 너무 건드리는 곳이 많음, setName() 과 getName() 이 Teacher 과 Student 에서 겹침
	//Person 으로 옮김
	/*void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}*/

	
	//밑에 함수들은 Person 엔 없고 Student class 만 갖고 있는 고유의 멤버 변수인 m_intel과 m_happy 를
	//가지고 있기 때문에 Person 으로 옮기면 안되고 그대로 둬야함
	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	void setHappy(const int& happy_in)
	{
		m_happy = happy_in;
	}

	int getIntel()
	{
		return m_intel;
	}

	int getHappy()
	{
		return m_happy;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		out << student.getName() << " " << student.m_intel << " " << student.m_happy;
		return out;
	}
};