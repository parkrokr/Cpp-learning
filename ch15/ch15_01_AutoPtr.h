#pragma once

#include <iostream>

//std::autu_ptr 이 있음, c++98 에 추가됨, c++11 부터 없어지는 추세고, c++17 부터 완전히 없어짐
//좀더 복잡한 경우 작동하지 않는 경우가 발생, r-value reference 가 도입된 스마트 포인터로 넘어감

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	//소멸자에서 nullptr 이 아니면 지워버림
	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}


	//밑의 복사 생성자와 대입 연산자는 사실 복사생성자와 대입연산자가 아님
	//밑에서 구현한건 copy semantics 를 구현한 것이 아니라 move semantics 를 구현한것임

	//copy constructor
	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;	//입력으로 들어온 (원래)포인터를 nullptr 로 바꿔버림
		//이렇게 하면 res1 이 지워질때 delete 를 할 수 없음
	}

	//copy assignment
	AutoPtr& operator = (AutoPtr& a)
	{
		//입력으로 들어온게 자기 자신을 경우를 대비
		if (&a == this)
			return *this;

		//소유권이 이전(move) 되고 있음
		delete m_ptr;		//이미 뭔가 갖고 있으면 지워버리기
		m_ptr = a.m_ptr;	//새로 들어온 주소를 복사해서 받기
		a.m_ptr = nullptr;	//들어온(원래의) 포인터가 가지고 있던 주소는 nullptr 로 바꿔버림
		return *this;
	}




	//de-referencing operator overloading
	T& operator*() const { return *m_ptr; }

	//member selection operatror overloading
	T* operator->() const { return m_ptr; }
	
	bool isNull() const { return m_ptr == nullptr; }
};
