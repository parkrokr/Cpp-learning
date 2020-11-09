// �Ҹ��� �ڷ����� ���ǹ� if  Boolean

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

	// ���� �̻��� ��� �߰�ȣ �ݵ�� 
	if (3 > 1)
	{
		cout << "This is true" << endl;
		cout << "True second line" << endl;
	}


	cout << std::boolalpha;
	cout << isEqual(1, 1) << endl;
	cout << isEqual(0, 3) << endl;


	// if ���ǹ� 0 �̸� false , �� �ܿ��� �� true
	if (-1)
	{
		cout << "True" << endl;
	}
	else
		cout << "False" << endl;

	bool b;

	cin >> b;
	cout << std::boolalpha;
	cout << "Your input : " << b << endl;


	return 0;
}