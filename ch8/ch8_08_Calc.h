#pragma once

#include <iostream>

//헤더에선 using 을 안쓰는게 좋음
//include 하는것들이 전부 그 영향을 받음

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value); //생성자도 보내버리기

	//body 는 Calc.cpp 로 빼고 prototype 만 남기기
	Calc& add(int value);  	
	Calc& sub(int value);
	Calc& mult(int value);
	void print();
};