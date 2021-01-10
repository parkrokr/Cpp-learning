//명령줄 인수 Command Line Arguments

//command line 에서 실행  Native Tools Command Prompt for Vs 
//또는 프로젝트의 Property Pages 에서 Debugging, Command Arguments 입력하는 방법이 있음

#include <iostream>
#include <string>

using namespace std;

//argc 는 main() 에 전달되는 데이터의 개수
//*argv[] 는 main() 에 전달되는 실제 데이터로 문자열의 array, char형 포인터 배열로 구성
//첫번째 문자열인 argv[0] 에는 프로그램의 실행 경로가 담겨있음


//사용자가 입력을 잘못했을 경우 오류처리를 매번 자세하게 해줘야됨
//개수가 예기치 못하게 안맞게 들어올수도 있음

//직접 구현하구나 Boost 라이브러리를 사용하는 방법이 있음 ( 준 표준 라이브러리)
//Boost.Program_options 를 사용하면 더 편리하게 사용할 수 있음
//앵간한 구현들은 Boost 라이브러리에 있음


int main(int argc, char *argv[])
{
	//문자열 array 로 들어온 값을 string 으로 받고, 필요에 따라 다른 자료형으로 변환

	for (int count = 0; count < argc; ++count)
	{
		string argv_single = argv[count]; //string 으로 바꿈

		if (count == 1)
		{
			int input_number = std::stoi(argv_single); // std::stoi() 정수로 바꿔줌, 원하는 type 으로 바꿔줌
			cout << input_number + 1 << endl; // 원하는 처리를 할 수 있음, command arguments 가 1024 일때 1025 출력
		}

		cout << argv_single << endl; 
	}


	return 0;
}