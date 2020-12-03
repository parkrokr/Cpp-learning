//영역 제한 열거형 Scoped Enumerations (열거형 클래스 Enum Class)

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
	// color 와 fruit 둘다 0이기 때문이다
	*/
	//enum은 별도의 이름공간(namespace)를 가지고 있지 않는다.



	//enum class c++11 부터 사용가능
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

	// color 와 fruit를 바로 비교는 못함, 캐스팅으로 비교를 해볼 수는 있음
	// 실전에선 비교 할 일을 만들지 않아야 함
	if (static_cast<int>(color) == static_cast<int>(fruit)) 
		cout << "Color is fruit ? " << endl;

	
	
	// 같은 enum class 끼리는 비교할 수 있음
	Color color1 = Color::RED;
	Color color2 = Color::BLUE;

	if (color1 == color2)
		cout << "Same color " << endl;
	else
		cout << "Diffrent color " << endl;

	return 0;
}
