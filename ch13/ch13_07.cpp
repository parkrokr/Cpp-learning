// 포인터에 대한 템플릿 특수화

//포인터에 대해서 특수화를 하는 클래스를 상속 구조를 통해서 구현하는것도 가능함


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

//포인터에 대하여 특수화

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


	//포인터인 경우에만 특별하게 작동시키고 싶음
	//특수화 안하면 주소가 출력됨

	int temp = 456;

	//parameter 로 int의 포인터 넣기
	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();


	//double 의 포인터 넣기
	double temp_d = 3.141592;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();



	return 0;
}