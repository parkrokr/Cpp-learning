#pragma once

//#include <iostream>  //Position2D 를 include 하면 iostream 이 안에 들어있음
#include <string>
#include "ch10_02_Position2D.h"

class Monster
{
private:
	std::string m_name;
	
	//location
	//std::string 도 char* data 와 unsigned length 로 묶여 있음
	//location 도 int m_x,와 m_y를 묶어서 사용하기 ( class 새로 만들기 ) 
	//int m_x; 
	//int m_y;
	Position2D m_location;


public:
	//Position2D 를 구현하기 전
	/*Monster(const std::string name_in, const int & x_in, const int & y_in)
		:m_name(name_in), m_x(x_in), m_y(y_in)
	{}*/

	//구현 한 후
	Monster(const std::string name_in, const Position2D & pos_in)
		: m_name(name_in), m_location(pos_in)
	{}


	//Position2D 를 구현하기 전
	/*void moveTo(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}*/

	//구현 한 후
	void moveTo(const Position2D& pos_target)
	{
		//m_location.set(pos_target);
		m_location = pos_target; //= operator overloading
	}

	//output operator overloading
	friend std::ostream& operator << (std::ostream& out, const Monster& monster)
	{
		//out << monster.m_name << monster.m_x << " " << monster.m_y << std::endl;

		//Position2D 에서도 operator overloading 을 해줬기 때문에
		out << monster.m_name << " " << monster.m_location; //endl 중복
		return out;
	}
};