//���� �ð� �����ϱ�

//sorting �ϴµ� �ɸ��� �ð��� ����
//���� ������ �Ҷ� �����ϴ� ���� �ð��� �����ϰ� �������� Debug ��尡 �ƴ϶� Release ���� �ؾߵ�

//���α׷��� ���� �ð��� �ſ� ���� ��ҵ鿡 ������ �ޱ� ������ ����ȭ�� ����� ���̴�
//�ð��� ��� 3���� �����غ�����


#include<iostream>
#include<vector>
#include<algorithm> //to use sort
#include<random>
#include<chrono>	//�ð� ���ִ� library

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now(); 
	//Timer �� ��������� �ð��� clock_t::now()�� ������ start_time �̶�� member variable �� �ʱ�ȭ

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();
		//elapsed() �� ȣ���� �Ǹ� ����ð��� end_time �� �־���

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
		//end_time ���� start_time �� ���� '��' �� �ٲ㼭 ���
	}

};

int main()
{
	random_device rnd_device; //�õ尪 ����
	mt19937 mersenne_engine{ rnd_device() }; //�õ尪 ����


	vector<int> vec(10);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;


	std::shuffle(begin(vec), end(vec), mersenne_engine); //������ ������

	for (auto& e : vec)cout << e << " ";
	cout << endl;


	Timer timer;  //�ð� ���� ����

	std::sort(begin(vec), end(vec));  //sort

	timer.elapsed();  //������ �ð� ���


	//sort�� �� �Ǿ��� ��� Ȯ��
	for (auto& e : vec)cout << e << " ";
	cout << endl;




	//10���� �ʹ� �۾Ƽ� �ð� �����ϴ� �ǹ̰� ���� ����
	vector<int> vec2(100000);

	std::shuffle(begin(vec2), end(vec2), mersenne_engine);

	Timer timer2;  

	std::sort(begin(vec2), end(vec2)); 

	timer2.elapsed();

	return 0;
}