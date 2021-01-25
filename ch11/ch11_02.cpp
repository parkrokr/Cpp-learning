//상속의 기본 [2/2] Inheritance ( is-a relationship )

#include "ch11_02_Student.h"
#include "ch11_02_Teacher.h"

using namespace std;

//Student 와 Teacher class 를 만들고 보니 std:srting m_name 이라는 멤버가 둘다 있고 그 멤버를 사용하는
//멤버 함수들이 둘다 중복되어 가지고 있음(기능도 같음) 그래서 이것들을 묶어서 일반화된 Person class 로 옮겨버림
//사용할때는 Student 와 Teacher 가 상속을 받아 사용하게 하고 Student 와 Teacher class 에만 각각 있어야 
//하는 내용을 각각 별도로 구현해서 사용, Student 와 Teacher class 가 함부로 서로의 클래스에 있는걸 사용
//못하게 막고, Person class 에서도 가져다 쓰지 못함

//Person 의 member variable 이 public: 으로 선언되어있다면 Student 와 Teacher class 에서 쉽게 가져다 쓸 수 있지만
//보통은 캡슐화를 위해 protected: 로 막아두는게 일반적이고 기본적

//m_name 의 관리책임은 Person 에 있기 때문에 m_name 을 초기화 하는 생성자는 Person 에서 가지고 있음
//Student 와 Teacher class 의 생성자에서 m_name 를 초기화 하고 싶은 경우 Person 의 생성자를 통해서 초기화
//Student 의 생성자에서는 m_name 말고도 추가로 다른 멤버변수를 초기화 함 



int main()
{

	//Student class 랑 Teacher class 에서 setName(), getName() 이 중복되고 있음
	//Student 와 Teacher 모두 이름을 가지고 있음 -> 학생도 사람이고 선생도 사람이다, 사람이란 측면에서 중복됨
	//Student 와 Teacher 를 '사람' 이라는 일반화된 객체로 묶을 수 있음

	//Student is a Peraon, Teacher is a Person


	//상속을 이용해서 중복되는 부분을 Person class 로 뺏고 Student class 와 Teacher class 가 상속을 받아서
	//클래스 안에 없는걸 있는것 처럼 사용을 할 수 있음
	Student std("Jack Jack");
	std.setName("Jack Jack2");
	std.getName();
	std::cout << std.getName() << endl;

	Teacher teacher1("Dr . H");
	teacher1.setName("Dr . K");
	std::cout << teacher1.getName() << std::endl;

	std::cout << std << std::endl;
	std::cout << teacher1 << std::endl;

	//Person 에서 새로 만든 doNothing()
	std.doNothing();
	teacher1.doNothing();

	//보통은 각자 가질 기능만 가지는게 유지보수하기 좋음
	std.study();
	teacher1.teach();


	//자식 class 가 가지고 있는걸 부모 class 가 가져다 쓰진 못함
	Person person;
	person.setName("Mr. Increible");
	person.getName();
	//person.study(); //error , Person 에는 study() 가 구현되어 있지 않기 때문에
	//person.teach(); //error , Person 에는 study() 가 구현되어 있지 않기 때문에

	return 0;
}