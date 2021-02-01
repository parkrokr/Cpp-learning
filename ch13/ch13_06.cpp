// ���ø��� �κ������ Ư��ȭ�ϱ� Partial Specialization

//template parameter �� �������� ��� ��� �ٰ� �ƴ� �κ������� Ư��ȭ

//����Լ��� ���� Ư��ȭ �ϱⰡ ���� ���ŷο�
//���ϰ� �ϴ� ��� : Ŭ���� ��� �ޱ�
//���� Ŭ������ _BASE �� ����� ���� �̸��� ���� Ŭ������ ��ӹް� ������
//�� Ŭ������ Ư��ȭ ��Ű�� �ʿ��� �Լ��� �������̵�
//����� �޴� ������� �����ϴ°� ��ü�� Ư��ȭ �ϴ°ͺ��� ����
//��ü�� Ư��ȭ �Ϸ��� �ٸ� �Լ��鵵 �ݺ������� �����ؾߵ�(�� ������ Ŭ���� Ư��ȭó�� �׳� ���ο� Ŭ������ ����²�)
//����� ����ϸ� Ŭ���� ���ο� print() �� �־ ����� �޾ұ� ������ �ٸ� �Լ��鵵 ��� �� �� ����


//template parameter�� ��� Ư��ȭ �Ͽ� '���� Ư��ȭ'�� �Ҷ��� ��� �Լ��� Ŭ���� �ٱ����� Ư��ȭ ����
//������ ���� Ư��ȭ �Ϸ��� char, 3 ���� ��üȭ �ؾ������� size �� ��üȭ �ϸ� �ȵǱ� ������
//class �� Ư��ȭ �ϴ� �κ�Ư��ȭ �� �Ϸ��� �ϴ°�, �׸��� ����Լ��� Ŭ���� �ۿ��� Ư��ȭ �Ҷ�
//�κ�Ư��ȭ�� ������ ����(�Լ��� �����ε��� �����ϰ� �ؼ��ΰ����� ����?)



#include <iostream>
using namespace std;

// class T �� ���� ���ø�ȭ�� �Ǿ��ְ� int size(Non-type parameter) �� ���ؼ� ���ø�ȭ�� �Ǿ�����
template <class T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}


	//�ۿ� �ִ� print() �� ����Լ��� �����

	//template <typename T, int size>		//���� ������ �����ʿ� ����
	void print()							//StaticArray<T, size>& array �� ���� �ʿ� ����
	{
		for (int count = 0; count < size; ++count)
		{
			//std::cout << array[count] << ' ';
			std::cout << (*this)[count] << ' ';
		}
		std::cout << endl;
	}
};


//print() �Լ��� ����Լ��� �ְ� ����
/*
//�Լ��� ���ø�ȭ�� �Ǿ�����
template <typename T, int size>
void print(StaticArray<T, size>& array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count] << ' ';
	std::cout << endl;
}

//typename T �� int size �߿��� typename T �� Ư��ȭ
template <int size>
void print(StaticArray<char, size>& array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count]; //char type �� ���ؼ� ��ĭ�� ������� �ʱ�
	std::cout << endl;
}
*/


//����Լ��� Ư��ȭ �Ҷ� ���� Ŭ������ _BASE �� ����� �� Ŭ������ ��ӹ޴� Ŭ������ ����(������ �̸��̶� ������)
//����� ���� ������ template �� ��°�� Ư��ȭ �ϴ°ͺ��� ���ϱ� ����

template <class T, int size>
class StaticArray :public StaticArray_BASE<T, size>
{
};

//class �� char type �� ��쿡 ���ؼ��� ������ ����� �ѹ� �� ����
template <int size>
class StaticArray<char,size> :public StaticArray_BASE<char, size>
{
public:
	//print() �� �������̵�
	void print()							
	{
		for (int count = 0; count < size; ++count)
		{
			std::cout << (*this)[count];	// << ' ' ����
		}
		std::cout << endl;
	}
};
//����� �޾ұ� ������ print() ���� �ٸ� �Լ����� �ٽ� �������� �ʿ䰡 ����



int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	//print(int4);  //print() �� ����Լ��� ����� ��
	int4.print();
	//1 2 3 4   //��ĭ �ϳ��� �� ��µǰ� ����


	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';
	//. . .

	strcpy_s(char14.getArray(), 14, "Hello, World");

	//print(char14);  ////print() �� ����Լ��� ����� ��
	char14.print();
	//Ư��ȭ �� : H e l l o ,   W o r l d  ?  
	//���ڿ��� ����ϴµ� ����ִ°��� ������ ��
	//print() �� << ' '; �κ��� �����Ǵ°���
	//char type �� ���ؼ� print() �� �Ҷ� ��ĭ�� �������� ������ -> Ư��ȭ
	
	//typename T �� int size �߿��� typename T �� Ư��ȭ�� ����ߵ�(size �� ���� �ִ°� �ʹ� ����)


	//print() �� ����Լ��� ������ �ٽ� ��ĭ�� ��Ƴ�
	//����Լ��� Ư��ȭ �ϱⰡ ���� ���ŷο�
	//���ϰ� �ϴ� ��� : Ŭ���� ��� �ޱ�
	//���� StaticArray �� StaticArray_BASE �� �����(��������� �ϸ� ������ ����� �ν��Ͻ��� ������)
	//StaticArray_BASE�� ��ӹ޴� StaticArray �� ����


	return 0;
}