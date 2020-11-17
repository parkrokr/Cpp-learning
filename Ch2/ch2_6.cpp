// 불리언 자료형과 조건문 if  Boolean

#include <iostream>

bool isEqual(int a, int b)
{
	bool result = (a == b);

	return result;
}


int main()
{
	using namespace std;

	bool b1 = true; // copy initialization
	bool b2(false); // direct initialization
	bool b3{ true }; // uniform initialization
	b3 = false;

	cout <<std:: boolalpha;
	cout << b3 << endl;
	cout << b1 << endl;
	cout << std::noboolalpha;

	// ! not operator
	cout << !true << endl;
	cout << !false << endl;

	//  &&  and operator  
	cout << (true && true) << endl;
	cout << (true && false) << endl;
	cout << (false && true) << endl;
	cout << (false && false) << endl;

	//  ||  or operator
	cout << (true || true) << endl;
	cout << (true || false) << endl;
	cout << (false || true) << endl;
	cout << (false || false) << endl;

	// if operator
	if (true)
		cout << "This is true" << endl;
	else
		cout << "this is false" << endl;

	// 두줄 이상인 경우 중괄호 반드시 
	if (3 > 1)
	{
		cout << "This is true" << endl;
		cout << "True second line" << endl;
	}


	cout << std::boolalpha;
	cout << isEqual(1, 1) << endl;
	cout << isEqual(0, 3) << endl;


	// if 조건문 0 이면 false , 그 외에는 다 true
	if (-1)
	{
		cout << "True" << endl;
	}
	else
		cout << "False" << endl;
	
	
	// 이 결과는 시스템마다, comiler 마다 다를 수 
	
	bool b;

	cin >> b;
	cout << std::boolalpha;
	cout << "Your input : " << b << endl;


	return 0;
}
