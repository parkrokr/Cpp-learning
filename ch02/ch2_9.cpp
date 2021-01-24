// 심볼릭 상수 Symbolic Constants

#include <iostream>
#include "MY_CONSTANTS.h"
#define PRICE_PER_ITEM 30

using namespace std;

void printNumber(const int my_number)
{
	// my_number = 456; 이런식으로 parameter를 직접 바꾸는것은 좋지 않음

	int n = my_number;

	cout << my_number << endl;
}

int main()
{
	printNumber(123);


	//상수값 고정 , 반드시 초기화 해줘야 됨 
	//const 는 보통 앞에 붙임 , 당장은 순서 별로 상관 없음
	const double gravity{ 9.8 };
	double const gravity1{ 9.8 };

	//gravity = 1.2; const로 고정했기 때문에 바꾸지 못함

	
	// 컴파일 할때 결정되는 compiletime 상수
	const int my_const(123);
	
	
	//실행시켜야 결정되는 runtime 상수
	int number;
	cin >> number;

	// 변수 number는 바꿀 수 있지만 special_number는 못바꿈
	const int special_number(number);

	// constexpr 은 compile 상수라는걸 체크함
	constexpr int my_newconst(123);

	//constexpr int special_newnumber(number); runtime 상수이기 때문에 안됨



	// 매크로는 보통 대문자,const는 특별한 경우 앞에 k 같은거 붙임
	const int k_price_per_item = 30; 
	int num_item = 123;

	// c style ( 매크로 선언 )
	//debug가 힘들기 때문에, 상수 적용 범위가 너무 넓어지기 때문에 안좋음
	int price = num_item * PRICE_PER_ITEM;

	// 바람직한 style
	int price = num_item * k_price_per_item;

	double radius;
	cin >> radius;

	double circumferce = 2.0 * radius * constants::pi;



	return 0;
}
