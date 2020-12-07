// 배열 Array 의 기초적인 사용법 [1 of 2]

#include<iostream>

using namespace std;

struct Rectangle //구조체에 배열을 쓸 수 있음
{
	int length;
	int width;
};

enum StudentName //enum 과 배열을 같이 쓸 수 있음
{
	JACKJACK,		// = 0
	DASH,			// = 1
	VIOLET,			// = 2
	NUM_STUDENTS,	// = 3
};


int main()
{
	//여러개의 변수를 선언하는 방법
	int jackjack_score;
	int dash_score;
	int violet_socer;
	// . . .

	//이름이 다 들어있어서 관리가 힘듬

	int student1_score; //jackjack
	int student2_score; //dash
	// . . .

	//변수가 많아지면 for 문에 넣지 못함



	//배열

	int one_student_score; // 1 variable
	int student_scores[5]; // 5 int

	//5개 int 의 메모리를 한번에 빌려옴

	cout << sizeof(one_student_score) << endl;  // 4 bytes
	cout << sizeof(student_scores) << endl;		// 4*5 = 20 bytes

	// 빅데이터 같은 곳에서 1열로 된 메모리를 한번에 못 받을 수도 있음


	// assignement

	one_student_score = 100;

	student_scores[0] = 100; //1st element is 100,  1st element's index is 0
	student_scores[1] = 80;  //2nd element
	student_scores[2] = 90;  //3rd element
	student_scores[3] = 50;  //4th element
	student_scores[4] = 0;   //5th element

	//student_scores[5] = 30;  //6th elemnt , 5개만 선언했기 때문에 사용못함

	//다른 언어에서도 array 는 0으로 시작함

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	//cout << student_scores[5] << endl;   //runtime error 발생! 출력은 될 수도 있음 

	
	//평균 내는 코드

	cout << (student_scores[0] + student_scores[1]) / 2.0 << endl;
	// 일반적인 int 사용하는것과 동일하게 쓸 수 있음


	//구조체에 배열을 쓸 수 있음

	cout << sizeof(Rectangle) << endl; //8

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl; //나중에 배열을 함수 parameter 로 사용할때 sizeof()가 문제가 될 수 있음

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;


	//array 를 초기화 하는 방법

	int my_array[5] = { 1,2,3,4,5 };
	//int my_array[5] = { 1,2, };		// 초기화 안한건 0으로 초기화됨
	//int my_array[] = { 1,2,3,4,5 };	// 개수가 명확한 경우 컴파일러가 알아서 할당함
	//int my_array[5]{ 1,2,3,4,5 };		//uniform initilization 처럼 = 없어도 초기화 가능, c++11부터 가능

	cout << my_array[0] << endl;
	cout << my_array[1] << endl;
	cout << my_array[2] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;


	//enum 과 배열을 같이 쓸 수 있음

	cout << my_array[JACKJACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;

	//student 같은 자료를 저장할때 enum 으로 사람이름 저장하는건 권장하지 않음
	//student 가 몇명이 될지 모르고 이름이 바뀔 수도 있기 때문에 다른 방식을 사용함(class 로 묶기)

	//NUM_STUDENTS == 3 인것을 이용할 수 있음, 갯수를  편리하게 맞출 수 있음
	int students_scores[NUM_STUDENTS];

	students_scores[JACKJACK] = 0;
	students_scores[DASH] = 100;


	//[]를 넣어 만드는 array의 size 는 compiletime 에 고정이 되어야함

	int num_students = 0;
	cin >> num_students;

	//int students_scores_[num_students]; //num_students 가 runtime 에 결정되기 때문이다
	// array의 length(size) 가 compiletime 에 반드시 결정이 되어있어야함

	//num_students 를 const로 선언하고 cin으로 안받으면 사용 가능

	//c style 에선 #define NUM_STUDENTS 100000 식으로 큰 숫자로 정의함
	//c++ style 에선 위의 방식을 권장하진 않음 (동적 할당) 

	return 0;
}