// ģ��(friend) �Լ��� Ŭ����

//�������� class �����ϰ� ��ȣ�ۿ��ϴ� ��� ����ϰ� �����ϴ°� ����� �� ����
//��ü������ �⺻��Ģ�� ĸ��ȭ�� ���� �������� ��� ���

//������ �����ε����� friend �� ���� ���� ��

#include<iostream>
using namespace std;

class B; //forward declaration  ������Ҷ� ���ǰ� ����ִ��� ã�ƾ� �ϴ� ���ŷο��� ������ ��¿ �� ����

class A
{
private:
	int m_value = 1;

	//doSomething() �� class A �� ģ���� �����,B�� ģ���ε� �����, class B �� A ���� �ؿ� ����(���漱�� �ʿ�)
	friend void doSomething(A& a, B& b); 
};

//class �� �ΰ��϶� �Լ��� �ΰ� ��� �����ϴ� ���
class B
{
private:
	int m_value = 2;

public:
	friend void doSomething(A& a, B& b);
};


void doSomething(A& a, B& b)  //doSomething() �� class A �� ģ���� �����, class B �� ģ���ε� �����
{
	cout << a.m_value << endl;
	//m_value �� public �� �Ҽ������� ĸ��ȭ�� ��Ģ�� Ǫ�°�
	//class A�� friend �� �Ǹ� private member ���� ������ �� ����
}




//�ٸ� class �� private member �� �����ϰ� ���ֱ�
class C;  //C �ȿ� doSomething()�� �ִٴ°� class C �� �� ����� ����, ���漱������ ����


class D
{
private:
	int m_value = 4;

public:
	void doSomething(C& c); // prototype �� �����

};

class C 
{
private:
	int m_value = 3;

	//friend class D; //class D �� ģ���� �����
	friend void D::doSomething(C& c); //D �ȿ� ����ִ� doSomething ���Ը� �����ְڴ�
};


void D::doSomething(C& c)
{
	cout << c.m_value << endl;
}


int main()
{
	//�Լ��� ģ���� �����
	A a;
	B b;
	doSomething(a,b);


	//class �� ģ���� �����
	C c;
	D d;
	d.doSomething(c);

	//class A �� class B �� class B�� ����Լ��� friend �Ϸ��� ���(����Լ��� ���Ǵ� class B �� ����)

	//class B�� friend �ϴ� ���
	//A �� �տ� �ְ� B �� �ڿ� �ִ� ���		: B�� ���漱��
	//B �� �տ� �ְ� A �� �ڿ� �ִ� ���		: A�� ���漱��, ����Լ� prototype �� ����� body �� A �ڷ� ������


	//class B �� ����Լ��� friend �Ϸ��� ���
	//A �� �տ� �ְ� B �� �ڿ� �ִ� ���		: �Ұ���
	//B �� �տ� �ְ� A �� �ڿ� �ִ� ���		: A�� ���漱��, ����Լ� prototype �� ����� body �� A �ڷ� ������



	return 0;
}