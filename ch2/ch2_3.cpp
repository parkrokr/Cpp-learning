// ���� �ʺ� ���� Fixed - width Integers

#include <iostream>
//#include <cstdint>   //iostream �� cstdint �� ����

int main()
{
	using namespace std;

	std::int16_t i(5);       //2 bytes data �� �ٲ���
	std::int8_t myint = 65;  //1 bytes data �� �ٲ���

	cout << myint << endl;   

	std::int_fast8_t fi(5);  //int �߿��� 8bit ������ �߿� ���� ���� type
	std::int_least64_t fl(5);//��� 8 bytes data type

	return 0;
}