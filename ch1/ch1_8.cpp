// �����ڿ��� ù ���� Operators

#include <iostream>

using namespace std;

int main()
{
	int x = 2; // x is a variable, 2 is a literal, = is assignment

	int y = (x > 0) ? 1 : 2; // ���̸� ����,�����̸� ������
	//���� ������(Conditional operator)��
	//C++�� ������ ���� ������(Ternary operator)

	cout << x + 2 << endl; //binary ���׿�����

	cout << -x << endl; // unary ���׿�����

	cout << y << endl;

	cout << "My Home" << endl;


	return 0;
}