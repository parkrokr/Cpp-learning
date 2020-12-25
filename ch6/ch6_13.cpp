//������(Pointer) �� const

//int value = 5;
//const int* ptr1 = &value;
//int *const ptr2 = &value;
//const int *const ptr3 = &value;

//�Լ��� parameter �� �迭�� ������ �ּҳ� ���� �ٲ��� �ʰ� �����ϰ� �ڵ��ϰ� ������� �����


#include <iostream>

using namespace std;

int main()
{
	//const int * ptr     �������� ���� ���ٲ�

	const int value = 5;
	const int* ptr = &value;
	//*ptr = 6; �Ұ��� // value = 6;�� �ȵǱ� ����

	//value�� ���� �ٲ����� �������� �ּҴ� ������ �� ����, �����͸� ���� value �� �������� ����
	cout << *ptr << endl;

	int value_ = 6;
	const int* ptr_ = &value_;
	//*ptr_ = 6; �Ұ��� // �������� �������δ� ���� ���ٲ����� �ٲ� ���� ������ ���� ����
	value_ = 6;



	//���� �ΰ��� �ִ� ���
	int value1 = 5;
	const int* ptr1 = &value;
	// *ptr2  = 7; �Ұ��� //������ ������ ���� �ٲܼ��� ������ �����Ϳ� �ٸ� ������ �ִ°� ��

	int value2 = 6;
	ptr1 = &value2;

	// int * �տ� const �� �������� �ּҿ� �ִ� ���� �ȹٲٰڴٴ� ���� ptr �� ����Ǵ� �ּҰ��� �ȹٲٰڴٴ°� �ƴ�





	//int *const ptr     ����� �ּҰ��� ���ٲ�

	int value3 = 5;
	int* const ptr3 = &value3;

	*ptr3 = 10;  //�������� �� �ٲٱ� ����
	cout << *ptr3 << endl;

	int value4 = 8;
	//ptr3 = &value4; �Ұ���  //�����Ϳ� �ִ� �ּڰ��� ���ٲ�




	//const int *const ptr     �������� ���̶� ����� �ּҰ� �Ѵ� ���ٲ�

	int value5 = 5;
	const int* const ptr5 = &value5;  //�ݵ�� �ʱ�ȭ �ʿ�

	//*ptr5 = 10;  �Ұ���

	return 0;
}