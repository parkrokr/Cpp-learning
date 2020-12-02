//조건문 if

#include<iostream>

using namespace std;

//두 정서중 작은 값을 return 하는 함수
int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
	
	//if (x > y)  return y;
	//else	return x;

	//return (x > y) ? y : x;
}

int main()
{
	int x;
	cin >> x;

	//if 다음에 오는 문장이 하나인 경우에만 {}를 안써도 됨
	if (x > 10)
	{
		cout << x << " is greater than 10" << endl;
	}
	else
		cout << x << " is not greater than 10" << endl;
	
	if (1)
		int x = 5;
	else
		int x = 6;

	cout << x << endl; // cin 으로 받은 x 가 출력됨, if 문 {}안에서 선언한 변수는 {}를 벗어나지 못함
	
	//chaining
	if (x > 10)
		cout << "x is greater than 10" << endl;
	else if (x < 10)
		cout << "x is less than 10" << endl;

	else // if (x == 10) 주석 달아주기
		cout << "x is exactly 10" << endl;


	//if 나 else {} 안에 다시 if문이 있고 그 안에 if 문이 있으면 논리구조를 파악하기 힘들어짐
	//문법적으로 가능하고 상황이 명확한 경우엔 괜찮지만 양날의 검임
	if (x > 10)
		cout << "x is greater than 10" << endl;
	else
	{
		if (x < 10)
		cout << "x is less than 10" << endl;

		else
		cout << "x is exactly 10" << endl;
	}

	
	//이런식으로 else if 논리구조가 복잡해지면 { }를 씌어 명확하게 해준다
	//문법상 else 는 가장 가까운 if에 붙게 된다
	//indenting(들여쓰기) 이 엉망인 상태일때 기능이 의도한대로 작동안됨
	/*if (x >= 10)
		if (x <= 20)
			cout << "x is between 10 and 20 " << endl;
		else
			cout << ". . ." << endl;*/

	if (x >= 10)
	{
		if (x <= 20)
			cout << "x is between 10 and 20 " << endl;
		else
			cout << ". . ." << endl; // 이 else 는 if (x <= 20)에 걸림
	}

	if (x >= 10)
	{
		if (x <= 20)
			cout << "x is between 10 and 20 " << endl;
	}
		else
			cout << ". . ." << endl; // 이 else 는 if (x >= 10)에 걸림


	//논리연산자 사용 가능
	int a, b;
	cin >> a >> b;

	if (a > 0 && b > 0)
		cout << "both numbers are positive" << endl;
	else if (a > 0 || b > 0)
		cout << "one of numbers are positive" << endl;
	else
		cout << "Neither number is positive" << endl;


	//if 문은 프로그램을 긴급하게 중단시키거나 함수 실행을 멈추고 바로 return 해서 나가버릴 수도 있음
	if (x > 10)
		cout << "A" << endl;
	else if (x == -1)
		return 0; //exit(0) 
	else if (x < 0)
		cout << "B" << endl;

	cout << "Hello" << endl; //x == -1 이면 이 문장은 실행되지 않고 프로그램이 끝남


	//null statment
	if (x > 10)
		; // 왜 null statment 를 쓰는지 주석 달기

	//주의
	if (x > 10);
	{
		x = 1; //위에 ; 때문에 if문과 상관없이 이 줄이 실행됨
	}


	//주의
	if (x = 0) //x = 0; if(x) -> 항상 false
		cout << x << endl;

	return 0;
}