// 고정 너비 정수 Fixed - width Integers

#include <iostream>
//#include <cstdint>   //iostream 이 cstdint 를 포함

int main()
{
	using namespace std;

	std::int16_t i(5);       //2 bytes data 로 바꿔줌
	std::int8_t myint = 65;  //1 bytes data 로 바꿔줌

	cout << myint << endl;   

	std::int_fast8_t fi(5);  //int 중에서 8bit 사이즈 중에 가장 빠른 type
	std::int_least64_t fl(5);//적어서 8 bytes data type

	return 0;
}