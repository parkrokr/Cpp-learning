// �� ������ ( ==, != , > , >= ) �����ε��ϱ�

//std::shuffle �� �����ϱ� ���ؼ� < (less than) �� �����ؾߵ�


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>  //std::shuffle
#include <chrono>	//std::chrono::system_clock

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	// == ������ �����ε� 
	friend bool operator == (const Cents & c1, const Cents & c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}

	//ũ��� ������ �����ε�
	//std::sort �� �����ϱ� ���ؼ� > �� �ƴ� < �� �����ؾ���
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;  // > �� �ٲٸ� �������� ���ĵ�,�������� ���׳��� ������ ���X
	}

};

int main()
{
	int a = 3, b = 3;
	if (a == b)
		cout << "Equal" << endl;


	Cents cents1(6);
	Cents cents2(6);

	if (cents1 == cents2)
		cout << "Equal" << endl;


	//sort 
	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i; //arr[i] = i;

	//shuffle
	std::random_shuffle(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	//C++ 17 ���� std::random_shuffle �� ���(deprecated) �Ǿ���
	//C++ 17 �̻� �����Ϸ������� �Ʒ��� ���� std::shuffle �� ����� �� ����
	
	// . . .  . . .
	//std::random_device rd;
	//std::mt199937 g(rd());
	//std::shuffle(arr.begin(), arr.end(), g);

	//�Ǵ�
	//unsigned seed =
	//std::chrono::system_clock::now().time_science_epoch().count();
	//std::shuffle(begin(arr),end(arr), 
	//std::default_random_engine(seed)));


	//sort
	std::sort(begin(arr), end(arr));  //sort �� �ϱ� ���ؼ� ũ����ϴ� �����ڸ� �����ε� �������(���ϸ� ����)

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;


	return 0;
}