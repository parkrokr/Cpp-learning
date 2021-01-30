#pragma once
#include <iostream> 
#include <assert.h> //for assert()



//�Ϲ�ȭ ��Ű��  

//template �� �Ű������� class �� �ƴҼ� �ֱ� ������ typename �� ���� �Ϲ���
//typename ��ſ� class �� �ᵵ ���� �������� ���� ����
//T�� ������ó�� �����ϸ� �ǰ� �Լ��� �Ϲ�ȭ�ϱ� ���ؼ� ������ ���ؼ� �����ϴ°�ó�� 
//�Է����� �����°� �Ű������� �ϵ���
//���ø�ȭ(templatize) �Ҷ� ��� type �� ���� �Ű�������� ������ �� ����


template<typename T>		
class MyArray
{
private:
	int m_length;
	//int* m_data;
	//int �� ���� ���� double, float, bool, . . . �� ��� �Ϲ�ȭ

	T* m_data;


public:
	MyArray()
	{
		m_length = 0;
		m_data = nullptr;
	}

	MyArray(int length)
	{
		//m_data = new int[length];
		m_data = new T[length];
		m_length = length;
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	//int& operator[](int index)
	T & operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
		//index �� ������ �� index �� �ش��ϴ� int �� data �� ������ ��ȯ
		//���ø�ȭ ��Ų�� T �� �ٲ��ֱ�(������ int �� ������ �־��� ������)
	}

	int getLength()
	{
		return m_length;
	}

	void print();

	//����� class �ȿ� �ڵ尡 �� �ִ°� ������� class ������ ���� ���� move definition location �� ��
	/*void print()  
	{
		for (int i = 0; i < m_length; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}*/
};


//move definition loacation �� ������ �׳� MyArray.h �� ����

//�� Ŭ������ ���ø�ȭ�� ���� �ʾҾ��ٸ�
//�ؿ� ó�� �Ǿ�������
//void MyArray::print()
//{
//	. . .
//}


//������ template �̱� ������
/*template<typename T>		//template paramter �� ����ְ�
void MyArray<T>::print()	//���⵵ template paramter �� �������
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}*/

//�̿� definition �� ������ cpp ���Ϸ� �ű��?
//��ŷ ���� �߻�!


//��ŷ ���� ��ü�� �����Ϸ����� ��� ������ �߻��ߴ��� �˷����� �ʱ� ������ ����� ������ ����

//main() �ִ� cpp ���� include "MyArray.h"�� �ϸ� ���빰�� ���� main.cpp �� �����ؼ� �ٿ��ֱ�
// �Ѱ�ó�� �۵���

//MyArray<char> my_array(10); �� �ϸ� MyArray ��� class �� char type �� ���ؼ�
// instantiation�� �ؾߵǴ±��� ���� �����Ϸ��� ������

//print() ��� ����Լ��� body �� ������ �Ҷ���  MyArray.cpp ���� �������� ��

//main.cpp ������ MyArray.h �� include �ϱ� ������ MyArray.cpp �� �ִ� ������ ��
//�׷��� MyArray.cpp �� �ִ� �Լ��� instantiation �� �Ҷ� char type ���� �ؾߵȴٴ°� ��


//����: main.cpp ���� �������� �Ҷ� MyArray.cpp���� � type ���� instantiation ���� ��
