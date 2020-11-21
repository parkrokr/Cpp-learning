// 비트단위 연산자 Bitwise Operators

#include <iostream>
#include <bitset> // 2진수로 바꿔서 출력해주는 library

int main()
{
	using namespace std;

	// Bitwise Operators
	// << left  shift
	// >> right shift
	// ~ not , & and , | or , ^ xor

	// Bit 레벨에선 Unsigned 사용


	unsigned int a = 3;

	// 4 bit 까지만 출력하고 a 가 내부적으로 어떻게 이진수로 표현되는지 출력
	cout << std::bitset<4>(a) << endl; // 0011

	
	// << left  shift

	//패턴을 왼쪽으로 밀고 0으로 채움
	// bitshift 가 *같은 연산보다 더 속도가 빠름
	// 일반적인 곱하기 나누기에는 사용 못함
	unsigned int b = a << 3;

	cout << std::bitset<4>(b) << " " << b << endl; // 0110 

	cout << std::bitset<16>(a) << endl;
	cout << std::bitset<16>(a << 1) << " " << (a << 1) << endl;
	cout << std::bitset<16>(a << 2) << " " << (a << 2) << endl;
	cout << std::bitset<16>(a << 3) << " " << (a << 3) << endl;
	cout << std::bitset<16>(a << 4) << " " << (a << 4) << "\n" << endl;

	// >> right  shift

	a = 1024;

	cout << std::bitset<16>(a) << endl;
	cout << std::bitset<16>(a >> 1) << " " << (a >> 1) << endl;
	cout << std::bitset<16>(a >> 2) << " " << (a >> 2) << endl;
	cout << std::bitset<16>(a >> 3) << " " << (a >> 3) << endl;
	cout << std::bitset<16>(a >> 4) << " " << (a >> 4) << "\n" << endl;


	// ~ not

	// !a 는 logicla not, bitwise not 은 ~a

	cout << std::bitset<16>(a) << endl;
	cout << std::bitset<16>(~a)<<" "<<(~a) << "\n" << endl; // ! = Logical NOT


	// and( & ) , or ( | ) , xor( ^ )

	// 이진수 표연은 앞에 0b 를 붙임 

	unsigned int x = 0b1100;
	unsigned int y = 0b0110;

	cout << x << " " << y << endl;

	cout << std::bitset<4>(x & y) << endl; // bitwise AND
	cout << std::bitset<4>(x | y) << endl; // bitwise OR
	cout << std::bitset<4>(x ^ y) << endl; // bitwise XOR


	// bitwise operator 도 assignment 에 결합해서 사용할 수 있다
	x = x & y; // x &= y;   

	
			   //Quiz
	/*0110 >> binary to decimal
	5 | 12
    5 & 12
	5 ^ 12*/

	unsigned int c = 0b0110;
	cout << c << endl;
	cout << "   " << bitset<8>(5) << "\n   " << bitset<8>(12) << endl;
	cout << " | " << bitset<8>(5 | 12) << endl;
	cout << " & " << bitset<8>(5 & 12) << endl;
	cout << " ^ " << bitset<8>(5 ^ 12) << endl;

	return 0;
}