#pragma once

#include <iostream>

class Position2D
{
private:
	int m_x;
	int m_y;

public:
	Position2D(const int& x_in, const int & y_in)
		:m_x(x_in), m_y(y_in)
	{}

	

	//parameter �� �ΰ��� �ް� �־ Monster.h �� moveTo() ���� ���� �߻�
	void set(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	void set(const Position2D& pos_target)
	{
		set(pos_target.m_x, pos_target.m_y);
		//m_x = pos_target.m_x;
		//m_y = pos_target.m_y; �Ҽ��� ������ set �� ����� ��ġ�� ��Ȱ�� �ϴ°� ����
	}

	//output operator overloading
	friend std::ostream& operator << (std::ostream& out, const Position2D& pos2d)
	{
		out << pos2d.m_x << " " << pos2d.m_y; //endl; �ߺ�
		return out;
	}

	//assignment operator overloading
	Position2D& operator = (const Position2D& location)
	{
		set(location.m_x, location.m_y);

		return *this;
	}
};