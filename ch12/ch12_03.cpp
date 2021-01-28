//override, fianl, 공변 ( Covariant ) 반환형  

//오버라이드를 의도적으로 할때 override 를 붙이면 실수를 막을 수 있음

#include <iostream>
using namespace std;

class A
{
public:
	//virtual void print(int x) { cout << "A" << endl; } //B의 print() 와 parameter type 이 다름
	virtual void print() { cout << "A" << endl; }


	//B의 getThis() 가 A의 getThis() 와 return type 이 다르지만 오버라이드가 됨
	void print1() { cout << "A" << endl; }
	virtual A* getThis() 
	{
		cout << "A::getThis ";
		return this;
	}
};

class B : public A
{
public:
	//부모클래스의 print() 와 parameter type 이 다름
	//오버라이딩을 하고 싶었지만 컴파일러는 오버로딩으로 해석함(parameter 가 달라서)
	//오버라이드를 하게 막고 싶은 경우 override 키워드를 붙이면 됨(컴파일 에러를 미리 찾아줌)

	//void print(short x) override { cout << "B" << endl; } //parameter 가 달라 에러 발생
	//void print1(int x) override { cout << "B" << endl; } //함수 이름이 달라 에러 발생
	//void print(int x) const override { cout << "B" << endl; }//const가 되어 에러 발생(부모의 함수가 const 면 가능)
	
	//final 을 붙이면 밑에 함수들은 오버라이드를 못함,내용을 못바꿈
	void print() final override { cout << "B" << endl; } 
	

	//A의 getThis() 와 return type 이 다르지만 오버라이드가 됨
	void print1(){ cout << "B" << endl; }
	virtual B* getThis() 
	{
		cout << "B::getThis ";
		return this;
	}
};

class C : public B
{
public:
	//virtual void print() {cout << "C" << endl; } //final 로 위에서 막아서 오버라이드를 못함
};


int main()
{
	A a;
	B b;
	C c;

	A& ref = b;
	//ref.print(1);  //B에 있는 print() 가 실행되기를 바랬음 하지만 A 가 나옴
	//함수는 parameter 가 다르면 오버라이딩을 할 수 없음
	//컴파일러 입장에선 함수가 오버라이딩이 아니고 오버로딩을 한걸로 해석함


	//공변 ( Covariant ) 반환형 
	b.getThis()->print1();		//B, B::getThis()
	ref.getThis()->print1();	//A, B::getThis()
	//ref 의 type 은 A 라서 B::getThis() 에서 B의 포인터를 리턴해줘도
	//내부적으로 다시 A의 포인터로 바꾼후 A::print()를호출함

	cout << typeid(b.getThis()).name() << endl;		//class B *
	cout << typeid(ref.getThis()).name() << endl;	//class A *

}