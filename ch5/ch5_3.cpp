// Switch-case
//break

#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	// 너무 번거로움
	/*if (color == Colors::BLACK)
		cout << "Black" << endl;
	else if (color == Colors::WHITE)
		cout << "White" << endl;
	else if (color == Colors::RED)
		cout << "Red" << endl;*/ 

	
	/*switch (color)
	{
	case Colors::BLACK :
		cout << "Black" << endl;
		break;
	case Colors::BLUE:
		cout << "Blue" << endl;
		break;
	case Colors::GREEN:
		cout << "Green" << endl;
		break;
	}*/


	//::BLACK 하는것이 귀찮을 수 있음
	//using 은 못씀 Colors 는 namespace 가 아님
	//printColorName()이 enum class 안으로 들어가지 못함
	//멤버가 내부적으로 int 로 처리되기 때문에 static_cast 사용하면 가능

	switch (static_cast<int>(color))
	{
	case 0:
		cout << "Black" << endl;
		break;
	case 1:
		cout << "Blue" << endl;
		break;
	case 2:
		cout << "Green" << endl;
		break;
	}
}

int main()
{
	printColorName(Colors::BLACK);

	//입력받은 숫자를 문자로 출력하는 함수
	int x;
	cin >> x;

	switch (x)
	{
	/*case 0:
		cout << "Zero";
	case 1:
		cout << "One";
	case 2:
		cout << "Two";*/
	//break; 가 없기 때문에 0이 입력되면 그 밑에까지 다 실행됨
	//의도적으로 break를 안 쓸수도 있음, 특별한 경우 주석으로 상황 설명해두기
	//break 만나는 즉시 switch 블록에서 나감

	case 0:
		cout << "Zero";
		break;
	case 1:
		cout << "One";
		break;
	case 2:
		cout << "Two";
		break;
	}
	cout << endl; //어차피 endl; 을 쳐야 하기 때문에 밑에서 한번에 적용되게 하나만 사용

	
	//주의사항
	//case 문 안에 내용이 많아지면 { }으로 감싸기
	//내부에서 변수가 사용되면 적은 범위에서, 사용되기 직전에 정의해서 사용하기
	switch (x)
	{
		int a; //변수 선언 가능, switch 문 밖으로 나가면 사라짐
		int b = 5; //선언은 가능하지만 초기화(메모리 할당)는 못함
	
	case 0:
		int y; //case 문 다음에 변수선언 가능, case 밖에서 선언한거랑 같음
		a = 1; //값을 넣어주는건 case문 다음에서만 할 수 있음
		cout << a << endl;
		break;

	case 1:
		y = 5; //초기화는 case 1 에서만 했기 때문에 case 0 에서 y = 5;를 하면 case 1에선 가비지값이 나옴
		cout << y << endl;
		break;
	case 2:
	{
		int y = 5;
		y = y + x;
		cout << y << endl;
		break;
	}
	
	//case 가 정의안된 모든 경우에 대해서 default 가 실행
	default:
		cout << "Undefined input" << x << endl;
		//break;// 보통 default 에 대해서 break 가 없는게 일반적, 굳이 쓰는 이유는 통일감을 위해

	}

	return 0;
}