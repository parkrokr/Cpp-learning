#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
public:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
		std::cout << "AutoPtr default construcotr "<< std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor " << std::endl;

		if (m_ptr != nullptr) delete m_ptr;
	}


	//copy constructor
	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor "<< std::endl;

		//deep copy, 느려질것임
		m_ptr = new T;
		*m_ptr = *a.m_ptr;	// Resource 의 copy assignment operator 를 호출하는 부분
	}

	//copy assignment
	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment " << std::endl;

		//prevent self-assignment
		if (&a == this)	
			return *this;

		if (m_ptr != nullptr)delete m_ptr;

		//deep copy	 느려질것임
		m_ptr = new T;
		*m_ptr = *a.m_ptr;	// Resource 의 copy assignment operator 를 호출하는 부분
		
		return *this;
	}



	//move construtor, assignment
	//paramter 가 r-value reference 임, 메모리에 자리를 제대로 잡은게 아니고 잠깐 생겼다 사라질것임
	//함수가 return 해서 들어오는 값은 r - value, 즉 다시 사용할 일이 없음
	//deep copy 하는 대신에 r-value 만 받아서 shallow copy 만 하고 있음
	//포인터가 그대로 넘어가는것

	//a.m_ptr = nullptr; //really necessary? r-value 니까 어차피 사라지니까 nullptr 을 넣어줘야 하는가?
	//위험 부담을 줄이기 위해 넣어주는게 좋음
	//사실 nullptr 을 안넣으면 디버거 모드에선 에러, nullptr 를 너놓고 지우는것을 시도하지 않도록 만들어 주기

	//copy constructor, assignmnet 가 주석처리 안되어있어도 오버로딩이 되어서 move 가 실행됨
	//함수가 return 한 건 r-value 이기 때문 


	//move constructor
	AutoPtr(AutoPtr&& a)		//paramter 가 r-value reference 임
		:m_ptr(a.m_ptr) //포인터만 복사하고 있음, deep copy 가 아님
	{
		a.m_ptr = nullptr;		// really necessary?  보통 넣는게 좋음

		std::cout << "AutoPtr move constructor " << std::endl;
	}

	
	//move assignment
	AutoPtr& operator=(AutoPtr&& a)		//paramter 가 r-value reference 임
	{
		std::cout << "AutoPtr move assignment " << std::endl;

		if (&a == this)			// prevent self-assignment
			return *this;


		if (!m_ptr) delete m_ptr;


		//shallow copy, 의미상(semantics)으로는 move 가 됨
		m_ptr = a.m_ptr;		//포인터만 복사하고 있음, deep copy 가 아님

		a.m_ptr = nullptr;		//really necessary?	 보통 넣는게 좋음

		return *this;
	}




	//de-referencing operator overloading
	T& operator*() const { return *m_ptr; }

	//member selection operatror overloading
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};
