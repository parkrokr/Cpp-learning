#pragma once

//#include <iostream>
//#include <string>
#include "Ch11_02_Person.h"

class Student : public Person
{
private:
	//std::string m_name; 
	//Student �� Teacher �� m_name �� �ߺ��ǰ� �־ �Ϲ�ȭ ���Ѽ� Pesrson �� �̾ұ� ������ ���� ��
	
	
	int m_intel;  //intelligence
	int m_happy = 0;  //happiness

	

public:
	//m_name �� �����ϴ� 1�� å���� Person �� ����
	//������ ȣ�� ������ Student �� ������ �Ǵ� ��Ȳ���� m_name �� ���� ������ �ȵǾ� ����
	//�׷��� �����ڴ� �θ� Ŭ������ Person ���� �������� ��
	//�ᱹ�� Student�� ������ ���� Person �� �����ڸ� ȣ���ؼ� ���������� �ʱ�ȭ��


	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		//: m_name(name_in), m_intel(intel_in) //m_name �� ���� �ʱ�ȭ �Ϸ��� �ϴ� ���� �߻�
		: Person(name_in), m_intel(intel_in) //"No Name" �� default constructor �� ��� ������ ����
	{}

	
	// m_name �� �ʹ� �ǵ帮�� ���� ����, setName() �� getName() �� Teacher �� Student ���� ��ħ
	//Person ���� �ű�
	/*void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}*/

	
	//�ؿ� �Լ����� Person �� ���� Student class �� ���� �ִ� ������ ��� ������ m_intel�� m_happy ��
	//������ �ֱ� ������ Person ���� �ű�� �ȵǰ� �״�� �־���
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