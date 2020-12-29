//�����Ϳ� ������ ��� ��å ������ Member Selection Operators

//���ο��Ϳ���    -> ���
//reference ����  . ���

#include <iostream>

using namespace std;

struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;

	person.age = 5;
	person.weight = 30;

	//���� ���
	Person& ref = person;
	ref.age = 15;

	//������ ���    -> ���
	Person* ptr = &person;
	ptr->age = 30;
	//de-referencing operators �� ���� �� �� ����
	(*ptr).age = 20;  //. �� * ���� �켱������ ���� ������ ( ) �ݵ�� �ʿ�! �׷��� �� ���� ����

	Person& ref2 = *ptr;
	ref2.age = 45;


	//�� �ּҰ� ����
	cout << &person << endl;
	cout << &ref2 << endl;
	//���� person  - > ������   - > ref  �ص� ���� ������ ���� �ּҰ� ����

	return 0;
}
