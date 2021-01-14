//Using 문과 모호성(Ambiguity)

#include<iostream>

namespace a
{
	int my_var(10);
	int my_a(123);
	int count(123123);
}

namespace b
{
	int my_var(20);
	int my_b(123);
}


int main()
{
	using namespace std;
	
	// std 안에 있는 cout, endl 만 가져오는방법, 보통은 이렇게 안하고 std를 다 가져옴
	/*using std::cout;
	using std::endl;*/
	
	//using namespace std::cout; //잘못된 표현

	cout << "Hello" << endl;

	using namespace a;
	using namespace b;


	cout << my_a << endl;
	cout << my_b << endl;

	//cout << my_var << endl; // 변수 이름이 같아 error, "my_var" is ambiguous 
	cout << a::my_var << endl;
	cout << b::my_var << endl;

	// ::를 쓰지 않고 싶으면 { }로 감싸주기
	/*
	{
		
		using namespace a;

		// 블록 밖 namspace b 에 my_var이 또 있다면 여전히 ambiguous 하기 때문에 error
		cout<< my_var << endl;

		//std에 count가 있기 때문에 error, a::count 사용
		cout<<count<<endl;
	}

	{
		using namespace b;
		cout << my_var << endl;
	}
	*/


	// namespace를 특정 헤더에서 전역범위에 넣게 되면 그 헤더를 include하는 모든 cpp파일에 영향을 주게 된다
	// 가급적이면 cpp파일에 넣는것이 좋다
	// 헤더에 using namespace를 써도 되긴 하지만 가급적 전역에 넣는건 좋지 않다


	//함수를 쪼개거나 using namespace를 쓰지말고 ::사용,
	//using namespace 는 한번 선언하면 취소할 방법이 없음
	//가급적 { }를 이용하여 싸주는것이 좋음
	//typing 효울성 때문에 넓게 사용하려면 한쪽은 희생시켜야 할 수도 있음


	return 0;
}