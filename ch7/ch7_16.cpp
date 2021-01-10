//������ȣ Ellipsis 

#include<iostream>
#include<cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...) // count �� parameter �� ���� arguments �� ����, �� ������ ...
{
	double sum = 0;

	va_list list; // ���ڿ��� ����

	va_start(list, count);

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); // int �� ��ȯ

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; // �Ǿ��� 1 �̱� ������ �ι�° 1�� ����ǰ� �������� ����
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; //�����߻�

	//������ ���ϴ´�� �־��ټ� �ִٴ� ������ ������ � type ���� ������ �̸� ������ �־�� ��
	//����ϱ� �����ϰ� ����뵵 ���� 
	//������ ������� �ʰ� �������� ����Ҷ��� ���

	return 0;
}
