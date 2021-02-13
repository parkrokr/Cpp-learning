// 흐름 상태 (stream states ) 와 입력 유효성 ( input validation ) 검증

//입력이 유효한지 검증, 구현하는 방법도 있고 일반적으론 정규식을 사용하는 방법도 있음

#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterCalssification(const int& i)
{
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl;
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;

	//cctype 에 들어있음
	//return type 이 int 임
	//0 이 아니면 true, 0이면 false 로 간주하라고 reference manul 에 정의가 되어있음
	//출력을 할때 bool 로 casting 해서 출력을 하고 있음
}


//ios stream 이 어떤 상태인지 확인하는 함수들
	//ios 는 굉장히 높은 부모 클래스, 이 스트림은 콘솔,파일 스트림을 공통적을 사용할 수 있음
	//cout 이 c 의 printf 보다 길다고 느낄 수 있으나 콘솔, 파일 입출력에서 일관되게 사용할 수 있음
	//c 에서는 파일출력에서 fprintf 를 사용해야 하나 c++ 에서는 cout 코드를 가지고 파일 출력에도 사용가능
void printStates(const std::ios& stream)		
{
	cout << boolalpha;
	cout << "good()="<<stream.good() << endl;		//상태가 좋은지,good() 의 return type 이 bool 
	cout << "eof()=" << stream.eof() << endl;		//end of file 인가,파일을 다 읽었는가를 체크
	cout << "fail()=" << stream.fail() << endl;		//실패하면 true, 좋은 상태이면 false	
	cout << "bad()=" << stream.bad() << endl;		//데이터를 읽거나 쓰다가 에러나면 falg 세움

	//reference manul 참고

	//return type 이 bool 이라 깔끔하게 알 수 있음

	//std::ios::rdstate  에러상태를 비트플래그로 반환함
	//goodbit, eofbit, failbit, badbit
}

bool isAllDigit(const string& str)
{
	//입력받는 string 를 isdigit() 를 이용해서 원하는 형식인지 한글자씩 비교

	bool ok_flag = true;

	for(auto e : str)
		if (!std::isdigit(e))
		{
			ok_flag = false;		//한글자라도 digit 가 아니면 flase 
			break;
		}

	return ok_flag;
}

void classifyCharacters(const string& str)
{
	for (auto e : str) //한글자씩 다 비교
	{
		cout << e << endl;
		std::cout << "isdigit " << std::isdigit(e) << endl;		//숫자인지 비교
		std::cout << "isblank " << std::isblank(e) << endl;		//공백인지 비교
		std::cout << "isalpha " << std::isalpha(e) << endl;		//알파벳인지 비교
	}
}


int main()
{
	while (true)
	{
		//int i;
		char i;

		cin >> i;					//숫자가 들어와야 하는데 문자가 들어오면 문제가 생김
									//이때 stream 이 어떤 상태인지 확인하는 함수들이 있음

		printStates(cin);			//아래의 비트플래그를 이용하는 방법보다 더 많이 쓰이는 경향

		//정수가 잘 들어왔을때
			//good() = true
			//eof() = false
			//fail() = false
			//bad() = false
		 //int 가 아니라 double 이 들어온경우 절삭이 되긴 하지만 good 이라고 뜸

		//정수가 들어오지 않았을때(문자가 들어왔을때)
			//good() = false
			//eof() = false
			//fail() = true
			//bad() = false

		//double 을 int 에 넣는건 문제라고 잡진 않지만 숫자가 들어올곳에 문자가 들어오면 문제라고 잡음




		//std::ios::rdstate  에러상태를 비트플래그로 반환함
		//goodbit, eofbit, failbit, badbit
		
		//state 의 flag 를 받아와서 mask 를 이용해서 체크
		//이런 방식도 있지만 위에처럼 함수를 만들면 더 깔끔, 모던 c++ 이 가능 방향
		cout << boolalpha;
		cout << bitset<8>(cin.rdstate()) << endl;	//good 함수 대신에 rdstate 호출,현재의 상태를 나타내는 int 를 return
		cout << bitset<8>(istream::goodbit) << endl;	//goodbit 은 mask 임, goodbit 출력
		cout << bitset<8>(istream::failbit) << endl;	//fialbit 은 mask 임, failbit 출력
		cout << !bool((cin.rdstate() & istream::failbit) != 0) << endl;	
		
		// rdstate() 로 읽어온 flag 로부터 failbit mask 를 이용해서 현재 상태를 추출
		// & 를 해서 0 이 아니라면 fail, good 을 호출하려면 앞에 !를 붙임
		//goodbit 가 cin 에 정상적으로 정수가 들어왔을때 00000000 이라서 상태추출을 위해 failbit 를 이용해
		//간접적으로 추출하고 있음

		//이런 코드는 c 에서 많이 보임,퍼포먼스 때문에 많이 쓰는 경향이 있음
		//퍼포먼스때문에 쓴다고 하지만 정말 빨라지는지는 알수가 없음
		//이런 코드가 문제가 생기지 않지만 검증을 해야하기 때문에 조금더 시간이 걸리는 경향이 있음
		

		//cin.rdstate() == std::istream::goodbit;		//이렇게 추출하는 방법도 있음
		//어떤게 되고 안되는지는 주어진 환경에서 테스트 해봐야 될수도 있음
		


		//state 외에 들어온 입력값이 내가 원하는 문자인지를 검증하는 함수
		//i를 char 로 선언해서 받고 있음
		printCharacterCalssification(i);
		/*
		a
		isalnum true
		isblank false
		isdigit false
		islower true		//소문자니까 true
		isupper false

		A
		isalnum true
		isblank false
		isdigit false
		islower false
		isupper true

		1024
		isalnum true
		isblank false
		isdigit true		//숫자니까 true
		islower false
		isupper false


		//cin 에선 공백을 입력의 구분으로 삼기 때문에 빈칸을 못읽어드려서 isblank 를 이 예제에선 사용못함
		*/


		cin.clear();
		cin.ignore(1024, '\n');			//앞에서 입력받은 버퍼를 비우는 과정, \n 까지 1024 개를 무시함
		cout << endl;
	}


	//원하는 형태로 들어왔는지 확인하는 함수
	//지금 예제는 한글자씩 다 비교하는 방식
	//다음 강의의 정규 표현식( regular expression ) 을 쓰면 편해짐

	//입력을 string 으로 받았는지 가정
	
	cout << boolalpha;
	cout << isAllDigit("1234") << endl;		//전부 숫자			treu
	cout << isAllDigit("a1234") << endl;	//문자가 하나 있으니	false


	classifyCharacters("1234");
	classifyCharacters("a 1234");

	//핸드폰 전화번호 같은 형식이 있는 입력의 경우 
	//if 문 으로 isAllDigit() 같이 구현하는 방법이 있고
	//정규식 쓰는 방법이 있음

	//추세는 정규식을 사용하는 방식, 웹프로그래밍에선 정규식을 많이 사용함

	return 0;
}