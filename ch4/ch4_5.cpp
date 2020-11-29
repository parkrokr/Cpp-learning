// �Ͻ��� ����ȯ(Implicit Type C0nversion (coersion)) ��
// ����� ����ȯ(Explicit Type Conversion (casting) )

#include <iostream>
#include <typeinfo> // typeid()�� ����ϱ� ���� �ʿ���
#include <iomanip>

int main()
{
	using namespace std;


	// typeid( )�ȿ� dadta literal �̳� �������� ����ְ� .name() �Լ��� ȣ���ϸ� � type���� �������
	cout << typeid(4.0).name() << endl;

	int a = 123;
	cout << typeid(a).name() << endl;
	

	//�Ͻ��� ����ȯ(Implicit Type C0nversion (coersion))
	
	//�Ͻ��� ����ȯ �� ���α׷��Ӱ� ����ȯ�� �ش޶� ��� ��û���� �ʴ°��
	// �����Ϸ��� �˾Ƽ� ������ ����ȯ�� ���ѹ����°�
	// int a = 123.0 �ϴ� ��� �����Ϸ��� double �� int �� ��ȯ��
	// int a = (int)123.0; ���� ��� ����� �� ��ȯ

	
	
	//numeric promotion ���� ���� ū ������  
	float f = 1.0f; //double �� float ���� ŭ(�޸�)
	double d = f;  // numeric promotion

	//���е��� �������� ������ ����
	//ex) int -> long , char -> int , int -> float


	
	
	//numeric conversion ū ���� ���� ������ , type�� �ٲ�� �� 
	double b = 3;
	short s = 2;

	
	//������ ���� �� ����
	int i = 30000;
	char c = i; //char ������ 255 ������ singed ���-128~ 127 ������ ������ i�� �� ���� �� ����

	//���� c�� char type���� ����ϸ� ����� ���� ���鳢 ������ ����� ����ȯ static_cast �� �����
	cout <<static_cast<int>(c) << endl; // 48
	
	//double �� ���е��� ���� ������ �������� �ս��� �Ͼ �� ����  possible loss of data
	double d1 = 0.123456789;
	float f1 = d1;
	cout << std::setprecision(12) << d1 <<"\n" << f1 << endl;

	//�������� �Ǽ������� �ٲܶ��� �ִ��� ����ϰ� �ٲ���
	int i2 = 1234;
	float f2 = i2;
	cout << std::setprecision(12) << i2 << "\n" << f2 << endl;

	// �Ͻ��� ����ȯ�� �Ҷ� float�� double �޺κ��� �Ҽ��� �κ��� ������
	float f3 = 3.14;
	int i3 = f3;
	cout << std::setprecision(12) << f3 << "\n" << i3 << endl;



	//���� ���� �������� ������ ������ �������� ����
	int i1 = 2;
	char c1 = i1;
	cout << static_cast<int>(c1) << endl; // �̶� ������ ����

	


	// unsigned �� �����ؾ���
	// unsigned ���� ����Ѱ� unsigned�� �������� ��
	cout << 5 - 10 << endl;
	cout << 5u - 10 << endl; // u �� unsigned
	cout << 5 - 10u << endl;
	cout << 5u - 10u << endl;

	
	//����ȯ���� �켱������ ����
	//int ���� ������(4byte ����)�� int�� �ٲ���
	//�켱������ ������ ���������� �ȹٲ�, unsigned int �� int�� �ȹٲ�
	//int, unsigned int, long , unsigned long,
	//long long, unsigned long long, float, double, long double(highest)


	
	
	// ����� ����ȯ(Explicit Type Conversion (casting) )
	int x = int(4.0);   //c++ style
	int x1 = (int)4.0;  //c	  style
	int x2 = static_cast < int>(4.0); //�������� ��ɻ� ���̴� ����

	return 0;
}