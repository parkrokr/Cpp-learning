//�ݺ��� for

//for���� while ���� ��ȣ��ȯ�� ������

#include<iostream>

// ���� power �Լ�
int pow(int base, int exponent)
{
	int result = 1;

	for (int count = 0; count < exponent; ++count)
		result *= base;

	return result;
}


int main()
{
	using namespace std;

	

	//   count ����  /    count �˻�  / �� iteration �� ������ ���� 
	for (int count = 0; count < 10; ++count)
	{
		cout << count << endl;
	}

	//cout << count << endl; // count �� for ���� ���������� ������, ���� ������ for �ۿ� ����

	int count = 0;
	//   ��ĭ ����
	for (; count < 10; ++count)
	{
		cout << count << endl;
	}
	cout << count << endl; // �� 10�� �������� �߿�

	//while(true) ó�� ��� ���� ��� while ���� ()���� ��ĭ�̸� ������ ��
	//for (;;++count) // ��ĭ���� �ֵ� �������

	//count = 1 �� �ʱ�ȭ �ϰ� < ��ſ� <= �� �ᵵ ���������� �� ������

	
	//pow �Լ�
	cout << pow(2, 4) << endl;

	//�����ϴ� �ڵ�     /   >= ����
	for (int count = 9; count >= 0; --count)
	{
		cout << count << endl;
	}

	//2�� �����ϴ� �ڵ�
	for (int count = 9; count >= 0; count -= 2)
	{
		cout << count << endl;
	}

	
	
	//������ 2�� 3���� ����� �� ����	
	for (int i = 0, j = 0; (i + j) < 10; ++i, j+=2)
	{
		cout << i << " " << j << endl;
	}
	

	//���߷���
	for(int j = 0; j<9;++j)
		for (int i = 0; i < 9; ++i)
		{
			cout << i << " " << j << endl;
		}
	

	//count �� unsigned �� ����Ǹ� ������ �߻� (overflow ���ɼ�)
	/*for (unsigned int i = 9; i >= 0; --i)
		cout << i << endl;*/


	return 0;
}