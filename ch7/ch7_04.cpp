// �ּҿ� ���� �μ� ���� Passing Arguments by Address (Call by Address)

//�ᱹ ������ ������ ����� �ּ�'��'�� �����ϴ� call-by-value ��
//literal �� ���� �ȵ�
//�ּҷ� �����ϴ°��� ���� ������ ������� ���ϼ��� ������ c style ���� �ʼ����̾���
//�迭�� �ѱ涧�� ������ ��ü�� �ƴ� �ּҸ� ������ ������ ȿ������

#include <iostream>

using namespace std;

//void foo(const int* ptr)  //de-referecing �� ���� ���ٲ�,  ���� �̷��� �����
//void foo(const int* const ptr)//ptr�� ����� �ּҰ��� ���ο��� ���ٲ�
void foo(int* ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl;

	//foo(const int* ptr)�϶� �Ұ���, ���� �� ���·� ���� �����
	//*ptr = 1;  
	

	//foo(const int* const ptr)�϶� �Ұ���
	//�Լ� ���θ� �����Ҷ� �߰��� �Ǽ��ϴ°��� ���� ���� ���¼ҽ����� ���� �����
	
	//x = 1;
	//ptr = &x;
}

//�����͸� ����Ͽ� �Լ��� ���ó�� ����� �� ����
void getSinCos(const double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}


//���� ���Ǵ� c style �ڵ�
void arr(int* arr, int length) //���� �迭�� ���� �ٲٰ� ���� ������ const�� ����
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;
	
	//�̷��� �迭�� ���� �ٲٸ� �Ŀ� �Լ��� ������ �迭�� ���� �ٲ�
	//�ۿ� �ִ� �迭�� �ּҸ� �޾Ƽ� �ٲٴ� ���̱� ������ �Ȱ��� �۵���
	arr[0] = 1.0;  //[] ��ȣ�� de-referecing��
}


int main()
{
	int value = 5;

	cout << value << " " << &value << endl;

	int* ptr = &value;

	cout << &ptr << endl;


	//�Լ��� �ּҸ� �־���� ��
	
	//foo(5);  //5�� literal �̶� �ּҰ� ����, �Լ����� const �� �޾Ƶ� �ȵ�
	
	//��� ����
	foo(ptr); //������ ���� ������ �ֱ�
	foo(&value); //�ٷ� �ּ� �ֱ�
	

	//main ������ ptr�� �ּҶ� foo()������ ptr�� �ּҰ� �ٸ� 
	//�����Ϳ� ���� ������ �ᱹ �ּҶ�� '��'�� ���� ���� ������ ����
	//������ '����'�� ����� �ּ�'��'�� ����� �� ������ ������ �ּұ��� �Ѿ�� ���� �ƴ�


	//�����͸� ����Ͽ� �Լ��� ���ó�� ����� �� ����
	double degrees = 30;
	double sin, cos;

	//������ ���� ���ް� �޸� ����ϴ� sin, cos �� �ּҸ� ������ ��
	getSinCos(degrees, &sin, &cos);

	cout << sin << " " << cos << endl;
	
	//�ǿ����� �鿡�� ������ ���°� �� ����

	return 0;
}