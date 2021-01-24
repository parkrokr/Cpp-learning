//����ȯ�� �����ε� �ϱ�  static_cast  typecast

// ����ȯ�� �����ε��Ҷ� return type , parameter �� ����
//C++ �� �츮�� �´� tyep �� return �Ұ��̶�� ������


#include<iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	}

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents; }

	//int �� ����ȯ�� �����ε�
	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};


//dollar �� cents �� cast
class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int& input) : m_dollars(input){}

	//dollar �� cents �� cast
	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};
void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	printInt(cents); //�����ε� ���ϸ� �Ͻ��� ����ȯ�� �ȵ�

	//���� ����
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	Dollar dol(2);

	Cents dollar_to_cents = dol;

	printInt(dollar_to_cents);

	return 0;
}