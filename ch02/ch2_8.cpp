// 리터럴 상수 literal constants

#include <iostream>

int main()
{
	using namespace std;

	
	// 숫자 뒤에 u 는 unsigned
	float pi = 3.14f;
	int i = (unsigned int)12324;// 12324u;


	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e-10;


	// Decimal : 0 1 2 3 4 5 6 7 8  9  10
	// Octal   : 0 1 2 3 4 5 6 7 10 11 12
	// Hexa    : 0 1 2 3 4 5 6 7 8  9  A  B C D E F 10

        // Octal 로 표현 하고 싶을때 앞에 0	
	int x = 012; 

	// Hexa 로 표현 하고 싶을때 앞에 0x
	int x1 = 0xF;

	// Binary 로 표현 하고 싶을때 앞에 0b 붙이기,  c++ 14 부터 binary literal 이 가능해짐
	//  c ++ 14 부터 literal 사이 ' 는 컴파일러가 무시함
	int x3 = 0b10'1111'1101'0110;
	
	cout << x << " " << x1 << " " << x3 << endl;

	// 예제의 10 같은 숫자를 magic number 라고 함
	int num_items = 123;
	int price = num_items * 10; // 10 is . . .

	// Symbolic 상수를 쓰는게 더 좋음`
	const int price_per_item = 10;
	int num_items1 = 123;
	int price1 = num_items1 * price_per_item;

	return 0;
}
