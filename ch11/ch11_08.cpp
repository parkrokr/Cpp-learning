//��ӹ��� �Լ� ( Inherited Functions ) �� ���߱�

//��ӹ����� ������� �ʵ��� ����

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		:m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}

	friend std::ostream& operator <<(std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d = 0;
public:
	Derived(int value)
		:Base(value)
	{}

	//Base ���� protected �� m_i �� �̷��� �ϸ� Derived ���� public �� �Ǿ����
	using Base::m_i;


	//Base �� print() �� �ۿ��� ������ ���ƹ�����
	//delete �ϱ�
	void print() = delete;

	//private: ���� using �ϱ�
private:
	//using Base::print;  //�̶��� �̸��� ������ �Ǳ� ������ ()�� ġ�� �ȵ�
};

int main()
{
	Base base(5);
	Derived derived(7);
	
	//m_i �� Base �� protected �� ����Ǿ��� ������ �ۿ��� ���� ����
	//Derived class ���� using Base::m_i; �� �ϸ� ����
	derived.m_i = 1024;

	//Derived �� Base �κ��� ��ӹ��� print() �� �ۿ��� ������ ���ƹ��� �� ����
	//derived.print();  //��������
	base.print();		//�̰� ����(�ڽĿ����� ���ұ� ������ �θ𿡼��� ���� ����)

	return 0;
}