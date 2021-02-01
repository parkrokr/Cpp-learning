//자료형이 아닌 템플릿 매개변수 Non-type Parameters


//Non-type paramter 는 compile time 에 결정되어 있어야 함

//Non-type parameter 를 사용할때 함수를 cpp 로 뺄경우 
//들어올수 있는 숫자에 대해서 전부 explicit instantiation 을 해줘야 하기 때문에
//Non-type parameter 가 있을 경우 boy 를 전부 헤더에만 둠

//이런 방식이 잘 사용되는 경우는 메모리 개수 결정보단 
//알고리즘을 구현할때 2차원일때는 몇개, 3차원일때는 몇개 이런식으로 사용됨

#include "ch13_03_MyArray.h"

using namespace std;

int main()
{
	//std::array를 사용했을때는 std::array<double,100> 처럼 자료형과 data가 몇개 들어가는지도
	//template 에 paramter 로 넣었음

	//std::vector<double> my_array; my_array.resize(100);
	//예를 들어 vector 는 compile time 에 100 이 안정해져 있어도 됨
	//그러나 double 이라는 data type 을 instantiation 할꺼라는건 compile time에 알려져 있었어야 함

	//MyArray 에 100, 자료형이 아닌(Non-type)걸 parameter 에 넣기
	//100 은 지금 compoile time 에 결정되고 있음(되어있어야 함)
	//100이란 숫자가 변수로 들어오게 되면 컴파일이 안됨
	
	int i = 100;
	//MyArray<double, i> my_array;  //빌드 안됨
	//template 기본 원리가 사람이 코딩을 안해줘도 경우에 맞춰서 컴파일을 따로따로 해주는것
	//그래서 컴파일 하기 전에 결정이 나있어야 함. const int i = 100 해서 i 를 넣을순 있지만 그냥 100 넣고맘


	MyArray<double, 100> my_array;

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();


	//이런 방식이 잘 사용되는 경우는 메모리 개수 결정보단 
	//알고리즘을 구현할때 2차원일때는 몇개, 3차원일때는 몇개 이런식으로 사용됨

	return 0;
}
