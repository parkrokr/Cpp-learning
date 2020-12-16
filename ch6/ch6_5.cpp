//정적 다차원 배열 Multi-dimensional Array

#include<iostream>

using namespace std;

int main()
{
	//행렬을 출력하는 코드 
	const int num_rows = 3;
	const int num_columns = 5;

	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
		{
			cout << '[' << row << ']' << '[' << col << ']' << '\t';
		}
		cout << endl;
	}

	cout << endl;



	//컴퓨터 메모리는 1차원적, 다차원 배열은 1차원적 메모리를 가지고 '접어서' 2차원적으로 보이게 하는것

	//다차원 배열 선언(2차원)
	//row-major 방식  <-> column-major
	int array[num_rows][num_columns] =  // copy initialization, =가 없어도 됨(c++11 이상)
	{
		{1,2,3,4,5},	//row 0
		{6,7,8,9,10},	//row 1
		{11,12,13,14,15}//row 2
	};


	//하나씩 초기화 하는 방법
	/*array[0][0] = 1;
	array[0][1] = 2;*/

	// num_rows 생략 가능 , num_columns 는 생략 불가능
	/*int array[][num_columns]  //2차원 이상의 배열을 함수 parameter로 주고받을때 좀 불편할 수 있음
	{
		{1,2, },		//row 0  초기화 안한 값은 0 으로 초기화
		{6,7,8,9,10},	//row 1
		{11,12,13,14,15}//row 2
	};
	*/

	//row 개수와 columns 개수가 들어있는 경우 모두 0으로 초기화 가능
	//int array[num_rows][num_columns] = { 0 };


	// array 출력
	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
			cout << array[row][col] << '\t';
		cout << endl;
	}
	cout << endl;

	// array 주소 출력
	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
			cout << (int)&array[row][col] << '\t';
		cout << endl;
	}
	cout << endl;


	//3차원 array
	int array_[5][4][3];

	//텐서를 표현하기 위해 다차원 array 사용

	//행렬 곱하기를 다차원 array 를 사용하여 구현하기

	return 0;
}