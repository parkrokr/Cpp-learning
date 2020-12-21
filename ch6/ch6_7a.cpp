//�� ������ null pointer

#include <iostream>
#include <cstddef> //std::nullptr_t nptr;

//�Լ� parameter�� ����
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
	//null pointer ����
	//double* ptr = 0; // = null;			 //c-style
	double* ptr = nullptr;				    //modern c++
	//double *ptr{ nullptr };  //uniform initialization �� ����, { 0 } �� ���������� nullptr �� ����

	
	//���  �ùٸ� �ּҰ� ���������� �����ϰ�
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

	//������ ������ �ּ�
	std::cout << "address of pointer variable in main() " << &ptr << std::endl;

	//main �� doSomething �� ������ ������ �ּҰ� �ٸ�(�ٸ� �޸𸮸� ���)
	//�ּҰ��� �����ؿ��� �� �ּҸ� �����ϴ� �޸𸮴� �ٸ�


	//<cstddef>
	std::nullptr_t nptr; // null pointer �ۿ� ����


	return 0;
}