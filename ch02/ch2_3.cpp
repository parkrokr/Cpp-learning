// 고정 너비 정수 Fixed - width Integers

#include <iostream>
//#include <cstdint>   //iostream 이 cstdint 를 포함

int main()
{
	using namespace std;

	//어떤 플랫폼이든지 똑같은 data size를 사용할 수 있게 해줌
	
	
	std::int16_t i(5);       //2 bytes data 로 바꿔줌
	std::int8_t myint = 65;  //1 bytes data 로 바꿔줌 //int라고 생각하고 썼지만 컴파일러 내부적으로는 char로 처리함

	cout << myint << endl;   //컴파일러 내부적으로 char 로 처리했기 때문에 'a' 가 출력됨

	std::int_fast8_t fi(5);  //int 중에서 8bit 사이즈 중에 가장 빠른 type    //singed char 로 처리됨
	std::int_least64_t fl(5);//적어도 8 bytes 를 갖는 data type 		  //long long 으로 처리됨

	return 0;
}
