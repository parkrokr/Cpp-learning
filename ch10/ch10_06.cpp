//컨테이너 클래스 Container Class

//다른 class 를 담는 class 

//다양한 컨테이너가 존재함
//STL ( Standard Container Library )

//컨테이너들은 ~가 ~의 멤버다, member-of 관계를 가짐


#include <iostream>
#include <vector>
#include <array>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	int m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(const int& length = 0)
		:m_length(length)
	{
		m_data = new int[length];
	}

	
	~IntArray()
	{
		delete[] this->m_data;
		m_data = nullptr;
	}

	
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	
	void reset()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}		
	}

	
	IntArray& resize(int new_length)
	{
		if (new_length == m_length)return *this;
		else if (new_length > m_length)
		{
			
			/*int* temp = new int[new_length];
			for (int i = 0; i < m_length; ++i)
			{
				temp[i] = m_data[i];
			}
			
			for (int i = m_length; i < new_length; ++i)
				temp[i] = 0;
			
			m_length = new_length;
			
			m_data = temp;*/


			IntArray temp;
			temp = *this;
			
			delete[] m_data;
			//reset();
			m_length = new_length;
			m_data = new int[new_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = temp.m_data[i];
			
			for (int i = m_length; i < new_length; ++i)
				m_data[i] = 0;

			
			return *this;
		}
		else
		{
			int* temp = new int[new_length];
			
			for (int i = 0; i < new_length; ++i)
			{
				temp[i] = m_data[i];
			}

			m_length = new_length;
				
			m_data = temp;

			return *this;		
		}


	}

	IntArray& operator = (const IntArray& arr)
	{
		if (this == &arr)
		{
			return *this;
		}
		else
		{
			delete[] m_data;
			m_length = arr.m_length;
			if (arr.m_data != nullptr)
			{
				m_data = new int[m_length];
				for (int i = 0; i < m_length; ++i)
				{
					m_data[i] = arr.m_data[i];
				}
			}
			else
				m_data = nullptr;

			return *this;
		}
	}

	friend ostream& operator << (ostream &out,const IntArray& arr)
	{
		for (int i = 0; i < arr.m_length; ++i)
		{
			out << arr.m_data[i] << " ";
		}		
		return out;
	}

	
	IntArray& insertBefore(const int &value, const int& ix)
	{
		resize(m_length + 1);
		
		for (int i =m_length-1; i>ix; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[ix] = value;
		
		return *this;
	}

	
	IntArray& remove(const int & ix)
	{
		for (int i = ix; i < m_length - 1; i++)
		{
			m_data[i] = m_data[i + 1];
		}
		resize(m_length - 1);
		
		return *this;
	}

	
	IntArray& push_back(const int& value)
	{
		resize(m_length + 1);
		m_data[m_length -1] = value;

		return *this;
	}
};


int main()
{

	//std::vector<int> int_vec;		//int 가 vector 에 담겨있음
	//std::array<int, 10> int_arr;	//int 가 array 에 담겨있음


	//IntArray 구현
	IntArray my_arr{ 1, 3, 5, 7, 9 };
	cout << my_arr << endl;

	my_arr.insertBefore(10, 1);			//1, 10, 3, 5, 7, 9
	cout << my_arr << endl;

	my_arr.remove(3);					//1, 10, 3, 7, 9
	cout << my_arr << endl;

	my_arr.push_back(13);				//1, 10, 3, 7, 9, 13
	cout << my_arr << endl;
	
	return 0;
}