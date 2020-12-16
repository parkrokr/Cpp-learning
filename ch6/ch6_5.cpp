//���� ������ �迭 Multi-dimensional Array

#include<iostream>

using namespace std;

int main()
{
	//����� ����ϴ� �ڵ� 
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



	//��ǻ�� �޸𸮴� 1������, ������ �迭�� 1������ �޸𸮸� ������ '���' 2���������� ���̰� �ϴ°�

	//������ �迭 ����(2����)
	//row-major ���  <-> column-major
	int array[num_rows][num_columns] =  // copy initialization, =�� ��� ��(c++11 �̻�)
	{
		{1,2,3,4,5},	//row 0
		{6,7,8,9,10},	//row 1
		{11,12,13,14,15}//row 2
	};


	//�ϳ��� �ʱ�ȭ �ϴ� ���
	/*array[0][0] = 1;
	array[0][1] = 2;*/

	// num_rows ���� ���� , num_columns �� ���� �Ұ���
	/*int array[][num_columns]  //2���� �̻��� �迭�� �Լ� parameter�� �ְ������ �� ������ �� ����
	{
		{1,2, },		//row 0  �ʱ�ȭ ���� ���� 0 ���� �ʱ�ȭ
		{6,7,8,9,10},	//row 1
		{11,12,13,14,15}//row 2
	};
	*/

	//row ������ columns ������ ����ִ� ��� ��� 0���� �ʱ�ȭ ����
	//int array[num_rows][num_columns] = { 0 };


	// array ���
	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
			cout << array[row][col] << '\t';
		cout << endl;
	}
	cout << endl;

	// array �ּ� ���
	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
			cout << (int)&array[row][col] << '\t';
		cout << endl;
	}
	cout << endl;


	//3���� array
	int array_[5][4][3];

	//�ټ��� ǥ���ϱ� ���� ������ array ���

	//��� ���ϱ⸦ ������ array �� ����Ͽ� �����ϱ�

	return 0;
}