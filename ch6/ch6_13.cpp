//포인터(Pointer) 와 const

//int value = 5;
//const int* ptr1 = &value;
//int *const ptr2 = &value;
//const int *const ptr3 = &value;

//함수에 parameter 로 배열을 넣을때 주소나 값을 바꾸지 않고 안전하게 코딩하고 싶은경우 사용함
//함수 parameter로 const char* value 를 쓸 경우  호출하는 곳에서 전달받은 문자열을 변경하지 않고 사용만 하겠다는 의미




#include <iostream>

using namespace std;

int main()
{
	//const int * ptr     역참조된 값을 못바꿈(ptr 주소 메모리의 내용 변경 불가)

	const int value = 5;
	const int* ptr = &value;
	//*ptr = 6; 불가능 // value = 6;이 안되기 때문

	//value의 값을 바꾸지는 못하지만 주소는 가져올 수 있음, 포인터를 통해 value 를 읽을수는 있음
	cout << *ptr << endl;

	int value_ = 6;
	const int* ptr_ = &value_;
	//*ptr_ = 6; 불가능 // 포인터의 역참조로는 값을 못바꾸지만 바꾼 값을 가져올 수는 있음
	value_ = 6;



	//변수 두개가 있는 경우
	int value1 = 5;
	const int* ptr1 = &value;
	// *ptr1  = 7; 불가능 //역참조 했을때 값을 바꿀수는 없지만 포인터에 다른 변수를 넣는건 됨

	int value2 = 6;
	ptr1 = &value2;

	// int * 앞에 const 가 붙을때는 주소에 있는 값을 안바꾸겠다는 거지 ptr 에 저장되는 주소값을 안바꾸겠다는건 아님





	//int *const ptr     저장된 주소값을 못바꿈

	int value3 = 5;
	int* const ptr3 = &value3;

	*ptr3 = 10;  //역참조로 값 바꾸기 가능
	cout << *ptr3 << endl;

	int value4 = 8;
	//ptr3 = &value4; 불가능  //포인터에 있는 주솟값을 못바꿈




	//const int *const ptr     역참조된 값이랑 저장된 주소값 둘다 못바꿈

	int value5 = 5;
	const int* const ptr5 = &value5;  //반드시 초기화 필요

	//*ptr5 = 10;  불가능

	return 0;
}
