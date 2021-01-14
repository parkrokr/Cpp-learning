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
	const int m = 3;
	const int n = 3;
	const int p = 3;

	// matrix a
	int matrix_a[m][n]
	{
		{3,2,5},
		{7,2,4},
		{1,3,2}
	};

	// matrix b
	int matrix_b[n][p]
	{
		{2,4,0},
		{6,1,2},
		{2,7,3}
	};

	// matrix c (ab)
	int matrix_c[m][p] = { 0 };

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			//sum of c[i][j]
			int sum_of_c(0);
			for (int k = 0; k < n; ++k)
			{
				sum_of_c +=( matrix_a[i][k] * matrix_b[k][j]);
			}

			matrix_c[i][j] = sum_of_c;

		}
	}

	//print matrix_a
	cout << "matrix a " << endl;
	for (int row = 0; row < m; ++row)
	{
		for (int col = 0; col <n; ++col)
			cout << matrix_a[row][col] << '\t';
		cout << endl;
	}
	cout << endl;

	//print matrix_b
	cout << "matrix b" << endl;
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < p; ++col)
			cout << matrix_b[row][col] << '\t';
		cout << endl;
	}
	cout << endl;

	//print matrix_c
	cout << "matrix c" << endl;
	for (int row = 0; row < m; ++row)
	{
		for (int col = 0; col < p; ++col)
			cout << matrix_c[row][col] << '\t';
		cout << endl;
	}
	cout << endl;

	return 0;
}
