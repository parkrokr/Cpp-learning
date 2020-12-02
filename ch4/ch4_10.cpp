//����ü struct

//�پ��� ��ҵ��� ��� ��ġ �ϳ��� ����� ���� �ڷ����ΰ�ó�� ���

#include<iostream>
#include<string>

using namespace std;

//����� ���ؼ� ��� ����ϴ� �Լ�
/*void printPerson(double height, float weight, int age, name . . .)
{

}*/
//���� �������� �Ź� �����ϴ°� �δ㽺����

struct Person
{
	double height;
	float  weight;
	int	   age;
	string name;

	//�ʱ�ȭ�� ����� ���� �Ҽ��� ����
	/*double height = 3.0;
	float  weight = 200.0;
	int	   age = 50;
	string name = "Mr. Incrdible";*/

	//����ü�� �����ִ� �Լ�
	//data�� ����� ���� �� ����
	void print()
	{
		// ��� ���� �����ڸ� �� �ʿ䰡 ����
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}
};


/*void printPerson(Person ps)
{
	// �� �Լ����� ����ϴ� �������� Person �� �����ִµ� ���� ps��� parameter �� �� �ʿ䰡 ����
	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
	cout << endl;
}*/


//����ü �ȿ� ����ü�� ���� �� ����
struct Family
{
	Person me, mom, dad;
};

//�Լ��� ����ü�� return �ϰ� �Ҽ��� ����
Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack Jack" };

	return me;
}

struct Employee	      //2 +(2) + 4 + 8 = 16  //(2)�� �߰��Ǵ°� padding �̶� ��
{
	short	id;       //2 bytes + (2)
	int		age;	  //4 bytes
	double	wage;	  //8 bytes
	
	//��� type ������ �����ִ°� ����ȭ�� ���α׷� ����ȭ�� �߿���
	//struct member alignment
};


int main()
{
	/*//���� ����� �����Ҷ�
	double height1, height2, height3;// �迭 double height1[100]�� ����� ǥ���� �� �ִ�
	//���� ������ ����ؾ� �Ѵٴ� ���� �ٸ��� ����, weight age ���� ���� ���� ������ �����
	float weight;
	int age;
	string name;*/


	//struct ���
	Person me{ 2.0, 100.0, 20, "Jack Jack" }; // uniform �ʱ�ȭ ����� ������
	//����ü ����� �ʱ�ȭ�� �Ǿ��־ me �� �ʱⰪ�� ����


	//printPerson(me); //�Լ��� ����ü �ۿ� ���� ���
	me.print();		   //�Լ��� ����ü �ȿ� ���� ���
   

	//���Ե� ����
	//Person me2(me);

	//�ܼ��� ��쿡�� ����
	//�ɹ��� ���������� ���ϴ� ��� �۵����� ���� �� ����
	Person me2;
	me2 = me;

	me2.print();
  

	//����ü �ȿ� �ִ� ����� �����Ϸ��� ps �ڿ� .(member selection operator) �� �ٿ�����
	//���� �ʱ�ȭ ���
	/*me.age = 20;
	me.name = "Jack Jack";
	me.height = 2.0;
	me.weight = 100.0;*/
	
	
	//�Լ��� ����ü parameter �� �������� �ְ� return �ϰ� �Ҽ��� ����
	Person me_from_func = getMe();
	me_from_func.print();


	Employee emp1;

	//sizwof()�� ����ü ũ�⸦ �����ҋ��� ����� �� ����
	cout << sizeof(Employee) << endl; // 16, 14�� �ƴ�
	//short �� 2bytes �� �ƴ϶� 4bytes�� �Ҵ�Ǿ��������� ����
	//data structure alignment �˻�

	return 0;
}