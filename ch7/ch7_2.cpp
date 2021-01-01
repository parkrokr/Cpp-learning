//���� ���� �μ� ����  Passing Arguments by Value ( Call by Value)

#include<iostream>

using namespace std;

void doSomething(int y)
{
	cout << "In func " << y << " " << &y << endl;
}

int main()
{
	//���� ���� ����
	//�Լ� ȣ���� �ϸ� int y �� ����ǰ� 5��� literal �� �ϳ��� �Լ��� y �� ���簡 �� �ʱ�ȭ�� ��
	doSomething(5);

	//������ ����ϴ� ���
	int x = 6;

	cout << "In main " << x << " " << &x << endl;

	doSomething(x);
	doSomething(x + 1);
	//������ ���޵Ǵ°� ���� x�� ����ִ� 6�̶�� ��(value)�� arguments �μ� �Լ� parameter�� ���޵�
	//x�� ����Ǿ����� �ּҵ� x�� ���ƾ� ������ ������ �ּҸ� ����غ��� �ٸ� ���� �� �� ����
	//x+1 �� 7�̶�� ���� ���޵Ǵ� ����


	//���� ���� ���� �����
	//�Լ� y�� x�� �ּҰ� �ٸ��� ������ �Լ����� �ۿ� ������ �� �� ����
	//�ڵ尡 ���������� �Լ��� �ڱ��ϸ� �ϴ°� �����
	//� ��Ȳ���� �ܺο� ������ ���ľ� �� ���� ������ ���� ���� ������ ����



	return 0;
}