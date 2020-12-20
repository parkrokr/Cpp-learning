//포인터의 기본적인 사용법

#include <iostream>
#include<typeinfo>

using namespace std;

//함수가 return type, parameter 로 받을 수도 있음
int* doSomething(int* ptr_a)
{
	return nullptr;
}

struct Something
{
	int a, b, c, d; // 4 * 4 = 16
};


int main()
{
	// 큰 메모리에 저장되어 있는 데이터 중에서 일부분을 cpu가 사용하기 위해 메모리로부터 가져올 때는
	//메모리 전체를 모두 뒤지면서 찾는 것이 아니라 필요한 데이터가 저장되어 있는 '주소'를 사용하여
	//직접 접근하여 가져옴
	
	int x = 5;
	//지역 변수는 '스택'메모리를 사용, 동적 할당 메모리는 '힙'메모리 사용

	cout << x << endl;
	
	// 변수 x가 사용하는 메모리 주소를 알고 싶을 때
	cout << &x << endl;// & : address-of operator
	cout << (int)&x << endl; // 메모리 주소는 16진수로 나옴


	//de-reference operator (*)

	//포인터는 레퍼런스의 일종,일부
	//c++에는 포인터와 레퍼런스가 또 따로 있음

	//de-reference 는 포인터가 "저쪽 주소에 가면 이 데이터가 있어요"라고 간접적으로 가리키기만 하는 것에 
	//대해서 "그럼 거기에 진짜 뭐가 있는지 내가 들여다볼께"라며 직접적으로 접근하겠다는 의미

	cout << *(&x) << endl; // x의 메모리 주소에 저장되어 있는 실제 값인 5 가 출력됨
	//연산자 우선선위 때문에 *&x도 상관없음



	//포인터는 주소를 저장하는 변수

	//포인터 변수 선언
	
	int* ptr_x = &x, * ptr_y = &x;

	// int * ptr_x 에서 *가 왼쪽에 붙으면 헷갈릴 수 있음
	// int *ptr_x = &x; ptr_y = &x; 에서 ptr_y는 포인터 변수가 아님
	// int *ptr_x = &x; *ptr_y = &x; 식으로 사람의 실수를 줄이기 위해 *앞에 빈칸을 두는 식으로 많이 사용함


	//typedef int* pint;
	//pint ptr_x;

	//pint ptr_x = &x, ptr_y = &x; 는 문제가 없음
	//이중포인터나 삼중 포인터를 어쩌다 한번 써야될 경우 이런식으로 돌려서 쓸때도 있음


	//주소는 data type과 상관이 없이 중립적임
	//포인터가 type을 알아야 하는 이유는 de_referenceing 할때 
	//어떤 타입의 데이터를 가져와야 할지 알아야 하기 떄문에

	//*ptr_x 는 int type 이다, ptr_x가 int 의 포인터 type으로 선언이 되었기 때문에
	

	cout << typeid(ptr_x).name() << endl;
	//visula studio 에선 int *, gcc(codeblock)에선 Pi (pointer integer) 로 뜸 


	//포인터를 쓰는 이유는 배열 때문이 큼, 배열을 함수 parameter로 직접 받을 경우
	//배열에 저장된 데이터를 모두 복사하는데 많은 시간이 걸리기 때문에 
	//포인터로 시작하는 부분의 주소와 사이즈만 알려주면 다룰 수 있음

	
	//다양한 data type 에 대해서 쓸 수 있음
	double d = 1.0;
	
	double* ptr_d = &d;
	//double *ptr_d = 0x00D8F744; 는 불가능함
	//아예 불가능 하진 않음, 해킹의 원리중 하나

	
	//structure 나 class 같은 사용자 정의 자료형에 대해서도 쓸 수 있음
	Something ss;
	Something* ptr_s;

	cout << sizeof(Something) << endl;	 // 4*4 = 16
	cout << sizeof(ptr_s) << endl;		 // 4



	//포인터 변수는 주솟값만 저장하기 때문에 data type 과 상관없이 같은 크기를 가짐
	cout << sizeof(x) << endl; //4
	cout << sizeof(d) << endl; //8
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl; // 4 4  , x64에선 8 8
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // 4 4  , x64에선 8 8

	// x64에선 주솟값을 찍어보면 더 길게 찍힘


	//문제가 될 수 있는 부분
	//초기화 없이 de-referencing 할 경우
	int* ptr_z;

	//cout << *ptr_z << endl; //가장 많은 에러 원인



	return 0;
}