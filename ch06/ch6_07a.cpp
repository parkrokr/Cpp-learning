//널 포인터 null pointer

#include <iostream>
#include <cstddef> //std::nullptr_t nptr;

//함수 parameter도 가능
void doSomething(double* ptr)
{
	std::cout << "address of pointer variable in doSomthing() " << &ptr << std::endl;
	if (ptr != nullptr)
	{
		// do something useful
		std::cout << *ptr << std::endl;
	}
	else
	{
		// do something with ptr
		std::cout << "Null ptr, do nothing" << std::endl;
	}
}


int main()
{
	//null pointer 선언
	//double* ptr = 0; // = null;			 //c-style
	double* ptr = nullptr;				    //modern c++
	//double *ptr{ nullptr };  //uniform initialization 도 가능, { 0 } 도 가능하지만 nullptr 사용이 더 좋음, 

	
	//사용  올바른 주소가 들어왔을때만 동작하게
	if (ptr != nullptr)
	{
		// do something useful
	}
	else
	{
		// do something with ptr
	}

	doSomething(ptr);
	doSomething(nullptr);

	double d = 123.4;

	doSomething(&d);

	ptr = &d;

	doSomething(ptr);

	//포인터 변수의 주소
	std::cout << "address of pointer variable in main() " << &ptr << std::endl;

	//main 과 doSomething 의 포인터 변수의 주소가 다름(다른 메모리를 사용)
	//주소값만 복사해오지 그 주소를 저장하는 메모리는 다름


	//<cstddef>
	std::nullptr_t nptr; // null pointer 밖에 못넘


	return 0;
}
