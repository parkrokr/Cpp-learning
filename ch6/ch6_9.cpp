//������ ����� �迭 �ε��� Indexing

#include<iostream>

using namespace std;

int main()
{
	int value = 7;
	int* ptr = &value;

	//10������ �������� int �� ĳ���� �ϴ� ��� unsinged int pointer type ���
	//int ���̶� ��ĭ�� 4
	cout << uintptr_t(ptr-1) << endl; 
	cout << uintptr_t(ptr) << endl;
	cout << uintptr_t(ptr+1) << endl;
	
	//doubl��
	double d_value = 7.0;
	double* d_ptr = &d_value;

	//double �� 8 byte �� 8
	cout << uintptr_t(d_ptr - 1) << endl;
	cout << uintptr_t(d_ptr) << endl;
	cout << uintptr_t(d_ptr + 1) << endl;
	


	//������ ������ �����Ҷ� data type �� ���� �����ϴ� ���� :
	//de-referencing �Ҷ� � type���� ���� �����;����� �˱� ����
	//������ ������ �Ҷ� (short ������ +1�� 2����Ʈ, int ������ 4����Ʈ�̰� double ������ 8����Ʈ)


	//int �� array ������ 4�� ������ (�ּҰ� �̿��� ����)
	int array[] = { 9,7,5,3,1 };

	ptr = array;  //*ptr = array �ϸ� ���� �߻�, *ptr �� de-referencing �� �ű� ����

	//iterate �ϱ�
	for (int i = 0; i < 5; ++i)
	{
		//cout << array[i] << " " << (uintptr_t) & array[i] << endl;
		cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
	}


	//���ڿ�
	char name[] = "jackjack";

	const int n_name = sizeof(name) / sizeof(char);

	char* c_ptr = name;

	for (int i = 0; i < n_name; ++i)
	{
		//cout << *(name + i);
		cout << *(c_ptr + i);
	}
	cout << endl;

	//���ڿ� ����� while �� break �� ����Ͽ� null character ���� ����ϱ�, ++ptr

	while (*c_ptr != '\0')
	{
		cout << *c_ptr++;
	}

	c_ptr = name;
	while (1)
	{
		if (*c_ptr == '\0')break;
		cout << *c_ptr++;
	}

	return 0;
}
