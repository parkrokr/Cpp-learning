//������ ( Derived ) Ŭ�������� ���� ����

#include <iostream>
using namespace std;

class Mother
{
public:
	int m_i;
	
	//������ class �� �����Ǵ� ������ �˾ƺ��� ���� �����ڰ� ���� ȣ��Ǵ����� ���°� ����
	//�⺻ �����ڶ� ���°� �����(parameter �� ����)
	//�ǵ������� ȣ������ �ʾƵ� ���������� �ڵ����� ȣ�� �� �� ����
	//������ ������ ������ ȣ����
	//parameter �� �ִ� �����ڸ� ����������� �ڵ����� �����Ǵ� �⺻�����ڵ� ���� ������ �����

	Mother(const int & i_in = 0) //const int & i_in ������ ������ �⺻������ ������ ����,������ ���� ������
		:m_i(i_in)
	{
		cout << "Mother construction" <<endl;
	}
};

class Child :public Mother
{
public:
	double m_d;

public:
	Child()
		//:m_d(1.0)  //, m_i(1024) �� �ʱ�ȭ�� �ȵ�
		//: Mother(), m_d(1.0)  //��� �տ� Mother() �� ��������
		//: m_d(1.0), Mother(1024)  //������ �ٲ� Mother �� �����ڸ� ���� ȣ����
		: Mother(1024), m_d(1.0) //Mother() �� ���ڸ� �־ �ʱ�ȭ �ϰ� ���� -> ����
	{
		
		//������ class �� �����Ǵ� ������ �˾ƺ��� ���� �����ڰ� ���� ȣ��Ǵ����� ���°� ����
		cout << "Child construcion " << endl;


		//m_i �� Mother �� ��ӹ޾ұ� ������ �����Ӱ� �����ؼ� ��ġ �ڱ��ó�� ����� �� ����
		this->m_i = 10;
		Mother::m_i = 1023;
		this->Mother::m_i = 1024;
	}

};


//class �� ���̰� �ִ� ���(������ ���)
class A
{
public:
	A()
	{
		cout << "A construcotor " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constuctor " << endl;
	}
};

class C :public B
{
public:
	C()
	{
		cout << "C constructor " << endl;
	}
};

int main()
{
	//������ class �� �����Ǵ� ������ �˾ƺ��� ���� �����ڰ� ���� ȣ��Ǵ����� ����
	Child c1;
	//Mother construction �� ���� �Ͼ(�ڵ����ζ� ����)
	//�� ������ Child construction �� �Ͼ

	//Mother �� �ִ°� ��� �ʱ�ȭ ���� Child �� �ʱ�ȭ

	//����ŷ� ���� c1�� ����� �� c1�� �����ڷ� ������ Mother �� �����ڷ� ���� 
	//��� �̴ϼȶ������� ���� m_i �� �ʱ�ȭ �ϰ� "Mother construction" �� ����ϰ�
	//child�� �����ڷ� ���ƿ��� ��� �̴ϼȶ������� ���� m_d�� �ʱ�ȭ �ϰ� "Child construcion " �� ���


	//Child  �������� ��� �̴ϼȶ����� ����Ʈ, m_d�� �޸𸮸� ��Ƶ� //m_i�� ���� �޸����� ������ �ʾұ� ������ ����
	//Mother �� �����ڷ� �̵�
	//Mother �������� ��� �̴ϼȶ����� ����Ʈ, m_i �� �޸𸮸� ��Ƶ�
	//Mother �������� body, m_i �� �޸𸮿� ���� �־� �ʱ�ȭ 
	//Child  �� �����ڷ� �̵�
	//Child  �������� body, m_d �� �޸𸮿� ���� �־� �ʱ�ȭ //���⼭ m_i �� ���� ���� �� ����



	//class �� ���̰� �ִ� ���(������ ���)
	C c;
	//A, B, C ������ ȣ���

	B b;
	//A, B ������ ȣ���
	
	A a;
	//A �� ȣ���

	//�Ҹ��ڴ� ������ ȣ�� ������ �ݴ�� ȣ���
	return 0;
}