#pragma once

#pragma once
#include <iostream> 
#include <assert.h> //for assert()


//m_length ��ſ� unsigned int T_SIZE ���,
//�̷��� �ϸ� ������ Ÿ�ӿ� T_SIZE �� �����Ǿ�����
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	//int m_length;  //��ſ� unsigned int T_SIZE ���

	T* m_data;
	
	//T_SIZE �� compile time �� ������ �Ǵ� 
	//T m_data[T_SIZE]; 
	//�̷��Ե� �Ҽ� ������ stack ���� ū ����� ������ ������ ���� �Ҵ��� ���°� ����


public:
	MyArray()
	{
		m_data = new T[T_SIZE];
	}

	~MyArray()
	{
		delete[] m_data;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	//ch13_02 ���� print()�� cpp �� ���� explicit �� ������
	//���� ���⼱ T_SIZE �� unsigned int �� � ���ڵ� �����ؾ� �ϱ� ������
	//explicit instantiation �� �ؾ� �Ѵٸ� ���� �� �ִ� ���ڿ� ���ؼ� �� ����� �ϱ� ������
	//���� �������
	//�׷��� Non-type parameter �� ����Ҷ��� ���� ������� ��
	void print()
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	//��� �¸� ���̺귯�� ��� �ϴ� ���¼ҽ����� ���� �ִµ�
	//������� ���Ƶ�
};



