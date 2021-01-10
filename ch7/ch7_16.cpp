//생략부호 Ellipsis 

#include<iostream>
#include<cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...) // count 는 parameter 로 들어올 arguments 의 개수, 그 다음에 ...
{
	double sum = 0;

	va_list list; // 문자열로 받음

	va_start(list, count);

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); // int 로 변환

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; // 맨앞이 1 이기 때문에 두번째 1만 적용되고 나머지는 무시
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; //오류발생

	//개수를 원하는대로 넣어줄수 있다는 장점이 있지만 어떤 type 으로 들어갈지는 미리 정해져 있어야 함
	//사용하기 위험하고 디버깅도 힘듬 
	//가급적 사용하지 않고 마지못해 사용할때만 사용

	return 0;
}
