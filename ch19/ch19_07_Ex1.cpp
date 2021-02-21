// �Ϻ��� ����( Perfect Forwaring ) �� std::forward

#include <iostream>
#include <vector>
#include <utility>	//std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)	//r value �� l value �Ŀ� ���� �����ε��� ��
{
	cout << "Pass by R-ref" << endl;
}

//void func(MyStruct s)
//{
//	cout << "Pass by R-ref" << endl;
//}

template<typename T>
void func_wrapper(T t)
{
	func(t);
}


template<typename T>
void func_wrapper_perfect(T&& t)		//perfect forwarding 
{
	func(std::forward<T>(t));
	
	//std::forward �� t �� ���ö� l value �̸� l value, r value �̸� r value �� return ����
}


int main()
{
	MyStruct s;

	func(s);							//Pass by L-ref
	func(MyStruct());					//Pass by R-ref
	//visual studio �� ide �������� ��������

	//�̷��� ���������� ����ϴ°��� ��������
	
	//������ ���ø��� ����Ҷ� ������ ������
	func_wrapper(s);					//Pass by  L-ref
	func_wrapper(MyStruct());			//Pass by  L-ref
	//�ΰ��� ���� ����, ���ø�ȭ �ϸ鼭 r value ���� l value ���� ������ ���ư�����


	//�ذ��ϱ� ���� perfect forwarding �� ������
	func_wrapper_perfect(s);			//Pass by L-ref
	func_wrapper_perfect(MyStruct());	//Pass by R-ref
	//std::forward �� t �� ���ö� l value �̸� l value, r value �̸� r value �� return ����


	return 0;
}