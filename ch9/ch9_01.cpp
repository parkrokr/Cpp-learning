//��� ������ �����ε� Overloading �ϱ�


// +, -, *, / ������ �� ������ �����ε� �� �� ����
	// �켱������ �״����(�������ΰ͵鸸 �����ε� �ϴ°��� ����)
	// ^ �� �켱������ �ſ� ���� ������ ()�� �μ� ����ϰ� �׳� �����ε� ���ϴ°� ����

	//�Ұ����� �����ڵ�
	// ?:		���׿�����
	// ::		scope ������
	// sizeof	������
	// .		member selection ������
	// .*		member pointer ������
	// #		���ڿ� ��ó���� ��ȯ
	// ##		��ó���� ����

	//member function ���θ� �ؾ� ������ �����ڵ�
	// = , [] , () ,->


//������ �����ε��� ��� �Լ��� �ϴ� ��� ù��° parameter �� this �� �̿��ؾ���


#include<iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; } //sum ������ �⺻�� �־��ֱ�
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }  //������ ��ȯ�ؾ� l value �� �Ǿ� c_out.getCents() ���� ������ ��������


	//.getCents() �� �Ⱦ��� ���� friend �ϱ�
	//friend Cents operator + (const Cents& c1, const Cents& c2) 
	//{
	//	return Cents(c1.m_cents + c2.m_cents);
	//};



	//freind ���� �ʰ� ��� �Լ��� ����������
	//too many parameters : + �Լ��� parameter �ΰ��� ������ ��

	Cents operator + (const Cents& c2) //���� parameter �� this �� �ٲ����
	{
		return Cents(this->m_cents + c2.m_cents);
	};
};



//c_out �� ���� parameter �� �޾Ƽ� output ���� ����
//void add(const Cents& c1, const Cents& c2, Cents& c_out)
//{
//	c_out.getCents() = c1.getCents() + c2.getCents();
//}



//ouput �� return type ���� �ޱ�(�ֱ� ����)
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}



//add() �� ���� ������(������ �����ε�)
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}



//c1.getCents() ���� getCents() �� ���� ������, �Լ��� friend �ϱ�
//class ������ �־������
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.m_cents + c2.m_cents);
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	//���ϰ� ������
	//add() �����
	/*Cents sum;
	add(cents1, cents2, sum);*/

	//cout << sum.getCents() << endl;
	//cout << sum << endl; //ch9_02


	//������ �۾��Ҷ�
	int i = 6, j = 8; cout << i + j << endl;	//���ϰ� �����


	//output �� return type ���� �ޱ�
	cout << add(cents1, cents2).getCents() << endl;  //.getCents() �� �ݵ�� �ٿ������


	//������ �����ε�
	cout << (cents1 + cents2).getCents() << endl;
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;  //�͸� ��ü�� ����Ͽ� Cents(6) ���� ���ϱ�


	//getCents() �� �Ⱦ��� ����
	//�Լ��� friend �ؼ� c1.getCents() ���� �ʰ� �ٷ� m_value �� �����Ҽ� �ְ� friend �ϱ�
	cout << (cents1 + cents2).getCents() << endl;  //����Ҷ� �����


	// +, -, *, / ������ �� ������ �����ε� �� �� ����
	// �켱������ �״����(�������ΰ͵鸸 �����ε� �ϴ°��� ����)
	// ^ �� �켱������ �ſ� ���� ������ ()�� �μ� ����ϰ� �׳� �����ε� ���ϴ°� ����

	//�Ұ����� �����ڵ�
	// ?:		���׿�����
	// ::		scope ������
	// sizeof	������
	// .		member selection ������
	// .*		member pointer ������

	//member function ���θ� �ؾ� ������ �����ڵ�
	// = , [] , () ,->

	return 0;
}