#pragma once


#include<vector>
#include "ch10_03_Student.h"
#include "ch10_03_Teacher.h"

class Lecture
{
private:
	std::string m_name;

	//Teacher teacher;  //Lecture class 인스턴스가 사라질때 같이 사라짐(구성 관계의 중요 특징)
	//std::vector<Student> students;  //Lecture class 인스턴스가 사라질때 같이 사라짐


	// teacher 와 students 의 주소를 가져오면 해결
	Teacher *teacher;
	std::vector<Student*> students; 
	//students 는 vector class 의 인스턴스라 Lecture class 가 사라지면 같이 사라짐
	//하지만 Student* 가 가리키고 있는 주소에 있는 것들은 유지됨(lec1 이 사라져도 std1 은 사라지지 않음)

public:
	Lecture(const std::string & name_in = "No Name")
		:m_name(name_in)
	{}

	~Lecture()
	{
		//do NOT delete teacher
		//do NOT delete students
	}

	/*void assignTeacher(const Teacher& teacher_input)
	{
		teacher = teacher_input;
	}*/

	//teacher 가 포인터라 포인터를 넘겨줘야 하고 주소를 바꿔줄꺼라 앞에 const 지우기
	void assignTeacher(Teacher* const teacher_input)  
	{
		teacher = teacher_input;
	}


	/*void registerStudent(const Student& student_input)
	{
		students.push_back(student_input);  

		// &student_input != &student[0] , 복사해서 넣었기 때문에
	}*/

	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}


	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		//Note: without &, 'auto element' doesn't work, 
		//for (auto& element : students) // value 로 받아오면 값이 업데이트 되지 않음
			//element.setIntel(element.getIntel() + 1);



		//for(auto & element : students)
		for (auto element : students)  //이렇게 value 로 갖고 와도 되고 & 로 갖고 와도 됨
			(*element).setIntel((*element).getIntel() + 1);  //de-referencing 사용하기
		//	element->setIntel(element->getIntel()+1);		//-> 사용하기
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		/*out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element << std::endl;*/

		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl;  //element 만 출력하면 포인터가 출력되니 de-referencing

		return out;
	}

};
