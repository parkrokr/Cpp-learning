//���� �Լ� (Virtual Functions) �� ������ ( Polymorphism )

//virtual �� ���� ��� virtual �� ���� ȣ���ϴ°� �ƴ϶� ���̺��� ��ӹ��� 
//�ν��Ͻ��� ã�ư��� ������ ��ġ�� ������ ����
//ȣ���� ���� ���� �Ǵ� �Լ��� ���� ������

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B :public A
{
public:
	/*virtual*/ void print() { cout << "B" << endl; }
};

class C :public B
{
public:
	/*virtual*/void print() { cout << "C" << endl; }
};

class D :public C
{
public:
	/*virtual*/void print() { cout << "D" << endl; }

	//�������̵��� �Ҷ� return type �� �ٸ� ���
	//virtual int print() { cout << "D" << endl; return 0; }  
	//�������� �ȵ�, A::print() �� return type �� �ٸ��ٰ� ������ �߻�, 
	//C �� ��ӹ޾Ƶ� ���� ���� Ŭ������ A �� �����Լ��� ����
	//�����ε��� �Ҷ� return type ������ ������ ����
};

int main()
{
	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();


	//AŸ���� ������ b �־��ֱ�, c,d �� ���� �Ȱ���
	A& ref = b;
	ref.print();
	//A�� print() �� virtual �� ������ �ڽ� Ŭ�������� �������̵� �� �Լ��� �״�� �����

	//B class �� ������� �ν��Ͻ��� A �� ������ �ִµ� A �ȿ� �ִ� print() �� virtual �� ���
	//�ؿ� ��ӹ��� class ���� �������̵� �� �Լ��� ���� ��� virtual �� �ƴ϶� �� �Լ��� �����

	//A�� print() �� virtual �̰� B�� print() �� virtual �� �ƴ����� A type ������ C type �� �������
	//C�� A�� ���� ��ӹ޴°� �ƴ϶� �߰��� B�� ���İ����� �ұ��ϰ� B�� ����ϴ°� �ƴ� C �� �����
	A& ref1 = c;
	ref1.print(); //C


	//���� ���� class �� �ִ°� virtual �� �Ǿ������ �ؿ� �ִ� �͵鵵 virtual ó�� �ൿ��
	//�׷��� ��������� �ؿ� �ִ� �Լ��鵵 virtual �� ���̴� ��Ÿ���� ����
	//�ٿ��θ� ����� �Ҷ� �������� ���� �����Լ��� �������̵� �Ѱ����� �ƴ��� ���� �ľ��� �� ����
	B& ref2 = c;
	ref2.print(); //C




	return 0;
}