//재귀적 함수 호출 Recursive Function Call

#include <iostream>

using namespace std;

//입력한 숫자로부터 1씩 줄어들면서 출력하는 함수
void countDown(int count)
{
	cout << count << endl;

	if(count > 0)  //종료 조건 : 0 까지 출력하고 함수에서 하나씩 나오고 종료
		countDown(count - 1);  // 자기가 자기를 호출

	//재귀를 할때는 반드시 종료 조건이 있어야함
	//재귀가 너무 많으면 stack overflow 날 수 있음
	//stack overflow 가 너무 우려되면 ch7_11 에 나온 vector를 stack 처럼 사용하는 방법이 있음
}

// 코드는 메모리에 저장되어 있고 함수 호출할때는 주소로만 호출하기 때문에
// 자기 자신도 호출 할 수 있는게 가능


//숫자를 더해나가는 함수
int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
		return sumTo(sumto - 1) + sumto; // sumto + (sumto -1) + (sumto -2) + . . .

	//이렇게 재귀해서 오는걸 임시로 변수에 저장하면 디버그 할때 보기 편함
	/*else
	{
		const int sum_munus_one = sumTo(sumto - 1);
		return sum_minus_one + sumto;
	}*/
}


//피보나치 수열
// 0 1 1 2 3 5 8 13 21
int fibonacci(int n) // n번째 피보나치수 반환
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
	
}


int main()
{
	//입력한 숫자로부터 1씩 줄어들면서 출력하는 함수
	countDown(5);

	//숫자를 더해나가는 함수
	cout << sumTo(10) << endl;

	//피보나치 수열
	cout << fibonacci(10) << endl; // 10번째 피보나치 수



	//Recursive 재귀
		// 보통 구현하기 더 쉬움
		// Iteration과 달리 stack을 사용해야 하기 때문에 호출할수 있는 depth 가 기계마다 다르고 한계가 있음
		// 퍼포먼스가 중요한 코드에선 사용 안하는게 좋을 수 있음


	//Iterative 반복
		// 가능하면 Recursion 을 Iteration 으로 바꿔서 구현


	return 0;
}