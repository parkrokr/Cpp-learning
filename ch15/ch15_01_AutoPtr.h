#pragma once

#include <iostream>

//std::autu_ptr �� ����, c++98 �� �߰���, c++11 ���� �������� �߼���, c++17 ���� ������ ������
//���� ������ ��� �۵����� �ʴ� ��찡 �߻�, r-value reference �� ���Ե� ����Ʈ �����ͷ� �Ѿ

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

	//�Ҹ��ڿ��� nullptr �� �ƴϸ� ��������
	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}


	//���� ���� �����ڿ� ���� �����ڴ� ��� ��������ڿ� ���Կ����ڰ� �ƴ�
	//�ؿ��� �����Ѱ� copy semantics �� ������ ���� �ƴ϶� move semantics �� �����Ѱ���

	//copy constructor
	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;	//�Է����� ���� (����)�����͸� nullptr �� �ٲ����
		//�̷��� �ϸ� res1 �� �������� delete �� �� �� ����
	}

	//copy assignment
	AutoPtr& operator = (AutoPtr& a)
	{
		//�Է����� ���°� �ڱ� �ڽ��� ��츦 ���
		if (&a == this)
			return *this;

		//�������� ����(move) �ǰ� ����
		delete m_ptr;		//�̹� ���� ���� ������ ����������
		m_ptr = a.m_ptr;	//���� ���� �ּҸ� �����ؼ� �ޱ�
		a.m_ptr = nullptr;	//����(������) �����Ͱ� ������ �ִ� �ּҴ� nullptr �� �ٲ����
		return *this;
	}




	//de-referencing operator overloading
	T& operator*() const { return *m_ptr; }

	//member selection operatror overloading
	T* operator->() const { return m_ptr; }
	
	bool isNull() const { return m_ptr == nullptr; }
};
