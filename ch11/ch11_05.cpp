//��Ӱ� ���� ������

#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;

};


class Derived : public Base
{
public:
	Derived()
	{
		m_public = 123;
		m_protected = 123;
		//m_private = 123; �Ұ���
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		Derived::m_public;
	}
};

int main()
{
	Base base;


	//�ڽ�Ŭ������ �θ�Ŭ������ ������������ �� ������ ���ѵ������� ��

	//			�θ�Ŭ����	public		protected		private	
	//�ڽ�Ŭ����	
	//public				public		protected		private
	//protected				protected	protected		pirvate
	//private				private		private			private

	//�ڽ�Ŭ������ �θ�Ŭ������ ���������ڰ� ������ private �� �� ��� ����Ŭ���������� ���� ����
	//(private �� �� ��� �ڽ�Ŭ�������� ���� ���Ѵ� �Ŷ� ����)

	base.m_public = 123; 
	//�Ұ���
	//base.m_protected = 123;
	//base.m_private = 123;

	//Derived class
	Derived derived;
	derived.m_public = 1024;
	//�Ұ���
	//derived.m_protected;  //�ڽ�Ŭ�������� public, �� ���������ڰ� ���� protected ����
	//derived.m_private;

	return 0;
}