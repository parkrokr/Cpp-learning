#pragma once

#include <iostream>

//������� using �� �Ⱦ��°� ����
//include �ϴ°͵��� ���� �� ������ ����

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value); //�����ڵ� ����������

	//body �� Calc.cpp �� ���� prototype �� �����
	Calc& add(int value);  	
	Calc& sub(int value);
	Calc& mult(int value);
	void print();
};