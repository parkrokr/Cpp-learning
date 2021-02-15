// 함수에서 여러개의 리턴값 반환하기 C++17

#include <iostream>
#include <tuple>

using namespace std;


//기본적으로 함수는 하나의 값만 return 함
//우회하는 방법으로 return type 을 structure 나 class 를 만들어서 사용하는 방법이 있음
//또는 std::tuple 을 사용하는 방법이 있음



tuple<int, int>my_func()	//int 두개를 return
{
	return tuple<int, int>(123, 456);
}


//더 편리하게 쓰기
auto my_func2()				//auto 사용
{
	//return tuple<int, int, int>(123, 456, 789);		//여기서 어떤걸 몇개를 return 할지 정함

	return tuple(123, 456, 789,10);						//C++17 부턴 <int, int, int> 가 없어도 됨
}


int main()
{
	tuple<int, int> result = my_func();		//tuple 을 받기

	cout << get<0>(result) << " " << get<1>(result) << endl;



	//더 편리하게 받기						//auto 사용
	auto result2 = my_func2();

	cout << get<0>(result2) << " " << get<1>(result2) << endl; 
	//return 값이 하나 더 늘었기 때문에 get<2>(result2)를 추가해줘야됨



	//더 편리하게 받기						//result 하나가 아니라 여러개 받기
	auto [a, b, c, d] = my_func2();			//변수 a,b,c,d 를 선언하면서 받는거랑 같음

	cout << a << " " << b << " " << c << " " << d << endl;


	return 0;
}