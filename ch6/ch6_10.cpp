//C ��Ÿ���� ���ڿ� ��ȣ�� (Symbolic) ���

#include <iostream>

using namespace std;

const char* getName()
{
	return "Jackjack";
}


int main()
{
	//char name [] = "jackjack";
	//char *name = "jackjack"	//���� �Ұ��� 
	//"jackjack"�� ���ͷ��̰� *name �� ������ �����̱� ������ ���� �����͸� ������ �޸𸮰� �ʿ�

	//const �� �����ϸ� ����
	const char* name = "jackjack";
	

	cout << name << endl;

	//�������ΰ�
	const char* name2 = "jackjack";

	cout << (uintptr_t)name << endl;
	cout << (uintptr_t)name2 << endl;
	//�ּҰ� ����
	

	//return type ���ε� ����� �� ����
	name = getName();
	name2 = getName();

	cout << (uintptr_t)name << endl;
	cout << (uintptr_t)name2 << endl;


	//�������ΰ�
	//cout ���� ���ڿ��� Ư���� ó���Ѵ�

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello World!";
	const char* c_name = "Jack Jack";

	cout << int_arr << endl;		//�ּ�
	cout << char_arr << endl;		//���ڿ�
	cout << c_name << endl;			//���ڿ�

	//cout �� ���ڿ� �ּҰ� ������ �ּҰ� �ƴ� ��̸� �����


	char c = 'Q';
	cout << &c << endl;
	//cout�� �ּҰ� ������ ���ڿ��̶� �Ǵ��ϰ� ��� -> Q��������X�� 
	cout << *&c << endl; //de-referencing �ϸ� Q ���������� ��µ�

	return 0;
}