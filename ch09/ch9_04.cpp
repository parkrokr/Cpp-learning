// 비교 연산자 ( ==, != , > , >= ) 오버로딩하기

//std::shuffle 를 구현하기 위해선 < (less than) 을 구현해야됨


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

	// == 연산자 오버로딩 
	friend bool operator == (const Cents & c1, const Cents & c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}

	//크기비교 연산자 오버로딩
	//std::sort 를 구현하기 위해선 > 가 아닌 < 를 구현해야함
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;  // > 로 바꾸면 역순으로 정렬됨,실전에선 버그날수 있으니 사용X
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

	//C++ 17 에서 std::random_shuffle 이 폐기(deprecated) 되었슴
	//C++ 17 이상 컴파일러에서는 아래와 같이 std::shuffle 를 사용할 수 있음
	
	// . . .  . . .
	//std::random_device rd;
	//std::mt199937 g(rd());
	//std::shuffle(arr.begin(), arr.end(), g);

	//또는
	//unsigned seed =
	//std::chrono::system_clock::now().time_science_epoch().count();
	//std::shuffle(begin(arr),end(arr), 
	//std::default_random_engine(seed)));


	//sort
	std::sort(begin(arr), end(arr));  //sort 를 하기 위해서 크기비교하는 연산자를 오버로딩 해줘야함(안하면 에러)

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;


	return 0;
}