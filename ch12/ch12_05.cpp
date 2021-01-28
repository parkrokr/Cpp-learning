//동적 바인딩 ( Binding ) 과 정적 바인딩

#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2: multiply" << endl;
	cin >> op;

	//static binding (early binding)
	/*int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;*/

	//모든 identifier 즉 함수명이나 변수명이 빌드타임에 정의되어 있을때 정적바인딩 이라고 함


	//Dynamic binding (late binding)
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl;

	//func_ptr 에 들어갈 주소가 add,subtract,multiply 중에 뭐가 될지 runtime 에 결정됨
	//값을 구할때도 func_ptr 을 통해 동적으로 할당된 함수의 포인터를 찾아가서 실행하는 간접적인 방식을 씀

	//op 가 0,1,2 중에만 하나여만 하기 때문에 방어적 프로그래밍 하기


	//속도는 정적 바인딩이 더 빠름, 대신에 동적 바인딩을 쓰면 프로그램이 더 유연해질 수 있음
	//예를 들어 게임에서 입력 키를 사용자가 원하는 대로 바꿀 경우 정적 바인딩으로 구현하면
	//if 문이 많이 필요할것임
	//참고 : https://www.geeksforgeeks.org/early-binding-late-binding-c/

	return 0;
}
