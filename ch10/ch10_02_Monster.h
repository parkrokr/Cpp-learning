#pragma once

//#include <iostream>  //Position2D �� include �ϸ� iostream �� �ȿ� �������
#include <string>
#include "ch10_02_Position2D.h"

class Monster
{
private:
	std::string m_name;
	
	//location
	//std::string �� char* data �� unsigned length �� ���� ����
	//location �� int m_x,�� m_y�� ��� ����ϱ� ( class ���� ����� ) 
	//int m_x; 
	//int m_y;
	Position2D m_location;


public:
	//Position2D �� �����ϱ� ��
	/*Monster(const std::string name_in, const int & x_in, const int & y_in)
		:m_name(name_in), m_x(x_in), m_y(y_in)
	{}*/

	//���� �� ��
	Monster(const std::string name_in, const Position2D & pos_in)
		: m_name(name_in), m_location(pos_in)
	{}


	//Position2D �� �����ϱ� ��
	/*void moveTo(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}*/

	//���� �� ��
	void moveTo(const Position2D& pos_target)
	{
		//m_location.set(pos_target);
		m_location = pos_target; //= operator overloading
	}

	//output operator overloading
	friend std::ostream& operator << (std::ostream& out, const Monster& monster)
	{
		//out << monster.m_name << monster.m_x << " " << monster.m_y << std::endl;

		//Position2D ������ operator overloading �� ����� ������
		out << monster.m_name << " " << monster.m_location; //endl �ߺ�
		return out;
	}
};