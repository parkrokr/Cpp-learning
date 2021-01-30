//객체 잘림 (Object slicing) 과 reference_wrapper

//상속의 구조를 봤을때 자식 클래스에 정보가 더 많이 있음
//보다 작은 부모의 객체에 보다 큰 자식 클래스의 객체를 강제로 대입하면 
//자식클래스에만 있는 정보들은 사라지게 됨(객체 잘림(slicing))
//reference_wrapper 는 이를 방지할 수 있음

//참조나 포인터를 사용하지 않고 부모클래스에 자식클래스를 복사대입 해버리면 부모클래스에 있는 정보 빼고 날라가버림

//std::vector<Base> 의 push_back() 을 할때 slicing 이 일어남
//Base 의 포인터를 사용해도 되지만
//참조를 사용하고 싶으면 reference_wrapper 를 사용해야함(Base& 같은 참조는 벡터에 사용 못함)

#include <iostream>
#include <vector>
#include <functional> //to use std::refernece_wrapper<>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;
	//m_i는 안보이지만 추가 되어있음

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	Base& b = d;

	b.print();  //I'm derived

	// Base b = d; 를 하면 복사대입 되어버림, b는 d 와 완전히 별개인 Base type 의 객체가 되어버림
	// Derived 가 더 많은 정보를 담고 있기 때문에 m_j 는 없어지고(slicing)
	//다형성이 사라져 b.print(); 의 결과가 I'm base 임
	// Derived 에 담겨진 추가 정보들이 날라가기 때문에 Base 에 있는 함수들만 실행이 가능함
	// 의도적으로 slicing을 사용하는 경우는 보통 없고 다형성을 구현하려다가 실수한게 일반적
	// 의도된 경우 주석을 남겨두기

	doSomething(d);//I'm derived 가 

	//의도적이든 실수든 doSomething( Base & b) 에서 &를 지워버리면 복사가 되어버림
	//다형성이 사라져 I'm base 가 출력되어버림


	//초보때 자주 하는 실수
	vector<Base> my_vec;
	//Base b;
	Derived d;

	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto& ele : my_vec)
		ele.print();
	//둘다 I'm base 출력됨
	//두번째 push_back() 에 d 를 넣어지만 push_back 를 하는 과정에서 slicing 이 발생함
	
	
	//vector<Base&> my_vec; 를 시도하지만 빌드안됨, 벡터에는 참조를 넣을 수 없음
	
	
	//포인터는 됨
	vector<Base*> my_vetptr;
	my_vetptr.push_back(&b);
	my_vetptr.push_back(&d);

	for (auto& ele : my_vetptr)
		ele->print();
	//I'm Base
	//I'm Derived 출력 잘 됨


	//참조의 장점 때문에 참조를 쓰고 싶음, vector<Base&> 이런 의도로 사용하고 싶음(문법상 불가능)
	//std::reference_wrapper를 사용하면 my_vetref 는 Base 의 reference 를 저장하는 벡터가 됨
	vector<reference_wrapper<Base>> my_vetref;
	my_vetref.push_back(b);
	my_vetref.push_back(d);

	for (auto& ele : my_vetref)
		ele.get().print(); //reference 로부터 실제로 인스턴스를 받아와야하기 때문에 .get() 을 해야함

	return 0;
}
