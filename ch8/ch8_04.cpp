//생성자의 멤버 이니셜라이져 리스트 Member Initializer List

// : 으로 시작하고 마지막에 ; 없음

#include <iostream>

using namespace std;


//멤버 안에 다른 user defiend type, 즉 class 가 들어갈 경우
class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		: m_b(m_b_in)
	{}

	const int& getter()
	{
		return m_b;
	}
		
	void print()
	{
		cout << m_b << endl;
	}
};


class Something
{
private:
	int		m_i;
	double	m_d;
	char	m_c;
	int		m_arr[5]; //c++ 11 부터 array 도 초기화 가능
	B		m_b;

	/*이렇게 두곳에서 초기화를 한경우
	int		m_i = 100;
	double	m_d = 100.0;
	char	m_c 'F';
	int		m_arr[5] = {10,20,30,40,50};
	B		m_b{ 1024 };
	멤버 초기화 리스트를 따라 초기화됨
	*/
	//non-static member 의 경우 여기서 초기화가 가능

public:
	Something()
		//:m_i(1),m_d(3.14),m_c('a') //Member Initializer List
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b(m_i - 1)     //{}초기화 형변환을 막음
	{
		//이 안에서 또 다시 대입을 해준게 최종값이 됨
		/*m_i = 2;
		m_d = 6.28;
		m_c = 'b';*/

		m_i *= 3;
		m_d *= 3.0;
		m_c += 3;
	}

	/* 여러가지 코딩 스타일
	* 적당한 곳에서 내리기
	: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 },  
		m_b(m_i - 1)

	* 한줄씩 차지하게 내리기
	 : m_i{ 1 },
	 m_d{ 3.14 },
	 m_c{ 'a' },
	 m_arr{ 1,2,3,4,5 },  
	 m_b(m_i - 1)


	 * , 가 밑으로 오게 한줄씩 차지하게 내리기,  멤버에 변동이 많을경우 편함
	 : m_i{ 1 }
	 , m_d{ 3.14 }
	 , m_c{ 'a' }
	 , m_arr{ 1,2,3,4,5 }
	 , m_b(m_i - 1)
	*/

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
		cout << m_b.getter() << endl;
		m_b.print();
	}

};

int main()
{
	Something som;
	som.print();


	return 0;
}