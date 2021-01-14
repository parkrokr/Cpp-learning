//반복문 while

//무한루프

#include<iostream>

using namespace std;

int main()
{
	// 0~1 까지 출력하는 코드
	/*cout << 1 << endl;
	cout << 2 << endl;
	// . . .
	cout << 9 << endl;*/

	
	cout << "While-loop test" << endl;

	//counter 선언
	int count = 0;
	while (1)  //( ) 안이 true 면 작동, false 면 작동하지 않음. 1이나 true 를 넣어서 infinite-loop
	{
		cout << count << endl;

		++count; //count++;
		// count를 while 문 안에서 선언하면 무한루프, 밖에서 선언 권장
		//굳이 내부에서 선언하겠다면 static 변수로 선언, 대신에 위험할 수도 있음

		if (count == 10) break;
	}


	//goto 문을 사용해 while 문 재현
	skip:
	cout << count << endl;
	count++;
	if (count < 10)
		goto skip;

	
	// unsigned int 를 카운터로 사용하게 되면 overflow 발생할 수도있음
	// 감수하는 경우 위험함, 증가시키는 경우 위험성이 적음
	// 복잡한 계산쪽은 unsigned 가 조금 더 빠를 수도 있음
	
	/*unsigned int counter = 10;

	while (counter >= 0)
	{
		if (count == 0)cout << "zero";
		else cout << count << " ";

		count--;
	}*/


	// ~번에 한번씩 기능하게 하고 싶은 코드
	count = 1;

	while (count < 100)
	{
		if (count % 5 == 0)cout << "Hello" << count << endl; //5번에 한번씩 Hello 출력, % 사용

		count++;
	}

	
	//while 문 안에 while 문

	int outer_count = 1;

	while (outer_count <= 5)
	{
		int inner_count = 1;
		while (inner_count <= outer_count)
		{
			cout << inner_count++ << " ";
		}

		cout << endl;
		++outer_count;
	}

	//여러가지 연습하면 좋음

	return 0;
}