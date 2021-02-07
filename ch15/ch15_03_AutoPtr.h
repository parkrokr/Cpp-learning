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

		//deep copy, ����������
		m_ptr = new T;
		*m_ptr = *a.m_ptr;	// Resource �� copy assignment operator �� ȣ���ϴ� �κ�
	}

	//copy assignment
	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment " << std::endl;

		//prevent self-assignment
		if (&a == this)	
			return *this;

		if (m_ptr != nullptr)delete m_ptr;

		//deep copy	 ����������
		m_ptr = new T;
		*m_ptr = *a.m_ptr;	// Resource �� copy assignment operator �� ȣ���ϴ� �κ�
		
		return *this;
	}



	//move construtor, assignment
	//paramter �� r-value reference ��, �޸𸮿� �ڸ��� ����� ������ �ƴϰ� ��� ����� ���������
	//�Լ��� return �ؼ� ������ ���� r - value, �� �ٽ� ����� ���� ����
	//deep copy �ϴ� ��ſ� r-value �� �޾Ƽ� shallow copy �� �ϰ� ����
	//�����Ͱ� �״�� �Ѿ�°�

	//a.m_ptr = nullptr; //really necessary? r-value �ϱ� ������ ������ϱ� nullptr �� �־���� �ϴ°�?
	//���� �δ��� ���̱� ���� �־��ִ°� ����
	//��� nullptr �� �ȳ����� ����� ��忡�� ����, nullptr �� �ʳ��� ����°��� �õ����� �ʵ��� ����� �ֱ�

	//copy constructor, assignmnet �� �ּ�ó�� �ȵǾ��־ �����ε��� �Ǿ move �� �����
	//�Լ��� return �� �� r-value �̱� ���� 


	//move constructor
	AutoPtr(AutoPtr&& a)		//paramter �� r-value reference ��
		:m_ptr(a.m_ptr) //�����͸� �����ϰ� ����, deep copy �� �ƴ�
	{
		a.m_ptr = nullptr;		// really necessary?  ���� �ִ°� ����

		std::cout << "AutoPtr move constructor " << std::endl;
	}

	
	//move assignment
	AutoPtr& operator=(AutoPtr&& a)		//paramter �� r-value reference ��
	{
		std::cout << "AutoPtr move assignment " << std::endl;

		if (&a == this)			// prevent self-assignment
			return *this;


		if (!m_ptr) delete m_ptr;


		//shallow copy, �ǹ̻�(semantics)���δ� move �� ��
		m_ptr = a.m_ptr;		//�����͸� �����ϰ� ����, deep copy �� �ƴ�

		a.m_ptr = nullptr;		//really necessary?	 ���� �ִ°� ����

		return *this;
	}




	//de-referencing operator overloading
	T& operator*() const { return *m_ptr; }

	//member selection operatror overloading
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};
