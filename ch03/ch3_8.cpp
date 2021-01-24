// ��Ʈ���� ������ Bitwise Operators

#include <iostream>
#include <bitset> // 2������ �ٲ㼭 ������ִ� library

int main()
{
	using namespace std;

	// Bitwise Operators
	// << left  shift
	// >> right shift
	// ~ not , & and , | or , ^ xor

	// Bit �������� Unsigned ���


	unsigned int a = 3;

	// 4 bit ������ ����ϰ� a �� ���������� ��� �������� ǥ���Ǵ��� ���
	cout << std::bitset<4>(a) << endl; // 0011

	
	// << left  shift

	//������ �������� �а� 0���� ä��
	// bitshift �� *���� ���꺸�� �� �ӵ��� ����
	// �Ϲ����� ���ϱ� �����⿡�� ��� ����
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

	// !a �� logicla not, bitwise not �� ~a

	cout << std::bitset<16>(a) << endl;
	cout << std::bitset<16>(~a)<<" "<<(~a) << "\n" << endl; // ! = Logical NOT


	// and( & ) , or ( | ) , xor( ^ )

	// ������ ǥ���� �տ� 0b �� ���� 

	unsigned int x = 0b1100;
	unsigned int y = 0b0110;

	cout << x << " " << y << endl;

	cout << std::bitset<4>(x & y) << endl; // bitwise AND
	cout << std::bitset<4>(x | y) << endl; // bitwise OR
	cout << std::bitset<4>(x ^ y) << endl; // bitwise XOR


	// bitwise operator �� assignment �� �����ؼ� ����� �� �ִ�
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