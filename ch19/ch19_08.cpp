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


};

int main()
{
	Examples examples;
	
	examples.ex1();


	return 0;
}