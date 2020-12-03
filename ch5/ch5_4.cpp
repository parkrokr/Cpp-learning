//goto

#include<iostream>
#include<cmath> // sqrt()

using namespace std;

int main()
{
	//숫자를 입력받고 그 sqrt를 구하는 코드
	double x;
	
	tryAgain : //label

	cout << "Enter a non-negative number" << endl;
	cin >> x;

	//x 가 음수면 문제가 발생
	if (x < 0.0)
		goto tryAgain; // goto 로 지정한 label 로 이동

	cout << sqrt(x) << endl;
	

	//'옛날'엔 goto를 반복문 대신에 사용했었음, 어셈블리어엔 반복문이 goto문임
	//goto를 쓰지 말라는건 뭘할지 미리 생각을 하고 계획성을 가지고 블록을 만들라는 것이다


	//x 가 선언되기전에 x+=3을 하기 때문에 문제가 발생
	/*goto skip;

	int x = 5;

skip:

	x += 3;*/


	return 0;
}