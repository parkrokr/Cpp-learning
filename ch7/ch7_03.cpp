//������ ���� �μ� ���� Passing Arguments by Reference (Call by Reference)

//c++�� �Լ� return ���� �ϳ��� �����ϱ� ������ �Ű������� ���� ���� ��찡 ����
//�Ϲ������� �Է��� ��, ����� ������ �ڿ� ��

//const int& x ���� ���� ���� ǥ��


#include<iostream>
#include <cmath> // sin() , cos()
#include <vector>


using namespace std;

void addOne(int& y) //call by value ���ٸ� �ۿ� ������ ����ġ ������
{
	cout << y << " " << &y << endl;

	y = y + 1;
}


//�Լ��� ����� �������µ� ����ϱ⵵ ��
//degress �� �Լ��� �Է�, sin_out, cos_out �� �Լ��� ������� �����

//degrees �� ���ο��� ���� �Ⱥ��ϴ� const, &�� �ϸ� �� ����
void getSinCos(const double &degrees, double& sin_out, double& cos_out) 
{
	static const double pi = 3.141592 / 180.0; //����� �̴� ����� ���� , / ������ �ѹ��� �ϰ� 
	
	const double radians = degrees * pi ;  //�ѹ� ���ǰ� �ȹٲ�� �͵��� const��
	
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}


//������ �ѱ涧�� ����
//foo(6); �� �ȵ� // 6�� �ּҰ� ����(literal �̱� ����)
//void foo(int x) �� �ϰų� void foo(const int &x) �� �ϴ� ����� ����
//��� const int &x�� ���ο��� ���� �ٲ��� ���� ���� ����

void foo(const int& x)  //const int& x ���� ���� ���� ǥ��
{
	cout << x << endl;
}


//������ ������ ������ �޴� ���
void foo_ptr(int*& ptr)
{
	cout << ptr << " " << &ptr << endl;
}


//array�� parameter�� �����ϴ� ���

//void printElement(int(&arr)[4]) //element ������ ��Ȯ�ؾ���
//���� �̷��� array�� �������� �������� ���� array �� ����
void printElement(const vector<int>& arr)
{

}

int main()
{
	int x = 5;

	cout << x << " " << &x << endl;  //5

	addOne(x);

	cout << x << " " << &x << endl;  //6


	//�Լ��� ����� �������µ� ����ϱ⵵ ��
	//c, c++���� �Լ��� return ���� �ϳ����� �������� ���� return �� ���� ���� ����

	//������ �̸� �����ϰ� ������ �Ѱܼ� output �� �������� ������ �ϴ� ���
	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl;


	//������ �ѱ涧�� ����
	//foo(6); �� �ȵ� // 6�� �ּҰ� ����(literal �̱� ����)


	//�Է��� const int &x ó�� �ް� ����� ������ �ϴ°� �������� ���
	//��� c++���� return value optimization ����� �� ���ԵǾ� �ְ�
	//�������� return type �� �����ϴ°��� �������� �ʰԵ� 
	//���� 19.2 C++17 �Լ����� ���� ���� return�� ��ȯ�ϱ� ����



	//�����Ϳ� ���� ������ ������

	//int*& ptr �� (int*) &ptr �� �����ص� ��(�����Ϸ��� �ȹ޾���)
	//�Ǵ� typedef int* pint; �� ���� ��Ȯ�ϰ� �ص� ��
	//���������� ���� ������ ���� �Ǽ��� �پ�� �� ����

	x = 5;
	int* ptr = &x;

	cout << ptr << " " << &ptr << endl;
	foo_ptr(ptr);

	//�̷��� ������ ������ ������ ����ִ� �ּҰ��� ���� �Ѿ�� ������ ������ �ּҵ� ���� �Ѿ



	//array�� parameter�� �����ϴ� ���

	//void func(const vector<int>& arr) �� �Ϲ�����
	
	//int arr[]{ 1,2,3,4 }; //���� �̷��� array�� �������� �������� ���� array �� ����
	vector<int> arr{ 1,2,3,4 };

	 printElement(arr);
	//���� �̷��� array�� �������� �������� ���� array �� ������ ������ ������ class �� ����
	//std::array �� std::vector �� ����ϸ� ������ �� ����


	return 0;
}