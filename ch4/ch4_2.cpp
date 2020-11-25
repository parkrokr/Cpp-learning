// ���� ����(Global Variable), ��������(Static Variable), ���� ����(Internal Linkage), �ܺ� ����(External Linkage)


/*
	int g_x; // �ʱ�ȭ�� ���ϰ� ���Ǹ� �ϴ°�� external linkage �� �� �� ����
	static ing g_x; // internal likage �ٸ� cpp���Ͽ��� ������ �� ���� �ʱ�ȭ�� �Ǿ����� ���� ����������
	const int g_x(0); //�ʱ�ȭ�� �ݵ�� �ʿ���, ���� ���Ŀ� �ȹٲ�

	extern int g_z;
	extern const int g_z;// �ٸ��� ��� �Ѱ������� ���� �ʱ�ȭ �������

	int g_y(1); //external linkage�� �ʱ�ȭ�� �� ��������
	static int g_y(1);//�ٸ������� ������ �Ұ����� ���� ���� ������ �ʱ�ȭ
	const int g_y(1); //���� ���� �ȿ����� ���� ������ ���� �ٲܼ� ���� ����

	extern int g_w(1);// �ʱ�ȭ�� �ٸ� cpp���Ͽ��� ���� ������ ��������
	extern const int g_w(1);// �ʱ�ȭ �Ǿ��� ���� ���ٲٰ� �ٸ� cpp���Ͽ��� ���� ����
	�ʱ�ȭ�� �ѹ� ���ָ� �ٸ������� �ʱ�ȭ�� �ϸ� �ȵȴ�.
*/


// �������� ������ ��� ���ؾ���, ���α׷��� Ŀ���� ������ �������

#include<iostream>
#include "MyConstants4_2.h"

using namespace std;

int value = 123;

//int a = 1;

// ���������� static�� ���̸� �ٸ� cpp���Ͽ��� ����,����� �Ұ�����
static int g_a = 1;


//forward declaration
void doSomething();// �տ� extern �̶�� Ű����� �����Ǿ�����
extern int b; //extern �̱� ������ ���α׷� ��ü���� ���� �̸��� ���� ������ �ϳ����� ��, �ٸ������� �ʱ�ȭ �ϸ� �浹��


void doSomething_()
{
	// static �̶� a�� os�κ��� ���� �޸𸮰� static �̴�, ���� �޸𸮸� �����Ѵ�
	// static ������ ����ɶ� ���� �޸𸮸� ����ϰ� �ʱ�ȭ�� �ѹ�����, �ʱ�ȭ�� �ݵ�� �ʿ���
	// �Լ��� ��� ȣ��Ǿ����� ����ϴ� ������ debuging �� ������

	static int a = 1; // static ������ �޸𸮴� �����Ǿ� ������ ���� �����̱� ������ �ٸ������� �� ���� ����
	//int a = 1; �� ��
	++a;
	cout << a << endl;
}


int main(void)
{
	// value �� ���� global
	cout << value << endl;
	
	// local variable ��������
	// ������ �������� ��밡��, ������ ��� ���� ���,���� ����,scope ����,duration ����
	int value = 1;// ���� �̸��� ���� ������ namehiding �� �����

	cout << value << endl;
	cout << ::value << endl;//:: ���� ������ Global scope operator ����Ͽ� �ٸ� ������ ���ǵ� ���� ���

	// a �� static �϶�, global �϶� ��
	// �������� a�� �� cpp�� �ѹ� ����Ǳ� ������ static�� �����ϰ� �۵���
	// ���������� �����ϸ� ���������� ����� ������ ���������
	// �Լ��� int a�� �޴½����� �� �����ϴ� ���, ���������� g_�� ���̴� ������ �̸��� �ٸ��� �� ���� �ϴ� ����� �ִ�
	// ���� ������ ��ü������ ���� �������� ����� �ּ�ȭ
	doSomething_();
	doSomething_();
	doSomething_();
	doSomething_();

	
	//local variable �� �ٸ� ���Ͽ� �ִ� ���𰡿� ���� �� ���� ����
	
	//Internal linkage �� ���� cpp ���Ͽ����� �������� �۵��ϴ� ��������
	//External linkage �� �ٸ� cpp ���Ͽ����� ���������� ����� �� �ִ�

	doSomething();// ���� ������ �ʿ���
	cout << b << endl;//ó�� ����� test4_2.cpp���� �ʱ�ȭ



	cout << "In ch4_2.cpp file " << Constants::pi << " " << &Constants::pi << endl; //& �տ� ���̸� �ּ�
	doSomething();
	// ������Ͽ��� ���� ���ְ� MyConstants4_2���� �ʱ�ȭ�� ���ָ� pi�� ���� �ּҸ� �����


	
	return 0;
}
