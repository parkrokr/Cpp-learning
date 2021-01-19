//��ȯ ������ ( Converting constructor ) , explict, delete

#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_deniminator;


public:
	//�⺻���� �ΰ��� parameter �� �ϳ��� ���͵� ������ ������
	explicit Fraction(int num = 0, int den = 1)  //explicit Ű���尡 ������ ��ȯ ������ ����
		: m_numerator(num), m_deniminator(den)
	{
		assert(den != 0); 
	}

	//delete
	Fraction(char) = delete;  //char �� ���ٲٰ� ����


	//copy constructor 
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);//�⺻���� �ΰ��� parameter �� �ϳ��� ���͵� ������ ������

	doSomething(frac);
	doSomething(Fraction(7)); //���ݴ� �����ϰ� ���� ������ �͸� ��ü ���
	
	//copy constructor
	//doSomething(7);

	//�̷��� �ص� ����,  �̷��� �ڵ����� �ٲ��ִ°� converting constructor ��� ��
	//�Լ� ���忡�� �޾Ƶ��ϼ� �ִ°� Fraction �ۿ� ������ ������ó�� �ڵ����� �ٲ���
	//explicit Ű���尡 ������ ��ȯ ������ ����, doSomething(7); �Ұ���



	//delete
	//Fraction frac2('c');  //deleted funcion

	//char �� ������ ���ƹ���
	//�������� �ϸ鼭 ���� ������� ���� ���ϰ� ���� ���� ���
	//�ڵ� ��ȯ �ǰų� casting �Ǵ°� ���� ���� ���

}