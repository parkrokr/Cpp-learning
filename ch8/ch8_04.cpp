//�������� ��� �̴ϼȶ����� ����Ʈ Member Initializer List

// : ���� �����ϰ� �������� ; ����

#include <iostream>

using namespace std;


//��� �ȿ� �ٸ� user defiend type, �� class �� �� ���
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
	int		m_arr[5]; //c++ 11 ���� array �� �ʱ�ȭ ����
	B		m_b;

	/*�̷��� �ΰ����� �ʱ�ȭ�� �Ѱ��
	int		m_i = 100;
	double	m_d = 100.0;
	char	m_c 'F';
	int		m_arr[5] = {10,20,30,40,50};
	B		m_b{ 1024 };
	��� �ʱ�ȭ ����Ʈ�� ���� �ʱ�ȭ��
	*/
	//non-static member �� ��� ���⼭ �ʱ�ȭ�� ����

public:
	Something()
		//:m_i(1),m_d(3.14),m_c('a') //Member Initializer List
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b(m_i - 1)     //{}�ʱ�ȭ ����ȯ�� ����
	{
		//�� �ȿ��� �� �ٽ� ������ ���ذ� �������� ��
		/*m_i = 2;
		m_d = 6.28;
		m_c = 'b';*/

		m_i *= 3;
		m_d *= 3.0;
		m_c += 3;
	}

	/* �������� �ڵ� ��Ÿ��
	* ������ ������ ������
	: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 },  
		m_b(m_i - 1)

	* ���پ� �����ϰ� ������
	 : m_i{ 1 },
	 m_d{ 3.14 },
	 m_c{ 'a' },
	 m_arr{ 1,2,3,4,5 },  
	 m_b(m_i - 1)


	 * , �� ������ ���� ���پ� �����ϰ� ������,  ����� ������ ������� ����
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