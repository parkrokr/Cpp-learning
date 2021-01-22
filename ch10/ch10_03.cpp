//���� ���� Association

//�����͸� �ְ� �޾Ƽ� lec1 �� lec2 �� Jack Jack ���� �л��� instace�� '����'�ϰ� ����(���� �޸𸮿� �ִ°� ����)
//�л� ó�� �Ҷ��� ��ǻ���� �޸𸮰� �и��Ǿ� �ֱ� ������ ���� ¥����
//�纻�� �������⿡�� ������ �ϰ� ����ȭ ������ ���ľ� ��

#include<iostream>
#include <vector>
#include <string>
#include "ch10_03_Lecture.h"
#include "ch10_03_HobbyClub.h"

int main()
{
	using namespace std;

	//Composition Relationship

	//������ student �� ���ε��� member variable �� ���� ����
	//lec1 �� lec2 �� �ִ� student �� �ٸ� �޸� �ּҸ� ���� �ֱ� 
	//����ȭ�� �����ֱ� ���ؼ� intelligence �� ����ȭ �ϴ� ������ ������ ���ľ� ��

	//Lecture lec1("Introduction to Computer Programming");
	//lec1.assignTeacher(Teacher("Prof. Hong"));
	//lec1.registerStudent(Student("Jack Jack", 0));
	//lec1.registerStudent(Student("Dash", 0));
	//lec1.registerStudent(Student("Violet", 2));


	//Lecture lec2("Computational Thinking");
	//lec2.assignTeacher(Teacher("Prof. Good"));
	//lec2.registerStudent(Student("Jack Jack", 0)); //lec1 �� Jack Jack �� �ٸ�(�ٸ� �ּҸ� ����) ������

	////test
	//{
	//	cout << lec1 << endl;
	//	cout << lec2 << endl;

	//	//event
	//	lec2.study();
	//	//lec2 ���� study �� �ص� ���� Jack Jack �л��� lec1 ���� intelligence �� �ö��� ����

	//	cout << lec1 << endl;
	//	cout << lec2 << endl;
	//}



	//Aggreagation Relationship
	
	//std1,std2,std3 �� �ּҸ� ������ ���� ������ lec1 �� lec2 ���� ���� �л����� �ν���
	//�����ͷ� ������ �ϸ� lec2 ���� std1�� member variable �� �ٲ������� lec1 ������ �ڵ����� �ݿ��� ��

	Student std1("Jack Jack", 0);
	Student std2("Dash", 1);
	Student std3("Violet", 2);

	Teacher teacher1("Prof. Hong");
	Teacher teacher2("Prof. Good");


	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);
	lec1.registerStudent(&std3);


	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(&std1);

	//test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		//event
		lec2.study(); //lec2���� study �� �ϸ� lec1 �� �ִ� Jack Jack �� intelligence �� �ö�
		
		cout << lec1 << endl;
		cout << lec2 << endl;
	}




	//������ student �� main() ���� ������ �����ϸ� main() �� scope �� ���� local variable �̱� ������
	//main() �� ������ �ڵ����� �����
	//main() �� �ƴ� �ٸ� �������� ������ ���� �Ҵ����� �����ϱ⵵ ��
	//��ſ� �޸𸮸� �ݵ�� ���������

	Student *ptr_std1 = new Student("Jack Jack", 0);
	Student *ptr_std2 = new Student("Dash", 1);
	Student *ptr_std3 = new Student("Violet", 2);

	Teacher *ptr_teacher1 = new Teacher("Prof. Hong");
	Teacher *ptr_teacher2 = new Teacher("Prof. Good");

	Lecture lec3("Introduction to Computer Programming2");
	lec3.assignTeacher(ptr_teacher1);
	lec3.registerStudent(ptr_std1);
	lec3.registerStudent(ptr_std2);
	lec3.registerStudent(ptr_std3);


	Lecture lec4("Computational Thinking2");
	lec4.assignTeacher(ptr_teacher2);
	lec4.registerStudent(ptr_std1);

	// test
	{
		cout << lec3 << endl;
		cout << lec4 << endl;

		//event
		lec4.study(); 

		cout << lec3 << endl;
		cout << lec4 << endl;
	}

	//delete memory (if necessary )
	delete ptr_std1;
	delete ptr_std2;
	delete ptr_std3;

	delete ptr_teacher1;
	delete ptr_teacher2;


	//TODO: class HobbyClub
	HobbyClub hbc("Computer Club");
	hbc.registerStudent(&std1);
	hbc.registerStudent(&std2);

	HobbyClub hbc2("Game Club");
	hbc2.registerStudent(&std1);

	{
		cout << hbc << endl;
		cout << hbc2 << endl;

		//event
		hbc2.play();

		cout << hbc << endl;
		cout << hbc2 << endl;
	}

	return 0;
}