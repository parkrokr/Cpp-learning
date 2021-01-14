// 제어 흐름 소개 Control Flow

/*
	중단 Halt
	
	반복(루프) Loops
		while, do while, for

	점프 Jump
		goto, break, continue

	예외처리 Exceptions
		try, catch, throw

	조건 분기 Conditional braches
		if, switch
*/

#include <iostream>
#include <cstdlib>

int main()
{
	// 출력을 두번 하는 코드를 만들었지만 중간에 나가고 싶음

	std::cout << "I love you " << std::endl;

	exit(0);  //include <cstdlib>
	//return 0; 보다 긴급하게, 무조건 종료 시켜야 할 경우
	//밑에 코드가 남겨져 있어도, 코드 어디에 있던지 return type 상관없이 종료시킬 수 있음 
	//디버그 할때 많이 사용함, 여기까지만 보고 상황을 끝내고 뒤를 안봐도 된다 싶을때

	
	
	// . . . 코드가 밑에 남아 있을때 주석을 남겨서 밑에 코드가 남겨져 있는 상황을 알려줌 아니면 exit(0)사용

	/*std::cout << "I loce you, too" << std::endl;

	return 0;*/
}