#pragma once

#pragma once
#include <iostream> 
#include <assert.h> //for assert()


//m_length 대신에 unsigned int T_SIZE 사용,
//이렇게 하면 컴파일 타임에 T_SIZE 가 결정되어있음
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	//int m_length;  //대신에 unsigned int T_SIZE 사용

	T* m_data;
	
	//T_SIZE 가 compile time 에 결정이 되니 
	//T m_data[T_SIZE]; 
	//이렇게도 할수 있지만 stack 에는 큰 사이즈가 못들어가기 때문에 동적 할당을 쓰는게 좋음


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

	//ch13_02 에서 print()를 cpp 로 빼고 explicit 을 했지만
	//지금 여기선 T_SIZE 가 unsigned int 중 어떤 숫자든 가능해야 하기 때문에
	//explicit instantiation 을 해야 한다면 들어올 수 있는 숫자에 대해서 다 해줘야 하기 때문에
	//아주 어려워짐
	//그래서 Non-type parameter 를 사용할때는 전부 헤더에만 둠
	void print()
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	//헤더 온리 라이브러리 라고 하는 오픈소스들이 많이 있는데
	//헤더에만 몰아둠
};



