//�������� �⺻���� ����

#include <iostream>
#include<typeinfo>

using namespace std;

//�Լ��� return type, parameter �� ���� ���� ����
int* doSomething(int* ptr_a)
{
	return nullptr;
}

struct Something
{
	int a, b, c, d; // 4 * 4 = 16
};


int main()
{
	// ū �޸𸮿� ����Ǿ� �ִ� ������ �߿��� �Ϻκ��� cpu�� ����ϱ� ���� �޸𸮷κ��� ������ ����
	//�޸� ��ü�� ��� �����鼭 ã�� ���� �ƴ϶� �ʿ��� �����Ͱ� ����Ǿ� �ִ� '�ּ�'�� ����Ͽ�
	//���� �����Ͽ� ������
	
	int x = 5;
	//���� ������ '����'�޸𸮸� ���, ���� �Ҵ� �޸𸮴� '��'�޸� ���

	cout << x << endl;
	
	// ���� x�� ����ϴ� �޸� �ּҸ� �˰� ���� ��
	cout << &x << endl;// & : address-of operator
	cout << (int)&x << endl; // �޸� �ּҴ� 16������ ����


	//de-reference operator (*)

	//�����ʹ� ���۷����� ����,�Ϻ�
	//c++���� �����Ϳ� ���۷����� �� ���� ����

	//de-reference �� �����Ͱ� "���� �ּҿ� ���� �� �����Ͱ� �־��"��� ���������� ����Ű�⸸ �ϴ� �Ϳ� 
	//���ؼ� "�׷� �ű⿡ ��¥ ���� �ִ��� ���� �鿩�ٺ���"��� ���������� �����ϰڴٴ� �ǹ�

	cout << *(&x) << endl; // x�� �޸� �ּҿ� ����Ǿ� �ִ� ���� ���� 5 �� ��µ�
	//������ �켱���� ������ *&x�� �������



	//�����ʹ� �ּҸ� �����ϴ� ����

	//������ ���� ����
	
	int* ptr_x = &x, * ptr_y = &x;

	// int * ptr_x ���� *�� ���ʿ� ������ �򰥸� �� ����
	// int *ptr_x = &x; ptr_y = &x; ���� ptr_y�� ������ ������ �ƴ�
	// int *ptr_x = &x; *ptr_y = &x; ������ ����� �Ǽ��� ���̱� ���� *�տ� ��ĭ�� �δ� ������ ���� �����


	//typedef int* pint;
	//pint ptr_x;

	//pint ptr_x = &x, ptr_y = &x; �� ������ ����
	//���������ͳ� ���� �����͸� ��¼�� �ѹ� ��ߵ� ��� �̷������� ������ ������ ����


	//�ּҴ� data type�� ����� ���� �߸�����
	//�����Ͱ� type�� �˾ƾ� �ϴ� ������ de_referenceing �Ҷ� 
	//� Ÿ���� �����͸� �����;� ���� �˾ƾ� �ϱ� ������

	//*ptr_x �� int type �̴�, ptr_x�� int �� ������ type���� ������ �Ǿ��� ������
	

	cout << typeid(ptr_x).name() << endl;
	//visula studio ���� int *, gcc(codeblock)���� Pi (pointer integer) �� �� 


	//�����͸� ���� ������ �迭 ������ ŭ, �迭�� �Լ� parameter�� ���� ���� ���
	//�迭�� ����� �����͸� ��� �����ϴµ� ���� �ð��� �ɸ��� ������ 
	//�����ͷ� �����ϴ� �κ��� �ּҿ� ����� �˷��ָ� �ٷ� �� ����

	
	//�پ��� data type �� ���ؼ� �� �� ����
	double d = 1.0;
	
	double* ptr_d = &d;
	//double *ptr_d = 0x00D8F744; �� �Ұ�����
	//�ƿ� �Ұ��� ���� ����, ��ŷ�� ������ �ϳ�

	
	//structure �� class ���� ����� ���� �ڷ����� ���ؼ��� �� �� ����
	Something ss;
	Something* ptr_s;

	cout << sizeof(Something) << endl;	 // 4*4 = 16
	cout << sizeof(ptr_s) << endl;		 // 4



	//������ ������ �ּڰ��� �����ϱ� ������ data type �� ������� ���� ũ�⸦ ����
	cout << sizeof(x) << endl; //4
	cout << sizeof(d) << endl; //8
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl; // 4 4  , x64���� 8 8
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // 4 4  , x64���� 8 8

	// x64���� �ּڰ��� ���� �� ��� ����


	//������ �� �� �ִ� �κ�
	//�ʱ�ȭ ���� de-referencing �� ���
	int* ptr_z;

	//cout << *ptr_z << endl; //���� ���� ���� ����



	return 0;
}