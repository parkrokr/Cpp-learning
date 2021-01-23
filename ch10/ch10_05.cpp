//의존 관계 Dependencies

#include "ch10_05_Worker.h"

using namespace std;


int main()
{
	Worker().doSomething();

	//Timer 에 대해서 Worker class 가 몰라도 됨
	//Worker 의 doSomething() body 를 cpp 로 옮기면 Worker.h 에선 Timer.h 를 include 하지 않아도 됨
	//Worker.cpp 에서만 Timer class 를 알고 있으면 됨

	//의존 관계는 class 레벨에서는 서로를 몰라도 됨, 구현하는 body 에서만 알면 됨
	//main() 에서도 worker class 만 알고 있으면 됨

	//뭔가 함수 혼자 있으면 의존 관계를 이용해서 뭔가를 가져다 쓴걸 추측해볼 수 있음
	//가장 많이 볼 패턴

	//class 가 사라지면 같이 사라진다는 관점에서 멤버의 존재를 클래스가 관리한다고 할 수있으나
	//멤버로 들어가지도 않는 경우도 많음
	//방향성은 단방향, Woker class 는 자기가 시간을 측정하는 기능을 알 필요가 없음


}