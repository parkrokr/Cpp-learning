//이니셜라이저 리스트 std::initializer_list

//initializer list 는 std::array 나 std::vector 와 달리 [] 연산자를 제공하지 않음


#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	//동적할당 받는 구조
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length)//길이만 입력받으면 메모리를 잡아주는 생성자
		: m_length(length)
	{
		cout << "construcetor called " << endl;
		m_data = new int[length];
	}

	//Initializer list 를 prameter 로 받고 있는 생성자
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size()) //다른 생성자를 호출해서 메모리를 받아옴, 중복되는 기능은 쪼개서 한곳에서만 구현되게
	{
		cout << "call by initializer list constructor called " << endl;
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;  //m_data[count++] 하는 C style 도 있지만 분리하면 실수 줄일 수 있음
			++count;
		}

		//for-each 문은 내부적으로 initilizer_list 안에 들어있는 iterator 를 사용하는 구조

		//error, initializer list 는 std::array 나 std::vector 와 달리 [] 연산자를 제공하지 않음
		/*for (unsigned count = 0; count < list.size(); ++count)
			m_data[count] = list[count];*/
	}

	//대입연산자 오버로딩
	IntArray& operator =(const initializer_list<int>& list)
	{
		cout << "assignment operator overloading called " << endl;
		delete[] m_data;

		m_length = list.size();		//m_length 에 넣어주지 않으면 출력 연산자에서 기존 m_length 까지 출력함
		m_data = new int[m_length];
		//m_data = new int[list.size()];
	   

		if (&list != nullptr)
		{
			int count = 0;
			for (auto& element : list)
			{
				m_data[count] = element;
				++count;
			}

			return *this;
		}
		else
			m_data = nullptr;
	}



	~IntArray()
	{
		delete[] this->m_data;
	}

	//출력 연산자 오버로딩
	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for(unsigned i = 0;i<arr.m_length;++i)
			out<<arr.m_data[i]<<" ";
		out << endl;
		return out;
	}
};


int main()
{
	// initializer list { 1,2,3,4,5 }를 통해서 편하게 초기화 가능
	int my_arr[5] = { 1,2,3,4,5 }; //정적할당
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };  //동적할당

	
	auto il = { 10,20,30 };  //auto 가 initilizer_list 로 잡음,include 없으면 에러

	IntArray int_array{ 1,2,3,4,5 };
	//IntArray int_array = { 1,2,3,4,5 };
	cout << int_array << endl;

	int_array = { 5,4,3,2,1,2,3 };
	cout << int_array << endl;

	return 0;
}
