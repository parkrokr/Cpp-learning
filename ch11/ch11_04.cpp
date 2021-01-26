//������ ( Derived ) Ŭ�������� ������ �ʱ�ȭ

#include <iostream>
using namespace std;

class Mother
{
private:
	int m_i;

public:
	Mother(const int& i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction " << endl;
	}

};

class Child : public Mother
{
public:
	float m_d; 
	//double m_d;
	//int m_temp;


public:
	Child()
		:m_d(1.0f), Mother(1024)
	{
		cout << "Child construcion" << endl;
	}
};



class A
{
public:
	A(int a)
	{
		cout << "A : " << a << endl;
	}

	~A()//�Ҹ��ڴ� �����ڶ� ��������� ~�� �ٰ� parameter �� ����
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		:A(a) //������ A�� �⺻�����ڰ� ��� ����
	{
		cout << "B : " << b << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C :public B
{
public:
	C(int a, double b, char c)
		:B(a,b)
	{
		cout << "C : " << c << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};



int main()
{
	//Ŭ������ ������ ����
	Child c1;

	cout << sizeof(Mother) << endl;  //4 : int �ϳ� ����־
	cout << sizeof(Child) << endl;   //8 : Mother �κ��� �������� 4 + �ڱⰡ ���� float( 4 )

	//�е� ( Padding )
	//�е� ��Ʈ ������ m_d �� double �� ��� Child �� ũ��� 8+4= 12 �� �ƴ� 8 + 8 �� 16 �� ����
	//Child �� int �� ������ �ϳ� �� �߰��ϸ� 8 + 8 + 8 �ؼ� 24 �� ����
	

	//Child class�� �޸� �Ҵ��� �������� Mother class �� ����ִ°͵� �� �ޱ� ���� ũ�� ����

	//����� ������ �� ��� Grand Child �� Grand Mother �� �����ڸ� ���� ȣ�� �� �� ����


	C c(1024, 3.14, 'a'); //C c �� ����Ұ���, �⺻�����ڰ� ���� ���� ����

	//���� ����(������ ȣ�� ����) �� A, B, C 
	//�Ҹ� ����(�Ҹ��� ȣ�� ����) �� C, B, A


	return 0;
}