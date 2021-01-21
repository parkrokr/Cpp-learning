//구성 관계 Composition

//#include <iostream>  Monster.h 에서 iostream 을 include 하고 있기 때문에 없어도 쓸 수 있음
#include "ch10_02_Monster.h"

using namespace std;



int main()
{
	//Monster mon1("Sansan", 0, 0);
	Monster mon1("Sansan",Position2D(0,0));

	cout << mon1 << endl;
	//Monster.h 와 Position2D.h 의 output 연산자에 있는 endl은 중복되니 지워주고 보통 main 에서만 endl 함

	//while (1)  //game loop
	{
		//event
		//mon1.moveTo(1, 1);
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}


	//mon1 의 m_location 은 mon1 에 속해있지만 다른 것들( m_name ) 에 대해서 알지도 못하고
	//알 필요도 없음

	//Monster 가 m_location 을 위해 Positin2D 를 사용하는걸 composition 이라고 함
	//m_laction 은 Monster 의 일부다

	//sub class 는 가능한 빨리 만드는게 좋음( m_x, m_y 를 묶기 위해 Position2D class 만듬)

	//moveTo를 할때 Monster 는 set() 만 해주면 되기 때문에 안에 어떻게 작동하는지 모름
	//기능을 구현해주고, 상위 class(기능을 가져다 쓰는 class) 는 뭘 할지만 알고
	//어떻게 하는지는 안보이는게 좋음

	//Position2D 정도의 class 는 수학 class 에 다 들어 있음, 이렇게 다 구현하는건 연습 단계에서
	//실무에선 이렇게 까지 코드양이 많진 않음

	//Position2D class 자체는 다른곳에서도 재상용이 될 수 있지만 Monster::m_location 은
	//다른 곳에서 쓸일이(필요가) 없음

	//mon1 이 사라지면 mon1.m_lacation 은 같이 사라짐, class 가 멤버의 존재를 직접 관리해야함

	//Monster class 가 작업을 할때는 Positin2D class 에 대해 뭐가 있는지 알고 사용하지만
	//Position2D class 가 작업을 할때는 Monster class 에 뭐가 있는지 모름
	//알아야 된다면 아주 잘못된것(설계가 잘못됨)
	return 0;
}