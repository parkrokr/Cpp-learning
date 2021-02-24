//�ڷ��� �߷� (Type Inference)  auto �� decltype

#include <iostream>
#include <vector>
#include <algorithm>	//std::min

//Referecne : http://thbecker.net/articles/auto_and_decltype/section_01.html

using namespace std;

class Examples
{
public:

	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr = vect.begin(); itr != vect.end(); itr++)
			cout << *itr;

		for (auto itr : vect)	//for (const auto & itr : vect)
			cout << itr;
	}

	void ex2()
	{
		int x = int();

		auto auto_x = x;	//int �� ����


		const int& crx = x;

		auto auto_crx1 = crx;	//crx �� const int & ������ auto �� const, reference �� ��� int �� ����

		const auto& auto_crx2 = crx;	//const int & �� ���� ������ auto ��ü�� const, reference �� ����


		volatile int vx = 1024;		//volatile �� ���� ���� ���ϴ� ����ȭ �Ҷ� ���޶� ��� �ǹ�
		//multi threading �� �Ҷ� ����� �� ���� 

		auto avx = vx;	//volatile �������� int �� ����

		volatile auto vavx = vx;	//volatile ���� ����ϰ� ������ voliatile auto ���


		//auto �� ���� �⺻���� �ڷ���(ex int) �� �߷����ְ� ������ ���ľ�(const, reference, volitile ) �� ������
		//����ڰ� �߰��ϰ� ������ �߰������ ��
	}


	template<class T>
	void func_ex3(T arg)
	{}

	/*template<class T>
	void func_ex3(const T& arg)
	{}*/

	void ex3()
	{
		const int& crx = 123;
		 
		func_ex3(crx);	//const �� & �� ���� int �� ����

		//const int reference �� �ְ� ������  void func_ex3(const T& arg) ���
	}

	
	void ex4()
	{
		const int c = 0;
		auto& rc = c;		//rc �� const int reference

		//rc = 123; �� �õ��ϸ� compile error �� �߻�

		//reference �� �޾ƿ��µ� c �� const �̱� ������ �޴� rc �� const ������, auto �� �� �߷��� ����
	}


	void ex5() //amendament(����, ����)
	{
		int i = 42;
		auto&& ri_1 = i;	// l value (amendament(����, ����))
		auto&& ri_2 = 42;	// r value

		//auto&&�� r vlaue reference �� �����ϰ� �ʹٴ� �ǵ�, l value �� ������ & �� �ٲ�
		//r value �� ������ &&(r value reference) �� ����
	}


	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;		//p2 �� const int * �� �� ����

		//auto �� �����͵� �������� const �� ������, auto �� �ݵ�� �ʿ��� ��� (������ ������� ��)
		//*p2 = 43; const �� error
	}






};

int main()
{
	Examples examples;
	
	examples.ex1();


	return 0;
}