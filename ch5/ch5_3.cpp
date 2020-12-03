// Switch-case
//break

#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	// �ʹ� ���ŷο�
	/*if (color == Colors::BLACK)
		cout << "Black" << endl;
	else if (color == Colors::WHITE)
		cout << "White" << endl;
	else if (color == Colors::RED)
		cout << "Red" << endl;*/ 

	
	/*switch (color)
	{
	case Colors::BLACK :
		cout << "Black" << endl;
		break;
	case Colors::BLUE:
		cout << "Blue" << endl;
		break;
	case Colors::GREEN:
		cout << "Green" << endl;
		break;
	}*/


	//::BLACK �ϴ°��� ������ �� ����
	//using �� ���� Colors �� namespace �� �ƴ�
	//printColorName()�� enum class ������ ���� ����
	//����� ���������� int �� ó���Ǳ� ������ static_cast ����ϸ� ����

	switch (static_cast<int>(color))
	{
	case 0:
		cout << "Black" << endl;
		break;
	case 1:
		cout << "Blue" << endl;
		break;
	case 2:
		cout << "Green" << endl;
		break;
	}
}

int main()
{
	printColorName(Colors::BLACK);

	//�Է¹��� ���ڸ� ���ڷ� ����ϴ� �Լ�
	int x;
	cin >> x;

	switch (x)
	{
	/*case 0:
		cout << "Zero";
	case 1:
		cout << "One";
	case 2:
		cout << "Two";*/
	//break; �� ���� ������ 0�� �ԷµǸ� �� �ؿ����� �� �����
	//�ǵ������� break�� �� ������ ����, Ư���� ��� �ּ����� ��Ȳ �����صα�
	//break ������ ��� switch ��Ͽ��� ����

	case 0:
		cout << "Zero";
		break;
	case 1:
		cout << "One";
		break;
	case 2:
		cout << "Two";
		break;
	}
	cout << endl; //������ endl; �� �ľ� �ϱ� ������ �ؿ��� �ѹ��� ����ǰ� �ϳ��� ���

	
	//���ǻ���
	//case �� �ȿ� ������ �������� { }���� ���α�
	//���ο��� ������ ���Ǹ� ���� ��������, ���Ǳ� ������ �����ؼ� ����ϱ�
	switch (x)
	{
		int a; //���� ���� ����, switch �� ������ ������ �����
		int b = 5; //������ ���������� �ʱ�ȭ(�޸� �Ҵ�)�� ����
	
	case 0:
		int y; //case �� ������ �������� ����, case �ۿ��� �����ѰŶ� ����
		a = 1; //���� �־��ִ°� case�� ���������� �� �� ����
		cout << a << endl;
		break;

	case 1:
		y = 5; //�ʱ�ȭ�� case 1 ������ �߱� ������ case 0 ���� y = 5;�� �ϸ� case 1���� ���������� ����
		cout << y << endl;
		break;
	case 2:
	{
		int y = 5;
		y = y + x;
		cout << y << endl;
		break;
	}
	
	//case �� ���Ǿȵ� ��� ��쿡 ���ؼ� default �� ����
	default:
		cout << "Undefined input" << x << endl;
		//break;// ���� default �� ���ؼ� break �� ���°� �Ϲ���, ���� ���� ������ ���ϰ��� ����

	}

	return 0;
}