// ����� ��Ʈ������ ù ���� cin, cout

#include <iostream> //cout, cin, endl, . . .
#include <cstdio>   //printf

int main()
{
	//using namespace std; ������ std:: ����

	int x = 1024;
	double pi = 3.141592;
	
	// << output operator , \n �ٹٲ�
	std::cout << "Hello World!\n"; //<< std::endl; 
	std::cout << "x is " << x << " pi is " << pi << std::endl;

	
	// \t tab,����� �ΰ� �ٸ��� �ϰ� ������
	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	// \a �Ҹ����
	std :: cout << "\a";
	

	//printf("I love this lecture! \n");

	int y = 1;

	std::cout << "Before your input, y was " << y << std::endl;
	
	// >> input operator
	std::cin >> y;

	std::cout << "Your input is " << y << std::endl;
	
	return 0;
}