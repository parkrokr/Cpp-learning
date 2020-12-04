//반복문 for

//for문과 while 문은 상호변환이 가능함

#include<iostream>

// 정수 power 함수
int pow(int base, int exponent)
{
	int result = 1;

	for (int count = 0; count < exponent; ++count)
		result *= base;

	return result;
}


int main()
{
	using namespace std;

	

	//   count 선언  /    count 검사  / 한 iteration 이 끝나면 실행 
	for (int count = 0; count < 10; ++count)
	{
		cout << count << endl;
	}

	//cout << count << endl; // count 가 for 문을 빠져나오면 사용못함, 쓰고 싶으면 for 밖에 선언

	int count = 0;
	//   빈칸 가능
	for (; count < 10; ++count)
	{
		cout << count << endl;
	}
	cout << count << endl; // 왜 10이 나오는지 중요

	//while(true) 처럼 사용 가능 대신 while 문은 ()안이 빈칸이면 에러가 남
	//for (;;++count) // 빈칸으로 둬도 상관없음

	//count = 1 로 초기화 하고 < 대신에 <= 를 써도 가능하지만 덜 간단함

	
	//pow 함수
	cout << pow(2, 4) << endl;

	//감소하는 코드     /   >= 주의
	for (int count = 9; count >= 0; --count)
	{
		cout << count << endl;
	}

	//2씩 감소하는 코드
	for (int count = 9; count >= 0; count -= 2)
	{
		cout << count << endl;
	}

	
	
	//변수를 2개 3개씩 사용할 수 있음	
	for (int i = 0, j = 0; (i + j) < 10; ++i, j+=2)
	{
		cout << i << " " << j << endl;
	}
	

	//이중루프
	for(int j = 0; j<9;++j)
		for (int i = 0; i < 9; ++i)
		{
			cout << i << " " << j << endl;
		}
	

	//count 가 unsigned 로 선언되면 문제가 발생 (overflow 가능성)
	/*for (unsigned int i = 9; i >= 0; --i)
		cout << i << endl;*/


	return 0;
}