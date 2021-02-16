//std::thread 와 멀티쓰레딩( multithreading ) 의 기초

//요즘의 cpu 들은 거의다 multi-core 임, 우리가 교과서에서 배우는 프로그래밍 기술들은 단일코어를 기준으로
//하나의 프로세서에서 순차적을 작업하는것 위주임
//C++11 부터 도입된 std::thread 를 이용한 멀티쓰레딩의 기초

//Process : os 가 우리가 작성한 프로램을 실행시킬때 관리하는 단위
//하나의 process 가 여러개의 thread 들을 관리할 수 있음

//multi processing 은 하나의 프로그램을 만들고 그 프로그램이 여러개의 thread 를 만들어서
//여러개의 코어를 동시에 활용해서 휴율을 높히는 방법
//cpu 하나에 코어 하나만 있던 시절 메인보드에 cpu 를 여러개를 꽂아서 multi processing 을 하기도 했음
//효율을 높이기 위해 네크워크를 이용해 여러개의 pc 를 연결해 그 pc 에 있는 코어들을 동시에
//활용하는 방법이 있음(분산 처리), 분산처리는 pc 가 전부 흩어져 있기 때문에 메모리를 공유하지 못함,
//통신을 할때 여러가지 부가적인 오버헤드가 발생하는듯 비효율적면이 있었음

//multithreading 은 하나의 cpu 에 여러개의 코어가 있는 경우 그 코어들을 활용해서 동시에
//여러가지 작업을 수행하는것을 의미함
//mulitprocessing 보다 효율이 좋음, 대세
//여러개의 thread 들이 메모리를 공유함, 프로그래머를 편하게 해주는 동시에 양날의 검

//멀티코어 cpu 에서 자동으로 효율을 높혀주는것이 아니고 프로그래머가 multithreading 을 하도록 직접
//프로그래밍을 해야함


//main() 을 실행하는 thread 를 Main Thread 라고 부름(주된 thread의 느낌, 우연히 둘다 이름이 main 이다의 느낌)

//여러개의 thread 들에게 일을 나눠서 시키고 싶을때 multi threading 으로 프로그래밍을 하게 되고
//main thread 가 여러개의 thread 들을 실행시킬 수 있음

//main thread 은 부가적인 thread 들을 구동시킬때 순차적으로 구동시킴, 개념상으론 동시에 몇개를 띄운다 라고 표현하는
//것은 문제는 안됨 
//main thread 가 어떤경우에서 생성한 자식 thread 에서 다시 자식 thread 를 생성할 수도 있음


//예를 들어 3000개의 작업을 한다면 thread 0 이 1000개, thread 1 이 1000개, thread 2 가 1000 개로 
//나눠서 작업할 수 있음
//thread 들이 각각 별도의 프로그램인것처럼 작동함
//각 thread 가 언제 끝나는지는 main thread 에서 알 수 없음
//어느것이 먼저 끝나는지는 알 수 없음

//보통 물리적 코어의 두배정도를 processor 개수로 봄
//Utilization(이용률) 이 현재 pc 에서 cpu 가 사용되고 있는 비율


#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;	//mutual exclusion 상호 배제, 서로 못건드리게 함

int main()
{
	//우리가 보기엔 아무 작업도 안하고 있지만 작업관리자에서 보면 cpu 이용률이 조금 올라가는것을 볼 수 있음
	//while (true) {}
	

	//우리가 이때까지 배운것은 main() 하나가 있으면( exe 파일을 하나 실행시키면) process 가 하나가 실행됨
	//process 하나가 차지하는것은 cpu 의 logical processor 하나를 사용함
	//logical processor 을 다 활용하면 cpu 를 100% 활용할수 있다는것이 multi threading


	//작업관리자가 아니라 std::thread 를 이용해 코어 개수 출력 가능
	cout << std::thread::hardware_concurrency() << endl;

	//프로그램이 어떠한 컴퓨터, 즉 몇개의 코어를 가진 cpu 에서 구동이 될지 알 수 없기 때문에
	//std::thread::hardware_concurrency()를 통해 코어 개수를 변수로 받아서 구동시킬 thread 개수를
	//조절 할 수 있음


	cout << std::this_thread::get_id() << endl;	//main() 이 실행되는 this thread 의 id 출력




	const int num_pro = std::thread::hardware_concurrency();

	cout << std::this_thread::get_id() << endl;

	//thread 에 실행하고 싶은것을 넣기, 함수포인터, std::function, 람다 함수 가 들어갈 수 있음
	std::thread t1 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;		//main()을 실행시킨 thread 와 다름
		while (true) {}});	//람다 함수 실행
	

	//실행시키면 while(true) 라 무한루프여야 하는데 에러가 발생되고 멈춤
	
	//main() 이 어떤 thread 에서 작동이 됨, 그 thread 에서 다른 thread 를 작동시킴
	//새로 생긴 thread 는 원래있던 thread 와 상관없이 작동하게 됨
	//문제는 새로 실행시킨 thread 가 작동을 하면서 원래의 thread 와 의사소통해야 하는데
	//main() 이 끝나버림, 이것을 막기 위해 join() 사용
	//실제로 작동하는 방식은 t1 이 끝날때까지 기다림



	//여러개의 thread

	//t1, t2, t3 가 동시에 실행되고 있음(동시성(concurrency)) 
	//cout 이 감당을 못해서 꼬여서 출력되고 있음
	//cpu 사용량이 올라감, while 문 하나밖에 없어도 여러개의 thread 가 동시에 실행되고 있어서 사용량이 올라감

	std::thread t2 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;		
		while (true) {}});

	std::thread t3 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});
	


	//더 많은 thread 사용,vector 사용
	
	vector<std::thread> my_threads;
	my_threads.resize(num_pro);			
	//일반적으론 하드웨어가 가지고 있는 프로세서의 수 하고 thread 의 수를 맞추는것이 일반적이지만
	//프로그램의 성질에 따라 thred 개수를 조절하기도 함

	for (auto& e : my_threads)
		e = std::thread([]() {
					cout << std::this_thread::get_id() << endl;
					while (true) {}});

	//thread 가 많아서 cpu 가 100% 이용되고 있음

	//작업을 잘 분배해서 넣으면 효율적으로 할 수 있음
	//그러나 모든 문제를 병렬로 처리할 수는 없음
	//그래도 일반적으론 multi threading 아주 유용하게 사용될 수 있음




	//이렇게 모든 thread 를 join() 하는것이 일반적
	//내용물이 while(true) 라 t2 부턴 실행이 안됨(t1 에서 걸림)
	//t1.join();
	//t2.join();
	//t3.join();


	for (auto& e : my_threads)
		e.join();

	



	//글자가 깨지는 이유:

	//순차적으로 실행
	auto work_func = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //100 milliseconds 동안 휴식
			//실제로는 할 작업들을 여기서 실행시킬 수 있음

			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
		}
	};

	//순차적으로 실행
	work_func("JackJack");
	work_func("Dash");


	//동일한 thread, 순차적으로 실행되고 있음
	//JackJack 이 실행되는 동안 Dash 가 실행이 안되고 있음 -> 비효율적
	/*
	JackJack 19724 is working 0
	JackJack 19724 is working 1
	JackJack 19724 is working 2
	JackJack 19724 is working 3
	JackJack 19724 is working 4
	Dash 19724 is working 0
	Dash 19724 is working 1
	Dash 19724 is working 2
	Dash 19724 is working 3
	Dash 19724 is working 4
	*/


	//multi threading
	auto work_func2 = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //100 milliseconds 동안 휴식
			//실제로는 할 작업들을 여기서 실행시킬 수 있음


			mtx.lock();		//한번에 하나의 thread 만 밑의 코드를 작동시키게 함, 다른 thread 가 못오게 잠굼
			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();	//작동이 끝나면 풀어줘야함
		}
	};

	std::thread t1 = std::thread(work_func2, "JackJack2");
	std::thread t2 = std::thread(work_func2, "Dash2");


	//t1 과 t2 가 일을 하고있는동안 main() 이 먼저 끝나버리면 안되니까 join()
	t1.join();
	t2.join();


	//출력은 꼬여있지만 JackJack2 가 일하고 있는동안 Dash2 도 같이 일하는것을 볼 수 있음
	//여러가지 일을 동시에 처리한다는 면에서 제대로 작동하고 있음
	/*
	JackJack2 10156 is working 0
	Dash2 9796 is working 1
	JackJack2 10156 is working 1
	JackJack2 10156 is working 2
	Dash2 9796 is working 2
	Dash2 9796 is working 3
	JackJack2 10156 is working 3
	JackJack2 10156 is working 4
	Dash2 9796 is working 4
	*/

	//예제에선 sleep 하고 있는 부분(복잡한 계산이 될수도 있음) 은 따로 해도 괜찮지만
	//출력을 할때만큼은 번갈아면서 출력을 하고 싶음
	//std::mutex 사용

	//cout << name << " " << std::this_thread::get_id() << " is working " << i << endl; 에 대해서
	//mutual exclusion 선언(lock() 을 걸어줌, 끝나면 unlock())

	//원하던 대로 순서대로 잘 출력되고 있음
	/*
	Dash2 11120 is working 0
	JackJack2 5764 is working 0
	JackJack2 5764 is working 1
	Dash2 11120 is working 1
	Dash2 11120 is working 2
	JackJack2 5764 is working 2
	JackJack2 5764 is working 3
	Dash2 11120 is working 3
	Dash2 11120 is working 4
	JackJack2 5764 is working 4
	*/

	//두 thread 가 sleep 에서 쉬었다가 먼저 끝나는 쪽이 mtx.lock() 으로 와서 잠궈버림
	//그럼 다른 thread 가 못들어옴, 출력이 다 끝나면 unlonk() 을 하면 다른 thread 가 와서
	//잠구고 실행하고 풀어주고 나감

	//unlock() 을 안해주면 멈춰버림, 이후 강의 lock guard, std::atomic 에서 더 다루게 됨



	return 0;
}

