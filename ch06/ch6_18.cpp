//void ������

#include <iostream>

using namespace std;

//void pointer �� generic pointer ��� �Ҹ��� (������)

enum Type
{
	INT,
	FLOAT,
	CHAR
};


int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr;

	//�ּ��̱� ������ type �� ������� ���� ����
	//��� void type �̱� ������ ���� type ���� ��
	ptr = &i;
	ptr = &f;
	//ptr = &c;  //���ڿ��� �ν�

	//�ּҴ� �����ϰ� ����
	cout << &f << " " << ptr << endl;

	//de-referencing �Ұ���
	//cout << *ptr << endl;
	cout << *static_cast<float*>(ptr) << endl; //ĳ��Ʈ �ϸ� de-referencing ����


	//int �� �������� ��� ������ ������ ����� �� ����
	int* ptr_i = &i;

	cout << ptr_i << endl;
	cout << ptr_i + 1 << endl;


	//void �����ʹ� ������ ������ �Ұ���
	//+1 �� �� ����Ʈ���� �𸣱� ����
	//cout<<ptr + 1 << endl;


	//��¿ �� ���� ����ؾ� �ϴ� ��찡 ����
	Type type = FLOAT;

	if (type == FLOAT)
		cout << *static_cast<char*>(ptr) << endl;
	else if (type == INT)
		cout << *static_cast<int*>(ptr) << endl;

	//�ֱ� c++ �������� �̷��� ���ص� �Ǵ� ������ ����

	return 0;
}