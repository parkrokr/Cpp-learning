//인라인 함수 Inline Functions

//

#include <iostream>
using namespace std;


//int min(int x, int y)
inline int min(int x, int y) // inline 함수 정의, 주로 헤더 파일에 정의할때 많이 사용함
{
	return x > y ? y : x; // x랑 y 중에 작은값을 return 
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;

	//이런 작은 함수들이 자주 사용될경우 함수 내부에서 실제 계산 하는 시간보다
	//값을 복사하고 저장하는 과정에 시간이 더 오래걸릴수도 있음

	//인라인 함수로 바꾸면 마치 함수가 아닌것처럼 작동함
	//cout << min(5, 6) << endl; 이
	cout << ( 5 > 6 ? 6 : 5) << endl; //처럼 작동함 

	//함수 호출, 지역변수 x,y 선언, 삭제 될일이 없어서 빨라짐
	//inline 키워드를 붙이면 강제로 inline 함수가 되는것이 아니고
	//컴파일러에게 권유 하는 느낌  
	//그래서 모든 함수가 inline 이 안될수도 있고 inline 키워드를 사용했다고 
	//반드시 빨라지지 않음

	//최근에는 inline 을 쓴다고 빨라지는 보장도 없고 안쓴다고 안빨라지지도 않음

	//inline 키워드가 적힌 함수가 많고 컴파일러가 그걸 다 inline으로 구현 했으면
	//컴파일된 프로그램의 크기가 커짐  -> inline을 사용한 효과를 못볼수도 있음

	return 0;
}