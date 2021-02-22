#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>	//std::forward


//r value reference �� parameter �� �޴� �Լ��� overloading �Ҷ��� ���������� move constructor ��
//����Ϸ��°��� �ǵ��ϰ� �����ϴ� ���̱� ������ std::move �� ����Ͽ� ����������

using namespace std;

class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);		//�����ڿ��� ���� �ʱ�ȭ �ϴ°ͺ��� �ʱ�ȭ �ϴ� �ڵ带 ������ �и��ϴ°� ���� 
	}


	//copy constructor
	CustomVector(CustomVector& l_input)
	{
		cout << "Copy constructor" << endl;

		init(l_input.n_data);	

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	//move constructor
	CustomVector(CustomVector&& r_input)
	{
		cout << "Move constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	
	~CustomVector()
	{
		delete[]ptr;
	}



	//�����ڿ��� ���� �ʱ�ȭ �ϴ°ͺ��� �ʱ�ȭ �ϴ� �ڵ带 ������ �и��ϴ°� ����
	void init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};


void doSomething(CustomVector& vec)
{
	cout << "Pass by L-reference" << endl;
	CustomVector new_vec(vec);	//copy constructor ȣ��
}

void doSomething(CustomVector&& vec)
{
	cout << "Pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec));	//move constructor ȣ��
	//std::move �� ������� ������ l value �� ����, vec ��ü�� l value �� �׷�
}

//���ø�ȭ �Ҷ� ������ �߻���
//std::forward �� ����Ͽ� perfect forwaring ����
template<typename T>
void doSomethingTemplate(T&& vec)	//&& �� �޾Ƶ� std::forward �����ϸ� �ҿ� ����(l value �� ����)
{
	doSomething(std::forward<T>(vec));	//
}

int main()
{
	CustomVector my_vec(10, 1024);

	CustomVector temp(my_vec);	//l value �� �������� copy constructor ȣ��

	CustomVector temp2(std::move((my_vec)));	//r value �� �־ move constructor ȣ��
	//my_vec�� r value �� �ٲ۴� ��� �ǹ� ���ٴ� ���������� �����Ҷ� copy constructor �� �ƴϰ� 
	//move constructor �� ȣ���ϰڴٴ� �ǹ̰� ����




	doSomething(my_vec);
	//doSomething(std::move(my_vec));	//�� ��� �ؿ��� my_vec �� �ٽ� ������ ������ �̷� ����� �������� ����

	doSomething(CustomVector(10, 8));	//�ٷ� r value reference �� �Ѿ, move constructor ȣ��



	//���ø�ȭ �Ҷ� ������ �߻���
	//std::forward ���
	doSomethingTemplate(my_vec);
	doSomethingTemplate(CustomVector(10, 8));

	//�������� ������ ���� ��� copy constructor �� move constructor �� ���� ȿ���� ���� ���̳�

	my_vec;	//doSomethingTemplate ���� my_vec �� l value �� �޾ұ� ������ my_vec �� ����� �� ����

	return 0;
}