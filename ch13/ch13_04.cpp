//함수 템플릿 특수화 Specialization

//getMax() 라는 템플릿화 된 함수가 있는데 특별한 경우(특정 data type 에 대해서) instantiation 
//이 되는경우 특수화를 할 수 있음


#include <iostream>
#include "ch13_04_Storage.h"

#include "ch13_04_Storage.cpp"		//특수화된 멤버함수를 cpp 파일로 옮겼을때 해결방법2
//cpp 파일을 include 하면 함수의 body 가 main.cpp 에 있는꼴이고 결국은 헤더에 있는거랑 같은꼴임
//다만 파일이 좀 분리되어 있을 뿐임

using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


//specialization 
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing chars " << endl;

	return (x > y) ? x : y;
}



int main()
{
	cout << getMax(1, 2) << endl;
	//getMax() 에 들어가는게 int 이기 때문에 자동으로 정수 type 에 대해서 빌드를 하고 있음
	//getMax<int>(1, 2)도 가능, <int> 는 parameter 가 int 이기 때문에 자동으로 찾아주고 있음

	//double 로 instantiation 하고 싶을때
	cout << getMax(1.0, 2.0) << endl;
	cout << getMax<double>(1, 2) << endl;  //강제로 double type 으로 instantiation 하고 있음


	//문자끼리 비교할때 문자끼리 비교한다는걸 사용자에게 경고하고 싶음
	cout << getMax('a', 'b') << endl;
	//if문은 못씀(compile time 에 해야되기 때문에) 대신 비슷한건 쓸 수 있지만 뒤에서 나옴

	//specialization 
	//특수한 type 에 대해서 특수화


	//member function 에 대한 특수화


	Storage<int> nValue(5);
	Storage<double> dvalue(6.7);


	//double type 에 대해선 scinetific notation(과학적 표기법) 을 했으면 좋겠음
	nValue.print();
	dvalue.print();


	return 0;
}