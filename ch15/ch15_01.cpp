// '이동' ( Move semantics ) 의 의미와 스마트 포인터 ( Smart pointers ) 소개

//c++ 에서 가장 번거로운 것은 new 와 delete 를 통해 직접 메모리를 동적할당해야 하는것
//이는 스마트 포인터를 통해 상당부분 해결되었음

#include <iostream>
#include <string>
#include "ch15_01_Resource.h"
#include "ch15_01_AutoPtr.h"

using namespace std;

// RAII : resource acquisition is initialization  생성한 존재가 끝까지 책임져야 한다

void doSomething()
{
	try
	{
		Resource* res = new Resource;

		//work with res

		 //delete 를 하기전에 early return 을 한 경우 
		if (true)
		{
			delete res;  //반복문 안에서 delete 를 하고 나가게 짜면 됨, 하지만 번거로운건 마찬가지임
			//return;
			throw - 1; //throw 하면서 동시에 delete 를 할수 없어서 문제가 될 수 있음(생성은 되는데 소멸이 안됨)
		}


		delete res; //new 한 곳에서 delete 해줘야 한다는것을 RAII 라고 함, 보통 클래스 안에 묶어둠
		//초보 프로그래머가 실수로 아예 delete 를 호출하지 않으면 문제가 생김, 익숙해지면 됨
		//조금더 난감한 경우는 조건문을 걸었는데 early return 을 하게 되는 경우

		//전통적인 방법은 나가기 전에 지우고 나가기, 최근의 방법인 스마트 포인터를 사용하면
		//반복문 안에서도, 밖에서도 delete 를 안해줘도 알아서 지워줌
	}
	catch (...)
	{

	}
	return;
}

void doSomething_new()
{
	try
	{
		//Resource *res = new Resource;			//dull pointer
		//Autoptr<Resource> res = new Resource;	//smart pointer
		
		AutoPtr<Resource> res(new Resource);	//문법상 더 좋음
		//assignment 보단 초기화이니까 이게 더 깔끔함,생성자에 바로 paramter 로 넣어줌
		
		//Autoptr<Resource> *res 처럼 포인터로 가져올 필요가 없음, res 는 Autoptr<Resource> 타입의 객체를 
		//가르키는 포인터임, Resource 타입의 주소가 들어감, *res 로 하면 타입이 안맞으니 (포인터의 포인터라)
		//마치 int* a 에 double 의 주소를 넣는 꼴


		return;		//early return 되는 경우에도 잘 작동함

	

		//work with res
		if (false)
		{
			throw - 1; //exception
		}

		//delete res;
	}
	catch(...)
	{

	}
}

int main()
{

	doSomething();
	//이 함수를 호출하면 이 함수 안에서 어떤 Resource 를 동적할당해서 받아오고
	//포인터를 통해서 작업을 한 후 return 해서 나감, 나가기 전에 delete 을 해줘야함

	//동적으로 메모리를 할당받고 있지만 자기가 끝까지 책임지지 않은 포인터를 dull pointer 이라고 부름

	//메모리 관리를 프로그래머에게 전적으로 맏겨놓으니 프로그래머 입장에선 번거로움
	//하나하나 신경 쓰기가 번거로워짐


	//직접 관리하기 보단 항상 관리를 자동으로 해줄 수 있는 추가적인 클래스를 만드는 방법이 있음
	doSomething_new();
	//delete 를 주석처리해도 생성자와 소멸자가 잘 호출됨
	//thorw 해도 소멸자를 알아서 호출하고 있음,혼자 잘 지워줌
	//스마트 포인터가 이런식으로 알아서 잘 지워준다


	//오토포인터의 한계
	{
		// int i; int *ptr1(&i); int *ptr2 = nullptr;  //이런 구조라 생각하면 됨

		AutoPtr<Resource> res1(new Resource);	
		AutoPtr<Resource> res2;		//메모리를 갖고 있지는 않음, 그냥 포인터로만 존재함,초기화 안됨

		cout << std::boolalpha;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

		res2 = res1;		//문제가 될수 있는 부분, 대입
		//기본 복사 생성자가 복사만 해주고 끝남, res1과 res2 모두 new Resource 에 대한 주소를 가짐

	
		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;


		//런타임에러 발생
		//Resource 는 한번만 생성됨, 대입 연산 이후에는 둘다 같은 주소를 포인팅 하고 있음
		//문제는 영역을 벗어나면서 res1 이 지워지고, 이미 지워진 메모리를 res2 가 또다시 지우려고 함
		//하나의 메모리 주소에 대한 소유권을 둘다 가지려고 하는것이 문제
		//자료구조나 sorting 에서 지운걸 또 지우려고 할때 runtime error 가 자주 발생함

		//해결 방법: 소유권을 항상 하나만 갖게 하는것
		//res2 에 대입할때 res1 의 소유권을 넘겨주기, res1은 소유권 박탈, 소유권을 이동(move)
		//복사생성자, 대입연산자오버로딩에 소유권 이전(move) 구현하기
		//이렇게 하면 res1은 소유권을 이전한후 nullptr 이기 때문에 delete 를 할수도 없음

		//res2 = res1 처럼 소유권을 이전 하는것을 move semantics 라고 부름
	}


	//syntax vs semantics
	//syntax 입장에선 문법이 맞는지 안맞는지, 컴파일이 되는지 안되는지가 중요함
	//semantics 입장에선 내부적으로 의미가 뭔지를 봄, 밑의 예제에서 같은 + 기호지만 의미가 다름
	int x = 1, y = 2;
	x + y;

	string str1("Hello"), str2("World");
	str1 + str2;  //append

	//프로그래밍 언어 과목에서 자세하게 배움

	//똑같이 대입 연산자를 쓰고 paramter 에 넣는건데(문법적으로 같은데)
	//받는쪽에 따라 어떻게 기능할지는 semantics 에 따라 달라짐
	
	// value sematics		(copy semantics)
	// reference semantics	(pointer)
	// move sematics		(move)

	//AutoPtr 클래스의 복사생성자와 대입연산자는 copy semantics 를 구현한것이 아니라 move semantics 를 구현한것임



	//기초적인 용법(소멸자에서 delete, move semantics 구현)은 구현되어있음
	
	//res1 을 함수에 paramter 로 넘긴 경우 소유권이 그 함수 안에 있는 AutoPtr 로 넘어가고
	//그 함수가 끝나면 소멸되어버리고 밖에선 접근할 수 없게됨, 이런 문제들을 자연스럽게 해결하는게
	//스마트 포인터에서 알아야 할 내용들임
	
	
	//예전에는 RAII 의 개념아래 프로그래머가 직접 책임을 지고 사용을 했었음
	//그러나 조금더 복잡한 경우에도 프로그래머가 편하게 메모리 관리를 자동으로 할 수 있게
	//스마트 포인터가 도입이 되었음



	return 0;
}