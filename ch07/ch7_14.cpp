//단언하기 assert

//debug 모드에서만 작동, release 모드에선 작동안함
//assert 가 발생하면 어디서 문제가 발생한지 알려줌
//assert 는 runtime 에 체크해줌
//static_assert 는 compiletime 에 체크해주고 문구를 남길 수 있음

#include <iostream>
#include <cassert> // asser.h
#include <array>

using namespace std;

void printvalue(array<int, 5>& my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1); // ||로 합칠수도 있지만 정확하게 뭐가 문제인지 알게하기 위해 쪼갬

	cout << my_array[ix] << endl;
}



int main()
{
	//assert(false); //debug 모드에서만 작동, release 모드에선 작동안함

	//cpp 파일의 property page의 C/C++\Preprosessor 에서 Preprocessor Definitions 가 NDEBUG 로 되어있으면 작동안함

	int number = 5;

	//number should be 5 //라고 주석만 적어둔다면 실용성이 없음
	assert(number == 5); //number 가 반드시 5 이도록 assert 를 걸어버리기




	array<int, 5> my_array{ 1,2,3,4,5 };

	//cout << my_array[5] << endl; //my_array[5]에 접근하면 runtime error 
	printvalue(my_array, 4);


	//static_assert
	//assert()는 runtime 에 체크하지만 static_assert() 는 compiletime 에 체크

	int x = 5;

	assert(x == 5); // x 는 변수니까 rutime 에 결정되도  assert() 가능

	//static_assert(x == 5);// x가 중간에 달라질 수 있으니 사용못함

	const int y = 5;

	assert(y == 5);

	static_assert(y == 5, " y should be 5"); //assert() 와 다르게 문구를 남길 수 있음, 문구는 error 메세지에서 출력





	return 0;
}