// 람다 (lambda ) 함수와 std::function

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>		//to use  for_each()
#include <functional>
using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye" << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};


int main()
{
	//람다 함수는 익명함수, anonymous function 라고도 함, 어원은 lambda calculous 에서 나왔다고 함
	//c++ 뿐만 아니라 최근 다른 언어들에서도 공통적인 사용법이 나타나고 있음
	//익명 함수니 이름이 없어도 됨

	auto func = [](const int& i)->void {cout << "Hello, World!" << endl; };
	
	// []						lambda-introducer 
	
	// (const int& i)				lambda-parameter-declaration	
									//일반 함수처럼 paramter 선언
	
	// ->void					lambda-return-type-clause		
									//return type 을 앞이 아니라 뒤에 붙일수도 있음
									//ch4_04 auto return type 참고, trailing

	// {cout << "Hello, World!" << endl; };		compound-statement
									//functin 의 body 가 됨
	
	
	//[], () ,return type을 생략할 수 있음

	func(123);	//이건 func 를 function pointer 처럼 사용하고 있는것

	
	//진정한 람다의 가치는 익명일때 나타남
	[](const int& i)->void {cout << "Hello, World!" << endl; }(123);
	//body 뒤에 () 를 바로 붙이면 실행됨


	//기존처럼 함수를 정의하고 body 를 만들고 호출해서 쓰는 과정이 잡다하게 많이 구현해야할경우 번거로워짐
	//그러나 이렇게 람다(무명) 함수를 사용하면 훨씬 유연하게 프로그래밍 할 수있음
	//Gui 관련된 프로그래밍을 많이 하다보면 많이 사용하게 됨



	// lambda-introducer
		//[] 안에 & 를 넣어두면 영역 안에서 함수 밖에 있는걸 reference 로 가져옴
		//[] 안에 = 를 넣으면 copy 를 해서 가져옴
		//paramter 가 아니라 scope 안에 있는 변수들을 가져오는 방식
	{
		string name = "JackJack";
		[&]() {std::cout << name << endl; }();
		[&name]() {std::cout << name << endl; }();	//이렇게 사용할 수도 있음

		[=]() {std::cout << name << endl; }();		//name 을 copy 를 해서 가져오고 있음

		//[this]() {std::cout << name << endl; }();	//class 의 member 로 정의할때 이렇게 쓸 수 있음
	}


	//이렇게 사용 가능
	cout << []()->int {return 1; }() << endl;



	//STL 이랑 같이 사용될 수도 있음
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	//for_each 를 이용해서 vector 에 있는 원소들을 이용해서 각각 함수가 실행되는걸 구현
	//함수를 정의하고 함수포인터로 집어넣고 하면 번거로워짐,이때 람다 함수를 사용할 수 있음
	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);

	//람다 함수는 사실 위에 방식보단 이렇게 바로 넣으려고 사용함, 최근에는 이방식을 사용함
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	//auto func2 = [](int val)->void {cout << val << endl; };	//이렇게 void 를 적어도 되지만
	//람다함수는 return type 이 void 인 경우 생략함





	//std::fucntion
		//function pointer 를 체계화 시킨것
	std::function<void(int)> func3 = func2;		//void 가 return type, int 가 parameter type
	func3(123);									//functor(함수객체) 처럼 실행시킬 수 있음


	//std::bind		
		//	parameter 를 모두 고정, return type 은 std:function, 즉 함수 포인터
		//	첫번째 parameter 에는 함수객체,함수포인터,함수 ref, 멤버함수포인터 같은 인자와 묶일수 있는
		//Collable object 가 온다
		//	두번째 parameter 부턴 인자들이 들어옴, 고정하지 않고 여러개의 인자들을 받고 싶으면 std::placeholders

	//특정 parameter에 대해서만 실행시키면 되는데 void(int) 이렇게 paramter 를 넣는게 귀찮을 수 있음
	//std::bind() 를 써서 (int 를 받는)func3 와 int를 bind 해줌
	//func4 는 func3 가 전달되는데 parameter 가 없음, void(void) 임
	std::function<void()> func4 = std::bind(func3, 456);
	func4();



	//std::placeholder
		//	std::function 과 std::bind 를 함께 사용할때 parameter 를 모두 고정하지 않고 특정 parameter 만 
		//고정해서 사용하고 싶은 경우 사용
		//	std::placeholders::_1 에서 _1 은 1번째 parameter 를 의미,
	
	{
		//function binding
		auto f = std::bind(&goodbye, std::placeholders::_1);	
		//goodbye() 의 parameter 가 1개라서 placeholders::_1
		//auto 대신에 std::function 에 넣어도 됨

		f("World");



		//member function binding
		Object instance;
		auto f2 = std::bind(&Object::hello, &instance, std::placeholders::_1); 
		//class Object 에 속해있는 멤버함수 hello() 를 실행시기 위해서는 Object class 의 
		//this 포인터를 가지고 있는 instance 가 필요함
		
		//hello()의 포인터, instance 의 포인터를 넣어주고 hello 의 parameter 가 하나라서
		//std::placeholders::_1 를 통해 첫번째 parameter 를 받음
		//멤버함수포인터는 형변환을 해주지 않기 때문에 &를 반드시 붙여줘야함

		f2(string("World"));		//string 이란걸 강조하기 위해서 string 을 씀
		f2("World");				//이렇게만 해도 됨
	}


	return 0;
}
