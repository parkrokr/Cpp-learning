// ostream 으로 출력하기

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//숫자 출력
	
	//showpos
	cout.setf(std::ios::showpos);			//플래그 세팅, showpos 는 + 기호 보이게 하는것
											//visual studio 에선 std::showpos 가 아니라 std::ios::showpos
	
	cout << 108 << endl;					//+108

	cout.unsetf(std::ios::showpos);			//플래그를 unset, + 사인이 다시 사라짐
	cout << 109 << endl;					//109


	//hex		16진수로 출력

	//cout.setf(std::ios::uppercase);					//16진수의 알파벳이 대문자로 나오게 세팅
	
	cout << std::hex << std::uppercase;					//이렇게도 uppercase 사용 가능(manipulator 사용)
														//include <iomanip> 을 해야 사용 가능

	//cout.unsetf(std::ios::dec);						//10진수 모드 끄기
	//cout.setf(std::ios::hex);							//바로 안됨, 10진수 모드를 먼저 꺼줘야 됨
	
	//cout.setf(std::ios::hex, std::ios::basefield);	//basefield의 플래그를 세팅, 바로 됨
	
	cout << std::hex;									//setf를 안쓰고 16진수로 출력

	cout << 108 << endl;								//6C
	cout << 109 << endl;								//6D

	//다시 10진수로
	cout << std::dec;
	cout << 110 << endl;								//110			



	//bool 값 출력할때
	cout << std::boolalpha;								//문자로 true, false 출력
	cout << true << " " << false << endl;				//true false


	//setw, fill
	cout << -12345 << endl;
	cout << std::setw(10) << -12345 << endl;						//-12345
	cout << std::setw(10) << std::left << -12345 << endl;			//    -12345		오른쪽으로 붙음
	cout << std::setw(10) << std::right << -12345 << endl;			//-12345			왼쪽으로 붙음
	cout << std::setw(10) << std::internal << -12345 << endl;		//-    12345		부호와 숫자 사이 빈칸

	cout.fill('*');													//빈칸을 * 로 채움
	cout << std::setw(10) << -12345 << endl;						//****-12345
	cout << std::setw(10) << std::left << -12345 << endl;			//-12345****		
	cout << std::setw(10) << std::right << -12345 << endl;			//****-12345			
	cout << std::setw(10) << std::internal << -12345 << endl;		//-****12345		


	//setprecision		정밀도 설정
	
	//cout << std::defaultfloat;						//기본 설정, 다른설정이 안되어 있으면 기본을 되어있음
	cout << std::showpoint;								//소수점 표시,기본설정만 되어있으면 소수점이 안나옴

	cout << std::setprecision(3) << 123.456 << endl;	//123
	cout << std::setprecision(4) << 123.456 << endl;	//123.5
	cout << std::setprecision(5) << 123.456 << endl;	//123.46
	cout << std::setprecision(6) << 123.456 << endl;	//123.456
	cout << std::setprecision(7) << 123.456 << endl;	//123.456
		
	cout << std::fixed;									//소수점 뒤에 자리가 고정
	cout << std::setprecision(3) << 123.456 << endl;	//123.456
	cout << std::setprecision(4) << 123.456 << endl;	//123.4560
	cout << std::setprecision(5) << 123.456 << endl;	//123.45600
	cout << std::setprecision(6) << 123.456 << endl;	//123.456000
	cout << std::setprecision(7) << 123.456 << endl;	//123.4560000


	cout << std::scientific << std::uppercase;			//과학적 표기, e 를 대문자로
	cout << std::setprecision(3) << 123.456 << endl;	//1.235E+02
	cout << std::setprecision(4) << 123.456 << endl;	//1.2346E+02
	cout << std::setprecision(5) << 123.456 << endl;	//1.23456E+02
	cout << std::setprecision(6) << 123.456 << endl;	//1.234560E+02
	cout << std::setprecision(7) << 123.456 << endl;	//1.2345600E+02

	return 0;
}