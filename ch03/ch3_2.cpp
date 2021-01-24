// 산술 연산자 Arithmetic Operators

#include <iostream>

int main()
{
	using namespace std;

	// 단항연산자는 붙여서 쓰기
	// ex) 1 - -x
	int x = 7 ;		
	int y = 4; 	
	int z = x % y;

	cout << x / y << " " << z << endl;

	// / 연산 입력값중 하나만 실수여도 return 값은 실수
	cout << x / y << endl;
	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl;

	// c++ 11 부터 음수 나눗셈 결과 소숫점 부분을 절삭
	// -5/2 = -2.5, return 값은 0.5를 버림하여 -2
	cout << -5 / 2 << endl;

	// c++ 11 부터 나머지 연산 return 값은 왼쪽에 있는 숫자의 부호를 따라감
	cout << -5 % 2 << endl;
	cout << 5 % -2 << endl;
	cout << -5 % -2 << endl;


	z = x;
	
	// += , -= , *= , /= , %= 
	z += y; // z= z + y;

	return 0;
}