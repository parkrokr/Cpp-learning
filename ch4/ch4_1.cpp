// ���� ������ ����(Scope)�� ���ӱⰣ(Duration)
//���(���չ�), ��Ī ����, �̸� �浹, �̸� �����

#include<iostream>

//�Լ��� ����� ���ǰ� �и��� �� �ֱ� ������ ������ �������� �����ص� ������ ���Ǵ� �ѹ��� �־����
// paremeter �� �ٸ� ��� �ٸ� �Լ��� ����ϱ� ������ �浹�� �Ͼ�� ����
// �浹�� ���ϱ� ���� namespace�� �����
// namespace �ȿ� namespace �� �� ����� �� ����

namespace work1
{
	int a = 1;
	void doSomething() 
	{
		a += 3;
	}
}

namespace work2
{
	int a = 1;
	void doSomething()
	{
		a += 5;
	}
}


// { } ������ �δ� ��� ��ſ� c++ 17���� ��� ������ ����, Properties\C/C++\Language ���� c++17�� �÷������
namespace work11::work111::work1111
{
	int a = 1;
	void doSomething()
	{
		a += 3;
	}
}

int main()
{
	using namespace std;

	int apple = 5;
	
	cout << apple << endl;


	//�������� ���α׷��ֿ����� ��������� ������ duration�� ���̷��� ��

	// { } �� ���ؼ� ����� ����
	{	
		// �� ū �������� ����� ������ �ȿ� �ִ� �������� ������ �ְ� ����� ���� ����

		int apple = 1;// ����� ������ ���� �����, �̸��� ������ ���� ������ �ٸ�, �׷��� ������ �̸� �ٸ��� ����
		cout << apple << endl;
	}

	cout << apple << endl;

	
	
	// :: ����, ���� ���� ������  scope resolution operator

	work1::a;
	work1::doSomething();

	work2::a;
	work2::doSomething();

	// c++ 17���� ��� ������ ����, Properties\C/C++\Language ���� c++17�� �÷������
	work11::work111::work1111::doSomething();

	return 0;
}

//apple = 1; �޸𸮰� �ݳ��Ǿ �� ���� ����
