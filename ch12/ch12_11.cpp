//���� Ŭ�������� ��� ������ ����ϱ�

//friend �Լ��� �������̵��� ����(����Լ��� �������̵��� �� �� ����)
//����� ���� �� ���� �Լ��� �������̵� �Ѱ�ó�� ����ϱ� ���ؼ� 
//����� ���ӹ��� �Ϲ��Լ��� �����Լ��� ����� �ڽ�Ŭ�������� �������̵� �ϴ� ����� ����

//� ����� ����� �Ҷ� �����Լ� �������� �Ϻη� �����ؼ� ���ϴ� ������� �ڽ�Ŭ�������� ����ϴ�
//��ĵ� ���� ����� ��

#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	//frined funciton �� ����� �ƴ�
	//����� �ƴϴ� ����  �������̵��� ����
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out); //��� �Լ� print() �� ���� �ñ�
	}

	//����ȭ ���� �ڽ�Ŭ�������� �������̵� ��
	virtual std::ostream& print(std::ostream& out)const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	//���ͺ��� ouput operator �� �������̵� �Ѱ� ������ �ڼ��� ���� �׳� print() ��
	virtual std::ostream& print(std::ostream& out) const override 
	{
		out << "Derived";
		return out;
	}

	//�ڽ� Ŭ���������� ������ �����ε� �Լ��� ������ ���� �ʿ䰡 ����
};

int main()
{
	Base b;
	cout << b << '\n'; //Base
	

	Derived d;
	cout << d << '\n'; //Derived

	Base& bref = d;
	cout << bref << '\n';  //Derived
	//�θ� Ŭ������ �ִ� ������ �Լ��� ���� �ε����� ��
	//�ڽ� Ŭ������ ������ �θ�Ŭ������ ������ ��ȯ�Ǽ� ������ ������ ������, �����Լ��� ȣ���
	//�ڽ� Ŭ������ print() �� ���� �����ϰ� �����

	return 0;
}