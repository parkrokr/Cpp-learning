//this �����Ϳ� ���� ȣ�� Chaining Member Functions

//�� instance ���� �ڱ���� �����͸� ������ �ְ� �� �����͸� ���� ���� this ��� Ű���带 ���
//this ���� �����Ǿ� ����

#include<iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);	
		//this->setID(id); �� ���� this-> ��������, ���� �ּҸ� ������ �ִ� instance ���� setID() �� ����Ѵ�
		//(&this).setID(id) �� ���� ǥ��, �̷��� �� ���� ����

		//this �� �̿��Ͽ� member variable ����
		this->m_id; //���� �ּҸ� ������ �ִ� this�� �ּ� �ȿ� ����ִ� m_id �� ����

		
		//�����ɶ� �ڱ� �ڽ��� �ּ� ���� �ϱ�
		cout << this << endl; //this Ű���带 ����ϸ� �ڱ� �ڽ��� �ּҸ� class �ȿ��� �� �� ����
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }

};

//Chaining Member Functions
//����ϴ� �Լ�
class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		:m_value(init_value)
	{}

	//void add(int value) { m_value += value; }  // ���ϱ� �Լ�
	//void sub(int value) { m_value -= value; }  // ���� �Լ�
	//void mult(int value) { m_value *= value; }  // ���ϱ� �Լ�
	
	//Chaining Member Functions
	//�ڱ� �ڽ��� reference �� return
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }


	void print()
	{
		cout << m_value << endl;
	}
};
int main()
{
	Simple s1(1), s2(2);

	s1.setID(2);
	s2.setID(4);

	//setID() ���� �Լ����� ���� ���� �����а� �ƴ϶� �ϳ��� �����ΰ� �ߺ��ؼ� �����
	// Simple::setID()�� ��򰡿� ����Ǿ� �ְ� ȣ���� �ɶ� Simple::setID(&s1, 1) �� ���� 
	//s1�� �����Ϳ� �ʿ��� ���ڸ� �־���,  ������ Simple::setID(&s1, 1)�̷��� �� �� ����

	//���������� s2 �� Simple::setID(&s2, 4)�� s2.setID(4) �� ���������� ������ �����ʸ� ��밡��

	//s1 �� s2 �� �����ϴ� ��� : �ּ����
	cout << &s1 << " " << &s2 << endl;


	//�� instance ���� �ڱ���� �����͸� ������ �ְ� �� �����͸� ���� ���� this ��� Ű���带 ���
	



	//Chaining Member Functions
	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2);

	cal.print();
	//�̷��� ġ�Ⱑ ���ŷο�

	Calc cal1(10);
	cal1.add(10).sub(1).mult(2).print();  //������ �������

	//�Ʒ��� ����
	Calc cal2(10);
	Calc& temp1 = cal2.add(10);
	Calc& temp2 = temp1.sub(1);
	Calc& temp3 = temp2.mult(2);
	temp3.print();


	//�ǿ뼺�� ���ؼ� ����� ����( c++ ���忡��)
	

	return 0;
}