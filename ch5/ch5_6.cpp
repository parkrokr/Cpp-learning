// 반복문 do-while

//while 과 다르게 반드시 한번은 실행
// do/while 문 뒤 while 뒤에 ; 찍어야함
//특정 알고리즘에서 쓰일 수 있음

#include<iostream>

using namespace std;

int main()
{
	// 1,2,3,4 중에 하나를 선택하고 그 외는 다시 입력을 받는 코드
	
	int selection; // must be declared outside do/while loop, do 내부에 선언되면 while 이 접근할 수 없음

	do
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;
		cin >> selection;
	} while (selection <= 0 || selection >= 5); // do/while 문 뒤 while 뒤에 ; 찍어야함

	cout << "You selected " << selection << endl;

	return 0;
}
