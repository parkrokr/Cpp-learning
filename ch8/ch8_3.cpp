//������ Constructors


//�����ڴ� ����� ���ÿ� �۵���
//���ǻ��� : Fraction frac; ���� �������� parameter �� �ϳ��� ���� ��쿡�� frac() ���� �׻� () �� ������ �Ǿ�����
//�����ڰ� �ϳ��� �������� �ƹ��ϵ� ���ϴ� default ������ Fraction() {} �� �ϳ� ��������
//��� �ϳ��� ������ �⺻�����ڴ� ������ �ȵ�
//parameter �� �ִ� �����ڶ� dafault value �� ��� �����Ǿ� ������ �⺻������ ����� ��

#include <iostream>

using namespace std;

//�м��� ��Ÿ���� class
class Fraction
{
private:
	int m_numerator;		//�и�    = 1; �ؼ� �⺻���� ������� ����, ���߿� �ٲٷ��� �� ���� �߻�
	int m_denominator;		//�и�


public:
	//������
	//�����ڰ� variable ���� instance �� ����°� �ƴϰ� �׳� �̸��� ������,
	//construction �ɶ� ȣ���� �Ǵ� �Լ���� �����ϸ� ��

	//return ���� ���� class �̸��� �����ϸ� ������
	//�ܺο��� ȣ���Ϸ��� ���°� �ƴ�
	//main() ���� ����� ���ÿ� ������ ��

	//�⺻������

	//�����ڰ� �ϳ��� �������� �ƹ��ϵ� ���ϴ� default ������ Fraction() {} �� �ϳ� ��������
	//��� �ϳ��� ������ �⺻�����ڴ� ������ �ȵ�
	/*Fraction() // default ������, �ּ��� �־ ��� �Ȱ���
	{
		m_numerator = 2; //�̷��� �ϸ� �Ϲ����� �Լ� �����ε��� ����� �ָ���(ambiguos) ���� �߻�
		m_denominator = 1;
	}*/


	//parameter �� ���� �� ����, daflult value ���� �� ����
	Fraction(const int& num_in = 1, const int& den_in = 1)  
	{
		m_numerator = num_in;
		m_denominator = den_in;

		cout << "Fraction() constructor" << endl;
	}


	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}

 };

//class �� ������ �ִ� ���
class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}
};


int main()
{
	//Fraction frac;

	//frac.print(); //�ʱ�ȭ�� �ȵǾ ������ ���� ����

	//class �� member variable �� public: ���� �ٲ���
	//Fraction frac({0, 1}; �Ǵ�
	//frac.m_numerator = 0;
	//frac.m_denominator = 1;

	//member variable �� public: ���� �ٲ۰� �δ㽺����



	//�����ڴ� main() ���� ����� ���ÿ� �۵���
	//Fraction frac; �� ����Ǹ� print() �� ����Ǳ� ���� ���������� ���� �����ڰ� �����
	//Fraction frac;
	//frac.print();

	//Fraction frac; ���� �������� parameter �� �ϳ��� ���� ��쿡�� frac() ���� �׻� () �� ������ �Ǿ�����


	//�����ڿ��� parameter �� ���� �� ����
	Fraction one_thirds(1, 3);
	one_thirds.print();

	//defautl value �� ���� �� ����
	Fraction one_one(1);
	one_one.print();


	//Fraction frac; �����ڰ� ������ ������ �ȳ�, ��� print() �ϸ� �̻��� ���� ����
	//�����ڰ� �ϳ��� �������� �ƹ��ϵ� ���ϴ� default ������ fraction() {} �� �ϳ� ��������
	//��� �ϳ��� ������ �⺻�����ڴ� ������ �ȵ�
	//�׷��� Fraction frac;�� �������� ������ parameter �� ���� �����ڰ� ���� �����̴�
	//Fraction frac; �� ������ �ȳ��� ���� parameter �� ���� �����ڰ� �ִ°�� Fraction frac(); �� 
	//�Ǿ�� �Ұ� ������ c++ �� �������� �Ѱ� ������(�Լ��� ȥ���ɱ��) Fraction frac;���� �����

	//Fraction frac; ���� �ȳ��� ���� �ΰ��� ���
	//�⺻ �����ڸ� �׳� ����� ���,
	//�������� �����ε��� �̿��ؼ� parameter �� �޴� �����ڿ� default ���� �ִ� ���
	//parameter �� �ִ� �����ڶ� dafault value �� ��� �����Ǿ� ������ �⺻������ ����� ��
	Fraction frac;
	frac.print(); // 1 / 1 ��µ�



	//�Ϲ����� �Լ� �����ε��� ����� �ָ���(ambiguos) ���� �߻��� ���� ����


	//copy initialization �� ����
	//Fraction one_thirds = Fraction{ 1,3 }; �������� ����, 
	Fraction one_thirds{ 1,3 };// �̷��� �ٿ��� �� �� ����


	//uniform initialization �� copy initialization �� ����
	//��κ��� ��� �Ѵ� ��������� uniform initialization �� �� �ֱٿ� ���԰� 
	//�� �����ϱ� ������ ���� ����

	//uniform initialization	Fraction one_thirds{ 1,3 };
	//������� public �϶��� ������ ���� �ʱ�ȭ �� �� ����, private �϶��� �ȵ�
	//�ɹ����� private �̰� �����ڰ� ������ �����ڸ� ȣ����
	//�Ͻ��� ����ȯ ��� �ȵ�
	//Fraction one_thirds{ 1.0 ,3 }; �ϸ� ������ �ȵ�

	//copy initialization		Fraction one_thirds(1, 3);
	//�Ͻ��� ����ȯ ��� ��
	//Fraction one_thirds(1.0 ,3 ); �ϸ� ��� �߰� �������� ��







	//class �� ������ �ִ� ���(class �ȿ� class �� �ִ� ���)
	First fir;
	//Second �� ���� ��������� �� ������ First �� �������

	//�����ڴ� class ���� ����� ���� �ʱ�ȭ�Ǿ� �Ǿ�� �װſ� ���� �۾��� ���� �� ����

	//�� class �� �ٸ� class �� �ڽ��� ��� variable �� ����� �� ���
	//��� variable �� �����ڰ� ���� ȣ���� �ȴ�

	
	//�����ڰ� private �� ��� main() ���� �����ڸ� ȣ�� ����
	//�̸� �̿��� ���α׷��� ����� ����



	return 0;
}