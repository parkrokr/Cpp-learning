//형변환을 오버로딩 하기  static_cast  typecast

// 형변환을 오버로딩할땐 return type , parameter 가 없음
//C++ 는 우리가 맞는 tyep 을 return 할것이라고 추측함


#include<iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	}

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents; }

	//int 로 형변환을 오버로딩
	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};


//dollar 를 cents 로 cast
class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int& input) : m_dollars(input){}

	//dollar 를 cents 로 cast
	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};
void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	printInt(cents); //오버로딩 안하면 암시적 형변환이 안됨

	//전부 같음
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	Dollar dol(2);

	Cents dollar_to_cents = dol;

	printInt(dollar_to_cents);

	return 0;
}