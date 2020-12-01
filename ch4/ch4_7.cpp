//열거형 Enumerated Types

#include<iostream>
#include<typeinfo>
#include <string>

//무기에 따른 피해량을 int로 반환하는 함수
int computeDamage(int weapon_id)
{
	if (weapon_id == 0) // sword
	{
		return 1;
	}
	if (weapon_id == 1) // hammer
	{
		return 2;
	}

	// . . .

	//실수가 많아지는 방법
}


// 열거형
enum Color // user-defined data types
{
	COLOR_BLACK, // 0 , COLOR_BLACK = -3, 을 하면 COLOR_RED는 -2 인 식으로 하나씩 숫자가 올라감
	COLOR_RED,   // 1
	COLOR_BLUE = 5,
	COLOR_GREEN = 5,//COLOR_BLUE와  COLOR_GREEN을 둘다 같은수로 설정하면 구분할 수 없게 됨
	COLOR_SKYBLUE// ,이 마지막줄엔 없어도 됨,예전엔 허용 안되었음
	//BLUE,
};
// { } 끝나고 ; 찍어야 함

enum Feeling
{
	HAPPY, // 보통 대문자로 침
	JOY,
	TIRED,
	BLUE, //enum의 값도 전역처럼 작동하기 떄문에 다른 {}에도 영향을 줌
};

// enum class 가 c++ 11 에 있음




int main()
{
	using namespace std;

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED }; // 특성이 조금 달라서 주의할 필요가 있음

	Color my_color = COLOR_BLACK;

	cout << my_color << " " << COLOR_BLACK << endl;
	cout << COLOR_RED << endl;


	// 수동으로 숫자를 할당할수 있지만 실수로 같은 숫자를 할당하면 오류가 생길 수 있음
	if (COLOR_BLUE== COLOR_GREEN)
	{
		cout << "Equal" << endl;
	}
	//기본 할당 된 숫자를 쓰는게 좋음


	//내부적으로 정수로 처리되지만 정수처럼 사용은 불가능
	int color_id = COLOR_RED;

	// Color my_color1 = color_id; //불가능
	//Color my_color1 = 5; //int 를 바로 넣는건 불가능, 필요한 경우 casting 은 가능
	Color my_color1 = static_cast<Color>(5);

	cout << color_id << endl;


	//입력
	//cin >> my_color; 바로 받는건 불가능

	//우회해서 받는건 가능
	int in_number;
	cin >> in_number;

	if (in_number == 0) my_color = COLOR_BLACK;
	if (in_number == COLOR_BLUE) my_color = COLOR_BLUE;
	if (in_number == static_cast<Color>(0)) my_color = static_cast<Color>(0);
	// . . .
	
	cout << my_color << endl;

	
	//string 으로 받고싶은 경우
	string str_input;

	getline(cin, str_input);

	if (str_input == "COLOR_BLACK") 
		my_color = static_cast<Color>(0);

	//권장하지 않음, 사람이기 떄문에 실수할 수 있음



	//선언한 enum을 다른곳에서 쓰고 싶은 경우 forward declatraion 보단 header 파일 안에 다 넣어두고 include 해서씀



	return 0;
}