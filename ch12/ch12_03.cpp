//override, fianl, ���� ( Covariant ) ��ȯ��  

//�������̵带 �ǵ������� �Ҷ� override �� ���̸� �Ǽ��� ���� �� ����

#include <iostream>
using namespace std;

class A
{
public:
	//virtual void print(int x) { cout << "A" << endl; } //B�� print() �� parameter type �� �ٸ�
	virtual void print() { cout << "A" << endl; }


	//B�� getThis() �� A�� getThis() �� return type �� �ٸ����� �������̵尡 ��
	void print1() { cout << "A" << endl; }
	virtual A* getThis() 
	{
		cout << "A::getThis ";
		return this;
	}
};

class B : public A
{
public:
	//�θ�Ŭ������ print() �� parameter type �� �ٸ�
	//�������̵��� �ϰ� �;����� �����Ϸ��� �����ε����� �ؼ���(parameter �� �޶�)
	//�������̵带 �ϰ� ���� ���� ��� override Ű���带 ���̸� ��(������ ������ �̸� ã����)

	//void print(short x) override { cout << "B" << endl; } //parameter �� �޶� ���� �߻�
	//void print1(int x) override { cout << "B" << endl; } //�Լ� �̸��� �޶� ���� �߻�
	//void print(int x) const override { cout << "B" << endl; }//const�� �Ǿ� ���� �߻�(�θ��� �Լ��� const �� ����)
	
	//final �� ���̸� �ؿ� �Լ����� �������̵带 ����,������ ���ٲ�
	void print() final override { cout << "B" << endl; } 
	

	//A�� getThis() �� return type �� �ٸ����� �������̵尡 ��
	void print1(){ cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis ";
		return this;
	}
};

class C : public B
{
public:
	//virtual void print() {cout << "C" << endl; } //final �� ������ ���Ƽ� �������̵带 ����
};


int main()
{
	A a;
	B b;
	C c;

	A& ref = b;
	//ref.print(1);  //B�� �ִ� print() �� ����Ǳ⸦ �ٷ��� ������ A �� ����
	//�Լ��� parameter �� �ٸ��� �������̵��� �� �� ����
	//�����Ϸ� ���忡�� �Լ��� �������̵��� �ƴϰ� �����ε��� �Ѱɷ� �ؼ���


	//���� ( Covariant ) ��ȯ�� 
	b.getThis()->print1();		//B, B::getThis()
	ref.getThis()->print1();	//A, B::getThis()
	//ref �� type �� A �� B::getThis() ���� B�� �����͸� �������൵
	//���������� �ٽ� A�� �����ͷ� �ٲ��� A::print()��ȣ����

	cout << typeid(b.getThis()).name() << endl;		//class B *
	cout << typeid(ref.getThis()).name() << endl;	//class A *

}