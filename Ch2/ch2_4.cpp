// 무치형 ( Void, 보이드) Void Type

#include <iostream>

void my_function()
{

}

int main()
{
	//void my_void; void는 메모리를 사용하지 않기 때문에 선언하지 못한다

	int i = 123;
	float f = 123.456f;

	void* my_void;

	my_void = (void*)&i;
    my_void = (void*)&f;

	//std::cout << sizeof(void*) <<std:: endl;

	return 0;
}