// sizeof , 쉼표 연산자(Comma Operator) , 조건(부) 연산자 (Conditional Operator)

#include <iostream>

int getPrice(bool onSale)
{
	if (onSale)
		return 10;
	else
		return 100;
}

int main()
{
	using namespace std;

	// sizof opertor
	float f;

	// sizeof 연산자는 변수를 넣어도 되고 data type 을 넣어도 됨
	sizeof(float); // 4 bytes
	sizeof(f);

	//sizeof 는 함수가 아닌 연산자
	cout << sizeof(float) << endl;;
	cout << sizeof f << endl;



	//comma operator
	// for 문에서 많이 사용함
	//쉼표 연산자는 각각의 피연산자를 왼쪽에서 오른쪽 순서로 평가하고, 마지막 피연산자의 값을 반환

	int x = 3;
	int y = 10;
	
	//int z = (++x, ++y);
	++x;
	++y;
	int z = y;

	cout << x << " " << y << " " << z << endl;

	
	int a = 1, b = 10; // comma operator 가 아닌 arguments들을 구분해주는 기호
	int c;

	// comma operator 연산 우선순위가 = 보다낮음
	//c = a, b; 는 (c = a) , b; 랑 같음

	c = (++a, a + b); //12

	cout << c << endl;


	
	//conditional operator (arithmetric if)
	// 복잡한 경우엔 if문 함수로 쪼개는 경우가 읽기도 편하고 debug도 편함
	
	bool onSale = true;

	const int price=(onSale == true)?10 : 100;
	
	// if문을 쓰고 싶다면 함수로 분리 시켜야 함
	//const int price = getPrice(onSale);

	// if 문으로 할때는 price 를 const 로 막을 수 없음
	/*if (onSale)
		price = 10;
	else
		price = 100;

	cout << price << endl;*/

	
	int i = 5;

	cout << ((i % 2 == 0) ? "even" : "odd") << endl;

	
	return 0;
}
