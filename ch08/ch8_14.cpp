//Ŭ���� �ȿ� ���Ե� �ڷ��� Nested types

//���� Ŭ������ ���������� ����ϴ� data type ��� ����� �̾Ƽ� �����ϴ°� ��������
//Ư�� Ŭ���������� ����ϴ� data type �� ��� class �ȿ� �ӽ÷� ����Ҽ� �ְ� ���� �� ����

#include<iostream>
using namespace std;

//Fruit class ������ member variable ���� ���� ����
//enum FruitType  
//{
//	APPLE, BANANA, CHERRY,
//};

class Fruit
{
public:
	enum FruitType  //class ������ ���� �� ����
	{
		APPLE, BANANA, CHERRY,
	};

	class InnerClass	//class �� ����( inner class )
	{
		//. . .
	};

	struct InnerStruct	//structure �� ����
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
	//class �ۿ� ���� ���
	/*Fruit apple(APPLE);

	if (apple.getType() == APPLE)
	{
		cout << "Apple" << endl;
	}*/


	Fruit apple(Fruit::APPLE);	//APPLE �̶� FruitType  class Fruit �ȿ� �����ִ°� ǥ���� �����

	if (apple.getType() == Fruit::APPLE)
	{
		cout << "Apple" << endl;
	}


	//enum class ����� Fruit::APPLE ��� Fruit::FruitType::APPLE ���� �� ��üȭ �������

	return 0;
}