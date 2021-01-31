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

//double type 에 대해선 scinetific notation(과학적 표기법) 을 했으면 좋겠음
//member function 을 double type 에 대해서 specialization 

//template<>
//void Storage<double>::print()
//{
//	std::cout << "Double Type ";
//	std::cout << std::scientific << m_value << '\n';
//}

//코드 정리를 위해 cpp 파일로 옮기고 싶음