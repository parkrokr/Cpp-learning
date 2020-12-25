//���� �Ҵ� �迭 Dynamiclally Allocating Arrays

#include<iostream>

using namespace std;

int main()
{
	int length;

	cin >> length;

	//int array[length];  ���� �Ҵ� �迭, compile time �� ����� �����Ǿ� �־����


	//���� �Ҵ� �迭
	int* array = new int[length];  //new �� ������ ���� delete �� �־�� ��

	//int* array = new int[length]();   //���� 0���� �ʱ�ȭ
	//int* array = new int[length] {}; 
	
	
	//int* array = new int[length] {1, 2, 3, 4, 5, 6};  //6���� ���� ���� �� length�� 5�� ������ ���� �߻�

	//int* array = new int[] {1, 2, 3, 4, 5, 6}; //���尡 �ȵ� ->������ Ÿ�ӿ� ������ ���Ϸ��� �ϱ� ����
	//int* array = new int[3] {1, 2, 3, 4, 5, 6};  //����, �ڿ� 4,5,6�� ���� �޸𸮸� �������� ���߱� ����

	array[0] = 1;
	array[1] = 2;

	//print 
	for (int i = 0; i < length; ++i)
	{
		cout << (uintptr_t) & array[i] << endl;
		cout << array[i] << endl;

	}



	//resizing 
	//�ٷδ� �ȵ�, ��ū �޸𸮸� �޾ƿ��� ������ ������
	//���Ϳ��� �ٷ�


	//���� �迭���� ������ ������ ���� �����ߵ��� �����迭������ ������ �� ����

	int* ptr = array;

	cout << "print using ptr var" << endl;

	for (int i = 0; i < length; ++i)
	{
		cout << *(ptr + i) << '\t' << (uintptr_t)(ptr + i) << endl;
	}

	delete[]array; //new �� �׻� �ѽ�!

	return 0;
}