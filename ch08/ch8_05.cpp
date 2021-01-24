//위임 생성자 Delegating Constructors

//생성자가 다른 생성자를 사용함

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int		m_id;
	string	m_name;

public:
	//위임 생성자
	Student(const string& name_in)
		// : m_id(0), m_name(name_in) //매우 비추천
		: Student(0,name_in) //생성자를 가져다씀
	{
		//init(0, name_in);			//초기화함수를 분리
	}

	Student(const int& id_in, const string& name_in)
		:m_id(id_in), m_name(name_in)
	{
		//init(id_in, name_in);		//초기화함수를 분리
	}


	//초기화함수를 분리하는 방법
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}


	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};


int main()
{
	Student st1(0, "jack jack");
	st1.print();

	Student st2("Dash");
	st2.print();

	return 0;
}