// 증가/감소 연산자 Increment/decrement

#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	using namespace std;

	// ++,-- 가 앞에 붙을땐 연산과 출력이 한꺼번에 이루어지지만
	// 뒤에 붙을땐 출력을 하고 연산은 그 다음에 이뤄짐

	int x = 6, y = 6;

	cout << x << " " << y << endl;
	cout << ++x << " " << --y << endl;
	cout << x << " " << y << endl;
	cout << x++ << " " << y-- << endl;
	cout << x << " " << y << endl;


	int z = 1, w = 2;
	//int v = add(z, ++z);// do not use , 컴파일러마다 정의가 다름
	int v = add(z , ++w);

	cout << v << endl;


	int a = 1;
	// a = a++; do not use, undefined

	a++;// or ++a
	cout << a << endl;

	
	return 0;
}