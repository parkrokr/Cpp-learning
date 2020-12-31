//std::array 소개

#include<iostream>
#include<array>
#include<algorithm>  //to use std::sort

using namespace std;

void printLength(array<int, 5> my_arr)
{
	cout << my_arr.size() << endl;
}

void printLength_ref(const array<int, 5>& my_arr) //복사를 막기위해 ref, 값 변경을 막기 위해 const
{
	cout << my_arr.size() << endl;
}


int main()
{
	//일반적인 array 는 함수 parameter 로 넣을때 사이즈가 날라가는(포인터) 일이 있었지만
	//std::array 는 그런일이 없음


	//int array[5] = { 1,2,3,4,5 };  //array 를 변수명으로 쓰기 찝찝한 이유   
	//일반적인 단어는 변수명으로 쓰면 충돌 날 수도 있음

	array<int, 5> my_arr = { 1,2,3,4,5 }; //size 숫자가 반드시 들어가야함
	my_arr = { 0,1,2,3,4 };
	my_arr = { 0,1,2 };  //나머지는 0으로 채워줌,  개수가 5보다 커지면 안됨

	cout << my_arr[0] << endl;
	cout << my_arr.at(0) << endl;  //at 가 member function이기 때문에 () 

	// [] 와 at() 의 차이
	//  [] 안에 5보다 큰 수가 들어가면 체크없이 무조건 execess 를 해보지만
	//  at() 는 체크를 하고 문제가 생기면 예외처리를 발동시킴. 그래서 약간 느려짐
	//  퍼포먼스가 아주 중요한 프로그램에선 [] 사용


	//편한 기능들
	
	//elements 가 몇갠지 셀수있음
	cout << my_arr.size() << endl;

	//함수 parameter 로 보낼때도 원래 성질이 그대로 유지됨
	printLength(my_arr);
	
	//대신 array 가 그래도 복사되기 때문에 시간이 걸릴 수 있음
	//ref 로 보내면 이를 막을 수 있음
	printLength_ref(my_arr);


	//std::array 나 std::vector 같은 표준라이브러리를 사용할때 함수 parameter 로
	//reference , 포인터 아니면 그냥 넣을지 주의해서 결정해야 함



	//
	my_arr = { 1, 21, 3, 40, 5 };  //순서가 뒤죽박죽

	//for-each 도 가능
	for (auto element : my_arr)
		cout << element << " ";
	cout << endl;

	for (auto &element : my_arr) //&를 달아주면 복사되는 과정 생략(빨라짐)
		cout << element << " ";
	cout << endl;


	//정렬 
	//<algorithm>에 std::sort 가 들어있음
	std::sort(my_arr.begin(), my_arr.end());  //begin 부터 end 까지

	cout << "after sort" << endl;
	for (auto& element : my_arr) 
		cout << element << " ";
	cout << endl;

	//역순 정렬
	std::sort(my_arr.rbegin(), my_arr.rend());  //reverse begin 부터 reverse end 까지

	cout << "after reverse sort" << endl;
	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	return 0;
}