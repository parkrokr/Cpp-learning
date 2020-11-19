// 무치형 ( Void, 보이드) Void Type

#include <iostream>

void my_function()
{

}

int main()
{
	//void my_void; void는 메모리를 차지하지 않기 때문에 선언하지 못한다

	int i = 123;
	float f = 123.456f;

	void* my_void; // *주소

	// type 이 달라도 주소의 타입은 같기 때문에 형변환이 가능하다
	
	my_void = (void*)&i; // &i 정수형 변수의 주소
        my_void = (void*)&f; // &f 실수형 변수의 주소

	//std::cout << sizeof(void*) <<std:: endl;

	return 0;
}
