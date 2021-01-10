//방어적 프로그래밍의 개념  Defnesive Programming

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// syntax error  문법 에러
	//ide 가 많이 잡아줌, ide가 쉽게 잡아주게 의존하는게 나쁘진 않음
	
	//int x     // ; 이 빠져서 에러


	// semantic error  문맥 오류, 의미 오류, 논리 오류
	//코드를 작성한 프로그래머 말고는 잡기 힘들기 때문에 프로그래머가 잘해야됨

	int x;
	cin >> x;

	if (x >= 5) 
		cout << "x is greater than 5 " << endl; 
	// 이 문장만 봤을때는 5일때는 출력이 안돼야하지만 코드로 보면 출력이 되기 때문에 논리 오류



	// violated assumption 가정을 위반
	//사용자가 프로그래머가 작성한 것과 전혀 다른 방식으로 프로그램을 사용함

	/*string hello = "Hello, my name is Jack Jack";

	int ix;
	cin >> ix;

	cout << hello[ix] << endl;*/
	// 26 이상의 ix를 입력하면 runtime error 발생
	//이런 오류가 발생하는걸 방지하게 '방어적'으로 프로그래밍


	//'방어적'프로그래밍, 사용자 테스트 할때 문제가 없게 여러가지 방어, 안전장치들이 있어야됨
	string hello = "Hello, my name is Jack Jack";

	cout << "Input from 0 to " << hello.size() - 1 << endl; //방어적 프로그래밍, 26이상 입력하지 말라고 문구출력

	while (true)//사용자가 원하는 값을 입력할때까지 반복해서 입력
	{
		int ix;
		cin >> ix;

		//범위 밖의 수가 입력되면 다시 입력하게 하기
		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}