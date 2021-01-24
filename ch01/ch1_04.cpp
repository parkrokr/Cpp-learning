// 입출력 스트림과의 첫 만남 cin, cout

#include <iostream> //cout, cin, endl, . . .
#include <cstdio>   //printf

int main()
{
	//using namespace std; 있으면 std:: 생략

	int x = 1024;
	double pi = 3.141592;
	
	// << output operator , \n 줄바꿈
	std::cout << "Hello World!\n"; //<< std::endl; 
	std::cout << "x is " << x << " pi is " << pi << std::endl;

	
	// \t tab,빈공간 두고 줄맞춤 하고 싶을때
	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	// \a 소리출력
	std :: cout << "\a";
	

	//printf("I love this lecture! \n");

	int y = 1;

	std::cout << "Before your input, y was " << y << std::endl;
	
	// >> input operator
	std::cin >> y;

	std::cout << "Your input is " << y << std::endl;
	
	return 0;
}