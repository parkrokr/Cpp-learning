// 문자열 소개 std::string

//cin 과 getlin()를 같이 쓸 경우 cin.ignore() 사용 

#include<iostream>
#include<string> //std::string 을 사용하기 위해 필요함
#include <limits> // 32767 같은 magic number를 쓰지 않기 위해 필요

using namespace std;

int main()
{
	cout << "Hello, World" << endl;
	//const char [13] 이라고 뜸, Hello, World는 12글자지만
	//뒤에 문자열이 끝났다는 걸 알려주는 한글자가 더있음


	// 프로그래머가 편하기 위해 사용하는 방식, 사용자 정의 자료형 , 컴파일러에 없기 때문에 include 해줘야함
	const string my_hello = "Hello, World!"; 
	//const string my_hello("Hello, World"); coppy initialization
	//const string my_hello{ "Hello, World" }; definition initilaization

	cout << my_hello << endl;

	// 기본적으로 사용하는 방식,기본 자료형
	const char my_strs[] = "Hello, World"; 
	
	
	string my_ID = "123"; 
	// 123 처럼 정수는 못넣음, 정수를 문자열로 암시적 형변환 하는 방법이 없음
	// 123같은 정수는 built in data 지만 string 은 std 이기 하지만 built in 은 아니기 문에
	// 좀더 다음단계의 기능들을 가지고 있기 때문에 바로 바꿀순 없음


	//이름과나이를 입력받는 코드
	cout << "Your age ? : ";
	//int age;
	//cin >> age;
	//std::cin.ignore(32767, '\n');  
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 32767같은 magic number를 안쓰기 위해

	string age;
	getline(cin, age);


	cout << "Your name ? : ";
	string name;
	//cin >> name;
	std::getline(std::cin, name);

	
	cout << name << " " << age << endl;
	
	//cin 을 썼을때 a b 처럼 중간에 빈칸이 있으면 앞에 a 까지 처음에 받고 뒤에 b와 enter를 밑에서 받음
	//getline 은 enter를 누를때까지 입력을 받음(line 단위로)

	//int 를 통해 age를 받고 cin으로 받으면 enter를 눌렀을때 버퍼에 있던 내용을 밑에서 다시 받는 문제가 발생
	//버퍼에 있는 내용을 한번 날려야 함
	//std::cin.ignore(32767, '\n'); -> \n을 만날때까지 32767개의 글자를 무시해라(2byte value max)
	// cin.ignore() 도 가능

	//std::numeric_limits<std::streamsize>::max() 
	//대신에 32767을 그냥 쓰거나 cin 하는 부분을 라이브러리로 만드는 방법이 있음


	
	//append 문자열 더하기 
	string a("Hello, ");
	string b("World");
	string hw = a + b; //append, +연산자가 string 안에 구현되어있기 때문

	hw += " I'm good";

	cout << hw << endl;

	//길이 측정
	string h("Hello, World");

	cout << h.length() << endl; // . 을 통해 string 안에 있는 legth() 함수를 불러옴

	//문자열 마지막에 문자열의 끝을 알리는 null character가 숨어있음
	// c style 문자열과 c++에 사용하는 string 은 차이가 있음

	return 0;
}
