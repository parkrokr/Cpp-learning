// ���� ���� Reference Variable

//Ư�� ��쿡 �����ͺ��� ����ϱ� ����
//�����ʹ� null �� �������� ref�� null�� ������ ����(�ݵ�� �ʱ�ȭ)
//�����ʹ� �Ҵ��Ҷ� ���� ��� ���Ͽ� &�� ���� �ּҰ��� �Ҵ�(���� ����)
//ref�� ��������� �״�� �Ҵ�(���� ����)
//�Լ��� parameter �� ���� ���޽� �����ʹ� �� ����(->�޸� �Ҹ�), ref�� ������x(->�޸� �Ҹ�x)

#include <iostream>

using namespace std;

//�ۿ� ������ ����
void doSomething(int n) 
{
	n = 10;
	cout << "In doSomething" << n << endl;
}

//�ۿ� ������ ��
void doSomething_ref(int& n) //(const int& n)  //�Է��� �ִ� ���� �Լ����� ��ġ�� ���� ���� ��� const ���
{
	cout << &n << endl;

	n = 10;  //(const int& n)�� ���ƹ����� ���� ��ġ�� ����
	cout << "In doSomething" << n << endl;
}

//�迭�� ref�� �޴� �Լ�
void printElements(/*const*/ int(&arr)[5]) //�Լ��� ref�� �ѱ涧�� elements ������ �ʿ���
{
	for (int i = 0; i << 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;

	//������ ���
	int* ptr = nullptr;
	ptr = &value;

	//���� ���
	int& ref = value; // 5

	cout << ref << endl;

	ref = 10;  //*ptr = 10; ó�� �۵���

	cout << value << " " << ref << endl;  //10 10


	//�ּ� ����
	cout << &value << endl;
	cout << &ref << endl;   //&value �� ����
	cout << ptr << endl;    //&value �� ����
	cout << &ptr << endl;


	//ref �� value �� ���� ���� �ּҵ� ���� ->value �� �ٸ� �̸�ó�� ���

	//ref�� �ݵ�� �ʱ�ȭ �ʿ� <-�����̱� ������ ���� �̸��� �ʿ�
	//int &ref; �Ұ���

	//ref���� �ݵ�� ����,lvalue �� ������, literal �� ����
	//int &ref = 104; �Ұ���

	//const ����
	/*
	//����
	int x = 5;
	int &ref = x; 
	
	//�Ұ���
	const int y = 5;
	int &ref = y;

	//����
	const int y = 5;
	const int &ref = y;
	*/


	//re-assign
	int value1 = 5;
	int value2 = 10;

	int& ref1 = value1;

	cout << ref1 << endl;  //5

	ref1 = value2;

	cout << ref1 << endl;  //10



	//ref
	int n = 5;

	cout << n << endl;  //5

	doSomething(n);  //10

	cout << n << endl;  //5

	//n�� �ִ� 5�� �Լ� n �� �����ϰ� �ٲ����� ���� �ִ� n �� �� 5�� ������ ����

	//ref ����ϱ�
	cout << n << endl;  //5

	cout << &n << endl;

	doSomething_ref(n);  //10   , ���� �ּҰ��� ����

	cout << n << endl;  //10

	
						
	//ref�� ���� �Ǹ� ���� ��ü�� �Ѿ�� ����
	//�����͸� ����ϸ� ������ �ּҸ� �ѹ� ���������� ref�� �ּ� ���� ���� ���� ��ü�� �Ѿ->ȿ���� �� ����

	//�Է��� �ִ� ���� �Լ����� ��ġ�� ���� ���� ��� const ���


	//�迭�� �Լ��� �־��ٶ��� ref ��� ����
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };
	
	printElements(arr); //�Լ��� ref�� �ѱ涧�� elements ������ �ʿ���



	//struct �� ���� ����
	Other ot;

	//v1�� ���� �ϰ� ���� ���   
	//ot.st.v1 = 1;   //->��� ���ŷο���

	//ref ���  
	int& v1 = ot.st.v1;
	v1 = 1;
	//v1�� ������ ���̴� ��� ref�� �ϸ� ���ϰ� ȿ���� ����



	//ref�� ������ ��  (ref �� ���������� �����ͷ� �����Ǿ� ����)
	int value3 = 5;
	int* const ptr3 = &value3;
	int& ref3 = value3;

	//int* const ptr3 = &value3; �� int& ref3 = value3; �� ��ɻ� ����

	//������ ���
	*ptr3 = 10;
	ref3 = 10;
	
	//��� �����ʹ� ������ ������ ����

	return 0;
}