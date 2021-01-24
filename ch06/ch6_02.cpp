// 배열 Array 의 기초적인 사용법 [2 0f 2]

#include<iostream>

using namespace std;

void doSomething(int students_scores[])  //int students_scores[20]는 문법상 배열이 아닌 포인터임, 그래서 []안이 비어도 됨
{
	cout << "doSomething" << endl;
	cout << (int)&students_scores << endl; //배열의 주소값을 저장하는 포인터 변수의 주소값 출력
	cout << (int)&students_scores[0] << endl; //배열의 주소값과 동일한(포인터 변수에 저장되어 있는) 값 출력
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << "size in doSomething " << sizeof(students_scores) << endl; //4, pointer size

	//x64에선 sizeof(students_scores)가 4가 아닌 8 -> x86에선 포인터변수 크기가 4bytes, x64에선 8bytes
	//x64 에선 주소가 overflow 됨, int 대신 long long 또는 size_t로 변환하면 됨
}



int main()
{
	const int num_students = 20;
	
	int students_scores[num_students] = { 1,2,3,4,5 }; //fixed-size array , num_students 가 const 기 때문에
	//[ ]안에 들어가는 type 이 int여야 할 필요는 없음, 정수형 이기만 하면 됨 short,char type 도 사용 가능

	cout << (int)&students_scores << endl; //students_scores[0]의 주소랑 같은 주소를 사용
	cout << (int)&students_scores[0] << endl;
	cout << (int)&students_scores[1] << endl; //students_scores[0]랑 4 (4 bytes, int) 차이
	cout << (int)&students_scores[3] << endl;

	cout << "size in main " << sizeof(students_scores) << endl; //80


	//array 를 함수 parameter 로 넣기
	doSomething(students_scores);
	
	// 읽기 편한 10진수로 출력하기 위해 주소를 int로 형변환, x64에서는 (long long) 권장,
	// x86, x64 모두 잘 작동하는 멀티플랫폼 코드에선 (size_t) 권장

	//doSomething(students_scores) 의 (int)&students_scores 값이 main 의 (int)&students_scores 값과 다름



	//배열의 이름(식별자, identifier, 인식자)은 내부적으로 주소로 사용
	cout << (int)students_scores << endl;
	cout << (int)&students_scores << endl;
	//그렇기 때문에 주소 연산자 & 를 쓰지 않아도 주소를 얻을 수 있음
	//배열은 주소로 데이터를 주고받는것이 원소들을 전부 복사하는것이 훨씬 효율적이라 문법이 이렇게 정의가 됨

    
	//함수가 매개변수로 받는 배열은 문법상 배열이 아닌 포인터임. 다만 배열을 받을때 사용할 것이다 라는것을
	//조금더 구체적을 보여주기 위해 이렇게 사용할 수 있는 것 뿐임

	
	//배열로 선언 -> 이름 자체가 주소, &사용하지 않아도 주소를 가져올 수 있음
	//함수의 parameter 에 배열의 주소값을 복사, 배열의 오든 원소를 복사해서 가져오는 것이 아님
	//함수 내부의 students_scores 는 배열이 아니고 포인터 변수(주소값 저장)이기 때문에 
	//다른 주소값(포인터 변수의 주소)을 가짐

	return 0;
}
