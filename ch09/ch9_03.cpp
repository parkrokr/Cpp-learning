// ���� ������ ( + , - , ! ) �����ε��ϱ�

#include<iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out,const Cents& cents)
	{
		out << cents.m_cents;
		return out;	
	}

	Cents operator - () const
	{
		return Cents(-m_cents);
		//return this->m_cents;
	}

	//not operator(!) �� return type �� bool
	bool operator! () const
	{
		//���ƻ� �����Ѱ� return �ؾ���

		// Cents �� 0 �̸� !Cents() �� true �� return �ϴ� �ڵ�
		//if �� �� ������ �ְ� conditional operator �� ������ ����

		return (m_cents == 0) ? true : false;
	}

};

int main()
{
	
	int a = 3;
	cout << -a << endl;	//���׿����� -
	cout << !a << endl;	//0


	Cents cents1(6);
	Cents cents2(0);

	// - operator
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(10) << endl;


	// !(not) operator
	auto temp = !cents1;  //temp �� bool �� �� ����
	cout << cents1 << " " << cents2 << endl;
	cout << !cents1 << " " << !cents2 << endl;



	return 0;
}