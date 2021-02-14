// 정규 표현식 소개 regular expressions

//웹프로그래밍에서 많이 사용
//이메일 주소, 핸드폰 번호 등 다양한 형식들을 구현할 수 있음

#include <iostream>
#include <regex>		//c++11 부터 regular expressions 가 들어오기 시작함

using namespace std;

int main()
{
	//regex re("\\d*");		// 앞에 \ 하나는 뒤에 \ 가 진짜라는 의미, \d 는 숫자냐를 판별
							//숫자 하나만 판별, 여러개를 넣고 싶으면 
							//\\d+ ( 1개 이상 입력 ) 또는 \\d* ( 입력을 안받아도 괜찮다 ), 둘다 여러개 입력됨

	//regex re("[ab]");		//[] 안에 있는 a 랑 b 만 괜찮다,a ok, b ok, ab not ok, a 랑 b각각은 괜찮지만
							//개수가 안맞음
	
	//regex re("[[:digit:]]{3}");	//[[:digit:]] 부분이 \d 랑 같은 역할을 함, {3} 은 3개로 맞춰서 받겠다
									//123456789 처럼 3개이상 입력했을 경우 no match 라고 뜨긴 하지만
									// 123 456 789 로 끊어서 받고 있음

	//regex re("[A-Z]+");		//A 부터 Z 까지 입력받고 개수는 1개이상이면 ok


	//regex re("[A-Z]{1,5}");		//A 부터 Z 까지 최소 1개, 최대 5개를 받겠다


	regex re("([0-9]{1})([-]?)([0-9]{1,4})");	//[-]?는  - 가 있어도 되고 없어도 되고를 의미


	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))			//regex_match 로 위에서 입력한 규칙에 string 이 맞는지 안맞는지 판단
			cout << "Match" << endl;
		else
			cout << "No match" << endl;


		// print matches
		//sregex_iterator 를 이용해 match 하는 부분만 출력
		//reference manual 참고
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();

			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";		//match 되는 부분만 출력
			}
			cout << endl;
		}
		cout << endl;


	}





	return 0;
}