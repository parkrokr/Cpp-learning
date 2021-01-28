//가상 (함수) 표  Virtual Tables

//가상함수를 가진 클래스는 가상함수테이블에 대한 포인터를 가지게 됨

#include <iostream>
using namespace std;

class Base
{
public:
	//FunctionPointer *_vptr;		//가상함수테이블에 대한 포인터
	virtual void fun1() {};
	virtual void fun2() {};
};

class Der : public Base
{
public:
	//FunctionPointer *_vptr;
	virtual void fun1() {};
	void fun3() {};
};

int main()
{
	Base my_base;

	//컴파일러 내부적으로 virtual fucntion 이 선언이 되면 정적바인딩이 아닌 
	//가상함수의 표를 만들고 동적 바인딩을 시킴
	//가상함수가 하나도 없다면 가상함수테이블에 대한 포인터도 필요가 없음

	my_base.fun1();
	//my_base 에서 fun1()같은 가상함수를 호출시키려는 경우 정적바인딩으로 직접 호출시키는게 아니라
	//일단 포인터를 타고 가서 가상함수테이블을 찾음, 그 안에는 fun1() 에 대한 포인터(fun1()과 type 이 같은)
	//가 하나 있고 fun2()와 parameter 와 return type 이 같은 함수들에 대한 포인터가 있음
	//그중에 fun1() 포인터가 가르키고 있는 함수로 와서 실행시킴


	Der my_derived;
	//자식클래스에선 좀 달라짐
	//자식클래스도 가상함수테이블에 대한 포인터를 가지고 있음
	my_derived.fun1();
	//my_derived.fun1()을 호출하려는 경우 테이블의 포인터를 보고 테이블로 건너감
	//fun1()을 실행시키고 싶으면 fun1()의 포인터를 타고 가서 실행을 시킴
	//fun1() 은 오버라이드가 되어있기 때문에 Der 의 fun1()을 실행시키면 됨
	
	//my_derived 에서 fun2() 를 실행시키려고 하면 가상함수테이블에 와서 fun2()의 포인터를 찾지만
	//Der 에는 없기 때문에 부모클래스를 fun2() 가 가르키고 있음


	//자식클래스로 생성이 된 객체를 부모클래스의 포인터나 참조에 넣어도 가상함수테이블이 바뀌지 않기 때문에
	//Der 로 가기도 하고 Base 로 가기도 하는 구조를 유지하면서 다형성을 사용함





	cout << sizeof(Base) << endl;
	cout << sizeof(Der) << endl;
	//가상함수가 하나도 없으면 둘다 1byte(최소 데이터)를 가지고 있음
	//가상함수로 바꾸면 4 byte(x86 에서), table 에 대한 pointer 의 크기
	//x64 로 실행시키면 포인터라서 8 byte 로 바뀜

	//부모에는 가상함수가 없고 자식에만 가상함수가 있게하면 1,4 가 나옴
	//자식에는 가상함수가 없고 부모에만 있으면 상속때문에 4,4 가 나옴

	return 0;
}