//��ȣ ������ ( () parenthesis ) �����ε��� �Լ� ��ü Function object ( Functor )

//��ȣ�����ڸ� �����ε��ϸ� �Լ��� ��ü�ΰ�ó�� , Functor �ΰ�ó�� ����� �� ����


#include<iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator() (int i) { return (m_counter += i); }
	

	//chaining ����
	/*Accumulator& operator() (int i)
	{
		m_counter += i;
		return *this;
	}*/
	
	int getnumber()
	{
		return m_counter;
	}
};


int main()
{
	Accumulator acc;
	cout << acc(10) << endl;  //10
	cout << acc(20) << endl;  //30

	//�Լ��� ����� ������ ���� ������ ��ü�� �Լ��� ȣ���ϴ°�ó�� �����(�̷� ����� functor ��� ��)
	//chaining ���� ����

	cout << acc(acc(10)) << endl;

	//cout << acc(10).getnumber() << endl;
	//cout << acc(10)(10).getnumber() << endl;

	return 0;
}