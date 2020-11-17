// 관계 연산자 Relational Operators

#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	/*while (true)
	{
		int x, y;

		cin >> x >> y;
		cout << " Your input values are : " << x << " " << y << endl;

		if (x == y)
			cout << "equal" << endl;
		if (x != y)
			cout << "not equal " << endl;
		if (x > y)
			cout << "x is greater than y" << endl;
		if (x > y)
			cout << "x is less than y" << endl;
		if (x >= y)
			cout << "x is greater than y or equal to y" << endl;
		if (x <= y)
			cout << "x is less than or equal to y" << endl;
	}*/


	//int 끼리의 비교는 크게 문제가 없지만 
	//부동소수점,무한, Not a number 비교는 문제가 발생할 수 있음

	double d1(100 - 99.99); //0.001
	double d2(10 - 9.99);	//0.001

	cout << d1 << endl;
	cout << d2 << endl;

	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "Not equal" << endl;

		if (d1 > d2) cout << "d1 > d2" << endl;
		else//if(d1 < d2) because d1 != d2
			cout << "d1 < d2" << endl;
			
	}
	
	cout << std::abs(d1 - d2) << endl; // 5.32907e-15

	//비슷한 숫자를 같은 숫자로 인식시키고 싶을때
	//오차의 한계를 지정
	const double epsilon = 1e-10;

	if (std::abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	
	return 0;
}
