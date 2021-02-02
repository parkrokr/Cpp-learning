// �����Ϳ� ���� ���ø� Ư��ȭ

//�����Ϳ� ���ؼ� Ư��ȭ�� �ϴ� Ŭ������ ��� ������ ���ؼ� �����ϴ°͵� ������


#include <iostream>
using namespace std;

template <class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		:m_value(input)
	{
	}

	void print()
	{
		cout << m_value << endl;
	}
};

//�����Ϳ� ���Ͽ� Ư��ȭ

template <class T>
class A<T*>
{
private:
	T* m_value;

public:
	A(T* input)
		:m_value(input)
	{
	}

	void print()
	{
		cout << *m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();


	//�������� ��쿡�� Ư���ϰ� �۵���Ű�� ����
	//Ư��ȭ ���ϸ� �ּҰ� ��µ�

	int temp = 456;

	//parameter �� int�� ������ �ֱ�
	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();


	//double �� ������ �ֱ�
	double temp_d = 3.141592;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();



	return 0;
}