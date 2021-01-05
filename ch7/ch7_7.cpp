//�Լ� �����ε� Function Overloading 

//������ �̸��� ���� �Լ��� �������� ����°�
//parameter�� �Լ� ����, return type ������ ���� �ȵ�
//��쿡 ���� ��ġ�� �ȵǼ�, ��ġ�� ���� �ָ��ϰ� �����ؼ� ������ �� �� ����


#include<iostream>

//x �� y�� ���ϴ� �Լ���
//int
int addInt(int x, int y)
{
	return x + y;
}
//double
double addDouble(double x, double y)
{
	return x + y;
}

//������ parameter �� �ٸ��� �ϴ� ����� ����� ��� �Լ������ε� ��� ����
//int
int add(int x, int y)
{
	return x + y;
}
//double
double add(double x, double y)
{
	return x + y;
}

//���� �̸��� ���� ���� ���

//parameter�� ���� �����޴� ���
void getRandomValue(int &x){}
void getRandomValue(double &x) {}


//tyepdef�� �ᵵ ������ �Ұ���
//typedef int my_int;
//void print(int x) {}
//void print(my_int x) {}

//���� �ȵ� , �̹� �ٵ� �ִٰ� ��


//������ �ȵǴ� ���
void print(const char* value) {}
void print(int value) {}

void print_2(unsigned int value){}
void print_2(float value){}


using namespace std;

int main()
{
	add(1, 2);  //return int
	add(3.0, 4.0);  //return double

	//�Լ��� ���� �ٸ����� ����   parameter
	//�̸��� ������ �ƴ�
	//�Լ� �̸��� ���Ƶ� parameter �� �ٸ��� �ٸ� �Լ��� ������
	//parameter�� ���� �Լ� �ΰ��� ������ ������ ����

	//c++���� return type �� �ٸ��͸����� �Լ� �����ε��� �ȵ�


	//�־��� ���ڿ� parameter �� ���� ������ ���� �Լ��� ã�Ƽ� ������

	//� add()�� ��������� compile �Ҷ� �����Ǿ�� ��



	//���� �̸��� ���� ���� ���

	//parameter�� ���� �����޴� ���
	int x;
	getRandomValue(x);

	// int x = getRandomValue(x);

	//x �� �Է����� ���� �������°��� ������ �Ȱ� �� ����
	// int x = getRandomValueInt(x);  �Լ� �̸����� ǥ�����ֱ�
	// int x = getRandomValue(int());  ���� �־���� �����ε��� �� �� ����



	//������ �ȵǴ� ���
	print(0); // int �� ���� ��Ȯ�� �� �� ����
	print('a'); //char �� �ƴ� *char �̱� ������ 'a'�� int �� �ν��ϰ� ����
	//�� �´°��� ��� ������ �ִ°��߿� ���� ����Ѱ� ���� ��� �� �ȸ��� ���

	print("a");  //const char* value �� �ƴϸ� ��ġ�� ��ã��(�´� �Լ��� ���ٰ� ����)


	//�ʹ� �� �´� ���
	//print_2('a'); //'a'�� �� �´°��� ������ unsigned int �� float �� �ٲ� �� ����   ambiguos ���� �߻�
	//print_2(0); //ambiguos ����
	//print_2(3.141592);  //ambiguos ����

	//��Ȯ�ϰ� �ֱ�
	print_2((unsigned int)'a');		//unsigned int
	print_2(0u);					//unsigned int
	print_2(3.141592f);				//float



	//��Ȯ�ϰ� ������ �ϸ� �Լ� �����ε��� ��ȣ���� ������ �� ����
	//�⺻������ ��Ȯ�ϰ� �����ϴ°��� �߿�
	//�׳� �ٸ� �̸��� ���°� ������ �����ε����� ���� ���� ����
	//�ּ� �޾Ƽ� ���ǻ��� ����ϱ�
	

	return 0;
}