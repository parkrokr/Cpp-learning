// ��� ������ Arithmetic Operators

#include <iostream>

int main()
{
	using namespace std;

	// ���׿����ڴ� �ٿ��� ����
	// ex) 1 - -x
	int x = 7 ;		
	int y = 4; 	
	int z = x % y;

	cout << x / y << " " << z << endl;

	// / ���� �Է°��� �ϳ��� �Ǽ����� return ���� �Ǽ�
	cout << x / y << endl;
	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl;

	// c++ 11 ���� ���� ������ ��� �Ҽ��� �κ��� ����
	// -5/2 = -2.5, return ���� 0.5�� �����Ͽ� -2
	cout << -5 / 2 << endl;

	// c++ 11 ���� ������ ���� return ���� ���ʿ� �ִ� ������ ��ȣ�� ����
	cout << -5 % 2 << endl;
	cout << 5 % -2 << endl;
	cout << -5 % -2 << endl;


	z = x;
	
	// += , -= , *= , /= , %= 
	z += y; // z= z + y;

	return 0;
}