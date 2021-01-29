//���� �⺻ Ŭ���� (Virtual base classes ) �� ���̾Ƹ�� ���� ( The diamond problem)

#include <iostream>
using namespace std;

//class A
//{};
//
//class B1 : public A
//{};
//
//class B2 : public A
//{};
//
//class C : public B1, public B2
//{};

//���̾Ƹ�� ����� ���������� �����δ� A �� �ΰ��� ����(B1�� B2�� ���� A�� �����ڸ� ȣ����)
//�׷��� B1 �� B2 �� virtual �� �־ ���� �⺻ Ŭ������ ����(���� ���)
//B1�� B2�� �������� �ϸ� B1�� B2 ���� A�� �����ڸ� ȣ������ ����
//C�� A�� �����ڸ� ȣ���ϰ� ��(�����ڸ� ȣ���ϴ� ��ü�� �Ǿ�� ��)

//���� �������� Copier ���� PowerdDevice�� paramter �� �ִ� �����ڸ� �������� ������
//paramter �� ���� �⺻�����ڸ� �ڵ����� ȣ���Ϸ� ������ PowerdDevice ���� paramter �� ����
//�����ڰ� ���ǵǾ� ���� �ʱ� ������ ���� �߻�(parameter �� �ִ� �����ڸ� �����߱� ������
//�⺻�����ڴ� �������� �ʰ� �Ǿ������)

class A
{};

class B1 : virtual public A
{};

class B2 : virtual public A
{};

class C : public B1, public B2
{};


//����
class PowerdDevice
{
public:
	int m_i;

	PowerdDevice(int power)
	{
		cout << "PowerdDevice: " << power << '\n';
	}

	PowerdDevice() {}
	//PowerDevice �� �⺻�����ڸ� �������ָ� Copier ���� parameter �� �ִ� �����ڸ� ȣ���ϴ°� �������� �ʾƵ�
	//�ڵ����� �⺻�����ڸ� ȣ���ϱ� ������ ������ �Ͼ�� ����
};

class Scanner : virtual public PowerdDevice
{
public:
	Scanner(int scanner, int power)
		:PowerdDevice(power)
	{
		cout << "Scanner: " << scanner << '\n';
	}
};

class Printer : virtual public PowerdDevice
{
public:
	Printer(int printer, int power)
		:PowerdDevice(power)
	{
		cout << "Printer: " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		:Scanner(scanner, power), Printer(printer, power)
		//PowerdDevice(power) //Scanner �� Printer �� ����ȭ ��Ų�� PowerdDevice �� �����ڸ� ȣ���ؾ���
	{}
};

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PowerdDevice::m_i << endl;
	cout << &cop.Printer::PowerdDevice::m_i << endl;

	//virtual �� ���̱� ��
	//PowerdDevice �� �ι� ȣ��ǰ� ����
	//m_i �� �ٸ� �ּҸ� ����
	//���� �ٸ� PowerdDevice ��

	//virtual �� ���� ��
	//���̸� Copier ���� ������ ��
	//Copier �� PoweredDevice �����ڸ� ������ ȣ�����ָ� ��

	//���:
	//PowerdDevice �� �����ڰ� �ѹ��� ȣ��ǰ� m_i �� �ּҴ� ������

	return 0;
}