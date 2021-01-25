#pragma once


//#include <string>  // ���ֵ� ��� ���� ��,������ �����
#include"Ch11_02_Person.h" //string �� Person �� �ְ� �θ� Ŭ������ Person �� include �ϸ� ��

class Teacher : public Person
{
private:
	//std::string m_name;  //Person class �� m_name �� ����
	

public:
	Teacher(const std::string& name_in = "No Name")
		: Person(name_in)
	{
	}

	// m_name �� �ʹ� �ǵ帮�� ���� ����, setName() �� getName() �� Teacher �� Student ���� ��ħ
	//Person ���� �ű�
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
		//out << teacher.m_name;  //Person ���� private ���� �����ֱ� ������ ���� ������ ����
		//m_name �� public �̳� protected �� �����ؼ� ������ �� ���� ����

		out << teacher.getName();
		//Teacher �� const �� ������ �ֱ� ������ �θ�Ŭ������ Person �� getName() �� const �̸� ��
		return out;
	}




};