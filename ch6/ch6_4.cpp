// 배열과 선택 정렬 Selection Sort

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
	/*		        value            index
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
	for (int startIndex = 0; startIndex < length - 1; ++startIndex) //length - 1 한 이유는 마지막은 비교할 필요가 없기때문
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[smallestIndex] > array[currentIndex])
			{
				smallestIndex = currentIndex; //index 만 바꾸면 value 는 따로 바꿀 필요가 없음
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
	int temp = array[0]; //temp 선언
	array[0] = array[1];
	array[1] = temp;
	//std::swap(. . .) 이 있음


	//증가하는 순서가 아니라 감소하는 순서로 만들어보기
	
	for (int startIndex = 0; startIndex < length - 1; ++startIndex) 
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[smallestIndex] < array[currentIndex])
			{
				smallestIndex = currentIndex; //index 만 바꾸면 value 는 따로 바꿀 필요가 없음
			}
		}

		//swap two values in the array
		//std::swap(array[smallestIndex],  array[startIndex]);
		int temp = array[smallestIndex];
		array[smallestIndex] = array[startIndex];
		array[startIndex] = temp;
		printArray(array, length);
	}
	
	//데이터 수를 늘려보기

	//Bubble sort 구현해보기
	
	for (int level = 0; level < length - 1; ++level)
	{

		for (int i = 0; i < length - level - 1; ++i)
		{
			if (array[i] >array[i + 1])
			{
				temp = array[i+1];
				array[i + 1] = array[i];
				array[i] =temp;
				
			}
			printArray(array, length);
		}
	}

	return 0;
}
