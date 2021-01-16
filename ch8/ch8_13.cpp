 //�͸� anonymous ��ü

//r-vlaue ó�� �۵���,�ѹ� ���� �������(�Ҹ��� ȣ��) ������ ���� ����

#include <iostream>
using namespace std;

class A
{
public:
	A()	
	{
		cout << "constructor" << endl;
	}

	~A()
	{
		cout << "destructor" << endl;
	}

	void print()
	{
		cout << "Hello" << endl;
	}
};

class B
{
public:
	int m_value;


	B(const int& input)
		:m_value(input)
	{
		cout << "constructor" << endl;
	}

	~B()
	{
		cout << "destructor" << endl;
	}

	void print()
	{
		cout << "Hello" << m_value << endl;
	}
};


class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	int getCents() const { return m_cents; }  //member variable �� �ٲ��� �ʴ� const �Լ�
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents()); //�ΰ��� ���� ����� ���� Cents �� ����� return
}

int main()
{
	//print() �� �ϱ� ���� �̷��� �ϴ°� ���ŷο� �� ����
	//a �� print() ����� ���̻� ������� ����
	
	A a;
	a.print();
	a.print();
	//�����ڿ� �Ҹ��ڰ� �ѹ����� ȣ���
	

	A().print();  //A() �� r-vlaue ó�� �۵���,�ѹ� ���� �������(�Ҹ��� ȣ��) ������ ���� ����
	A().print();
	//�����ڿ� ȣ���ڰ� �ι��� ȣ���


	//member variable �� ���� ���
	B b(1);
	b.print();

	B(1).print();




	//add() �� Cents �� return �ϱ� ������ .getCents() �� ��� ����
	cout << add(Cents(6), Cents(8)).getCents() << endl;

	cout << int(6) + int(8) << endl;	//������ �����ε��� ���缺

	return 0;
}