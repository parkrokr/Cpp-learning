//���� �����Ϳ� ���� ������ �迭

#include<iostream>

using namespace std;

int main()
{
	//���� ������ : �����Ϳ� ���� ������  
	//2���� ��� �����Ҷ� �����
	int* ptr = nullptr;
	int** ptrptr = nullptr;

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl;  //*(*ptrptr)

	
	//���� ������ . . .  ������ ���� �� ���� ����
	//int*** ptrptrptr, **** ptrptrptrptrptr;


	//��� ����
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	//�����ͷ� ����
	int* r1 = new int[col] {1, 2, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	//r�� ��� ������ �𸣱� ������ int �������� array�� ����
	//�������� r ���� ���� �����ͷ� ����
	int** rows = new int* [row] {r1, r2, r3};

	//��� 
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

	//delete[] r �� for ������ ������ ����
	int** matrix = new int* [row];

	//matrix �ʱ�ȭ //������ ������ �ݴ�
	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			matrix[r][c] = s2da[r][c];

	//��� 
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	//delete  //matrix �� ���߿� ���������
	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;


	//�̷��� ���� �����͸� ����ϴ°� �δ㽺���� �� ����
	int* other_matrix = new int[row * col];

	//1���� array �� ���η��� 2���� array ó�� ������ ��
	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
			other_matrix[c + col*r] = s2da[r][c];  //1���� array �� 2���� array ó�� ���̰� �ؾ���

	//c + col*r �� �Լ� ���� class �� ����� ���� ������

	//���
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << other_matrix[c + col * r] << " ";
		cout << endl;
	}

	delete[] other_matrix;


	//new delete ���ŷο�� vector ���
	//1���� �迭�� 2���� �迭�� �ִ� ����� �˰� �־�� ��
	//��κ��� ����( ���� ����� ) ���̺귯�� �߿� ���������͸� ����ϴ� �͵� �ְ�
	//������� �ʴ� �͵� ����
	//3,4,5... ������ array �� ��� indexing ���� �ѹ� �غ���

	return 0;
}