// ��� �Լ��� �ѹ� �� ���ø�ȭ�ϱ� Templatize

//� Ŭ������ �̹� ���ø�ȭ�� �Ǿ��ִ� ��쿡�� ����Լ��� �߰����� ���ø��� ������ �� ����

#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		:m_value(input)
	{
	}


	//TT �� doSomething() ������ ���Ǵ� template paramtert
	template<typename TT>
	void doSomething()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	template<typename TT>
	void doSomething(const TT& intput)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	//casting �Ҷ��� ����� �� ����
	template<typename TT>
	void doSomething_cast(const TT& intput)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;

		cout << (TT)m_value << endl; //m_value �� TT �� casting
	}

	//parameter �� ���� ��쿡�� ���� instantiation �� �� �� ����
	template<typename TT>
	void doSomething_cast()
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;

		cout << (TT)m_value << endl; //m_value �� TT �� casting
	}

	void print()
	{
		cout << m_value << endl;
	}


};

int main()
{
	A<int> a_int(123);
	a_int.print();

	//TT �� float ��(paramter �� ���� ���)
	a_int.doSomething<float>();

	//flaot type �� TT �� ���Ͽ� instantiation �� �Ǿ�����
	//�ű⿡ double �� ������ truncatoin �� �ȴٰ� ��� �߻�
	a_int.doSomething<float>(123.4);

	//parameter �� ������ �Ҽ� �ִ� ��쿡�� <float> �� �ʿ����
	a_int.doSomething(123.4);

	a_int.doSomething('a');  //doSomthing() �� char type �� ���ؼ� �߰������� ���ø�ȭ �Ǿ�����

	//casting �Ҷ��� ����� �� ����
	A<char> a_char('A');
	a_char.print();

	a_char.doSomething_cast(1);  //char type 'A' �� 1(int type ) ���� casting �Ϸ��� ��
	a_char.doSomething_cast(int()); //����Լ��� instantiation �� �����ϱ� ���� �̷��� �ϱ⵵ ��

	//parameter �� ���� ��쿡�� ���� instantiation �� �� �� ����
	a_char.doSomething_cast<int>();

	return 0;
}