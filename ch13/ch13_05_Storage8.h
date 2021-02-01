#pragma once

template <class T>
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T& value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}

};


//bool 에 대하여 specialization
//bool 에는 true false 만 있기 때문에 1bit 만 가지고도 데이터를 표현할 수 있음
//하지만 메모리 주소의 체계가 1 byte 단위로(8 bit) 할당이 됨
//그래서 8개의 bool type 을 동시에 처리한다면 1byte 만 가지고도 처리가 가능함

template<>
class Storage8<bool>
{
private:
	unsigned char m_data;	//1 byte

public:
	Storage8() : m_data(0)
	{

	}
	
	//bit mask
	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value)
			m_data |= mask;
		else
			m_data &= ~mask;
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		return(m_data & mask) != 0;
	}

};