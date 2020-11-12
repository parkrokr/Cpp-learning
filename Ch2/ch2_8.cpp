// ���ͷ� ��� literal constants

#include <iostream>

int main()
{
	using namespace std;

	
	// ���� �ڿ� u �� unsigned
	float pi = 3.14f;
	int i = (unsigned int)12324;// 12324u;


	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e-10;


	// Decimal : 0 1 2 3 4 5 6 7 8  9  10
	// Octal   : 0 1 2 3 4 5 6 7 10 11 12
	// Hexa    : 0 1 2 3 4 5 6 7 8  9  A  B C D E F 10

    // Octal �� ǥ�� �ϰ� ������ �տ� 0	
	int x = 012; 

	// Hexa �� ǥ�� �ϰ� ������ �տ� 0x
	int x1 = 0xF;

	// Binary �� ǥ�� �ϰ� ������ �ƿ� 0b  c++ 14 ���� binary literal �� ��������
	//  c ++ 14 ���� literal ���� ' �� �����Ϸ��� ������
	int x3 = 0b10'1111'1101'0110;
	
	cout << x << " " << x1 << " " << x3 << endl;

	// 10 ���� ���ڸ� magic number ��� ��
	int num_items = 123;
	int price = num_items * 10; // 10 is . . .

	// Symbolic ����� ���°� �� ����`
	const int price_per_item = 10;
	int num_items1 = 123;
	int price1 = num_items1 * price_per_item;

	return 0;
}