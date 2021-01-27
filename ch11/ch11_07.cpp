//상속받은 함수 (Inherited Funcions ) 를 오버라이딩 (Overriding) 하기

//부모 클래스에 있는 함수를 자식 클래스에서 기능을 추가하기 위해 새로 정의해서 사용하는것을 오버라이딩이라고 함

//fried 함수를 오버라이딩 하는법( static_cast 로 cast 하기)

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		:m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}

	//output operator overloading
	friend std::ostream& operator <<(std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d = 0;
public:
	Derived(int value)
		:Base(value)
	{}

	//Derived 에 print() 가 없는 경우 부모클래스의 print() 가 호출되어 "I'm base" 출력됨
	//Base 의 print() 와 비슷하지만 약간 다름, 이경우 Derived 의 print() 가 호출됨
	void print()
	{
		//부모클래스에 있는걸 수행하고 추가로 자기가 있는걸 수행하고 싶음(함수 이름은 유지)
		//함수이름을 그냥 다르게 해버릴 수도 있지만 다형성 파트에선 필요함

		Base::print(); //부모 클래스에 있던 print() 호출, 앞에 부모 클래스 이름을 써주면 됨

		cout << "I'm derived" << endl; //추가로 자식 클래스에서 기능을 구현

		//print(); 실수로 이렇게 호출할 경우 재귀호출이 되어버려 무한루프에 빠지게 됨
	}
	
	//output operator overloading overriding
	friend std::ostream& operator <<(std::ostream& out, const Derived& b)
	{
		//출력 연산자 오버라이딩하기,특히 friend 일때
		//b를 static_cast를 이용해서 Base 로 cast 하기(Derived 는 메모리에 Base 의 정보를 갖고 있기 때문에)
		out << static_cast<Base>(b);

		out << "This is derived output" << endl;
		return out;
	}

};

int main()
{
	//함수 오버로딩
	Base base(5);
	base.print();

	Derived derived(7);
	derived.print();

	//연산자 오버로딩 오버라이딩
	cout << base;
	cout << derived;

	return 0;
}