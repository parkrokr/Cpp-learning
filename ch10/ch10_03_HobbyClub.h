#pragma once

#include<vector>
#include "ch10_03_Student.h"
#include "ch10_03_Teacher.h"

class HobbyClub
{
private:
	std::string m_name;

	std::vector<Student*> students;
	

public:
	HobbyClub(const std::string& name_in = "No Name")
		:m_name(name_in)
	{}


	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}


	void play()
	{
		std::cout << m_name << " play " << std::endl << std::endl;

		for (auto element : students)
			(*element).setHappy((*element).getHappy() + 1);
		
	}

	friend std::ostream& operator << (std::ostream& out, const HobbyClub& excercise)
	{
		out << "Excercise name : " << excercise.m_name << std::endl;

		for (auto element : excercise.students)
			out << *element << std::endl;  
		return out;
	}

};