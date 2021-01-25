#pragma once

//class �� ���� ����� ���� ���� ��� Class Wizard �� �� ���� ����
//class wizard �� Add Class... �� MFC Class... �� MFC library �� ���°Ŷ�(UI ���鶧 �����), ������ ����
//Base class: �� �θ�(Mother) class �� �ǹ���, Class declaration �� �θ� Ŭ������ �ǹ��� 
//���߿��� Ŭ�������� ���鶧 �θ� Ŭ������ ���� ����� ��


#include <string>
#include <iostream>
//������� using namspace std; �� �Ⱦ��°� ����
//cpp ���Ϸ� �� ��쿣 using namespace std;�� �ᵵ ��
//�ڽ� Ŭ�������� �θ� Ŭ������ include �ϱ� ������ std ���� �θ�Ŭ������ �ַ� ���� ����

class Person
{
	
private: //public: �� class �� �Ӹ� �ƴ϶� �ڽ� Ŭ���������� ������ ���ϰ� ����
	//Teacher class �� Student class �� m_name �� ��ħ
	std::string m_name;

	//m_name �� �����ϴ� 1�� å���� Person �� ����
	//������ ȣ�� ������ Student �� ������ �Ǵ� ��Ȳ���� m_name �� ���� ������ �ȵǾ� ����
	//�׷��� �����ڴ� �θ� Ŭ������ Person ���� �������� ��
	//private: ���� �����ڸ� ����� ���� �ƿ� ���� ���ϰ� �Ϸ��� ���ƹ��� ���ų�
	//������ ������ �̱��� ���Ͽ��� private ���� �����ڸ� ȣ�� ���ϰ� ���ƹ��� ��쵵 ����

public:
	Person (const std::string &name_in = "No Name") //�ذ� ��� 2 : �����ڿ�  default ������ �־���
		:m_name(name_in)
	{}
	//����� �ϵ縻�� ����� �޴��ʿ��� m_name �� �޾Ƽ� ����� �� �� �ִٰ� �ѵ� 
	//���� å���� �θ� Ŭ������ Person �� ������ ����


	//Student �� �����ڿ��� "No Name" �� default constructor �� ��� ������ ����

	//�ذ� ��� 1 : parameter �� ���� default constrtuctor �� �ϳ� ����
	/*Person()
		:m_name("No Name")
	{}*/



	// m_name �� �ʹ� �ǵ帮�� ���� ����, setName() �� getName() �� Teacher �� Student ���� ��ħ
	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}


	//Teacher �� Student �� <<�����ε����� ���� Ŭ�������� const �� �ް� �ֱ� ������ getName() �� const �� �ٲٱ�
	//�Ȱ��� ������ Teacher �� Student ���� �Ͼ�µ� Person ������ �����ָ� �ذ��
	std::string getName() const
	{
		return m_name;
	}


	//���ο� ���
	void doNothing() const
	{
		std::cout << m_name << " is doing nothing " << std::endl;
	}
	

};