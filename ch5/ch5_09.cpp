// ���� ����� Random Number Generation

// ��ǻ�ʹ� ������ ������ ������ ����
// ����ó�� ���̴� ���ڵ��� ���� �� ����

#include <iostream>
#include <cstdlib>   //std::radn(), std::srand()
#include <ctime>	 //std::time()
#include <random>

using namespace std;

unsigned int PRNG() // Pseudo Random Number Generator // ���� ���� ������
{
	static unsigned int seed = 5523; //seed number // �ٽ� �Լ��� ȣ��Ǿ �ٲ� ���� ����ؾ� �ϱ� ������ static ����

	seed = 825379 * seed + 2396493; //oberflow �̿�

	return seed % 32768; // �ִ�ũ�� ���ڷ� ���缭 ���
}

int getRandomNumber(int min, int max) // ������ ���ؼ� ���� ����
{
	// �ؿ� ���� ������ ���� ���� ����� ���� ����ϴ� �͵� ���� ���
	static const double fraction = 1.0 / (RAND_MAX + 1.0); // /������ ������ ������ static ���� ����

	return min + static_cast<int>( (max - min + 1) * (std::rand() * fraction));
	//								//����
}


int main()
{
	for (int count = 1; count <= 50; ++count)
	{
		cout << PRNG() << "\t";   // \t  �� ���߱�

		if (count % 5 == 0)cout << endl; //���ٿ� 5���� ���
	}

	// std::srand(), std::rand()
	
	//std::srand(5323); // seed ���� ���� ,seed�� �ٲ�� �ٸ� �������� ����, debug ���� ���� ������ ����
	std::srand(static_cast<unsigned int>(std::time(0))); //cpu clock ���� �ð��� ������


	for (int count = 1; count <= 50; ++count)
	{
		cout << std::rand() << "\t";   

		if (count % 5 == 0)cout << endl;
	}

	
	//������ ���ؼ� ���� ����

	for (int count = 1; count <= 10; ++count)
	{
		cout << getRandomNumber(5,8)<< "\t";

		if (count % 5 == 0)cout << endl;
	}

	for (int count = 1; count <= 10; ++count)
	{
		cout << rand() %4 + 5 << "\t"; // rand between 5, 8
		// ���� ��� ��� ������ ū ������ ������ ��� �������� Ư�� �������� ���� �� ����

		if (count % 5 == 0)cout << endl;
	}


	//random library

	std::random_device rd; // time ������ ������ ���
	std::mt19937_64 mersenne(rd());// create a mersenne twister,
	std::uniform_int_distribution<>dice(1, 6); // 1�̻� 6���� �������� ������ Ȯ���� ����

	//mt19937 �� 32bit ������ , mt19937_64�� 64bit ������ ����

	for (int count = 1; count <= 20; ++count)
	{
		cout << dice(mersenne) << endl;
	}

	return 0;
}