//���ǹ� if

#include<iostream>

using namespace std;

//�� ������ ���� ���� return �ϴ� �Լ�
int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
	
	//if (x > y)  return y;
	//else	return x;

	//return (x > y) ? y : x;
}

int main()
{
	int x;
	cin >> x;

	//if ������ ���� ������ �ϳ��� ��쿡�� {}�� �Ƚᵵ ��
	if (x > 10)
	{
		cout << x << " is greater than 10" << endl;
	}
	else
		cout << x << " is not greater than 10" << endl;
	
	if (1)
		int x = 5;
	else
		int x = 6;

	cout << x << endl; // cin ���� ���� x �� ��µ�, if �� {}�ȿ��� ������ ������ {}�� ����� ����
	
	//chaining
	if (x > 10)
		cout << "x is greater than 10" << endl;
	else if (x < 10)
		cout << "x is less than 10" << endl;

	else // if (x == 10) �ּ� �޾��ֱ�
		cout << "x is exactly 10" << endl;


	//if �� else {} �ȿ� �ٽ� if���� �ְ� �� �ȿ� if ���� ������ �������� �ľ��ϱ� �������
	//���������� �����ϰ� ��Ȳ�� ��Ȯ�� ��쿣 �������� �糯�� ����
	if (x > 10)
		cout << "x is greater than 10" << endl;
	else
	{
		if (x < 10)
		cout << "x is less than 10" << endl;

		else
		cout << "x is exactly 10" << endl;
	}

	
	//�̷������� else if �������� ���������� { }�� ���� ��Ȯ�ϰ� ���ش�
	//������ else �� ���� ����� if�� �ٰ� �ȴ�
	//indenting(�鿩����) �� ������ �����϶� ����� �ǵ��Ѵ�� �۵��ȵ�
	/*if (x >= 10)
		if (x <= 20)
			cout << "x is between 10 and 20 " << endl;
		else
			cout << ". . ." << endl;*/

	if (x >= 10)
	{
		if (x <= 20)
			cout << "x is between 10 and 20 " << endl;
		else
			cout << ". . ." << endl; // �� else �� if (x <= 20)�� �ɸ�
	}

	if (x >= 10)
	{
		if (x <= 20)
			cout << "x is between 10 and 20 " << endl;
	}
		else
			cout << ". . ." << endl; // �� else �� if (x >= 10)�� �ɸ�


	//�������� ��� ����
	int a, b;
	cin >> a >> b;

	if (a > 0 && b > 0)
		cout << "both numbers are positive" << endl;
	else if (a > 0 || b > 0)
		cout << "one of numbers are positive" << endl;
	else
		cout << "Neither number is positive" << endl;


	//if ���� ���α׷��� ����ϰ� �ߴܽ�Ű�ų� �Լ� ������ ���߰� �ٷ� return �ؼ� �������� ���� ����
	if (x > 10)
		cout << "A" << endl;
	else if (x == -1)
		return 0; //exit(0) 
	else if (x < 0)
		cout << "B" << endl;

	cout << "Hello" << endl; //x == -1 �̸� �� ������ ������� �ʰ� ���α׷��� ����


	//null statment
	if (x > 10)
		; // �� null statment �� ������ �ּ� �ޱ�

	//����
	if (x > 10);
	{
		x = 1; //���� ; ������ if���� ������� �� ���� �����
	}


	//����
	if (x = 0) //x = 0; if(x) -> �׻� false
		cout << x << endl;

	return 0;
}