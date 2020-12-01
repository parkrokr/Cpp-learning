//���� ���� ������ Scoped Enumerations (������ Ŭ���� Enum Class)

#include<iostream>

int main()
{
	using namespace std;

	/*enum Color
	{
		RED,
		BLUE
	};

	enum Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = RED; // 0
	Fruit fruit = BANANA; // 0

	if (color == fruit)
		cout << "Color is fruit ? " << endl;
	// color �� fruit �Ѵ� 0�̱� �����̴�
	*/


	//enum class c++11 ���� ��밡��
	enum class Color
	{
		RED,
		BLUE
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = Color::RED; // 0
	Fruit fruit = Fruit::BANANA; // 0

	// color �� fruit�� �ٷ� �񱳴� ����, ĳ�������� �񱳸� �غ� ���� ����
	// �������� �� �� ���� ������ �ʾƾ� ��
	if (static_cast<int>(color) == static_cast<int>(fruit)) 
		cout << "Color is fruit ? " << endl;

	
	
	// ���� enum class ������ ���� �� ����
	Color color1 = Color::RED;
	Color color2 = Color::BLUE;

	if (color1 == color2)
		cout << "Same color " << endl;
	else
		cout << "Diffrent color " << endl;

	return 0;
}