#include <iostream>


void doSomething()
{
	using namespace std; //������Ͽ��� body �ۿ��� ���� ���ϸ��� �ߺ��ɼ� ����

#ifdef LIKE_APPLE  // #define LIKE_APPLE�� ch1_14.cpp������ ����
	cout << "Apple" << endl;
#endif

#ifndef LIKE_APPLE
	cout << "Orange" << endl;
#endif
}