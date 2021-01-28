//가상 함수 (Virtual Functions) 와 다형성 ( Polymorphism )

//virtual 을 쓰는 경우 virtual 을 직접 호출하는게 아니라 테이블에서 상속받은 
//인스턴스를 찾아가는 과정을 거치기 때문에 느림
//호출이 아주 자주 되는 함수에 쓰면 안좋음

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B :public A
{
public:
	/*virtual*/ void print() { cout << "B" << endl; }
};

class C :public B
{
public:
	/*virtual*/void print() { cout << "C" << endl; }
};

class D :public C
{
public:
	/*virtual*/void print() { cout << "D" << endl; }

	//오버라이딩을 할때 return type 이 다른 경우
	//virtual int print() { cout << "D" << endl; return 0; }  
	//컴파일이 안됨, A::print() 와 return type 이 다르다고 에러가 발생, 
	//C 를 상속받아도 가장 상위 클래스인 A 의 가상함수와 비교함
	//오버로딩을 할때 return type 만으론 구별을 못함
};

int main()
{
	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();


	//A타입의 참조에 b 넣어주기, c,d 가 들어가도 똑같음
	A& ref = b;
	ref.print();
	//A의 print() 에 virtual 이 붙으면 자식 클래스에서 오버라이딩 된 함수를 그대로 사용함

	//B class 로 만들어진 인스턴스를 A 의 참조에 넣는데 A 안에 있는 print() 가 virtual 일 경우
	//밑에 상속받은 class 에서 오버라이딩 된 함수가 있을 경우 virtual 이 아니라 그 함수를 사용함

	//A의 print() 만 virtual 이고 B의 print() 는 virtual 이 아니지만 A type 참조에 C type 을 넣을경우
	//C가 A를 직접 상속받는게 아니라 중간에 B를 거쳐감에도 불구하고 B를 사용하는게 아닌 C 를 사용함
	A& ref1 = c;
	ref1.print(); //C


	//가장 상위 class 에 있는게 virtual 이 되어버리면 밑에 있는 것들도 virtual 처럼 행동함
	//그래서 상습적으로 밑에 있는 함수들도 virtual 을 붙이는 스타일이 있음
	//붙여두면 디버깅 할때 다형성에 의해 가상함수를 오보라이딩 한것인지 아닌지 쉽게 파악할 수 있음
	B& ref2 = c;
	ref2.print(); //C




	return 0;
}