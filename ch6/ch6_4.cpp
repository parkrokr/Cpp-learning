// �迭�� ���� ���� Selection Sort

#include<iostream>

using namespace std;

void printArray(const int array[],const int length)
{
	for (int index = 0; index < length; ++index)
		cout << array[index] << " ";
	cout << endl;
}

int main()
{
	/*			  value    index
	3 5 2 1 4		1		 3
	1 5 2 3 4		2		 2
	1 2 5 3 4		3		 3
	1 2 3 5 4		4		 4
	1 2 3 4 5
	*/


	const int length = 5;

	int array[length] = { 3,5,2,1,4 };

	printArray(array, length);

	//my code
	for (int i = 0; i < length; ++i)
	{
		int value = array[i];
		int index = i;

		for (int j = i+1; j < length; ++j)
		{
			if (value >array[j])
			{
				index = j;
				value = array[j];
			}
		}
		//swap
		array[index] = array[i];
		array[i] = value;
		printArray(array, length);
	}

	//
	for (int startIndex = 0; startIndex < length - 1; ++startIndex) //length - 1 �� ������ �������� ���� �ʿ䰡 ���⶧��
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[smallestIndex] > array[currentIndex])
			{
				smallestIndex = currentIndex; //index �� �ٲٸ� value �� ���� �ٲ� �ʿ䰡 ����
			}
		}

		//swap two values in the array
		//std::swap(array[smallestIndex],  array[startIndex]);
		int temp = array[smallestIndex];
		array[smallestIndex] = array[startIndex];
		array[startIndex] = temp;
		printArray(array, length);
	}

	//swap  
	int temp = array[0]; //temp ����
	array[0] = array[1];
	array[1] = temp;
	//std::swap(. . .) �� ����


	//�����ϴ� ������ �ƴ϶� �����ϴ� ������ ������
	//������ ���� �÷�����

	//Bubble sort �����غ���

	return 0;
}