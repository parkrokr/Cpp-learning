//std::cin 더 잘쓰기   ignore(), clear(), fail()

//fail()  : 에러가 일어나면 1을 반환함
//clear() : 에러 플래그 초기화(에러 상태 취소),cin이 정상작동 하게함, 없으면 밑에 예제에서 계속 1 반환


#include<iostream>

using namespace std;

int getInt()
{
	while (true)
	{
		cout << "Enter an integer number : ";
		int x;
		cin >> x;

		//입력값이 너무 큰 경우 버퍼에 숫자가 계속 남아 문제가 생김
		//std::cin.fail()  실패했을 경우 true 를 return 함
		if (std::cin.fail())
		{
			std::cin.clear(); //지워버리기
			std::cin.ignore(32767, '\n'); //남이있는 버퍼 비우기
			cout << "Invalid number, please try again" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); //버퍼 비워주기
			return x;
		}
	}
}

//잘못된 문자를 입력한경우 마지막에 result 에서 invalid가 뜨는것보다 입력받는 즉시 뜨게 하기
//잘못된 문자를 입력한경우 다시 받는다 보다는
//무한히 문자를 입력받다가 맞는 문자가 입력되면 나온다는 방법이 권장됨
char getOperator() 
{
	while (true)
	{
		cout << "Enter an operator (+,-,*,/) : ";  //TODO: more operatros *, / etc.
		char op;
		cin >> op;
		std::cin.ignore(32767, '\n');

		if (op == '+' || op == '-' || op == '*' || op == '/')
			return op; //return문은 속해있는 함수를 바로 종료시킴
		else
			cout << "Invalid operator, please try agian" << endl;
	}
}

void printResult(int x, char op, int y)
{
	// case-switch 문을 바꿔보기

	/*if (op == '+')cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else
	{
		cout << "Invalid operator" << endl;
	}*/

	switch (op - '*')
	{
	case 0:
		cout << x * y << endl;
		break;
	case 1:
		cout << x + y << endl;
		break;
	case 3:
		cout << x - y << endl;
		break;
	case 5:
		cout << x / y << endl;
		break;

	default :
		cout << "Invalid operator" << endl;
		break;
	}
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printResult(x, op, y);


	//처음에 입력할때 1 2 같은 식으로 입력하면 처음에 1이 함수에 들어가고 2가 버퍼에 남아있다가
	//다음 함수에 들어가는 일이 발생

	//버퍼를 비워주기 위해 std::cin.ignore() 사용

	return 0;
}