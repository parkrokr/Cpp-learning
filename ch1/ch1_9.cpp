#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int x, int y) 
{ 
	return x + y;// indenting 빈칸 만드는거, 스페이스 4개 , tab키 
}                             //뒤돌아가려면 스페이스 4번 , tab키 한번

int main() 
{
	int my_v		= 1;
	int	z			= 4;
	int num_apples	= 123;
	
	//this is important
	int x = 1 + 2;
	
	//this is important, too
	int y = 3 + 4;

	cout << "Hello,  World" /*컴파일러가 인식하는 빈칸*/ << "abcdef" << 
		"Hello Home" << endl;
	

	return 0;
}

//하드(hard)코딩은 프로그래머가 코드에서 변수값을 리터럴 같이
//고정된 값으로 직접 대입해주는 방식. 반대로 소프트(soft) 코딩은
//프로그램 실행 중에 사용자의 입력이나 외부파일, 인터넷 통신 등으로 
//데이터를 가져오는 방식
