//ĸ��ȭ Encapsulation , ���� ������ Access Specifiers, ���� �Լ� Access Functions

//�پ ���α׷��Ӵ� �����Ѱ� �ܼ��ϰ� ���̵��� ������ ���ϰ� ������踦 ����ϰ� �����ϴ� ���


//���� class �ȿ� �ִ� ����� �ٸ� ����� ���� �� �� ����


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
//public:  //  access specifier ���� ������, ������ main() ���� class �ۿ��� member �� ���� ����

	//private : �� �ϸ� �ۿ��� ���� ����
	//�ƹ��͵� ������ ������ private : �� �⺻

	//private : �϶��� �ۿ��� �����Ҷ� ���� �Լ�(Access Functions )��� Ư���� ����� ���� ������ �����
	//��������� �׶��׶� ���� �Լ����� �������ִ°� ����
	//���¼ҽ�, ȸ�� �ڵ� ���� private�� �����ϰ� ��Ű�°�찡 ����
	//���¼ҽ����� private �� �Ⱥ��̴� �ڵ嵵 ����, �⺻�� private �̱� ������

	int m_month;
	int m_day;
	int m_year;


	//access function

	//���� class �� ������ �ڱ��ڽ��� public �̶� private �� ������ �� ����
public:

	//setters
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}


	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	void setDay(const int& day_input)
	{
		m_day = day_input;
	}

	void setYear(const int& year_input)
	{
		m_year = year_input;
	}


	//����ϱ� ���� ���� get() �� �������
	//value ���縦 ���� ���� reference , get() �� ���� �ٲٴ°� ���� ���� const
	//�̷��� ���� ��� ���� get() ���� getters ��� �θ�
	const int& getDay()
	{
		return m_day;
	}

	const int& getMonth()
	{
		return m_month;
	}

	const int& getYear()
	{
		return m_year;
	}



	//���� �����ϴ� �Լ�
	//�ڱ� �ڽ��� parameter �� ����, ���� ���ϰ� const
	void copyfrom(const Date& original)
	{
		// original �� ����� original �ȿ��� private ���� 
		//�ٸ� instance �� ����Լ����� �����ϰ� �� ������
		
		//today �� copy �� ���� Date ��� class �κ��� ��������� ������
		//�ٸ� �޸� �ּҸ� ������ �ִ� �ٸ� ����, instace ��
		//�ٸ� �޸𸮶� ���� class ���� �������� ������ �� �� ����
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}

	//�׳� �޸� ��°�� �����ϴ� ����� �� ���� ������� ������ �̷��� �������� �ϴ� ������
	//���� class �� ����� ������ �����Ѱ� ����� �����ε� �׶� �Ǽ��ϴ°� �����ϰ��� �ϴ°�

};

int main()
{
	Date today; //{ 1,12,2021 };

	//public : �� class �ȿ� ������ ������  main() ���� class Date �� ������ �� ����
	/*today.m_month = 1;
	today.m_day = 12;
	today.m_year = 2021;*/

	today.setDate(1, 12, 2021);
	today.setMonth(2);

	//����ϱ� ���� ���� get() �� �������
	cout << today.getDay() << endl;

	//today �� �����ϰ� ����
	Date copy;

	//copy.setDate(today.getMonth(), today.getDay(), today.getYear()); // �̷��� ġ�� �ʹ� ������

	//copyfrom() �� ����ų� setDate �� �����ε��ؼ� ���� ��
	copy.copyfrom(today);




	//getter(), setter() �� ������ ��� ������ ����
	//��� �������� �ٲ㵵 access function �� �ۿ��� �ٲ� �� �ְ� �����θ�
	//class �ȿ��� �ذ��� ������
	//Encapsulation�� �ص��� �ʰ� �� public �� �����ϸ� ���߿� �̰��������� ���ľ���
	//Visual Studio �� rename ��ɵ� �Ϻ����� ����


	return 0;
}