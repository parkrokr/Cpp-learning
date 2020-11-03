#include <iostream>


void doSomething()
{
	using namespace std; //헤더파일에서 body 밖에서 쓰면 파일마다 중복될수 있음

#ifdef LIKE_APPLE  // #define LIKE_APPLE은 ch1_14.cpp에서만 영향
	cout << "Apple" << endl;
#endif

#ifndef LIKE_APPLE
	cout << "Orange" << endl;
#endif
}