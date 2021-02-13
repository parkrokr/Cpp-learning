// ostream ���� ����ϱ�

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//���� ���
	
	//showpos
	cout.setf(std::ios::showpos);			//�÷��� ����, showpos �� + ��ȣ ���̰� �ϴ°�
											//visual studio ���� std::showpos �� �ƴ϶� std::ios::showpos
	
	cout << 108 << endl;					//+108

	cout.unsetf(std::ios::showpos);			//�÷��׸� unset, + ������ �ٽ� �����
	cout << 109 << endl;					//109


	//hex		16������ ���

	//cout.setf(std::ios::uppercase);					//16������ ���ĺ��� �빮�ڷ� ������ ����
	
	cout << std::hex << std::uppercase;					//�̷��Ե� uppercase ��� ����(manipulator ���)
														//include <iomanip> �� �ؾ� ��� ����

	//cout.unsetf(std::ios::dec);						//10���� ��� ����
	//cout.setf(std::ios::hex);							//�ٷ� �ȵ�, 10���� ��带 ���� ����� ��
	
	//cout.setf(std::ios::hex, std::ios::basefield);	//basefield�� �÷��׸� ����, �ٷ� ��
	
	cout << std::hex;									//setf�� �Ⱦ��� 16������ ���

	cout << 108 << endl;								//6C
	cout << 109 << endl;								//6D

	//�ٽ� 10������
	cout << std::dec;
	cout << 110 << endl;								//110			



	//bool �� ����Ҷ�
	cout << std::boolalpha;								//���ڷ� true, false ���
	cout << true << " " << false << endl;				//true false


	//setw, fill
	cout << -12345 << endl;
	cout << std::setw(10) << -12345 << endl;						//-12345
	cout << std::setw(10) << std::left << -12345 << endl;			//    -12345		���������� ����
	cout << std::setw(10) << std::right << -12345 << endl;			//-12345			�������� ����
	cout << std::setw(10) << std::internal << -12345 << endl;		//-    12345		��ȣ�� ���� ���� ��ĭ

	cout.fill('*');													//��ĭ�� * �� ä��
	cout << std::setw(10) << -12345 << endl;						//****-12345
	cout << std::setw(10) << std::left << -12345 << endl;			//-12345****		
	cout << std::setw(10) << std::right << -12345 << endl;			//****-12345			
	cout << std::setw(10) << std::internal << -12345 << endl;		//-****12345		


	//setprecision		���е� ����
	
	//cout << std::defaultfloat;						//�⺻ ����, �ٸ������� �ȵǾ� ������ �⺻�� �Ǿ�����
	cout << std::showpoint;								//�Ҽ��� ǥ��,�⺻������ �Ǿ������� �Ҽ����� �ȳ���

	cout << std::setprecision(3) << 123.456 << endl;	//123
	cout << std::setprecision(4) << 123.456 << endl;	//123.5
	cout << std::setprecision(5) << 123.456 << endl;	//123.46
	cout << std::setprecision(6) << 123.456 << endl;	//123.456
	cout << std::setprecision(7) << 123.456 << endl;	//123.456
		
	cout << std::fixed;									//�Ҽ��� �ڿ� �ڸ��� ����
	cout << std::setprecision(3) << 123.456 << endl;	//123.456
	cout << std::setprecision(4) << 123.456 << endl;	//123.4560
	cout << std::setprecision(5) << 123.456 << endl;	//123.45600
	cout << std::setprecision(6) << 123.456 << endl;	//123.456000
	cout << std::setprecision(7) << 123.456 << endl;	//123.4560000


	cout << std::scientific << std::uppercase;			//������ ǥ��, e �� �빮�ڷ�
	cout << std::setprecision(3) << 123.456 << endl;	//1.235E+02
	cout << std::setprecision(4) << 123.456 << endl;	//1.2346E+02
	cout << std::setprecision(5) << 123.456 << endl;	//1.23456E+02
	cout << std::setprecision(6) << 123.456 << endl;	//1.234560E+02
	cout << std::setprecision(7) << 123.456 << endl;	//1.2345600E+02

	return 0;
}