//자료형에게 가명 붙여주기 Type aliases

//긴것을 짧게 줄여줄때 편함
//유지보수할때 편함
//고정너비 정수에서 플랫폼에 독립적인 코딩을 할때 내부적으로 사용하고 있음


#include<iostream>
#include<vector>
#include<cstdint>

int main()
{
	using namespace std;

	//코드 상에선 두개가 섞여서 사용될 수 있음
	//의도는 distace_t 를 쓸때 double을 거리라는 개념으로 쓰기 위해 메모겸 주석
	//distace_t를 많이 사용하고 있다가 double을 float로 바꾸려고 할때 수정하기 쉬움
	typedef double distance_t;  //typedef float distance_t;

	//컴파일러 입장에선 같음, 프로그래머 편의를 위해 사용
	double     my_distance; //my_distanc 는 double이다
	distance_t home2work;   //home2work 가 distace_t 이고 double 을 사용해 표현하겠다
	distance_t home2school;

	
	//고정너비 정수 (ch2_3) 
	// 새로운 것을 정의한것이 아니고 typedef를 통해 있는것들중에 상황에 적합한 것을 가명만들어준것이다.
	std::int8_t i(97);


	// 이런 복잡한 자료형이 존재할 수도 있다
	//std::vector<std::pair<std::string, int> > pairlist;
	//vector<pair<string, int> >pairlist;

	
	//typedef vector<pair<string, int> > pairlist_t; // typedef 대신에 using 을 쓰는 방법도 있음
	using pairlist_t = vector<pair<string, int> >; 
	//assingnment 는 메모리공간을 복사하지만 using은 컴파일러에게 이거 대신에 저걸 쓰겠다고 알려주는 것이다

	vector<pair<string, int> >pairlist1;
	pairlist_t pairlist2; //깔끔해짐



	return 0;
}