// ��ġ�� ( Void, ���̵�) Void Type

#include <iostream>

void my_function()
{

}

int main()
{
	//void my_void; void�� �޸𸮸� ������� �ʱ� ������ �������� ���Ѵ�

	int i = 123;
	float f = 123.456f;

	void* my_void;

	my_void = (void*)&i;
    my_void = (void*)&f;

	//std::cout << sizeof(void*) <<std:: endl;

	return 0;
}