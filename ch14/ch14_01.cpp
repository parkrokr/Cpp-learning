// 예외 처리의 기본 Exception Handling

//좋은 프로그래머라면 정상적인 상황뿐만 아니라 비정상적인(예외적인) 상황에서도 안정적으로 작동할 수 있게 해야함


//throw 하는 type 에 대해서 catch 를 하고 만약 맞는 catch 가 없으면 casting 해서 억지로 받지 않고 
//런타임에러를 발생


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


//프로그램이 정상적으로 작동하는지 체크하는 방법
//compile time 또는 debut 할때 미리 준비하는 방식으로 assert 같은 것이 있음


//주어진 문자열에서 특정한 글자를 찾는 함수
int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
		if (string[index] == ch)
			return index;
	
	return -1; //no match 
	//index 에서 나올 수 없는 값을 return
	//이 함수를 호출하는쪽에서 문제가 있을때 -1 이 온다는걸 알고있어야 함
}

//x 를 y 로 나눔, y 가 0일 경우 나누기를 할 수 없음, 실패시 bool 값을 return
//paramter 로 그냥 result 를 보내는 방법도 있음, 취향차이
double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;  //실제로 이 0.0 을 사용하면 안됌
	}

	success = true;
	return static_cast<double>(x) / y;
}

int main()
{
	bool success;	//일종의 flag 변수를 하나 만듬
	double result = divide(5, 3, success);	//호출을 할때 flag 변수를 넣어줌

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	
	//! 를 통해 체크하기도 함
	//file 입출력에 대해선 뒤에 나옴
	//input_file 의 초기화를 하고 체크를 함
	//흔하게 사용되는 패턴
	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << endl;


	//이런 방식들이 보기에 깔끔하진 않지만 전통적으로 c++ 에선 이런 방법들을 써왔음
	//첫번째로 퍼포먼스 때문에
	//두번째로 마땅히 대체할 문법이 없었음

	// 예외처리는 관점이 약간 다름
	// throw-try-catch 로 이루어지는 예외처리는 위에 방식을 완전히 대체하려는 것은 아님
	// 문법적으로 좀더 깔끔해 보이지만 예외처리를 하게 되면 느려지는 면이 있음
	// 퍼포먼스가 굉장히 중요한 경우 예외처리가 느려질 가능성이 있는곳에선 사용하지 않음
	// 빅데이터 분석을 하는데 만약 데이터가 들어있는 입력파일을 읽지 못했으면 절대 진행을 하면 안됨
	// 그럴 경우 위에처럼 일반적인 프로그래밍 범위 안에서 처리하는게 보통
	
	//예외처리가 빈번하게 사용되는 곳은 정말로 예측할 수 없는 일이 많이 벌어지는 경우
	//서버 같은 경우 네트워크 환경, 여러 예측할수 없는 일들이 많이 벌어져도 버텨야 함
	//예측 할 수 없는 반응이 일어나도 작업을 지속해 나가기 위해 사용하는 경우가 많음
	
	//분야에 따라 안쓰는 분야도 많음, 대신에 써야 하는 분야는 아주 잘 구현해야됨



	//예외 처리는 try, catch, throw 로 이루어져 있음
	//try 는 시도, 시도하다가 감당할 수 없으면 throw 를 해서 예외를 던짐
	//catch 는 던져진 error 를 받아서 처리

	//try, catch, throw
	double x;
	cin >> x;

	try
	{
		//문제가 생길 수 있는 부분을 try 안에 넣어줌
		//sqrt 에 들어가는 숫자가 0보자 작을경우 구할 수 없음

		if (x < 0.0)throw std::string("Negative input"); //예외 발생시 문자열로 에러메시지를 던져줌

		cout << std::sqrt(x) << endl;  //입력된 x 가 정상이면 그냥 실행하면 됨
	}
	catch (std::string error_message) //catch 에서 에러메시지를 잡아챔
	{
		//do something respond
		cout << error_message << endl;
	}


	//주의사항 :
	//auto casting 이 안됨 implicit(암시적) 형변환이 안됨, 아주 엄격하게 처리함
	
	//만약 throw 에서 그냥 문자열,const char* 로 던지는데 catch 에서 string 으로 받고 있는경우
	//함수호출할땐 argument 로 문자열 넣어줬으면 알아서 string 으로 바꿔주었음
	//실행하면 runtime error 발생
	//throw 로 에러를 던졌는데 아무곳에서도 에러를 받아주지 못한것임

	try
	{
		// something happend
		
		
		//throw - 1;

		//throw 1.0; //double 을 던질때 받아줄 catch 가 없음(double 을 int 로 절대 casting 안해줌) 

		//throw "My error message ";

		throw std::string("My error message ");
	}
	catch (int x)
	{
		cout << "Catch inteager " << x << endl;
	}
	catch (double x)  //double 로 받아주는 catch 가 없으면 runtime error
	{
		cout << "Catch double " << x << endl;
	}
	catch (const char* error_message)
	{
		cout << "Char * " << error_message << endl;
	}
	catch (std::string error_message)
	{
		cout << "std::String" << error_message << endl;
	}

	//throw 하는 type 에 대해서 catch 를 하고 만약 맞는 catch 가 없으면 casting 해서 억지로 받지 않고 
	//런타임에러를 발생


	return 0;
}