// break, continue

//break 는 swith 문에서 필수

#include<iostream>

using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
			break;

		if (ch == 'r')
			return;
	}

	cout << "Hello" << endl;
}

int main()
{
	//break


	//while 문에서 break
	int count = 0;
	while (true)
	{
		cout << count << endl;
		if (count == 10)break;
		count++;
	}

	//함수에서 break
	breakOrReturn(); // b 입력시 Hello 출력, r 입력시 함수가 그냥 return 해서 나가버림

	//for 문에서 break
	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
		if (i == 5)break;
	}

	//break는 끊고 나올 수 있음
	//프로그램 실행중 특정 키를 누르면 나올 수 있게도 짤 수 있음


	//break를 쓰는게 조건 걸어주는것보다 편할수도 있음
	
	//특정 키를 입력받았을때 나오는 코드
	count = 0;
	bool escape_flag = false; //flag를 하나 정의해 줘야함

	while (!escape_flag)
	{
		char ch; //나중에 복잡한 class 를 만들때는 밖으로 빼주는게 도움이 될수 있음
		cin >> ch;

		cout << ch << " " << count++ << endl;

		if (ch == 'x')
			escape_flag = true;
	}

	//escape_flag 를 안쓰는 방법
	/*while (true)
	{
		char ch;
		cin >> ch;
		cout << ch << " " << count++ << endl;
		if (ch == 'x')break;
	}*/



	//continue

	//홀수만 출력
	//if로 { }를 만드는 방법, continue 를 쓰는 방법이 있음

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 1)cout << i << endl; 
	}

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)continue; //continue 가 실행이 되면 아랫부분을 실행시키지않고 다시 위로 올라감

		cout << i << endl;
	}

	
	//continue가 do/while 과 사용될때는 조금 애매해질 수 있음
	count = 0;
	
	do
	{
		if (count == 5)
			continue;

		cout << count << endl;

		//count++  // while( ) 안이 아닌 do 에 증감연산자가 있으면 continue 때문에 실행이 안됨 -> 무한루프
	} 
	//while (count <10)
	while (++count < 10);   //while 안에 증감연산자를 넣을 수 있음


	return 0;
}