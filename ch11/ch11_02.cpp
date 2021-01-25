//����� �⺻ [2/2] Inheritance ( is-a relationship )

#include "ch11_02_Student.h"
#include "ch11_02_Teacher.h"

using namespace std;

//Student �� Teacher class �� ����� ���� std:srting m_name �̶�� ����� �Ѵ� �ְ� �� ����� ����ϴ�
//��� �Լ����� �Ѵ� �ߺ��Ǿ� ������ ����(��ɵ� ����) �׷��� �̰͵��� ��� �Ϲ�ȭ�� Person class �� �Űܹ���
//����Ҷ��� Student �� Teacher �� ����� �޾� ����ϰ� �ϰ� Student �� Teacher class ���� ���� �־�� 
//�ϴ� ������ ���� ������ �����ؼ� ���, Student �� Teacher class �� �Ժη� ������ Ŭ������ �ִ°� ���
//���ϰ� ����, Person class ������ ������ ���� ����

//Person �� member variable �� public: ���� ����Ǿ��ִٸ� Student �� Teacher class ���� ���� ������ �� �� ������
//������ ĸ��ȭ�� ���� protected: �� ���Ƶδ°� �Ϲ����̰� �⺻��

//m_name �� ����å���� Person �� �ֱ� ������ m_name �� �ʱ�ȭ �ϴ� �����ڴ� Person ���� ������ ����
//Student �� Teacher class �� �����ڿ��� m_name �� �ʱ�ȭ �ϰ� ���� ��� Person �� �����ڸ� ���ؼ� �ʱ�ȭ
//Student �� �����ڿ����� m_name ���� �߰��� �ٸ� ��������� �ʱ�ȭ �� 



int main()
{

	//Student class �� Teacher class ���� setName(), getName() �� �ߺ��ǰ� ����
	//Student �� Teacher ��� �̸��� ������ ���� -> �л��� ����̰� ������ ����̴�, ����̶� ���鿡�� �ߺ���
	//Student �� Teacher �� '���' �̶�� �Ϲ�ȭ�� ��ü�� ���� �� ����

	//Student is a Peraon, Teacher is a Person


	//����� �̿��ؼ� �ߺ��Ǵ� �κ��� Person class �� ���� Student class �� Teacher class �� ����� �޾Ƽ�
	//Ŭ���� �ȿ� ���°� �ִ°� ó�� ����� �� �� ����
	Student std("Jack Jack");
	std.setName("Jack Jack2");
	std.getName();
	std::cout << std.getName() << endl;

	Teacher teacher1("Dr . H");
	teacher1.setName("Dr . K");
	std::cout << teacher1.getName() << std::endl;

	std::cout << std << std::endl;
	std::cout << teacher1 << std::endl;

	//Person ���� ���� ���� doNothing()
	std.doNothing();
	teacher1.doNothing();

	//������ ���� ���� ��ɸ� �����°� ���������ϱ� ����
	std.study();
	teacher1.teach();


	//�ڽ� class �� ������ �ִ°� �θ� class �� ������ ���� ����
	Person person;
	person.setName("Mr. Increible");
	person.getName();
	//person.study(); //error , Person ���� study() �� �����Ǿ� ���� �ʱ� ������
	//person.teach(); //error , Person ���� study() �� �����Ǿ� ���� �ʱ� ������

	return 0;
}