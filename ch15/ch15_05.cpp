//std::unique_ptr

// 포인터가 가르키는 데이터의 소유권이 한곳에만 속할 경우 사용하는 스마트 포인터

//unique_ptr 의 특성 : 복사를 못함
//res2 = res1;  //복사를 못함

//하지 말아야 하는것!
// 두곳 이상에 소유권을 주는것, 다시 지우려고 시도하기

#include <iostream>
#include <memory>		//to use std::unique_ptr
#include "ch15_05_Resource.h"

using namespace std;

auto doSomething()
{
	//여러가지 방법으로 return 할 수 있음

	/*auto res1 = std::make_unique<Resource>(5);
	return res1;*/

	//return std::unique_ptr<Resource>(new Resource(5));

	return std::make_unique<Resource>(5);	//가장 간단
	//unique_ptr 은 내부적으로 move semantics 를 사용하기 때문에 소유권이 확실하게 넘어감,빠름(copy 를 호출안함)
}


//void doSomething2(std::unique_ptr<Resource>& res)		//가장 선호하는 스타일
//auto doSomething2(std::unique_ptr<Resource> res)	//l-value ref 가 아니라 value 로 받고싶을 경우
void doSomething2(Resource * res)	 //포인터만 넘겨주는 방법, unique_ptr의 get() 사용
{
	res->setAll(10);

	//return res;  
	//l-value ref 가 아니라 value 로 받은경우 소유권을 넘겨받았지만 함수가 끝나면 사라지기 때문에 
	//다시 res1 에게 소유권을 돌려주기 위해 return ( move 로 받았다가 move 로 돌려줌)
}


int main()
{
	{
		Resource* res = new Resource(1000000);

		//early return or throw

		//delete res;	//delete 가 실행되지 않아 소멸자가 호출되지 않고 있음
		//unique 포인터를 사용하면 자동으로 처리해줌
	}


	//unique_ptr 사용
	{
		//std::unique_ptr<Resource> res = new Resource(1000000);
		std::unique_ptr<Resource> res(new Resource(1000000));  //이 방법을 권장


		//no delete
	}
	//delete 가 없지만 영역을 벗어나면 알아서 소멸자를 호출하고 있음


	
	{
		std::unique_ptr<int> upi(new int);		//기본 자료형에도 사용 가능

		//std::unique_ptr<Resource> res1(new Resource(5));
		
		// ptr 을 넣어서 초기화를 시킬 수도 있음
		//auto* ptr = new Resource(5);
		//std::unique_ptr<Resource> res1(ptr);


		//권장하는 방법 :		std::make_unique 사용
		//auto res1 = std::make_unique<Resource>(5);	
		  //std::make_unique<Resource> 가 마치 resource 인것처럼 생성자 호출 가능

		auto res1 = doSomething();  //함수에서 return 되어서 오는 경우


		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;	

		//res1, res2 는 포인터이기 때문에 nullptr 인지 아닌지를 bool 로 cast 해서 알수 있음

		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;		//res1은 확실히 초기화가 되었기 때문에 nullptr 아님
		cout << static_cast<bool>(res2) << endl;		//res2 는 초기화 안됨, nullptr 임


		//unique_ptr 의 특성 : 복사를 못함
		//res2 = res1;  //복사를 못함
		//소유권이 한곳에만 있어야 하기 때문에 복사가 안됨, copy semantics 는 사용을 못함, move semantics 만 가능
		//소유권이 unique
		res2 = std::move(res1);


		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;		//res1 은 소유권을 잃음
		cout << static_cast<bool>(res2) << endl;		//res2 는 소유권을 얻음(유일하게, unique 하게)

		
		if (res1 != nullptr)res1->print();
		if (res2 != nullptr)res2->print();				//(*res2).print();

		//unique_ptr 도 멤버선택연산자 ->, de-referencing연산자 * 도 오버로딩이 되어있어서 사용 가능
	}



	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();		//1 1 1 1 1

		//doSomething2(res1);		//함수에 paramter 로 넣는 경우, l-value ref 를 넣고 있음
		

		//만약 l-value ref 가 아니라 value 로 받는 경우 위에 코드는 빌드 안됨, unique 하기 때문에 copy 를 거부함
		//그래도 반드시 넣어야 겠다면 std::move() 로 넣기, 이렇게 하면 res1 은 소유권을 뺏김
		//함수 안에서 res1 을 이전 받아서 모두 바꾸고 출력도 가능하지만
		//지역변수처럼 작동해 함수가 끝나면 소멸됨, res1 은 빼앗기고 print() 작동도 못시킴
		//다시 res1 을 사용하고 싶으면 함수로부터 다시 돌려받으면 됨
		//돌려 받았으니 출력도 됨
		//최근 나오는 언어들에선 이런 돌려받는 구조를 택하는 구조를 가지고 있다고도 함(파이썬)
		//c++ 에선 이렇게 소유권을 주고 다시 돌려받는것보단 그냥 l-value ref 를 쓰는게 편함
		//res1 = doSomething2(std::move(res1));


		//포인터만 넘길때
		//unique_ptr 안에 get() 이 있음, 포인터를 반환함
		doSomething2(res1.get());


		res1->print();		//10 10 10 10 10
	}




	//하지 말아야 하는것!
	// 두곳 이상에 소유권을 주는것, 다시 지우려고 시도하기
	{
		Resource* res = new Resource;

		//res 포인터에 대한 소유권을 두곳에다가 주려고 하고 있음, 나중에 두번 지우려고 시도하기 때문에 문제 발생
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);	//x


		//delete 를 추가로 하는 경우 지운걸 다시 또 지우려고 하기때문에 하면 안됨
		delete res;		//x
	}

	return 0;
}