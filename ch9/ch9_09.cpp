//���� ������, ���� �ʱ�ȭ, RVO (Return Value Optimization)

//���� �����ڰ� private: �� �ִ°�� �ۿ��� ����� ����(���縦 ����)


#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_deniminator;


	//���� �����ڰ� private: �� �ִ°�� �ۿ��� ����� ����(���縦 ����)
	/*Fraction(const Fraction& fraction)
		:m_numerator(fraction.m_numerator), m_deniminator(fraction.m_deniminator)
	{
		cout << "copy constructor called" << endl;
	}*/



public:
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_deniminator(den)
	{
		assert(den != 0);  //�и� 0 �̸� �ȵȴٴ� ����
	}


	//copy constructor  �ڱ�� �Ȱ����� �����°�
	Fraction(const Fraction& fraction)
		:m_numerator(fraction.m_numerator), m_deniminator(fraction.m_deniminator)
	{
		cout << "copy constructor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_deniminator << endl;
		return out;
	}

};


Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}


int main()
{
	Fraction frac(3, 5);

	//copy
	Fraction fr_copy(frac);
	
	//Fraction fr_copy = frac;  //copy initialization �� ��쵵 copy constructor �� ȣ���
	
	//Fraction fr_copy(Fraction(3, 10));
	//�� ��� ������ڰ� ȣ����� ����, �����Ϸ��� Fraction fr_copy(3,10); ���� �ٲ�


	cout << frac << " " << fr_copy << endl;


	//RVO
	Fraction result = doSomething(); 
	cout << &result << endl;
	cout << result << endl;

	//debug ��忡�� result �� copy initialization �� �Ҷ� copy constructor �� ȣ���
	//temp�� result �� �ּҸ� ���� �ּҰ� �ٸ�, �ٸ��� ������ ���縦 �߾�� ��

	//release ��忡�� copy constructor �� �������� ����
	//return value �� �Լ��� ����� ������ ������ ���� ������ result �� �Űܹ���
	//temp �� result �� �ּҸ� ���� �ּҰ� ����, ���� ������ ���縦 �� �ʿ䰡 ����
	//�����Ϸ��� ����ȭ�� ���ִ°���(release ��忡����)

	return 0;
}