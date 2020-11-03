// 변수와의 첫 만남

#include <iostream>

int main()
{
	int x = 5 ; // initialization
	// int x(5); 도 가능
	x = 123; //assignment 대입

	//initialization 안하면 debug 모드에선 에러, release 모드에선 0 대입
		
	// left value     right value
	
	std::cout << x << std::endl;
	//std::cout << &x << std::endl; // &:ampersand  주소
	
	return 0;
}

//#include <iostream>
// 
//int main()
//{
//	int x = 1;
//	x = x + 2;
//	std::cout << x << std::endl;  //#1
//
//	int y = x;
//	std::cout << y << std::endl;  //#2
//
//	//is (x+y) l-value or r-value?
//	std::cout << x + y << std::endl; //#3
//
//	std::cout << x << std::endl; //#4
//
//	int z = 1;
//	std::cout << z << std::endl; //#5
//	
//	return 0;
//}