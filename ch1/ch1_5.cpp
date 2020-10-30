#include <iostream>

using namespace std;



void print()
{
	cout << "Hello" << endl;
}

/*int*/ void addTwoNumbers(int a, int b)
{
	//return a + b;
	print();
}

/*int mutilplyTWoNumbers(int num_a, int num_b)
{
	int sum = num_a * num_b;

	return sum;
}*/

/*void printHelloworld()
{
	cout << "Hello World " << endl;

	return;

	cout << "Hello World 2" << endl;
}*/

int main()
{
	//cout << mutilplyTWoNumbers(1, 2) << endl;
	
	//printHelloworld();

	//int sum = addTwoNumbers(1, 2);

	addTwoNumbers(1, 2);

	return 0;
}