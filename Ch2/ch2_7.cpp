// 문자형 char type

#include <iostream>
#include <limits>

int main()
{
	using namespace std;

	char c1(65);  // c1 = 65; c1{ 65 };
	char c2('A'); // "Hello, world!" // std::string 문자열
	
	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

	// c-style casting
	cout << (char)65 << endl;
	cout << (int)'A' << endl;

	// cpp style casting
	cout << char(65) << endl;
	cout << int('A') << endl;
	
	// static_cast 는 compiler 에게 미리 문제없는지 체크 받는 느낌, < > 사용해야 함 
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	//input abc,ab
	char c3(65);
	
	cin >> c3;
	cout << c3 << " " << static_cast<int>(c3) << endl;

	cin >> c3;
	cout << c3 << " " << static_cast<int>(c3) << endl;

        cin >> c3;
	cout << c3 << " " << static_cast<int>(c3) << endl;


	cout << sizeof(char) << endl;
	cout << (int)std::numeric_limits<char>::max() << endl;
	cout << (int)std::numeric_limits<char>::lowest() << endl;

	cout << sizeof(unsigned char) << endl;
	cout << (int)std::numeric_limits<unsigned char>::max() << endl;
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;


	// \n   줄바꿈 문자 , \n을 지나가도 버퍼에만 담기고 콘솔 화면에 출력 안될수도 있음
	// endl 줄바꿈과 동시에 cout 버퍼에 있는 내용 모두 출력
	// std::flush 줄바꿈을 하지 않고 버퍼에 있는 내용 모두 출력
	cout << int('\n') << endl;
	cout << "This is first line \nsecond line" << endl;
	cout << "This is new first line " << std::flush;
	cout << "new second line";

	cout << int('\t') << endl;
	cout << "This is first line\a  \tsecond line \"";

	
	// windows 에서 많이 쓰는 타입, 가급적 사용 안하는 것이 좋음
	wchar_t c;
	
	// 여려가지 문자 unicode 를 쓸수 있음
	char32_t c4;

	cout << "Hello, ɸ or \u0444!\n";

	return 0;
}
