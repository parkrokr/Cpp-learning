// Auto Ű����� �ڷ��� �߷�(Type Inference)

#include<iostream>

int add(int x, int y)
{
	return x + y;
}

// �Լ� return type�� auto�� �� �� ����
auto add(double x, int y) -> double //trailing ���븦 ���� �� ����
{
	return x + (double)y;
}

/*
int		 add(int x, int y);			  �̰ź���
double	 add(int x, int y);		

auto add(int x, int y) -> int;
auto add(int x, int y) -> double;     �̰� ���� ����

*/


//auto add(auto x, auto y) ó�� auto�� parameter type���� �� �� ����


//template�� ����ϸ� ����, �������� return ���� ��ȯ�� �� ����



int main()
{
	using namespace std;

	//int a = 123; //123 �� �����̱� ������ a�� �������� �� ���̴�, ���ٿ� ������ �ΰ��� �ִ�
	
	auto a = 123; //�ڷ����� ���׿� ���� ������ �߷��ϰ� �ϴ°� ���߷��̶�� �ϰ� auto�� �����

	// �ʱ�ȭ�� ���� ������ auto�� ����� �� ����

	auto d = 123.0; //double
	auto c = 1 + 2.0; //double

	// ��� ����� � �ڷ������� ���α׷��Ӱ� �˰� �־����

	// �Լ� return type �� auto�� �� �� ����
	auto result = add(1, 2);
	cout << result << endl;
	

	return 0;
}
