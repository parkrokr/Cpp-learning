// ����/���� ������ Increment/decrement

#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	using namespace std;

	// ++,-- �� �տ� ������ ����� ����� �Ѳ����� �̷��������
	// �ڿ� ������ ����� �ϰ� ������ �� ������ �̷���

	int x = 6, y = 6;

	cout << x << " " << y << endl;
	cout << ++x << " " << --y << endl;
	cout << x << " " << y << endl;
	cout << x++ << " " << y-- << endl;
	cout << x << " " << y << endl;


	int z = 1, w = 2;
	//int v = add(z, ++z);// do not use , �����Ϸ����� ���ǰ� �ٸ�
	int v = add(z , ++w);

	cout << v << endl;


	int a = 1;
	// a = a++; do not use, undefined

	a++;// or ++a
	cout << a << endl;

	
	return 0;
}