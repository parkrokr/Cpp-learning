//��ӹ��� �Լ� (Inherited Funcions ) �� �������̵� (Overriding) �ϱ�

//�θ� Ŭ������ �ִ� �Լ��� �ڽ� Ŭ�������� ����� �߰��ϱ� ���� ���� �����ؼ� ����ϴ°��� �������̵��̶�� ��

//fried �Լ��� �������̵� �ϴ¹�( static_cast �� cast �ϱ�)

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

	//output operator overloading
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

	//Derived �� print() �� ���� ��� �θ�Ŭ������ print() �� ȣ��Ǿ� "I'm base" ��µ�
	//Base �� print() �� ��������� �ణ �ٸ�, �̰�� Derived �� print() �� ȣ���
	void print()
	{
		//�θ�Ŭ������ �ִ°� �����ϰ� �߰��� �ڱⰡ �ִ°� �����ϰ� ����(�Լ� �̸��� ����)
		//�Լ��̸��� �׳� �ٸ��� �ع��� ���� ������ ������ ��Ʈ���� �ʿ���

		Base::print(); //�θ� Ŭ������ �ִ� print() ȣ��, �տ� �θ� Ŭ���� �̸��� ���ָ� ��

		cout << "I'm derived" << endl; //�߰��� �ڽ� Ŭ�������� ����� ����

		//print(); �Ǽ��� �̷��� ȣ���� ��� ���ȣ���� �Ǿ���� ���ѷ����� ������ ��
	}
	
	//output operator overloading overriding
	friend std::ostream& operator <<(std::ostream& out, const Derived& b)
	{
		//��� ������ �������̵��ϱ�,Ư�� friend �϶�
		//b�� static_cast�� �̿��ؼ� Base �� cast �ϱ�(Derived �� �޸𸮿� Base �� ������ ���� �ֱ� ������)
		out << static_cast<Base>(b);

		out << "This is derived output" << endl;
		return out;
	}

};

int main()
{
	//�Լ� �����ε�
	Base base(5);
	base.print();

	Derived derived(7);
	derived.print();

	//������ �����ε� �������̵�
	cout << base;
	cout << derived;

	return 0;
}