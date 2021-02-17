// 레이스 컨디션 ( Race Condition ) , std::atomic, std::scoped_lock

//muti threading 은 하나의 메모리 공간을 여러 thread 들이 함께 사용하게 해줄 수 있기 때문에
//다른 병렬처리 기법에 비해서 구현하기 편함
//대신 이 장점(같은 메모리 공간을 사용)이 오류가 되어서 문제가 될수도 있음( 레이스 컨디션 )

//현실에선 정상적으로 작동을 하기 때문에 오류가 발생한다는것을 인지하지 못할 수도 있음

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

//공유 메모리를 정수 하나라고 가정
//실제로는 정수 하나뿐만 아니라 더 커지고 자료구조도 복잡해짐
//여러개의 thread 들이 동시에 접근할 수 있다는것을 강조하기 위해 전역으로 선언
//main() 에 있어도 됨, 대신 람다 함수 선언에서 [&] 로 해야됨
//int shared_memory(0);


//레이스 컨디션 해결방법 2: mutex lock() 사용
mutex mtx;

int main()
{
	int shared_memory(0);
	//atomic<int> shared_memory(0);		//레이스 컨디션 해결방법 1: atomic 사용


	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::microseconds(1));	
			//sleep_for 가 없으면 여러개의 thread 들이 한번에 일을 끝내서 문제가 안보일 수도 있음
			//이 sleep_for 가 없으면 문제가 사라지는것이 아니라 문제가 안보이는것임
			//t1 이 생성되고 t2 가 생성되기 전에 연산이 끝나버림 -> 병렬처리가 이루어지지 않음
			//병렬처리의 어려운점중에 하나가 문제를 끄집어내는것(보는것, debut) 자체가 어려울 때가 있음
			

			//mtx.lock();		//해결방법 2: mutex lock 사용, 대신 반드시 unlock() 해야됨

			//std::lock_guard lock(mtx); //해결방법 3
			//c++17 부터 가능, 그 전엔 std::lock_guard<std::mutex> lock(mtx);

			std::scoped_lock lock(mtx);	//해결방법 3_1

			shared_memory++;
			// shared_memory 가 atomic<int> 일때 ++ 는 int 의 연산자가 아니고
			// atomic<int> 의 오버로딩된 연산자임(정의가 따로 되어있음)
			//단점 : int 의 ++ 보단 느려짐
			
			//shared_memory.fetch_add(1);	//++대신에 사용할 수 있음

			//mtx.unlock();		//해결방법 2: lock() 을 사용하는 대신에 unlock을 반드시 해야됨
		}
	};

	thread t1 = thread(count_func);

	thread t2 = thread(count_func);		//t1 과 t2 가 동시에 공유된 메모리에서 작업을 함

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	//1을 1000번 더하니 1000 이 나옴( thread 가 하나일때 )

	//t1 과 t2 가 동시에 공유된 메모리(shared_memory) 에 작업을 하니 2000이 나올것이라고 예상함
	//하지만 2000 이 정확하게 안나옴
	
	//cpu 로 shraed_memory 값을 읽어감 -> cpu 에서 값을 하나 더함 -> 더해진 결과값을 shared_memory 변수에 보내서
	//덮어쓰는 3단계로 이루어짐
	// t1 이 cpu 로 읽어드린 사이에 t2가 값을 바꿔버리고 t1 이 결과 값을 덮어쓰지만 이미 바뀌어있어서
	//더하기 하나가 사라진 꼴


	//해결하는 방법 1:
	//std::atomic, 쪼갤 수 없다 라는 의미, 위의 3단계를 한번에 묶는(나누지 못하게) 변수
	//atomic<int> 를 사용하면 2000 이 정확하게 나옴
	//단점 : int 의 ++ 보단 느려짐, 그래서 atomic을 마구 남발하면 효율이 급격히 떨어짐


	//해결하는 방법 2:
	//mutex lock() 사용, 동시에 여러개의 thread 가 접근 못함, 하나의 thread 만 접근 가능
	//unlock() 을 반드시 해줘야됨
	//프로그래머가 까먹을 수도 있고, 예외처리가 발생할때 건너뛸수도 있음(메모리 반납 안되는 문제처럼)
	

	//해결하는 방법 3:
	//std::lock_guard 사용
	//std::lock_guard lock(mtx); 는 C++17 부터 가능, 그 이전엔 std::lock_guard<std::mutex> lock(mtx);
	//범위를 벗어나는 순간 lock이 자동으로 풀림
	//대부분의 경우 mutex 를 직접 lock 을 거는것보다 lock_guard 사용을 권장

	//해결하는 방법 3_1;
	//std::scoped_lock 사용		C++17 부터 가능
	//lock_guard 보다 더 진보됨, lock_guard 보다 권장


	return 0;
}