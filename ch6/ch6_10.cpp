//C 스타일의 문자열 기호적 (Symbolic) 상수

//함수 parameter로 const char* value 를 쓸 경우  호출하는 곳에서 전달받은 문자열을 변경하지 않고 사용만 하겠다는 의미

#include <iostream>

using namespace std;

const char* getName()
{
	return "Jackjack";
}


int main()
{
	//char name [] = "jackjack";
	//char *name = "jackjack"	//빌드 불가능 
	//"jackjack"은 리터럴이고 *name 은 포인터 변수이기 때문에 실제 데이터를 저장할 메모리가 필요

	//const 로 선언하면 가능
	const char* name = "jackjack";
	

	cout << name << endl;

	//예외적인거
	const char* name2 = "jackjack";

	cout << (uintptr_t)name << endl;
	cout << (uintptr_t)name2 << endl;
	//주소가 같음(문자열이 값이 같아서)
	

	//return type 으로도 사용할 수 있음
	name = getName();
	name2 = getName();

	cout << (uintptr_t)name << endl;
	cout << (uintptr_t)name2 << endl;


	//예외적인것
	//cout 에서 문자열을 특별히 처리한다

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello World!";
	const char* c_name = "Jack Jack";

	cout << int_arr << endl;		//주소
	cout << char_arr << endl;		//문자열
	cout << c_name << endl;			//문자열

	//cout 에 문자열 주소가 들어오면 주소가 아닌 어레이를 출력함


	char c = 'Q';
	cout << &c << endl;
	//cout에 주소가 들어오자 문자열이라 판단하고 출력 -> Q儆儆儆儆X 
	cout << *&c << endl; //de-referencing 하면 Q 정상적으로 출력됨

	return 0;
}
