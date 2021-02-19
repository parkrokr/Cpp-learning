//��Ƽ������ ���� (���� ���� ���)


//��Ƽ�������� �Ҷ��� �� thread ���� ���� ������ �ְ� ���� �ʰ� ���� �۾��� �ϰ� 
//���� ����� �����ͼ� �����ϴ°��� ���� ����

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>		//std::inner_product
#include <execution>	//parallel execution

using namespace std;

mutex mtx;	//mutex �� �� ���������� �ʿ�� ����, thread ���� ���������� ������ �� �ִ� scope ���� ������ ��
			//�׻� mutex �� ������� �ʿ䵵 ����, lock guard �� �۵��ϰ� ���� ���� ��������� ��
			//class �� ����� �ְų� scope �� ������ ��


void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];

	//��ü 1�ﰳ �߿��� ��� ������ ������� ���ϱ� ���� i_start, i_end ���
}


void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	//lock �� ��� �Ŵ����� �߿���
	//lock �� �Ŵ� �κ��� �������� �����ս��� �ö�

	std::scoped_lock lock(mtx);

	//cout<< "Thread start " << endl;
	for (unsigned i = i_start; i < i_end; ++i)
	{
		//std::scoped_lock lock(mtx);	//c++17, ������������ lock_guard ���
		
		//mutex �� �� ���������� �ʿ�� ����, thread ���� ���������� ������ �� �ִ� scope ���� ������ ��
		//�׻� mutex �� ������� �ʿ䵵 ����, lock guard �� �۵��ϰ� ���� ���� ��������� ��
		//class �� ����� �ְų� scope �� ������ ��

		sum += v0[i] * v1[i];
	}
	//cout<<"Thread end " << endl;
}


void dotProductAtomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
	{
		sum += v0[i] * v1[i];
	}
}
//sum �� �޾ƿö� atomic<unsigned long long> ��



auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	int sum = 0;	//local sum

	//��Ƽ�������� �Ҷ��� �� thread ���� ���� ������ �ְ� ���� �ʰ� ���� �۾��� �ϰ� 
	//���� ����� �����ͼ� �����ϴ°��� ���� ����

	for (unsigned i = i_start; i < i_end; ++i)
	{
		sum += v0[i] * v1[i];
	}

	return sum;
}





int main()
{
	//���� inner product
	/*
	v0 = {1,2,3}
	v1 = {4,5,6}
	v0_dot_v1 = 1*4 + 2*5 + 3*6;
	*/


	const long long n_data = 100'000'000;
	const unsigned n_threads =5;			//thread ������ ���� ��Ƽ������ ȿ���� �޶���, �� ������� ����

	//initialize vector
	//vector v0 �� v1 �� 1~10�� ������ 1�ﰳ�� ������ ����
	std::vector<int> v0, v1;
	v0.reserve(n_data);		//pushback() �� ȿ���� ������ ����
	v1.reserve(n_data);

	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);		//1~10 �� ���Ժ����� ������ �ɱ�, ���ڰ� �ʹ� Ŀ���� ������� �ʹ� Ŀ��

	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}



	//����
	//std::inner_product �� ����� ���� ���ϱ�
	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		//�ι�° vector �� begin() �� ������ ��, ������ ���ٰ� �����ϱ� ����
		//sum �� unsigned long long ���� ������ ������ 0�� 0ull(unsingned long long) ���� �־��༭
		//0���� ������ int �� ������ �����÷ο찡 �߻��� ���� ����

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;			
		cout << endl;

		//sum �� vector �� random �� ������� ������ �׶��׶� �ٸ�
		//��Ƽ�������� ����� �Ǽ��� ������� ����� �ٸ��� ���� �� ����
		//����ó���� �Ҷ��� ������ ����ϰ�, ����� ������� ���ϰ� �����ս��� ���ؾߵ�
	}


	//����ó��
	//thread �� n_threads �� ���ڸ�ŭ ���帯 ���� vector �� ����
	cout << "Naive" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	//������ thread �� ���� ������, 
		//������ ������ ���� assumes remainder = 0, �������� ���� ���� ����� thread �� �߰��� ��Ű�� ��

		for(unsigned t = 0;t<n_threads;++t)
			threads[t] = std::thread(dotProductNaive, std::ref(v0),std::ref(v1),
			t* n_per_thread, (t + 1)* n_per_thread, std::ref(sum));

		//v0, v1 �� reference �� �Ѿ�� std::ref() �� ���
		//t* n_per_thread, (t + 1)* n_per_thread �� ���� thread �� ó���ϴ� ����


		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	/*std::inner_product
	0.0426168
	3025104183

	Naive
	0.590383
	897324127*/
	//�ϴ� �����Ű�� �ð��� �� ������ ���� Ʋ��
	//sum �� thread ���� ���ÿ� �ǵ���� ���� �߻�(���̽� �����)
	
	//�ذ� ��� 2����
	//1: lockguard ���
	cout << "LockGuard" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		//dotProductNaive ��ſ� dotProductLock ���

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	//lock guard �� for �� �ȿ� ������
	/*std::inner_product
	0.0426168
	3025104183

	LockGuard
	2.38702
	3025104183*/
	//����� �¾����� �ӵ��� �� ������, ����ó���� �ϴ� �ǹ̰� ����

	// lock guard �� for �� �ۿ� ������
	/*std::inner_product
	0.0416433
	3025046725

	Naive
	0.492644
	785485953

	LockGuard
	0.111453
	3025046725*/
	//���� �� ������ �ð��� ����
	//lock �� for �� �ۿ� �־ scope �� dotProductLock() ��ü�� ��ü�� lock �� �ɷ� �����δ�
	//����(������) �� �ƴ϶� ���������� ����Ȱ���, thread ���� ���������� ����ǰ� ������ thread�� �����ϴ� ������常 Ŀ��
	//�̷� ������� lock �� �ɾ��ִ°��� �ǹ̰� ����

	//scope lock �� ���� ������ ���°��� ������ �ʹ� ����ϰ� ���� ������ �Ǿ������ ������ ��������
	//���ϴ��ϸ� ���� ����� ����

	//lock �� �ɾ��ָ� ����� �߳������� �����ս��� ������ ������ ���� ����


	//��Ƽ�������� ó�� �õ��ϴ� ��� ������ �����ս��� �������ų� ����� �ٸ��� ���� ���� ����
	//��쿡 ���� ������ �޶���


	//�ذ� ��� 2:
	//atomic ���
	cout << "atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		//dotProductAtomic

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	//lock guard �ɾ��ִ°Ϳ� ���� ������ ������
	/*std::inner_product
	0.0450711
	3024866372

	atomic
	1.74685
	3024866372*/
	//����� �� �������� ����
	//atomic �� ���� �������� �������� ������ �����ε��� ����ϰ� �Ͼ�� �ְ�, atomic �� ���ϱ� ������
	//�Ϲ� int �� int ���꺸�� ������ ������ �����ս��� ������

	//�̷��� ����ϰ� ȣ��Ǵ°��� atomic �� ���� ������

	//����� ��Ȯ������ ����

	

	//�ذ� ��� 3:
	//task based  parallelism	future ���
	
	cout << "future" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::future<int>> futures;		//ull �� �ƴ� ����: �κ��� ���� int ���� �ȿ� ����
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);


		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();
		//��Ƽ�������� �Ҷ��� �� thread ���� ���� ������ �ְ� ���� �ʰ� ���� �۾��� �ϰ� 
		//���� ����� �����ͼ� �����ϴ°��� ���� ����
		//��� ������ ���� �����忡�� �ص� �����ս� ���ϰ� ����

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	//���� ��ü�� �޶���, ���� ������ sum �̶�� global ������ �ΰ� ���� thread �� �޷��� ���� ���ϴ� ����̾���
	//���⼭�� �� thread �� local sum �� ���ϰ� ����� �����ͼ� ������

	//thread ���� �̷��� ���ϴ� ����: thread �� ���� dotProductLock, dotProductAtomic ���� �Լ�����
	//���� return �� ����

	/*std::inner_product
	0.0434677
	3024655284

	future
	0.0253126
	3024655284*/
	//����� ��Ȯ�ϰ� �ӵ��� ������

	//thread �� 4 �� ����ϴµ� 1/4 ���� ���� �� �ɸ�
	


	//future �� ���°��� ������ ���ٰ� ���� �� ������ �� �׷����� ����
	//TODO: use diveide and conquer(3�� ���) strategy for std::thread
	//TODO: use promise 
	//TODO: use atomic



	//�����ϴ� ������ ����ó�� �ϱ� ���� ������
	//�����ϴ� ���̺귯�� std::transform_reduce �� C++17 �� ����
	//std::sort �� ���� ó���� ��������, ������ ������ ������ �� �� ����
	//��� std �� ��� ������ ���� ó�������� ����
	//����ó�� ������ ������ �߻��� ������ �и��� ����
	cout << "std::transform_reduce" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		//const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	//std::inner_product �� ������ ���� ���������� std::execution::par�̶�� ������ flag �� �ϳ� ��
	//parall �� par ��, �񵿱������� �����޶� �� �ǹ�
	//std::execution::seq �� ������ ���������� ������, std::inner_product �� �����ս��� ���� �������
	//future ���� ��¦ ������

	return 0;
}