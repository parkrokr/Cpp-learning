//동적 할당 배열 Dynamiclally Allocating Arrays

#include<iostream>

using namespace std;

int main()
{
	int length;

	cin >> length;

	//int array[length];  정적 할당 배열, compile time 에 사이즈가 결정되어 있어야함


	//동적 할당 배열
	int* array = new int[length];  //new 가 있으면 쌍으로 delete 가 있어야 함

	//int* array = new int[length]();   //전부 0으로 초기화
	//int* array = new int[length] {}; 
	
	
	//int* array = new int[length] {1, 2, 3, 4, 5, 6};  //6까지 값을 넣은 후 length에 5만 넣으면 에러 발생

	//int* array = new int[] {1, 2, 3, 4, 5, 6}; //빌드가 안됨 ->컴파일 타임에 결정을 안하려고 하기 때문
	//int* array = new int[3] {1, 2, 3, 4, 5, 6};  //에러, 뒤에 4,5,6을 넣을 메모리를 배정받지 못했기 때문

	array[0] = 1;
	array[1] = 2;

	//print 
	for (int i = 0; i < length; ++i)
	{
		cout << (uintptr_t) & array[i] << endl;
		cout << array[i] << endl;

	}



	//resizing 
	//바로는 안됨, 더큰 메모리를 받아오고 기존껄 복사함
	//벡터에서 다룸


	//정적 배열에서 포인터 연산을 통해 접근했듯이 동적배열에서도 접근할 수 있음

	int* ptr = array;

	cout << "print using ptr var" << endl;

	for (int i = 0; i < length; ++i)
	{
		cout << *(ptr + i) << '\t' << (uintptr_t)(ptr + i) << endl;
	}

	delete[]array; //new 와 항상 한쌍!

	return 0;
}
