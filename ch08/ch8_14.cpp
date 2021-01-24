//클래스 안에 포함된 자료형 Nested types

//여러 클래스가 공통적으로 사용하는 data type 경우 헤더로 뽑아서 관리하는게 편하지만
//특정 클래스에서만 사용하는 data type 의 경우 class 안에 임시로 사용할수 있게 만들 수 있음

#include<iostream>
using namespace std;

//Fruit class 에서만 member variable 으로 쓰고 있음
//enum FruitType  
//{
//	APPLE, BANANA, CHERRY,
//};

class Fruit
{
public:
	enum FruitType  //class 안으로 넣을 수 있음
	{
		APPLE, BANANA, CHERRY,
	};

	class InnerClass	//class 도 가능( inner class )
	{
		//. . .
	};

	struct InnerStruct	//structure 도 가능
	{
		//. . .
	};

private:
	FruitType m_type;

public:
	Fruit(FruitType type)
		: m_type(type)
	{}

	FruitType getType() { return m_type; }
};


int main()
{
	//class 밖에 있을 경우
	/*Fruit apple(APPLE);

	if (apple.getType() == APPLE)
	{
		cout << "Apple" << endl;
	}*/


	Fruit apple(Fruit::APPLE);	//APPLE 이란 FruitType  class Fruit 안에 속해있는걸 표시해 줘야함

	if (apple.getType() == Fruit::APPLE)
	{
		cout << "Apple" << endl;
	}


	//enum class 쓸경우 Fruit::APPLE 대신 Fruit::FruitType::APPLE 으로 더 구체화 해줘야함

	return 0;
}