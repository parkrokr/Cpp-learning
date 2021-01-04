//�پ��� ��ȯ ����(Returning Values)  ��, ����, �ּ�, ����ü, Ʃ��(Tuple)

#include<iostream>
#include<array>
#include<tuple>

using namespace std;

//return by value
int getValue(int x)
{
	int value = x * 2;
	return value;
}

//return by address
int* getValue_ptr(int x)
{
	int value = x * 2;
	return &value;
}

//return by address(dynamic allocated array)
int* allocateMemory(int size)
{
	return new int[size];
}

//return by reference
//return type�� �����ϴ� �κп��� reference ���� value ���� Ȯ���ؾ� �ؼ� �Ǽ� Ȯ���� �ö�
int& getValue_ref(int x)
{
	int value = x * 2;
	return value;
}

//return by reference �� �� ���� ���
//my_array �� �Ϻθ� �Լ��� ��ġ�� �ϱ�
int& get(std::array<int, 100>& my_array, int index)
{
	return my_array[index];
}

//�������� return ��
struct S
{
	int a, b, c, d;
};

//return by structure
S getStrct()
{
	S my_s{ 1,2,3,4 };
	return my_s;
}

//int�� double ���� return �ϰ� �ʹ�
std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}


int main()
{
	//return by value
	int value = getValue(3);
	
	//���� : ����� ������ ������ �Ͼ, �ӵ��� ���� ������


	//return by address
	
	//de-referecing �ؼ� ������ �ޱ�   ������ ���ϱ�
	int value_ptr_de_ref =*getValue_ptr(3);
	//���� ���� ����, �Լ� ������ ����� ���ÿ� ����� ������ ������ �ϴ°� �������� ���� 
	
	cout << value_ptr_de_ref << endl; // warning C4172 �߻�
	cout << value_ptr_de_ref << endl;

	//�ּҷ� �ޱ�		�� ������   �������� ����
	int* value_ptr = getValue_ptr(3);
	//�޾ƿ��� �ּҿ� ����ִ� ���� �Լ� ������ ������ ���� ��������� �� �� ����
	
	cout << *value_ptr << endl; // warning C4172 �߻�
	cout << *value_ptr << endl;  //�Լ� ������ ������ �޸𸮵� ������� �ٸ� ���� ����

	//return by address�� array �� ���鶧 ����ϴ� ���
	//int* array = new int[10];   // new int[10]�� �Լ��� �����
	int* array = allocateMemory(10);

	delete[] array;  // �̷������� ���� �޸𸮸� ����� ���� ���α׷��Ӹ� ����� �� �� ����(�Լ��� �и��Ǿ��־)



	//return by reference
	//���� ������
	int value_ref = getValue_ref(5);
	cout << value_ref << endl;

	//�޴��ʵ� ������ ��� ������ �߻��� �� ����,�ſ� ������
	//�Լ� ������ ������ �޸𸮵� �����, �Լ��� const �� �־ �ҿ� ����
	int& value_ref_ref = getValue_ref(5);
	cout << value_ref_ref << endl;
	cout << value_ref_ref << endl;  // �Լ� ������ ������ �޸𸮵� ������� �ٸ� ���� ����


	//return by reference �� �� ���� ���
	std::array<int, 100> my_array; //�Լ������� �޸� �޸𸮰� Ȯ���ϰ� ����
	my_array[30] = 10;
	
	//my_array �� �Ϻθ� �Լ��� ��ġ�� �ϱ�
	//���� ������ ���� ���ϰ� �ٷ� �� ����
	get(my_array, 30)= 1024;
	get(my_array, 30) *= 2;

	cout << my_array[30] << endl;




	//���� ���� return ��
	
	//c style
	//structure �� �޴°� �Ϲ���
	S my_s = getStrct();
	my_s.a;
	
	//���� : �Լ� �ϳ��� ���鶧���� ����ü�� �ϳ��� ����� ��� �Ѵ�
	//���� ���̺귯������ �̷������� ¥�� ����


	//tuple
	std::tuple<int, double> my_tp = getTuple();

	//���� �����ö�
	cout << std::get<0>(my_tp) << endl; //a
	cout << std::get<1>(my_tp) << endl; //b


	//in c++17
	auto [a, b] = getTuple();  //a�� b�� �����ϸ鼭 ���� �޴°�
	cout << a << endl;
	cout << b << endl;

	return 0;
}