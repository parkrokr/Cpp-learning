//포인터와 정적 배열

//포인터와 정적 배열은 같음
//정적배열에는 정적배열답게 쓸 수 있도록 몇가지 장치가 있음
//함수에선 정적배열을 포인터로 강제변환
//구조체나 class 안에 배열이 있으면 배열이 유지됨

#include <iostream>

using namespace std;


//array 가 parameter 로 들어오는 경우 포인터로 사용하게 됨

//void printArray(int array[])
void printArray(int *array)
{
	cout << sizeof(array) << endl;
	cout << *array << endl;

	*array = 100;
}


//구조체 안에 array를 넣는 경우
struct MyStruct
{
	int my_array[5] = { 9, 7, 5, 3, 1 };
};

//함수에 구조체 넣기
void doSomething(MyStruct ms) //ms 대신 *ms(포인터)
{
	cout << sizeof(ms.my_array) << endl; //ms 대신 *ms(de-referencing)
}

int main()
{
	

	int array[5] = { 9,7,5,3,1 };

	cout << array[0]<<" "<<array[1] << endl;
	cout << array << endl;
	cout << &(array[0]) << endl;

	//array 는 배열이 아니고 첫번째 값의 주소

	//de-referencing
	cout << *array << endl; //9

	//ptr 변수 선언후 대입
	int* ptr = array;		//여기서 *은 ptr 이란 변수가 포인터 변수임을 알려줌
	cout << ptr << endl;
	cout << *ptr << endl;	//여기서 *은 ptr을 de-referencing 하기 위한 연산자
	
	//ptr 자체의 주소는 또 다름


	//문자열
	char name[] = "jackjack";
	cout << *name << endl; //j //name 은 char type 포인터



	//포인터와 정적배열은 문법상 차이가 조금 있음. 
	
	//size 의 차이
	cout << sizeof(array) << endl; //5 * 4 = 20

	cout << sizeof(ptr) << endl;   //4 (포인터 변수의 사이즈)

	printArray(array);			   //4 (pointer size), array 가 parameter 로 들어오는 순간 pointer 가 됨

	cout << array[0] << " " << *array << endl; // 100 100 
	//함수 밖에서도 값이 바뀜, c에선 많이 사용했었음, c++에선 reference 를 사용함

	
	//포인터 연산
	cout << *ptr << " " << *(ptr + 1) << endl; //ptr + 1 하면 다음값 주소, 그래서 array[1]인 7



	//구조체 안에 array를 넣는 경우
	MyStruct ms;
	cout << ms.my_array[0] << endl;			//9
	cout << sizeof(ms.my_array) << endl;	//20

	doSomething(ms);						//20
	//ms 대신 &ms를 보내고 함수에서 포인터로 받아도 20은 그대로 유지됨

	//-> array 가 structure 나 class 안에 들어있을 경우 pointer 로 강제변환이 되지 않음,배열이 유지됨

	return 0;
}