//goto

#include<iostream>
#include<cmath> // sqrt()

using namespace std;

int main()
{
	//���ڸ� �Է¹ް� �� sqrt�� ���ϴ� �ڵ�
	double x;
	
	tryAgain : //label

	cout << "Enter a non-negative number" << endl;
	cin >> x;

	//x �� ������ ������ �߻�
	if (x < 0.0)
		goto tryAgain; // goto �� ������ label �� �̵�

	cout << sqrt(x) << endl;
	

	//'����'�� goto�� �ݺ��� ��ſ� ����߾���, ������ �ݺ����� goto����
	//goto�� ���� ����°� ������ �̸� ������ �ϰ� ��ȹ���� ������ ����� ������ ���̴�


	//x �� ����Ǳ����� x+=3�� �ϱ� ������ ������ �߻�
	/*goto skip;

	int x = 5;

skip:

	x += 3;*/


	return 0;
}