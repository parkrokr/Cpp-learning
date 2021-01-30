//���� ����ȯ Dynamic Casting

//static_cast �� ������Ÿ�ӿ� üũ�ϰ� ��Ÿ�ӿ��� üũ���� ������
//dynamic_cast �� ��Ÿ�ӿ� üũ�ϱ� ������ ������ ��� �� �� ����

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base* base = &d1;

	//d1�� ���� ������ ���Ҷ�
	//Base ���� ���� Derived1���� �ִ°ſ��� ������ ����
	d1.m_j; //d1 ���� m_j �� ������ ����������
	//base->m_j;  //Base ���� ������ ����

	//���踦 ���ؼ� �̷� ��찡 ������ �ϴ°� ������ � ��쿡 ��¿ �� ���� 
	//Base �� Derived1 type ���� �ٲ�߸� �� ���� ����
	//�׷� ��쿡 dynamic_cast �� ����� �� ����

	//base �� Derived1 ���� ���� ����ȯ�� �� �� ����
	auto* base_to_d1 = dynamic_cast<Derived1*>(base);  //auto �� class Derived1 ���� ����
	//auto* base_to_d1 = static_cast<Derived1*>(base); //static_cast �� ����


	//m_j �� ���� �� �� ����
	cout << base_to_d1->m_j << endl;	//1024
	
	//�̷��� �����ϱ� ��
	base_to_d1->m_j = 256;
	cout << d1.m_j << endl;				//256

	//�̰ǰ� �����ϱ� ������ ������ �Ⱦ��°� ����, �ڵ� �б⵵ ����� ����׵� �������� Ư���� ��� �ʿ���
	//�����Լ��� �̿��ؼ� �ذ��ϴ°� ����


	//d1�� base �� �־��ٰ� Derived2 �� ���� ����ȯ?
	auto* base_to_d2 = dynamic_cast<Derived2*>(base);
	//auto* base_to_d2 = static_cast<Derived2*>(base);

	//dynamic_cast �� casting �� �����ϸ� null pointer �� �־����
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl;
	else
		cout << "Failed" << endl;
	//Failed ���, casting ����

	//static_cast �� casting �� ������
	//static_cast �� �Ҽ��ִ��� �ִ��� ����
	//��ſ� runtime ���� error check(type check) �� ����,compile time �� üũ��
	//� ��쿣 �ȵǾ� �Ұ͵� �Ǵ����� ����, �̰� ������ ���������� �ָ���
	

	//dynamic_cast �� run time �� error check �� ��

	//static_cast �� ������Ÿ�ӿ� üũ�ϰ� ��Ÿ�ӿ��� üũ���� ������
	//dynamic_cast �� ��Ÿ�ӿ� üũ�ϱ� ������ ������ ��� �� �� ����



	//������ �Ȼ���� ���
	// d1�� base �� �ٲ�ٰ� �ٽ� d1���� �ٲٴ� ���(�޸𸮿� ����Ǿ��ִ°� d1) �Ѵ� ���������
	//������ ����� ���
	// d1�� base �� �ٲ�ٰ� d2���� �ٲٴ� ��� dynamic_cast �� runtime �� check �� �ؼ�
	//�ƴϸ� nullpointer �� �־ ���������� static_cast �� �׳� �о����


	//�Ϲ������� ����ĳ������ �Ⱦ��ڴ� ���� ����
	//�ֱٿ��� funcional �̳� ramda function �� ���� �߼�
	//�ִٴ°� �˾Ƶθ� ��ü���ⱸ���� ���⼺�� �����ϱ⿡ ����
	//������ ���� ������ �ѹ��� �����غ��� ����
	//static_cast �� ������ �˰� ����

	return 0;
}