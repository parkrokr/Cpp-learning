//std::string 과 std::wstring

//c style 문자열을 다루는것은 번거로움, 그래서 c++ 에는 string 과 wstring 이 있음

#include <iostream>
#include <string>
#include <cstddef>
#include <locale>

using namespace std;

int main()
{
	//c-style string example
	{
		char* strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		std::cout << strHello << std::endl;
	}


	//basic_string<>, string, wstring
	{
		std::string string;
		std::wstring wstring;

		//basic_string<> 이라는 템플릿으로 만들어빈 클래스의 서로 다른 instance 의 하나임
		//char 가 들어가면 string, wchar_t 가 들어가면 wstring
		//그래서 기능, 사용법은 동일함


		wchar_t wc;		//사실 unsigned short 임,
		//char 는 데이터 사이즈가 작아서 표현할수 있는 문자의 한계가 있지만 
		//wchar_t 는 데이터 사이즈를 많이 사용하는 문자를 표현하는데 사용함
		// wide-character / unicode 를 표현할때 사용함
		//국제어를 표현할때, 소프트웨어를 로컬화제이션해서 사용해야 한다면 많이 사용해야 함
		//설정하는게 조금 복잡할 수는 있음
	}


	//wsting example
	{
		// Stackoveflow.com
		//C++ Code to cout international characters using Visual Studio 2015 [closed]
		//https://stackoverflow.com/questions/33404685/c-code-to-cout-international-characters-using-visual-studio-2015


		const std::wstring texts[] =
		{
			L"안녕하세요?",						//Korean
			L"Ñá",								//Spanish
			L"forêt intérêt",					//French
			L"Gesäß",							//German
			L"取消波蘇日奇諾",					//Chinese
			L"日本人のビット",					//Japanese
			L"немного русский",					//Russian
			L"ένα κομμάτι της ελληνικής",		// Greek					//여기부턴 출력 안되고 있음
			L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ",					// Punjabi (wtf?). xD
			L"کمی از ایران ",					// Persian (I know it, from 300 movie)
			L"కానీ ఈ ఏమి నరకం ఉంది?",		//Telugu (telu-what?)
			L"Но какво, по дяволите, е това?"	//Bulgarian
		};


		std::locale::global(std::locale(""));	//이렇게 하면 locale 를 global 로 설정
		std::wcout.imbue(std::locale());		//wchar_t 를 사용하기 때문에 wcout 사용

		for (size_t i = 0; i < 11; ++i)
			std::wcout << texts[i] << std::endl;

	}

	return 0;
}