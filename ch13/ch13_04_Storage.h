#pragma once

#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		std::cout << m_value << '\n';
	}


};

//double type �� ���ؼ� scinetific notation(������ ǥ���) �� ������ ������
//member function �� double type �� ���ؼ� specialization 

//template<>
//void Storage<double>::print()
//{
//	std::cout << "Double Type ";
//	std::cout << std::scientific << m_value << '\n';
//}

//�ڵ� ������ ���� cpp ���Ϸ� �ű�� ����