#pragma once


#include<vector>
#include "ch10_03_Student.h"
#include "ch10_03_Teacher.h"

class Lecture
{
private:
	std::string m_name;

	//Teacher teacher;  //Lecture class �ν��Ͻ��� ������� ���� �����(���� ������ �߿� Ư¡)
	//std::vector<Student> students;  //Lecture class �ν��Ͻ��� ������� ���� �����


	// teacher �� students �� �ּҸ� �������� �ذ�
	Teacher *teacher;
	std::vector<Student*> students; 
	//students �� vector class �� �ν��Ͻ��� Lecture class �� ������� ���� �����
	//������ Student* �� ����Ű�� �ִ� �ּҴ� ������

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

	//teacher �� �����Ͷ� �����͸� �Ѱ���� �ϰ� �ּҸ� �ٲ��ٲ��� �տ� const �����
	void assignTeacher(Teacher* const teacher_input)  
	{
		teacher = teacher_input;
	}


	/*void registerStudent(const Student& student_input)
	{
		students.push_back(student_input);  

		// &student_input != &student[0] , �����ؼ� �־��� ������
	}*/

	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}


	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		//Note: without &, 'auto element' doesn't work, 
		//for (auto& element : students) // value �� �޾ƿ��� ���� ������Ʈ ���� ����
			//element.setIntel(element.getIntel() + 1);



		//for(auto & element : students)
		for (auto element : students)  //�̷��� value �� ���� �͵� �ǰ� & �� ���� �͵� ��
			(*element).setIntel((*element).getIntel() + 1);  //de-referencing ����ϱ�
		//	element->setIntel(element->getIntel()+1);		//-> ����ϱ�
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		/*out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element << std::endl;*/

		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl;  //element �� ����ϸ� �����Ͱ� ��µǴ� de-referencing

		return out;
	}

};