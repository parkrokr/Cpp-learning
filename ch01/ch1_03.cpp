// 변수와의 첫 만남

//객체 objects		
	//존재한다 존재하지 않는다의 구분은 메모리에 있냐 없냐, 의미있는 값들이 메모리에 저장되어있는걸 객체라고 함

//변수 variables
	//객체가 메모리에 담겨있을때 이름이 있어야 사용할 수 있음
	//내부적으로 메모리에 담겨있는 객체를 의미함
	//주소의 다른 이름

//Left-values 와 Right-values
	//메모리 주소를 프로그래머가 직접 접근할 수 있냐 없냐
	// x = 123; 에서 왼쪽에 있는걸 l value, 오른쪽에 있는걸 r value 라고 함
	//l value 는 주소를 가지고 있음, r value 는 123을 임시로 저장하지만 주소를 가지고 오기 힘듬(잠깐 작동을 하고 사라짐)

//초기화 initialization 과 대입 assignment

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
