//�������� �⺻ ����
//�ڽ� Ŭ������ ��ü�� �θ� Ŭ������ �����͸� ����Ѵٸ�?

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
		cout << m_name << " ??? " << endl; //animal �� �߻����̱� ������ ����� ¢���� ��
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


	//Animal type �����͸� ����� cat�� �ּҸ� �ֱ�
	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	//(�����Ϳ��� ->���)
	ptr_animal1->speak();	//my cat ???
	ptr_animal2->speak();	//my dog ???

	//�ڽ� Ŭ������ �θ� Ŭ������ �����ͷ� ĳ���� �ؼ� ����ϸ� �ڱⰡ �θ�Ŭ�������� �˰� �۵���

	//Ȱ���ϴ� ���
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	//cats �� dogs �� for ������ ������ ������
	for (int i = 0; i < 5; ++i)
		cats[i].speak();

	for (int i = 0; i < 2; ++i)
		dogs[i].speak();

	// . . .
	// . . .
	//Animal �� ��ӹ��� ������ Cat �� Dog �Ӹ� �ƴ϶� �� ���� ��� �����ϱ� ���ŷο�(for ���� ���̰� ����)

	//Animal class �� �������� �迭�� ����� (Cat �� Dog ��� ���� �� ����)
	Animal* my_animals[] = { &cats[0],&cats[1],&cats[2],&cats[3],&cats[4] ,
							&dogs[0],&dogs[1] };

	for (int i = 0; i < 7; ++i)
		my_animals[i]->speak();
	//������ ??? ��� ���� 

	//Animal class �� speak() �տ� virtual �� ����, Ÿ���� �θ�Ŭ�������� �ڽ�Ŭ���� �ΰ�ó�� �ൿ��


	return 0;
}