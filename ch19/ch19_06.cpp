//멀티쓰레딩 예제 (벡터 내적 계산)


//멀티쓰레딩을 할때는 각 thread 들이 서로 영향을 주고 받지 않고 각자 작업을 하고 
//끝낸 결과만 가져와서 취합하는것이 가장 좋음

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

mutex mtx;	//mutex 가 꼭 전역변수일 필요는 없음, thread 들이 공통적으로 접근할 수 있는 scope 에만 있으면 됨
			//항상 mutex 가 살아있을 필요도 없음, lock guard 가 작동하고 싶을 때만 살아있으면 됨
			//class 의 멤버로 넣거나 scope 에 있으면 됨


void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];

	//전체 1억개 중에서 어느 부위를 계산할지 정하기 위해 i_start, i_end 사용
}


void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	//lock 을 어디에 거는지도 중요함
	//lock 을 거는 부분이 적을수록 퍼포먼스가 올라감

	std::scoped_lock lock(mtx);

	//cout<< "Thread start " << endl;
	for (unsigned i = i_start; i < i_end; ++i)
	{
		//std::scoped_lock lock(mtx);	//c++17, 이전버전에선 lock_guard 사용
		
		//mutex 가 꼭 전역변수일 필요는 없음, thread 들이 공통적으로 접근할 수 있는 scope 에만 있으면 됨
		//항상 mutex 가 살아있을 필요도 없음, lock guard 가 작동하고 싶을 때만 살아있으면 됨
		//class 의 멤버로 넣거나 scope 에 있으면 됨

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
//sum 을 받아올때 atomic<unsigned long long> 임



auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	int sum = 0;	//local sum

	//멀티쓰레딩을 할때는 각 thread 들이 서로 영향을 주고 받지 않고 각자 작업을 하고 
	//끝낸 결과만 가져와서 취합하는것이 가장 좋음

	for (unsigned i = i_start; i < i_end; ++i)
	{
		sum += v0[i] * v1[i];
	}

	return sum;
}




void dotProductLockthread(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long & sum)
{
	//std::scoped_lock lock(mtx);
	unsigned long long local_sum = 0;

	for (unsigned i = i_start; i < i_end; ++i)
	{
		//std::scoped_lock lock(mtx);

		local_sum += v0[i] * v1[i];
	}

	{
		std::scoped_lock lock(mtx);
		sum += local_sum;
	}
}


void dotProductpromise(std::promise<int>&& prom, const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	int sum = 0;	//local sum

	for (unsigned i = i_start; i < i_end; ++i)
	{
		sum += v0[i] * v1[i];
	}

	prom.set_value(sum);
}


void dotProductLockatomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
	int local_sum = 0;

	for (unsigned i = i_start; i < i_end; ++i)
	{
		local_sum += v0[i] * v1[i];
	}
	sum += local_sum;
}


int main()
{
	//내적 inner product
	/*
	v0 = {1,2,3}
	v1 = {4,5,6}
	v0_dot_v1 = 1*4 + 2*5 + 3*6;
	*/


	const long long n_data = 100'000'000;
	const unsigned n_threads =4;			//thread 개수에 따라 멀티쓰레딩 효율이 달라짐, 단 비례하진 않음

	//initialize vector
	//vector v0 와 v1 을 1~10의 정수로 1억개의 난수로 만듦
	std::vector<int> v0, v1;
	v0.reserve(n_data);		//pushback() 의 효율을 높히기 위해
	v1.reserve(n_data);

	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);		//1~10 의 정규본포로 제약을 걸기, 숫자가 너무 커지면 결과값이 너무 커짐

	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}



	//내적
	//std::inner_product 를 사용해 정답 구하기
	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		//두번째 vector 는 begin() 만 있으면 됨, 개수가 같다고 가정하기 때문
		//sum 이 unsigned long long 으로 잡히는 이유는 0을 0ull(unsingned long long) 으로 넣어줘서
		//0으로 넣으면 int 로 잡혀서 오버플로우가 발생할 수도 있음

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;			
		cout << endl;

		//sum 은 vector 가 random 을 만들었기 때문에 그때그때 다름
		//멀티쓰레딩은 사소한 실수로 결과값이 정답과 다르게 나올 수 있음
		//병렬처리를 할때는 정답을 계산하고, 정답과 계산결과를 비교하고 퍼포먼스를 비교해야됨
	}


	//병렬처리
	//thread 를 n_threads 의 숫자만큼 만드릭 위해 vector 로 만듦
	cout << "Naive" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	//각각의 thread 에 일을 나눠줌, 
		//간단한 예제를 위해 assumes remainder = 0, 실전에선 남은 일을 몇몇의 thread 에 추가로 시키면 됨

		for(unsigned t = 0;t<n_threads;++t)
			threads[t] = std::thread(dotProductNaive, std::ref(v0),std::ref(v1),
			t* n_per_thread, (t + 1)* n_per_thread, std::ref(sum));

		//v0, v1 이 reference 로 넘어가니 std::ref() 로 명시
		//t* n_per_thread, (t + 1)* n_per_thread 는 각각 thread 가 처리하는 범위


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
	//일단 실행시키면 시간도 더 덜리고 ㈄ 틀림
	//sum 을 thread 들이 동시에 건드려서 에러 발생(레이스 컨디션)
	
	//해결 방법 2가지
	//1: lockguard 사용
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

		//dotProductNaive 대신에 dotProductLock 사용

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	//lock guard 가 for 문 안에 있을때
	/*std::inner_product
	0.0426168
	3025104183

	LockGuard
	2.38702
	3025104183*/
	//결과는 맞았지만 속도가 더 느려짐, 병렬처리를 하는 의미가 없음

	// lock guard 가 for 문 밖에 있을때
	/*std::inner_product
	0.0416433
	3025046725

	Naive
	0.492644
	785485953

	LockGuard
	0.111453
	3025046725*/
	//닶도 잘 나오고 시간도 줄음
	//lock 이 for 문 밖에 있어서 scope 가 dotProductLock() 전체라서 전체가 lock 이 걸려 실제로는
	//병렬(동시적) 이 아니라 순차적으로 실행된것임, thread 들이 순차적으로 실행되고 오히려 thread를 생성하는 오버헤드만 커짐
	//이런 방식으로 lock 을 걸어주는것은 의미가 없음

	//scope lock 은 작은 영역에 들어가는것이 좋지만 너무 빈번하게 자주 실행이 되어버려서 오히려 느려진것
	//안하느니만 못한 결과가 나옴

	//lock 을 걸어주면 결과는 잘나왔지만 퍼포먼스가 오히려 떨어질 수도 있음


	//멀티쓰레딩을 처음 시도하는 경우 오히려 퍼포먼스가 떨어지거나 결과가 다르게 나올 수가 있음
	//경우에 따라 현상은 달라짐


	//해결 방법 2:
	//atomic 사용
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
	//lock guard 걸어주는것에 비해 구현이 간단함
	/*std::inner_product
	0.0450711
	3024866372

	atomic
	1.74685
	3024866372*/
	//결과는 잘 나왔지만 느림
	//atomic 도 지금 예제에서 더해지는 연산자 오버로딩이 빈번하게 일어나고 있고, atomic 의 더하기 연산이
	//일반 int 의 int 연산보단 느리기 때문에 퍼포먼스가 떨어짐

	//이렇게 빈번하게 호출되는곳에 atomic 을 쓰면 느려짐

	//결과는 정확하지만 느림

	

	//해결 방법 3:
	//task based  parallelism	future 사용
	
	cout << "future" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::future<int>> futures;		//ull 이 아닌 이유: 부분의 합은 int 범위 안에 들어옴
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);


		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();
		//멀티쓰레딩을 할때는 각 thread 들이 서로 영향을 주고 받지 않고 각자 작업을 하고 
		//끝낸 결과만 가져와서 취합하는것이 가장 좋음
		//결과 추합은 단일 쓰레드에서 해도 퍼포먼스 저하가 없음

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	//전략 자체가 달라짐, 기존 예제는 sum 이라는 global 변수를 두고 여러 thread 가 달려들어서 값을 더하는 방식이었고
	//여기서는 각 thread 가 local sum 을 구하고 결과만 가져와서 추합함

	//thread 에서 이렇게 못하는 이유: thread 에 들어가는 dotProductLock, dotProductAtomic 같은 함수들은
	//값을 return 을 못함

	/*std::inner_product
	0.0434677
	3024655284

	future
	0.0253126
	3024655284*/
	//결과도 정확하고 속도도 빨라짐

	//thread 가 4 개 사용하는데 1/4 보단 조금 더 걸림
	


	//future 를 쓰는것이 무조건 좋다고 느낄 순 있으나 꼭 그렇지도 않음
	//diveide and conquer 방법을 이용하여 std::thread 를 이용하여 구현, atomic 을 이용하여 구현, promise 를 사용하여 구현
	/*
	std::inner_product
	0.0469466
	3025131035

	Naive
	0.606177
	947775124

	LockGuard
	0.114757
	3025131035

	atomic
	1.88939
	3025131035
	
	future
	0.0272816
	3025131035

	divide and conquer using std::thread
	0.0280988
	3025131035

	divide and conquer usingpromise
	0.02556
	3025131035

	divide and conquer using atomic
	0.0252057
	3025131035

	std::transform_reduce
	0.027207
	3025131035
	*/

	
	//TODO: use diveide and conquer(3번 방법) strategy for std::thread
	cout << "divide and conquer using std::thread" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		//unsigned long long sum = 0;

		vector<thread> threads;
		unsigned long long sum = 0;
		//unsigned long long result(0);

		threads.resize(n_threads);
		//sum.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductLockthread, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread,std::ref(sum));


		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t].join();
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	/* 
	std::inner_product
	0.0431377
	3025054551

	divide and conquer using std::thread
	0.0259145
	3025054551
	*/
	

	//TODO: use promise 
	cout << "divide and conquer usingpromise" << endl;
	{
		const auto sta = chrono::steady_clock::now();


		unsigned long long sum = 0;

		vector<std::promise<int>> prom;
		prom.resize(n_threads);

		vector<std::future<int>> futures;		
		futures.resize(n_threads);

		vector<thread> threads;
		threads.resize(n_threads);

		for (unsigned t = 0; t < n_threads; ++t)
		{
			futures[t] = prom[t].get_future();
		}

		const unsigned n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductpromise,std::move(prom[t]), std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);


		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t].join();
			sum += futures[t].get();
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
		
	}
	/*std::inner_product
	0.04523
	3025121175

	divide and conquer using promise
	0.030376
	3025121175*/
	//std::inner_product 보다 빠르고 std::transform_reduce 보단 느림


	//TODO: use atomic
	cout << "divide and conquer using atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		vector<thread> threads;
		atomic<unsigned long long>sum = 0;

		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductLockatomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));


		for (unsigned t = 0; t < n_threads; ++t)
		{
			threads[t].join();
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	/*
	std::inner_product
	0.0500797
	3024817682

	divide and conquer using atomic
	0.0256886
	3024817682
	*/







	//내적하는 예제가 병렬처리 하기 쉬운 예제임
	//내적하는 라이브러리 std::transform_reduce 가 C++17 에 있음
	//std::sort 도 병렬 처리를 지원해줌, 간단한 연산은 가져다 쓸 수 있음
	//대신 std 가 모든 문제를 병렬 처리해주진 않음
	//병렬처리 했을때 문제가 발생할 여지는 분명히 있음
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
	//std::inner_product 의 사용법과 거의 유사하지만 std::execution::par이라는 일종의 flag 가 하나 들어감
	//parall 의 par 임, 비동기적으로 돌려달라 란 의미
	//std::execution::seq 로 넣으면 순차적으로 실행함, std::inner_product 랑 퍼포먼스가 거의 비슷해짐
	//future 보단 살짝 빨라짐

	return 0;
}
