//�Լ� ������ Function Pointers

//�Լ��� ���� ������

#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func()
{
	return 5;
}

int goo()
{
	return 10;
}


//Ȧ��, ¦���� �����ؼ� ���
//void printNumbers(const array<int, 10>& my_array,bool print_even)
//{
//	for (auto element : my_array)
//	{
//		if (print_even && element % 2 == 0)cout << element;	//¦���϶��� ���
//		if (!print_even && element % 2 == 1)cout << element;//Ȧ���϶��� ���
//	}
//	cout << endl;
//}

//�Լ� ������ ���
//¦���� true ����
bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;	//������ ��� ��ΰ� ���ϰ��� ���ٴ� ������ ��
}
//Ȧ���� true ����
bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

// check_fcn�ڸ��� isEven()�� isOdd() ��
// bool (*check_fcn)(const int&) = isEven ���� default prameter ������ ���� ����
void printNumbers(const array<int, 10>& my_array, bool (*check_fcn)(const int&))
{
	for (auto element : my_array)
	{
		if (check_fcn(element) == true)cout << element;	
	}
	cout << endl;
}




int main()
{
	cout << func << endl;  //func() �� �ƴ�
	//�����ϸ� �ּҰ� ����
	//�Լ��� ��������(�ּҸ� ������ ����)

	//func();�� �ϸ� �Լ��� ��� �޸��ּҿ� �ִ��� �˾Ƴ��� �� �ּҿ� �ִ� ���α׷��� ������ �ͼ� ����


	//�Լ� ������ ����
	//fcnptr �Լ� ������ ���� ������ func�� �ʱ�ȭ
	int (*fcnptr)() = func; //�������� �Լ��� return type�� ��ġ�ؾ���

	cout << fcnptr() << endl;  //()�� ���̸� �Լ��� ������

	fcnptr = goo; //�߰��� �ٲ�ġ�� �� �� ����

	cout << fcnptr() << endl;



	//�Ű������� �Լ� �����͸� ������� ��� �� ������
	
	//int func(int x) {} �� ������ ������
	//int(*fcnptr)(int) = func;
	//goo()�� �ٲٷ��� 
	//int goo(int x) {}�� �Ű������� reuturn type�� ���������




	//�Լ� �����͸� �Լ� �Ű������� ���� �� ����
	std::array<int, 10>my_array = { 0,1,2,3,4,5,6,7,8,9 };

	//Ȧ��, ¦���� �����ؼ� ���
	//printNumbers(my_array,true);  //true�϶� ¦��
	//printNumbers(my_array, false); //false �϶� Ȧ��


	//�Լ� ������ ���
	//�Լ��� �̸���ü�� �����Ͷ� �տ� &�� �Ⱥٿ��� ��
	printNumbers(my_array,isEven);  // isEven �϶� ¦��
	printNumbers(my_array, isOdd);  // isOdd  �϶� Ȧ��

	//printNumbers(my_array); // isEven ���� default prameter ���������� ¦�� ���


	//Type aliases(���� ���̱�) �� �� ������
	//�Ź� bool (*check_fcn)(const int&)�ϱⰡ ���ŷο� ���

	//typedef �� ����ϴ� ���
	//typedef bool (*check_fcn_t)(const int&); �� �ϸ�
	//check_fcn_t�� �ٿ��� ����� �� ����

	//using �� ����ϴ� ���
	//using check_fcn_t = bool(*)(const int&)



	//std::function
	std::function<bool(const int&)> fcnptr = isEven;  //�� ����ϸ�

	//�޴��ʿ��� ����� �� ����
	/*void printNumbers(const array<int, 10>&my_array,std::function<bool(const int&)> fcnptr)
	{
		for (auto element : my_array)
		{
			if (check_fcn(element) == true)cout << element;
		}
		cout << endl;
	}*/

	//printNumbers(my_array, fcnptr);

	//fcnptr = isOdd;

	//printNumbers(my_array, fcnptr);

	return 0;
}