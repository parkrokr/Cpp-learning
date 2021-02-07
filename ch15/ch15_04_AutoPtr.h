#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
//private:
public:
	T* m_ptr;

public:
	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
		std::cout << "AutoPtr default construcotr " << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor " << std::endl;

		if (m_ptr != nullptr) delete m_ptr;
	}


	//copy constructor
	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor " << std::endl;

		//deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;	
	}

	//copy assignment
	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment " << std::endl;

		//prevent self-assignment
		if (&a == this)
			return *this;

		if (m_ptr != nullptr)delete m_ptr;

		//deep copy	
		m_ptr = new T;
		*m_ptr = *a.m_ptr;	

		return *this;
	}



	//���� �����ڿ� ���� ���Կ����ڸ� ������ ���� ���� ������
	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator = (const AUtoPtr& a) = delete;


	//move constructor
	AutoPtr(AutoPtr&& a)		
		:m_ptr(a.m_ptr) 
	{
		a.m_ptr = nullptr;		

		std::cout << "AutoPtr move constructor " << std::endl;
	}


	//move assignment
	AutoPtr& operator=(AutoPtr&& a)		
	{
		std::cout << "AutoPtr move assignment " << std::endl;

		if (&a == this)			//prevent self-assignment
			return *this;


		if (!m_ptr) delete m_ptr;


		//shallow copy
		m_ptr = a.m_ptr;		
		a.m_ptr = nullptr;	

		return *this;
	}




	//de-referencing operator overloading
	T& operator*() const { return *m_ptr; }

	//member selection operatror overloading
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};
