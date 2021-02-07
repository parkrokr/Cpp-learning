// std::move

#include "ch15_04_AutoPtr.h"
#include "ch15_04_Resource.h"
#include <vector>
#include <string>

using namespace std;


//std::swap 가 있지만 이름만 바꿔서 구현
template<class T>
void MySwap(T& a, T& b)
{
	/*T tmp = a;
	a = b;
	b = tmp;*/

	//move semantics 이용해서 swap
	//move 를 해줘도 문제가 발생하지 않는 경우 사용
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}


int main()
{
	{
		AutoPtr<Resource> res1(new Resource(1000000));

		cout << res1.m_ptr << endl;

		//AutoPtr<Resource> res2 = res1;
		AutoPtr<Resource> res2 = std::move(res1);

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}
	//move 가 아니라 copy semantics 를 쓰고 있음
	//주소를 보면 새로 하나를 만들어서 복사를 해서 넣고 있음

	//move semantics 를 사용하고 싶으면 std::move 붙이기
	//std::move() 를 하면 안에 들어있는 l-value 를 r-value 로 바꿔줌
	//r-value 로 바꿔주면 r-value 를 사용하는 연산자를 사용함(move 생성자 호출됨)
	//move 를 한후 결과를 보면 포인터가 move 했기 때문에 res1 은 nullptr 이 됨
	//res2 는 heap 에 있던 메모리를 통째로 넘겨받음

	//원래 가지고 있던 데이터로 뭔갈 하려면 res2 로 접근해야지 res1 으로는 더이상 접근 못함
	//옮겨준 후에 res1 으로 작업을 한다면 프로그래머의 책임임


	{
		AutoPtr<Resource> res3(new Resource(3));
		res3->setAll(3);

		AutoPtr<Resource> res4(new Resource(5));
		res4->setAll(5);

		res3->print();		//3 3 3
		res4->print();		//5 5 5 5 5

		MySwap(res3, res4);

		res3->print();		//5 5 5 5 5
		res4->print();		//3 3 3
	}
	//MySwap() 에서 move seantics 를 사용하면 복사 생성자가 호출되지 않음
	//move 로 교체해서 끝남


	//MySwap() 도 move 를 해서 문제가 발생하지 않는 경우라 move 를 해준거지
	//일반적인 경우 move 를 해주면 문제가 발생할 수 있음( 기존꺼에 다시 접근,사용을 못하니까)
	//그래서 r-value refernece 만 가지고 move semantics 를 구현하는것(r-value 는 어차피 곳 사라지니까
	//move 를 해서 옮기더라도 문제가 없어서)
	//잘 모르고 move 를 사용하면 문제를 일으킬 수 있음


	//AutoPtr 안에 move semantics 를 구현했기 때문에 std::move 를 통해 강제할 수 있음
	//클래스를 만들때 기능들을 구현해야 std::move 를 통해 move semantics 를 할 수 있음
	
	
	//std 에는 move semantics 가 거의다 구현되어있음

	//std::vector
	{
		vector<string> v;
		string str = "Hello";

		v.push_back(str);			//str 을 l-value(변수) 로 받고 있음, copy semantics 를 하겠다는 의미

		cout << str << endl;					//Hello
		cout << v[0] << endl;					//Hello  복사가 되어서 들어감

		v.push_back(std::move(str)); //r-value ref 로 받고 있음, move semantics

		cout << str << endl;					//아무것도 출력 안됨,move 해줘서 뺏김
		cout << v[0] << " " << v[1] << endl;	//Hello Hello
	}
	//내부적으로 r-value 에 대한 pushback() 이 별도로 구현되어있음

	

	//std::string 에서도 move semantics 가 구현되어있음
	//MySwap 의 내부를 어떻게 구현하는가에 따라 string 에서도 뭐가 호출되는지가 달라짐
	//copy semantics 의 경우 tmp 에 "abc" 가 남아있었지만
	//move semantics 의 경우 tmp 는 b에 move 해주고 비워짐
	{
		std::string x{ "abc" };
		std::string y{ "de" };

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;

		MySwap(x, y);

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}

	return 0;
}