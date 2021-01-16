// 난수 만들기 Random Number Generation

// 컴퓨터는 실제로 난수를 만들지 못함
// 난수처럼 보이는 숫자들은 만들 수 있음

#include <iostream>
#include <cstdlib>   //std::radn(), std::srand()
#include <ctime>	 //std::time()
#include <random>

using namespace std;

unsigned int PRNG() // Pseudo Random Number Generator // 유사 난수 생성기
{
	static unsigned int seed = 5523; //seed number // 다시 함수가 호출되어도 바뀐 값을 출력해야 하기 때문에 static 선언

	seed = 825379 * seed + 2396493; //oberflow 이용

	return seed % 32768; // 최대크기 숫자로 맞춰서 출력
}

int getRandomNumber(int min, int max) // 범위에 대해서 난수 생성
{
	// 밑에 줄을 밖으로 빼서 전역 상수로 만들어서 사용하는 것도 좋은 방법
	static const double fraction = 1.0 / (RAND_MAX + 1.0); // /연산은 느리기 때문에 static 으로 저장

	return min + static_cast<int>( (max - min + 1) * (std::rand() * fraction));
	//								//범위
}


int main()
{
	for (int count = 1; count <= 50; ++count)
	{
		cout << PRNG() << "\t";   // \t  탭 맞추기

		if (count % 5 == 0)cout << endl; //한줄에 5개씩 출력
	}

	// std::srand(), std::rand()
	
	//std::srand(5323); // seed 고정 설정 ,seed를 바꿔야 다른 난수들이 나옴, debug 때는 씨드 고정이 편함
	std::srand(static_cast<unsigned int>(std::time(0))); //cpu clock 에서 시간을 가져옴


	for (int count = 1; count <= 50; ++count)
	{
		cout << std::rand() << "\t";   

		if (count % 5 == 0)cout << endl;
	}

	
	//범위에 대해서 난수 생성

	for (int count = 1; count <= 10; ++count)
	{
		cout << getRandomNumber(5,8)<< "\t";

		if (count % 5 == 0)cout << endl;
	}

	for (int count = 1; count <= 10; ++count)
	{
		cout << rand() %4 + 5 << "\t"; // rand between 5, 8
		// 작은 경우 상관 없으나 큰 범위의 난수인 경우 난수들이 특정 영역으로 몰릴 수 있음

		if (count % 5 == 0)cout << endl;
	}


	//random library

	std::random_device rd; // time 연동과 유사한 기능
	std::mt19937_64 mersenne(rd());// create a mersenne twister,
	std::uniform_int_distribution<>dice(1, 6); // 1이상 6이하 난수들이 동일한 확률로 나옴

	//mt19937 은 32bit 난수를 , mt19937_64는 64bit 난수를 생성

	for (int count = 1; count <= 20; ++count)
	{
		cout << dice(mersenne) << endl;
	}

	return 0;
}
