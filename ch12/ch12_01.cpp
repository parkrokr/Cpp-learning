//다형성의 기본 개념
//자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?

//virtual

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;
public:
	Animal(std::string name)
		:m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const
	{
		cout << m_name << " ??? " << endl; //animal 은 추상적이기 때문에 뭐라고 짖는지 모름
	}
};

class Cat :public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog :public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

int main()
{
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();		//my animal ???
	cat.speak();		//my cat Meow
	dog.speak();		//my dog Woof


	//Animal type 포인터를 만들고 cat의 주소를 넣기
	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	//(포인터에선 ->사용)
	ptr_animal1->speak();	//my cat ???
	ptr_animal2->speak();	//my dog ???

	//자식 클래스를 부모 클래스의 포인터로 캐스팅 해서 사용하면 자기가 부모클래스인줄 알고 작동함

	//활용하는 방법
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	//cats 와 dogs 를 for 문으로 돌리고 싶을때
	for (int i = 0; i < 5; ++i)
		cats[i].speak();

	for (int i = 0; i < 2; ++i)
		dogs[i].speak();

	// . . .
	// . . .
	//Animal 을 상속받은 동물이 Cat 과 Dog 뿐만 아니라 더 많을 경우 구현하기 번거로움(for 문을 줄이고 싶음)

	//Animal class 의 포인터의 배열을 만들기 (Cat 와 Dog 모두 넣을 수 있음)
	Animal* my_animals[] = { &cats[0],&cats[1],&cats[2],&cats[3],&cats[4] ,
							&dogs[0],&dogs[1] };

	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();
	//여전히 ??? 라고 나옴 

	//Animal class 의 speak() 앞에 virtual 을 붙임, 타입은 부모클래스지만 자식클래스 인것처럼 행동함


	return 0;
}