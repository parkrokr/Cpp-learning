//메모리 동적 할당(Dynamic Memory Allocation)  new 와 delete

#include <iostream>

using namespace std;

int main()
{
	//int array[1000000];
	//stack overflow 발생함
	//프로그램에서 정적으로 할당하는 메모리는 stack 에 들어감 , stack 은 사이즈가 작음
	//동적으로 할당되는 메모리는 hip에 들어감 , 사이즈가 큼
	//->동적 할당을 사용해야 hip을 통해 메모리를 크게 받을 수 있음
	//메모리가 누수되는 문제등 문제가 발생 할 수도 있음


	//기존에 사용하던 방법
	//int var = 7;


	//다른 방법
	//new int 는 os에게 int 사이즈에 맞춰 메모리를 받아온 다음에 그 메모리 주소를 알려줌
	//포인터로 받아야 함
	int* ptr = new int;
	int* ptr2 = ptr;

	//메모리를 할당 받아야 하는데 못 받을 수도 있음(다른 프로그램이 메모리를 다 쓰고 있어서 등등)
	//new 가 에러를 일으켜도 버터야 함
	//std::nothrow 를 쓰면 에러를 일으키지 않고 버티게 해줌
	//int* ptr = new(std::nothrow)int{ 7 };


	*ptr = 7;

	//포인터로 메모리 주소를 받아오면서 동시에 초기화를 할 수도 있음
	//int* ptr = new int{ 7 };
	//int* ptr = new int(7);

	if (ptr) //if문을 쓰면 더 안전하게 할 수 있음
	{
		cout << ptr << endl;  //주소
		cout << *ptr << endl;  //7
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	//os에게 메모리 반납하기  
	//빅데이터같이 많은 메모리를 사용해야 하는 경우 반납하지 않으면 컴퓨터가 감당하지 못함
	//delete ptr; 이 없으면 프로그램이 끝났을때 os가 메모리를 회수해감
	delete ptr;
	ptr = nullptr;


	// ptr2 = nullptr; 없이 *ptr2 하면 문제가 발생함 ->꼼꼼해지거나 스마트포인터를 사용하거나


	//문제가 될 수 있는 경우
	/*cout << "After delete" << endl;
	cout << ptr << endl; 
	cout << *ptr << endl;*/

	//delete ptr 이후에도 ptr에 저장된 주소값은 유지 될 수도 있음
	//(강의 예제에선 유지되지만 지금 이 환경에선 유지 안됨)

	//방지하기 위해 delete ptr 다음에 ptr = nullptr; 또는 ptr = 0; 또는 ptr = NULL; 처럼 주소를 비워줌


	//ptr 이 지워지지 않고 의미가 있을때에만 de-referencing 을 하게 하는 코드
	cout << "After delete" << endl;
	if (ptr != nullptr)  //if(ptr) 로 줄일수도 있음
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}





	//memory leak 
	while (true)
	{
		int* l_ptr = new int;
		cout << l_ptr << endl;

		delete l_ptr; // delete 를 하지 않으면 계속 메모리를 빌려옴 
	}



	//new 와 delete 가 느림(os에게 갔다 와야 하기 때문에)
	//new 와 delete를 많이 안써야 빠름, 대신 c++에선 new 와 delete를 통해
	//메모리를 직접 관리할 수 있기 때문에 최적화에 좋음

	return 0;
}
