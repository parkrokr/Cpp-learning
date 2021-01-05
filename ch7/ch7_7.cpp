//함수 오버로딩 Function Overloading 

//동일한 이름을 가진 함수를 여러가지 만드는것
//parameter로 함수 구별, return type 만으론 구별 안됨
//경우에 따라 매치가 안되서, 매치가 전부 애매하게 가능해서 에러가 날 수 있음


#include<iostream>

//x 와 y를 더하는 함수들
//int
int addInt(int x, int y)
{
	return x + y;
}
//double
double addDouble(double x, double y)
{
	return x + y;
}

//들어오는 parameter 가 다른데 하는 기능이 비슷한 경우 함수오버로딩 사용 가능
//int
int add(int x, int y)
{
	return x + y;
}
//double
double add(double x, double y)
{
	return x + y;
}

//같은 이름을 쓰고 싶은 경우

//parameter로 값을 돌려받는 방법
void getRandomValue(int &x){}
void getRandomValue(double &x) {}


//tyepdef을 써도 눈속임 불가능
//typedef int my_int;
//void print(int x) {}
//void print(my_int x) {}

//빌드 안됨 , 이미 바디가 있다고 뜸


//구분이 안되는 경우
void print(const char* value) {}
void print(int value) {}

void print_2(unsigned int value){}
void print_2(float value){}


using namespace std;

int main()
{
	add(1, 2);  //return int
	add(3.0, 4.0);  //return double

	//함수가 같다 다르다의 기준   parameter
	//이름이 기준이 아님
	//함수 이름이 같아도 parameter 가 다르면 다른 함수로 정의함
	//parameter가 같은 함수 두개가 있으면 문제가 생김

	//c++에선 return type 만 다른것만으론 함수 오버로딩이 안됨


	//주어진 인자와 parameter 가 가장 조합이 좋은 함수를 찾아서 실행함

	//어떤 add()를 사용할지는 compile 할때 결정되어야 함



	//같은 이름을 쓰고 싶은 경우

	//parameter로 값을 돌려받는 방법
	int x;
	getRandomValue(x);

	// int x = getRandomValue(x);

	//x 가 입력인지 값을 가져오는건지 구분이 안갈 수 있음
	// int x = getRandomValueInt(x);  함수 이름으로 표현해주기
	// int x = getRandomValue(int());  뭔가 넣어줘야 오버로딩을 할 수 있음



	//구분이 안되는 경우
	print(0); // int 인 것을 정확히 알 수 있음
	print('a'); //char 가 아닌 *char 이기 때문에 'a'를 int 로 인식하고 있음
	//잘 맞는것이 없어서 억지로 있는것중에 가장 비슷한걸 맞춘 경우 잘 안맞은 경우

	print("a");  //const char* value 가 아니면 매치를 못찾음(맞는 함수가 없다고 나옴)


	//너무 잘 맞는 경우
	//print_2('a'); //'a'가 딱 맞는것은 없으나 unsigned int 랑 float 로 바꿀 수 있음   ambiguos 에러 발생
	//print_2(0); //ambiguos 에러
	//print_2(3.141592);  //ambiguos 에러

	//정확하게 넣기
	print_2((unsigned int)'a');		//unsigned int
	print_2(0u);					//unsigned int
	print_2(3.141592f);				//float



	//명확하게 지도를 하면 함수 오버로딩의 모호성을 제거할 수 있음
	//기본적으로 명확하게 구현하는것이 중요
	//그냥 다른 이름을 쓰는게 억지로 오버로딩보다 좋을 수도 있음
	//주석 달아서 주의사항 명시하기
	

	return 0;
}