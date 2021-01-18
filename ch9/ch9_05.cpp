// ���� ������ ( ++, -- ) �����ε��ϱ�

//���� ������(prefix) �� �ܼ��� ����������� ���� ������(postfix) �ӽ�(Temp) ��ü ����, �ʱ�ȭ, ������ ����������
//ȣ����� �߰� ó���� �ʿ��ϱ� ������ �������� �� ȿ�����̰� �ӵ��� ����( for ������ ++i �� ��õ�ϴ� ����(���ǹ��� ���� x))

//�������� ���۷����� return �Ѵ�(chaining�� ����)
//�������� ��� ���������� ������ ���� dummy int �� ����Ѵ�
//���� ���� return �ϰ� �ٲ�� �ϹǷ� ��ü ��ü�� return ���� ���ϰ� ���� return �Ѵ�(������ ��ȯ�ϸ� ���)


//			��� �Լ�				���� �Լ�
//������		Digit& operator ++()	Digit &operator ++ (T &t)
//������		Digit operator ++(int)	Digit operator ++ (T &t, int)

#include<iostream>

using namespace std;

//�� ������ 0~9 �� ������, 9�� 1�� ���ϸ� 0, 0���� 1�� ���� 9�� ���ư�
class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit) {}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}

	//������ prefix
	Digit& operator ++ ()
	{
		++m_digit;

		return *this;
	}

	//������ postfix
	//prefix �� �����ϱ� ���� parameter �� dummy �� int �ϳ� �־���
	Digit operator ++ (int)  //const Digit operator ++ (int) ����
	{
		//�ϴ� return �� �ϰ� ���� �ٲ������
		Digit temp(m_digit);

		++(*this);	//++m_digit; �̷��� �Ҽ��� ������ ++�� ������ ���������

		return temp;
	}

};

int main()
{
	int a = 10;

	cout << ++a << endl;  //������ : ����� ���� �ϰ� �����
	cout << a << endl;
	cout << a++ << endl;  //������ : ����� ���� �ϰ� �����
	cout << a << endl;


	//prefix
	Digit d(5);

	cout << ++d << endl;
	cout << d << endl;


	//postfix
	cout << d++ << endl;
	cout << d << endl;
	return 0;
}