//이중 포인터와 동적 다차원 배열

#include<iostream>

using namespace std;

int main()
{
	//이중 포인터 : 포인터에 대한 포인터  
	//2차원 행렬 구현할때 사용함
	int* ptr = nullptr;
	int** ptrptr = nullptr;

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl;  //*(*ptrptr)

	
	//삼중 포인터 . . .  가능은 하지 잘 쓰진 않음
	//int*** ptrptrptr, **** ptrptrptrptrptr;


	//행렬 구현
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	//포인터로 구현
	int* r1 = new int[col] {1, 2, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	//r이 몇개나 나올지 모르기 때문에 int 포인터의 array를 만듬
	//포인터인 r 들을 이중 포인터로 받음
	int** rows = new int* [row] {r1, r2, r3};

	//출력 
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	//delete
	delete[] r1;
	delete[] r2;
	delete[] r3;
	delete[] rows;

	//delete[] r 을 for 문으로 돌리고 싶음
	int** matrix = new int* [row];

	//matrix 초기화 //순서가 위에랑 반대
	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[r][c] = s2da[r][c];

	//출력 
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	//delete  //matrix 를 나중에 지워줘야함
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;


	//이렇게 이중 포인터를 사용하는게 부담스러울 수 있음
	int* other_matrix = new int[row * col];

	//1차원 array 를 구부려서 2차원 array 처름 만들어야 함
	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			other_matrix[c + col*r] = s2da[r][c];  //1차원 array 를 2차원 array 처럼 보이게 해야함

	//c + col*r 를 함수 보다 class 로 만들면 아주 편해짐

	//출력
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << other_matrix[c + col * r] << " ";
		cout << endl;
	}

	delete[] other_matrix;


	//new delete 번거로우니 vector 사용
	//1차원 배열을 2차원 배열에 넣는 방법은 알고 있어야 함
	//대부분의 수학( 선형 대수학 ) 라이브러리 중에 이중포인터를 사용하는 것도 있고
	//사용하지 않는 것도 있음
	//3,4,5... 차원의 array 는 어떻게 indexing 할지 한번 해보기

	return 0;
}