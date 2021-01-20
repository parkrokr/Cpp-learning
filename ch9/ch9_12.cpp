//�̴ϼȶ����� ����Ʈ std::initializer_list

//initializer list �� std::array �� std::vector �� �޸� [] �����ڸ� �������� ����


#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	//�����Ҵ� �޴� ����
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length)//���̸� �Է¹����� �޸𸮸� ����ִ� ������
		: m_length(length)
	{
		cout << "construcetor called " << endl;
		m_data = new int[length];
	}

	//Initializer list �� prameter �� �ް� �ִ� ������
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size()) //�ٸ� �����ڸ� ȣ���ؼ� �޸𸮸� �޾ƿ�, �ߺ��Ǵ� ����� �ɰ��� �Ѱ������� �����ǰ�
	{
		cout << "call by initializer list constructor called " << endl;
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;  //m_data[count++] �ϴ� C style �� ������ �и��ϸ� �Ǽ� ���� �� ����
			++count;
		}

		//for-each ���� ���������� initilizer_list �ȿ� ����ִ� iterator �� ����ϴ� ����

		//error, initializer list �� std::array �� std::vector �� �޸� [] �����ڸ� �������� ����
		/*for (unsigned count = 0; count < list.size(); ++count)
			m_data[count] = list[count];*/
	}

	//���Կ����� �����ε�
	IntArray& operator =(const initializer_list<int>& list)
	{
		cout << "assignment operator overloading called " << endl;
		delete[] m_data;

		m_length = list.size();		//m_length �� �־����� ������ ��� �����ڿ��� ���� m_length ���� �����
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

	//��� ������ �����ε�
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
	// initializer list { 1,2,3,4,5 }�� ���ؼ� ���ϰ� �ʱ�ȭ ����
	int my_arr[5] = { 1,2,3,4,5 }; //�����Ҵ�
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };  //�����Ҵ�

	
	auto il = { 10,20,30 };  //auto �� initilizer_list �� ����,include ������ ����

	IntArray int_array{ 1,2,3,4,5 };
	//IntArray int_array = { 1,2,3,4,5 };
	cout << int_array << endl;

	int_array = { 5,4,3,2,1,2,3 };
	cout << int_array << endl;

	return 0;
}