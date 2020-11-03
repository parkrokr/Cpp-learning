// 지역 범위 Local Scope

#include <iostream>

using namespace std;

void doSomething(int x)
{

	x = 123;
	cout << x << endl; //#2
}

int main()
{
	int x(0);// x = 0;
	
	cout << x << " " << &x << endl; //#1
	
	/*{
		// &x x의 메모리 주소
		int x = 1; //다른 메모리에 대한 식별자
		
		//x = 1; 같은 메모리
		cout << x << " " << &x << endl;
	}*/

	doSomething(x);

	cout << x << " " << &x << endl; //#2
	
	return 0;
}