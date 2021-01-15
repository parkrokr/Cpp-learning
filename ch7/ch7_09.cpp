//함수 포인터 Function Pointers

//함수에 대한 포인터

//  함수 이름 뒤에 () 를 붙이면 function call
// 함수는 함수의 포인터로 자동 형변환을 해줍니다.
// &를 안써도 형변환을 해서 포인터로 바꾼 후에 대입해줌

#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func()
{
	return 5;
}

int goo()
{
	return 10;
}


//홀수, 짝수를 선택해서 출력
//void printNumbers(const array<int, 10>& my_array,bool print_even)
//{
//	for (auto element : my_array)
//	{
//		if (print_even && element % 2 == 0)cout << element;	//짝수일때만 출력
//		if (!print_even && element % 2 == 1)cout << element;//홀수일때만 출력
//	}
//	cout << endl;
//}

//함수 포인터 사용
//짝수면 true 리턴
bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;	//없으면 모든 경로가 리턴값이 없다는 에러가 뜸
}
//홀수면 true 리턴
bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

// check_fcn자리에 isEven()나 isOdd() 들어감
// bool (*check_fcn)(const int&) = isEven 으로 default prameter 설정할 수도 있음
void printNumbers(const array<int, 10>& my_array, bool (*check_fcn)(const int&))
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true)cout << element;	
	}
	cout << endl;
}




int main()
{
	cout << func << endl;  //func() 가 아님
	//실행하면 주소가 나옴
	//함수도 포인터임(주소를 가지고 있음)

	//func();를 하면 함수가 어느 메모리주소에 있는지 알아내고 그 주소에 있는 프로그램을 가지고 와서 실행


	//함수 포인터 선언
	//fcnptr 함수 포인터 변수 선언후 func로 초기화
	int (*fcnptr)() = func; //받으려는 함수의 return type과 일치해야함

	cout << fcnptr() << endl;  //()를 붙이면 함수를 실행함

	fcnptr = goo; //중간에 바꿔치기 할 수 있음

	cout << fcnptr() << endl;



	//매개변수와 함수 포인터를 맞춰줘야 사용 할 수있음
	
	//int func(int x) {} 로 선언을 했으면
	//int(*fcnptr)(int) = func;
	//goo()로 바꾸려면 
	//int goo(int x) {}로 매개변수와 reuturn type을 맞춰줘야함




	//함수 포인터를 함수 매개변수로 넣을 수 있음
	std::array<int, 10>my_array = { 0,1,2,3,4,5,6,7,8,9 };

	//홀수, 짝수를 선택해서 출력
	//printNumbers(my_array,true);  //true일때 짝수
	//printNumbers(my_array, false); //false 일때 홀수


	//함수 포인터 사용
	//함수는 이름자체가 포인터라서 앞에 &를 안붙여도 됨
	printNumbers(my_array,isEven);  // isEven 일때 짝수
	printNumbers(my_array, isOdd);  // isOdd  일때 홀수

	//printNumbers(my_array); // isEven 으로 default prameter 설정했을때 짝수 출력


	//Type aliases(가명 붙이기) 도 할 수있음
	//매번 bool (*check_fcn)(const int&)하기가 번거로운 경우

	//typedef 를 사용하는 경우
	//typedef bool (*check_fcn_t)(const int&); 을 하면
	//check_fcn_t로 줄여서 사용할 수 있음

	//using 을 사용하는 경우
	//using check_fcn_t = bool(*)(const int&)



	//std::function
	std::function<bool(const int&)> fcnptr = isEven;  //을 사용하면

	//받는쪽에서 사용할 수 있음
	/*void printNumbers(const array<int, 10>&my_array,std::function<bool(const int&)> fcnptr)
	{
		for (auto element : my_array)
		{
			if (check_fcn(element) == true)cout << element;
		}
		cout << endl;
	}*/

	//printNumbers(my_array, fcnptr);

	//fcnptr = isOdd;

	//printNumbers(my_array, fcnptr);

	return 0;
}
