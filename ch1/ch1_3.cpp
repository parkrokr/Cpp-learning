// �������� ù ����

#include <iostream>

int main()
{
	int x = 5 ; // initialization
	// int x(5); �� ����
	x = 123; //assignment ����

	//initialization ���ϸ� debug ��忡�� ����, release ��忡�� 0 ����
		
	// left value     right value
	
	std::cout << x << std::endl;
	//std::cout << &x << std::endl; // &:ampersand  �ּ�
	
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