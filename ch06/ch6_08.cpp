//�����Ϳ� ���� �迭

//�����Ϳ� ���� �迭�� ����
//�����迭���� �����迭��� �� �� �ֵ��� ��� ��ġ�� ����
//�Լ����� �����迭�� �����ͷ� ������ȯ
//����ü�� class �ȿ� �迭�� ������ �迭�� ������

#include <iostream>

using namespace std;


//array �� parameter �� ������ ��� �����ͷ� ����ϰ� ��

//void printArray(int array[])
void printArray(int *array)
{
	cout << sizeof(array) << endl;
	cout << *array << endl;

	*array = 100;
}


//����ü �ȿ� array�� �ִ� ���
struct MyStruct
{
	int my_array[5] = { 9, 7, 5, 3, 1 };
};

//�Լ��� ����ü �ֱ�
void doSomething(MyStruct ms) //ms ��� *ms(������)
{
	cout << sizeof(ms.my_array) << endl; //ms ��� *ms(de-referencing)
}

int main()
{
	

	int array[5] = { 9,7,5,3,1 };

	cout << array[0]<<" "<<array[1] << endl;
	cout << array << endl;
	cout << &(array[0]) << endl;

	//array �� �迭�� �ƴϰ� ù��° ���� �ּ�

	//de-referencing
	cout << *array << endl; //9

	//ptr ���� ������ ����
	int* ptr = array;		//���⼭ *�� ptr �̶� ������ ������ �������� �˷���
	cout << ptr << endl;
	cout << *ptr << endl;	//���⼭ *�� ptr�� de-referencing �ϱ� ���� ������
	
	//ptr ��ü�� �ּҴ� �� �ٸ�


	//���ڿ�
	char name[] = "jackjack";
	cout << *name << endl; //j //name �� char type ������



	//�����Ϳ� �����迭�� ������ ���̰� ���� ����. 
	
	//size �� ����
	cout << sizeof(array) << endl; //5 * 4 = 20

	cout << sizeof(ptr) << endl;   //4 (������ ������ ������)

	printArray(array);			   //4 (pointer size), array �� parameter �� ������ ���� pointer �� ��

	cout << array[0] << " " << *array << endl; // 100 100 
	//�Լ� �ۿ����� ���� �ٲ�, c���� ���� ����߾���, c++���� reference �� �����

	
	//������ ����
	cout << *ptr << " " << *(ptr + 1) << endl; //ptr + 1 �ϸ� ������ �ּ�, �׷��� array[1]�� 7



	//����ü �ȿ� array�� �ִ� ���
	MyStruct ms;
	cout << ms.my_array[0] << endl;			//9
	cout << sizeof(ms.my_array) << endl;	//20

	doSomething(ms);						//20
	//ms ��� &ms�� ������ �Լ����� �����ͷ� �޾Ƶ� 20�� �״�� ������

	//-> array �� structure �� class �ȿ� ������� ��� pointer �� ������ȯ�� ���� ����,�迭�� ������

	return 0;
}