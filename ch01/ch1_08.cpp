// 연산자와의 첫 만남 Operators

#include <iostream>

using namespace std;

int main()
{
	int x = 2; // x is a variable, 2 is a literal, = is assignment

	int y = (x > 0) ? 1 : 2; // 참이면 왼쪽,거짓이면 오른쪽
	//조건 연산자(Conditional operator)는
	//C++의 유일한 삼항 연산자(Ternary operator)

	cout << x + 2 << endl; //binary 이항연산자

	cout << -x << endl; // unary 단항연산자

	cout << y << endl;

	cout << "My Home" << endl;


	return 0;
}