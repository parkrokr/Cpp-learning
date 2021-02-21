// 완벽한 전달( Perfect Forwaring ) 과 std::forward

#include <iostream>
#include <vector>
#include <utility>	//std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)	//r value 냐 l value 냐에 따라 오버로딩이 됨
{
	cout << "Pass by R-ref" << endl;
}

//void func(MyStruct s)
//{
//	cout << "Pass by R-ref" << endl;
//}

template<typename T>
void func_wrapper(T t)
{
	func(t);
}


template<typename T>
void func_wrapper_perfect(T&& t)		//perfect forwarding 
{
	func(std::forward<T>(t));
	
	//std::forward 는 t 가 들어올때 l value 이면 l value, r value 이면 r value 로 return 해줌
}


int main()
{
	MyStruct s;

	func(s);							//Pass by L-ref
	func(MyStruct());					//Pass by R-ref
	//visual studio 가 ide 래벨에서 구분해줌

	//이렇게 직접적으로 사용하는것은 구분해줌
	
	//하지만 템플릿을 사용할때 구분을 안해줌
	func_wrapper(s);					//Pass by  L-ref
	func_wrapper(MyStruct());			//Pass by  L-ref
	//두개를 구분 못함, 템플릿화 하면서 r value 인지 l value 인지 정보가 날아가버림


	//해결하기 위해 perfect forwarding 을 구현함
	func_wrapper_perfect(s);			//Pass by L-ref
	func_wrapper_perfect(MyStruct());	//Pass by R-ref
	//std::forward 는 t 가 들어올때 l value 이면 l value, r value 이면 r value 로 return 해줌


	return 0;
}