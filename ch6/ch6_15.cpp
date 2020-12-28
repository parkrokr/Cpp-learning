//����(Reference) �� const

#include <iostream>

using namespace std;

void doSomething(const int& x)
{
	cout << x << endl;
}

int main()
{
	int x = 5;
	int& ref_x = x;

	//����
	//int x = 5;
	//const int& ref_x = x;

	//�Ұ���
	//const int x = 5;
	//int& ref_x = x;

	//����
	//const int x = 5;
	//const int& ref_x = x;

	//const int& ref_2 = ref_x;


	//����
	//int x = 5;
	//const int& ref_x = x;

	//const int& ref_2 = ref_x;


	//����
	//int x = 5;
	//int& ref_x = x;

	//const int& ref_2 = ref_x;


	//ref�� �����Ҷ� '�ּ�'�� �־����
	//int &ref_x = 5; �Ұ���

	//������ const ref ������ ����
	//const int &ref_x = 3 + 4;

	//���� �ּҵ� ���� �� ����
	//cout <<ref_x <<endl;
	//cout<<&ref_x<<endl;



	//const int ref_x = 5; �� const int &ref_x = 5; �� ����
	//�Լ� parameter �� ���۷����� ������ �Ʒ� ������ �� ������

	int a = 1;

	doSomething(a);
	doSomething(1);
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}