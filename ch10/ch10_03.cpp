//집합 관계 Association

//포인터를 주고 받아서 lec1 과 lec2 가 Jack Jack 같은 학생의 instace를 '공유'하고 있음(같은 메모리에 있는걸 공유)
//분산 처리 할때는 컴퓨터의 메모리가 분리되어 있기 때문에 따로 짜야함
//사본을 여기저기에서 가져야 하고 동기화 과정을 거쳐야 함

#include<iostream>
#include <vector>
#include <string>
#include "ch10_03_Lecture.h"
#include "ch10_03_HobbyClub.h"

int main()
{
	using namespace std;

	//Composition Relationship

	//각각의 student 를 따로따로 member variable 로 갖고 있음
	//lec1 과 lec2 에 있는 student 는 다른 메모리 주소를 갖고 있기 
	//동기화를 시켜주기 위해선 intelligence 를 동기화 하는 복잡한 과정을 거쳐야 함

	//Lecture lec1("Introduction to Computer Programming");
	//lec1.assignTeacher(Teacher("Prof. Hong"));
	//lec1.registerStudent(Student("Jack Jack", 0));
	//lec1.registerStudent(Student("Dash", 0));
	//lec1.registerStudent(Student("Violet", 2));


	//Lecture lec2("Computational Thinking");
	//lec2.assignTeacher(Teacher("Prof. Good"));
	//lec2.registerStudent(Student("Jack Jack", 0)); //lec1 의 Jack Jack 와 다른(다른 주소를 가진) 존재임

	////test
	//{
	//	cout << lec1 << endl;
	//	cout << lec2 << endl;

	//	//event
	//	lec2.study();
	//	//lec2 에서 study 를 해도 같은 Jack Jack 학생이 lec1 에서 intelligence 가 올라가지 않음

	//	cout << lec1 << endl;
	//	cout << lec2 << endl;
	//}



	//Aggreagation Relationship
	
	//std1,std2,std3 의 주소만 가져다 쓰기 때문에 lec1 과 lec2 에서 같은 학생으로 인식함
	//포인터로 공유를 하면 lec2 에서 std1의 member variable 을 바꿔줬을때 lec1 에서도 자동으로 반영이 됨

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
		lec2.study(); //lec2에서 study 를 하면 lec1 에 있는 Jack Jack 로 intelligence 가 올라감
		
		cout << lec1 << endl;
		cout << lec2 << endl;
	}




	//지금은 student 를 main() 에서 변수로 선언하면 main() 의 scope 에 속한 local variable 이기 때문에
	//main() 이 끝나면 자동으로 사라짐
	//main() 이 아닌 다른 곳에서도 쓰려면 동적 할당으로 구현하기도 함
	//대신에 메모리를 반드시 지워줘야함

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