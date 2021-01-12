//다양한 반환 값들(Returning Values)  값, 참조, 주소, 구조체, 튜플(Tuple)

#include<iostream>
#include<array>
#include<tuple>

using namespace std;

//return by value
int getValue(int x)
{
	int value = x * 2;
	return value;
}

//return by address
int* getValue_ptr(int x)
{
	int value = x * 2;
	return &value;
}

//return by address(dynamic allocated array)
int* allocateMemory(int size)
{
	return new int[size];
}

//return by reference
//return type을 정의하는 부분에서 reference 인지 value 인지 확인해야 해서 실수 확률이 올라감
int& getValue_ref(int x)
{
	int value = x * 2;
	return value;
}

//return by reference 가 더 편한 경우
//my_array 의 일부를 함수가 고치게 하기
int& get(std::array<int, 100>& my_array, int index)
{
	return my_array[index];
}

//여러개의 return 값
struct S
{
	int a, b, c, d;
};

//return by structure
S getStrct()
{
	S my_s{ 1,2,3,4 };
	return my_s;
}

//int와 double 형을 return 하고 싶다
std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}


int main()
{
	//return by value
	int value = getValue(3);
	
	//단점 : 복사와 생성이 여러번 일어남, 속도가 조금 떨어짐


	//return by address
	
	//de-referecing 해서 값으로 받기   가급적 안하기
	int value_ptr_de_ref =*getValue_ptr(3);
	//권장 하진 않음, 함수 영역을 벗어남과 동시에 사라질 변수를 역참조 하는게 안전하지 않음 
	
	cout << value_ptr_de_ref << endl; // warning C4172 발생
	cout << value_ptr_de_ref << endl;

	//주소로 받기		더 위험함   권장하지 않음
	int* value_ptr = getValue_ptr(3);
	//받아오는 주소에 담겨있는 것이 함수 영역이 끝나면 뭐가 담겨있을지 알 수 없음
	
	cout << *value_ptr << endl; // warning C4172 발생
	cout << *value_ptr << endl;  //함수 영역이 끝나면 메모리도 사라져서 다른 값이 나옴

	//return by address를 array 를 만들때 사용하는 방법
	//int* array = new int[10];   // new int[10]를 함수로 만들기
	int* array = allocateMemory(10);

	delete[] array;  // 이런식으로 동적 메모리를 만드는 경우는 프로그래머를 힘들게 할 수 있음(함수와 분리되어있어서)



	//return by reference
	//비교적 안전함
	int value_ref = getValue_ref(5);
	cout << value_ref << endl;

	//받는쪽도 참조일 경우 문제가 발생할 수 있음,매우 안좋음
	//함수 영역이 끝나면 메모리도 사라짐, 함수에 const 를 넣어도 소용 없음
	int& value_ref_ref = getValue_ref(5);
	cout << value_ref_ref << endl;
	cout << value_ref_ref << endl;  // 함수 영역이 끝나면 메모리도 사라져서 다른 값이 나옴


	//return by reference 가 더 편한 경우
	std::array<int, 100> my_array; //함수영역과 달리 메모리가 확실하게 있음
	my_array[30] = 10;
	
	//my_array 의 일부를 함수가 고치게 하기
	//밑의 예제와 같이 편리하게 다룰 수 있음
	get(my_array, 30)= 1024;
	get(my_array, 30) *= 2;

	cout << my_array[30] << endl;




	//여러 개의 return 값
	
	//c style
	//structure 로 받는게 일반적
	S my_s = getStrct();
	my_s.a;
	
	//단점 : 함수 하나를 만들때마다 구조체를 하나씩 만들어 줘야 한다
	//옛날 라이브러리들이 이런식으로 짜여 있음


	//tuple
	std::tuple<int, double> my_tp = getTuple();

	//값을 가져올때
	cout << std::get<0>(my_tp) << endl; //a
	cout << std::get<1>(my_tp) << endl; //b


	//in c++17
	auto [a, b] = getTuple();  //a와 b를 선언하면서 값을 받는것
	cout << a << endl;
	cout << b << endl;

	return 0;
}
