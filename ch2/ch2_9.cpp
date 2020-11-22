// �ɺ��� ��� Symbolic Constants

#include <iostream>
#include "MY_CONSTANTS.h"
#define PRICE_PER_ITEM 30

using namespace std;

void printNumber(const int my_number)
{
	// my_number = 456; �̷������� parameter�� ���� �ٲٴ°��� ���� ����

	int n = my_number;

	cout << my_number << endl;
}

int main()
{
	printNumber(123);


	//����� ���� , �ݵ�� �ʱ�ȭ ����� �� 
	//const �� ���� �տ� ���� , ������ ���� ���� ��� ����
	const double gravity{ 9.8 };
	double const gravity1{ 9.8 };

	//gravity = 1.2; const�� �����߱� ������ �ٲ��� ����

	
	// ������ �Ҷ� �����Ǵ� compiletime ���
	const int my_const(123);
	
	
	//������Ѿ� �����Ǵ� runtime ���
	int number;
	cin >> number;

	// ���� number�� �ٲ� �� ������ special_number�� ���ٲ�
	const int special_number(number);

	// constexpr �� compile �����°� üũ��
	constexpr int my_newconst(123);

	//constexpr int special_newnumber(number); runtime ����̱� ������ �ȵ�



	// ��ũ�δ� ���� �빮��,cost�� Ư���� ��� �տ� k ������ ����
	const int k_price_per_item = 30; 
	int num_item = 123;

	// c style ( ��ũ�� ���� )
	//debug�� ����� ������, ��� ���� ������ �ʹ� �о����� ������ ������
	int price = num_item * PRICE_PER_ITEM;

	// �ٶ����� style
	int price = num_item * k_price_per_item;

	double radius;
	cin >> radius;

	double circumferce = 2.0 * radius * constants::pi;



	return 0;
}