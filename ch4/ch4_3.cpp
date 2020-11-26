//Using ���� ��ȣ��(Ambiguity)

#include<iostream>

namespace a
{
	int my_var(10);
	int my_a(123);
	int count(123123);
}

namespace b
{
	int my_var(20);
	int my_b(123);
}


int main()
{
	using namespace std;
	
	// std �ȿ� �ִ� cout, endl �� �������¹��, ������ �̷��� ���ϰ� std�� �� ������
	/*using std::cout;
	using std::endl;*/
	
	//using namespace std::cout; //�߸��� ǥ��

	cout << "Hello" << endl;

	using namespace a;
	using namespace b;


	cout << my_a << endl;
	cout << my_b << endl;

	//cout << my_var << endl; // ���� �̸��� ���� error, "my_var" is ambiguous 
	cout << a::my_var << endl;
	cout << b::my_var << endl;

	// ::�� ���� �ʰ� ������ { }�� �����ֱ�
	/*
	{
		
		using namespace a;

		// ��� �� namspace b �� my_var�� �� �ִٸ� ������ ambiguous �ϱ� ������ error
		cout<< my_var << endl;

		//std�� count�� �ֱ� ������ error, a::count ���
		cout<<count<<endl;
	}

	{
		using namespace b;
		cout << my_var << endl;
	}
	*/


	// namespace�� Ư�� ������� ���������� �ְ� �Ǹ� �� ����� include�ϴ� ��� cpp���Ͽ� ������ �ְ� �ȴ�
	// �������̸� cpp���Ͽ� �ִ°��� ����
	// ����� using namespace�� �ᵵ �Ǳ� ������ ������ ������ �ִ°� ���� �ʴ�


	//�Լ��� �ɰ��ų� using namespace�� �������� ::���,
	//using namespace �� �ѹ� �����ϸ� ����� ����� ����
	//������ { }�� �̿��Ͽ� ���ִ°��� ����
	//typing ȿ�Ｚ ������ �а� ����Ϸ��� ������ ������Ѿ� �� ���� ����


	return 0;
}