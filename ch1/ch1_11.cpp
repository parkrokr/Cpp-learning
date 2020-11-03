// 헤더파일 만들기

#include <iostream>
#include "MyHeaders/ch1_12_add_.h" //헤더파일을 다른곳에서 옮겨왔을때

using namespace std;

int main()
{
	cout << add(1, 2) << endl;

	return 0;
}