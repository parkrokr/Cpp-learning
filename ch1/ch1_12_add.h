//#pragma once  //Header Guard , include guard 라고도 함

#ifndef MY_ADD
#define MY_ADD

//body 는 definition 으로 가는것이 좋으나 현실적으로 쉽진 않음, 헤더에 다 넣어버려서 문제가 발생
//헤더가드가 그 문제를 방지함(body 가 헤더에 있어도 문제가 없게 함)
//헤더가드가 없으면 doSomething()이 add() 를 호출하기 위해 include 해주고 main() 이 있는 cpp 파일에서도
//my_work.h 를 include 하면서 doSomething() 과  add() 가 들어오고 add.h 를 include 해줬을때 또 add() 가 
//정의되어서 중복정의가 발생(에러 발생)

//헤더가드는 중복정의 되었을때 한번만 정의되게 해주는 것
int add(int a, int b) 
{
	return a + b;
}


#endif
