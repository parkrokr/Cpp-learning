// 연산자 우선순위와 결합법칙 Operator Precedence and Associativity

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x = 4 + 2 * 3; // add(4, mult(2,3)) 함수로 표현하는 것보다 훨씬 편함
	cout << x << endl;
	
	
	// Unary plus, Unary minus 는 Associativity 가 Left-to-right
	int y = 1 - 2 + -3; // 앞에 +는 minus 연산자, 뒤에 +는 Unary minus (1-2)+(-3)
	cout << y << endl;
	
	
	// 우선순위를 명확하게 하고 싶으면 ( ) 사용
	// 우선순위와 결합법칙 표가 위키에 있음
	
	
	// ^ 는 수학에서 쓰는 거듭제곱 연산자가 아님
	// pow operator 는 return 값이 double
	int z = std::pow(2, 3);
	cout << z << endl;
	
	return 0;
}