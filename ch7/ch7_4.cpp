// 주소에 의한 인수 전달 Passing Arguments by Address (Call by Address)

//결국 포인터 변수에 저장된 주소'값'을 전달하는 call-by-value 임
//literal 은 전달 안됨
//주소로 전달하는것이 참조 때문에 쓸모없어 보일수도 있지만 c style 에선 필수적이었음
//배열을 넘길때는 데이터 전체가 아닌 주소만 보내기 때문에 효과적임

#include <iostream>

using namespace std;

//void foo(const int* ptr)  //de-referecing 한 값을 못바꿈,  보통 이렇게 사용함
//void foo(const int* const ptr)//ptr에 저장된 주소값을 내부에서 못바꿈
void foo(int* ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl;

	//foo(const int* ptr)일때 불가능, 보통 이 형태로 많이 사용함
	//*ptr = 1;  
	

	//foo(const int* const ptr)일때 불가능
	//함수 내부를 구현할때 중간에 실수하는것을 막기 위해 오픈소스에서 많이 사용함
	
	//x = 1;
	//ptr = &x;
}

//포인터를 사용하여 함수의 출력처럼 사용할 수 있음
void getSinCos(const double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}


//많이 사용되던 c style 코딩
void arr(int* arr, int length) //원본 배열의 값을 바꾸고 싶지 않으면 const로 막기
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;
	
	//이렇게 배열의 값을 바꾸면 후에 함수에 들어오는 배열의 값도 바뀜
	//밖에 있는 배열의 주소를 받아서 바꾸는 것이기 때문에 똑같이 작동함
	arr[0] = 1.0;  //[] 기호가 de-referecing임
}


int main()
{
	int value = 5;

	cout << value << " " << &value << endl;

	int* ptr = &value;

	cout << &ptr << endl;


	//함수에 주소만 넣어줘야 함
	
	//foo(5);  //5는 literal 이라 주소가 없음, 함수에서 const 로 받아도 안됨
	
	//결과 동일
	foo(ptr); //포인터 변수 선언후 넣기
	foo(&value); //바로 주소 넣기
	

	//main 에서의 ptr의 주소랑 foo()에서의 ptr의 주소가 다름 
	//포인터에 의한 전달은 결국 주소라는 '값'을 값에 의한 전달한 것임
	//포인터 '변수'에 저장된 주소'값'만 복사될 뿐 포인터 변수의 주소까지 넘어가는 것이 아님


	//포인터를 사용하여 함수의 출력처럼 사용할 수 있음
	double degrees = 30;
	double sin, cos;

	//참조에 의한 전달과 달리 출력하는 sin, cos 의 주소를 보내야 함
	getSinCos(degrees, &sin, &cos);

	cout << sin << " " << cos << endl;
	
	//실용적인 면에서 참조를 쓰는게 더 좋음

	return 0;
}