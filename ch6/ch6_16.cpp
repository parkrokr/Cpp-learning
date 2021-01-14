//포인터와 참조의 멤버 선책 연산자 Member Selection Operators

//포인터에선		-> 사용
//reference 에선	   . 사용

#include <iostream>

using namespace std;

struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;

	person.age = 5;
	person.weight = 30;

	//참조 사용
	Person& ref = person;
	ref.age = 15;

	//포인터 사용    -> 사용
	Person* ptr = &person;
	ptr->age = 30;
	//de-referencing operators 를 같이 쓸 수 있음
	(*ptr).age = 20;  //. 이 * 보다 우선순위가 높기 때문에 ( ) 반드시 필요! 그래서 잘 쓰진 않음

	Person& ref2 = *ptr;
	ref2.age = 45;


	//두 주소가 같음
	cout << &person << endl;
	cout << &ref2 << endl;
	//원래 person  - > 포인터   - > ref  해도 원래 변수랑 같은 주소가 나옴

	return 0;
}
