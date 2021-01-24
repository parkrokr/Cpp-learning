//���ð� �� Stack and Heap

//�޸𸮴� ���� ����(segment) �� ������ ����

//���׸�Ʈ���� ������ �ٸ�

//Heap

//Stack

//Data	����Ǵ� ���� 2
	//Data
		//initialized data segment  �ʱ�ȭ �� ����, ���� ����
		//initialized global and static variables


	//Bss (Block started by symbol)
		//uninitialized data segment  0���� �ʱ�ȭ��(�ʱ�ȭ���� ����) ����, ���� ����
		//zero-initialized global and static variables


//Code	����Ǵ� ���� 1
//�츮�� �ۼ��� ���α׷��� ����Ǿ� ����




//stack 

//frame �ȿ��� �Լ��� ������ ���� ���ư��� �ϴ����� �� ����
//frame �� �׿��ְ� ���� ������Ѿ� �ϴ°��� ���� ���� �ֱ� ������ ���� ����

/*
#include <iostream>

int g_i = 0;  // 1. ���������� ���� �޸𸮿� �ڸ�����(ó�� ����ٰ� �ʰ� �����)

int second(int x)  //4. ���� ���� frame �ȿ� �Ű����� x�� �ڸ�����
{
	return 2 * x;
} //5. second() �� ������ ���� ���� second()�� ����ִ� frame ���� �����

int first(int x)  // 3. �� frame �ȿ� �Ű����� x,�������� y�� �ڸ�����
{
	int y = 3;
	return second(x + y);  //4. second()�� ȣ���߱� ������ ���ο� stack frame �� ����(second()�� �������)
} //6. first() �� ������ frame �� ���ŵ�

int main() // 2. Stack ���� Stack frame �ȿ� main() ����
{
	using namespace std;

	int a = 1, b;  // 2. Stack ���� Stack frame �ȿ� �������� a,b ����
	
	b = first(a); //3. first()�� Stack frame �� ���ܼ� ���� ����
	cout << b << endl;

	return 0;
} //7. main() �� ������ frame �� �����


//8. main()�� ������� ���������� ������� ���α׷��� ������ os�� ��� �޸𸮸� �����ذ�
*/

//stack �� ����
//����� �� ����

//�̷� �ڵ带 �����Ű�� array �� �ʹ� Ŀ�� �޸� �Ҵ��� ����
//stack�� ����� ���� ��Ȳ���� ū ������ �޸𸮸� �������� �ϸ� ���Ĺ���(Stack Overflow!)
//ū�� �ѹ��� ��Ƽ� ��ĥ���� ������ ������ ������ ��Ƽ� ��ĥ���� ����(ex) ��� ȣ��)

/*
int main()
{
	int array[100000];  //Stack Overflow

	return 0;
}
*/


//Heap
//���� �Ҵ�

//���� �������� stack �� ������ �ǰ� stack�� ���� �������� stack overflow ���� ������ �߻��� ������
//�̸� �����ϱ� ���� Heap �޸𸮸� �����

//Heap �� ����� ŭ(ū �����Ͱ� �� �� �ִ� ������ ������ Ȯ���� �� ����)
//������ ��� ������ �����ϱ� ����(�޸𸮰� ��� ���� ��)

/*
int main() // 1. main() �� frame �� ��
{
	int* ptr = nullptr;  //1. ���� ���� *ptr�� main()�� ���� frame�� ��
	
	ptr = new int[1000000]; //2. ���� �޸� �Ҵ��� �ϸ� Heap�� �䱸�ϴ� ������ ��ŭ �޸𸮸� ����
							//  �� �޸� ������ ù �ּҸ� �����Ϳ� ������

	delete[] ptr;  //3. Heap �� �ִ� �޸𸮸� �ݳ���


	//Heap �� �ִ� �޸� ��ü�� os�� �ݳ��� �Ǿ����� ptr���� ���� �ּҰ��� �� ����
	//ptr �� de-referencing �� �õ��ϸ� ������ ����
	//delete[] ptr; ���� ptr �� ���϶� nullptr �� assignment �� ����ؾ� ��

	return 0;
}
*/


//�����Ҵ��� delete�� ���Ұ�� (memory leak)
/*
void initArray() //2. initArray() , �������� int *ptr2 �� �ִ� frame ���� 
{
	int* ptr2 = new int[1000]; //3. new �� ���� Heap�� �޸𸮸� ����, ptr2���� ù �ּҰ��� ������ 
	// delete []ptr 2;
} 
//4. initArray() �� ������ frame�� �������µ� delete�� ������
//�������� ptr2�� ��������� Heap ���� ���� �޸𸮰� �����ְ� �� �ּҸ� ��
//�޸𸮰� �����ֱ� ������ ����� �� ����
//�̷� ���� �ݺ��� �Ǹ� ���� ���� �޸𸮰� Heap �� �� ���� �� (memory leak)
//�ٸ� ���α׷��� ����� �޸𸮱��� ����ع��� �� ����

int main()  //1. stack �� main() �� �ִ� frame ����
{
	initArray(); //2. initArray() �� �ִ� frame ����

	return 0;
}
*/