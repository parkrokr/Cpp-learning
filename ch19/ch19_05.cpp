//작업 ( Task ) 작업 기반 비동기 프로그래밍 async, future, promise

//async 가 future 랑 연결이 되어있지 않을때는 그냥 sequential 인것처럼 진행됨

#include <iostream>
#include <future>		//async, future, promise
#include <thread>

using namespace std;

int main()
{
	// multi - threading	(thread-based parallelism)
	{
		int result;
		std::thread t([&] {result = 1 + 2; });		//thread 를 관리하고 있음
		t.join();
		cout << result << endl;
	}
	//전통적인 방법
	//최근에는 thread 만 접근할 수 있는 변수를 선언이 가능해서 좀 괜찮아졌지만
	//전통적으론 scope 를 넓게 잡고 그 안에 있는 변수(result) 를 여러 thread 들이 공유하는것이 일반적
	//thread 위주로 프로그래밍이 됨



	// task-based parallelism
	{
		//std::future<int> fut = ...
		auto fut = std::async([] {return 1 + 2; });
		cout << fut.get() << endl;
	}
	//std::thread 대신에 std::async 를 사용함, async(비동기적)
	//return 이 들어감, 마치 return value 를 fut 가 받는것처럼 보임
	//1+2 대신에 시간이 더 오래걸리는 작업을 할때 바로 return value 를 받는건 힘듬
	//async(비동기적) 하게 main thread 가 진행되는것과 별도로 안에서 작업이 이루어짐
	//async 는 thread 를 다룰 수 있는 옵션이 더 있음, 일반적으로 thread 보다 async 를 선호함


	//thread-based 에선 thread를 관리하고 생성하고 어떤 일을 할지 지정해주는것에 더 관심이 있음
	
	//task-base 에선 어떤 일,작업을 할 것인가를 위주로 프로그래밍 함
		//return 해주는 값을 현재(바로) 받을 수 있는것이 아님(보장이 없음)

	//그래서 auto fut 가 std::future 로 잡힘 
	//std::future<int> fut = ... 은 작업(이 예제에선 1+2 ) 가 끝나면 int 를 받아오겠다는 의미(마치 int result)
	//int result 는 thread 밖에 있어서 어떤 일을 겪을지 알 수 없지만
	//std::future 는 async 가 실행되는 task 와 정확하게 결합되는 구조

	//fut.get() 의 return type 이 정확하게 int 임, return 해주는 값이 int type 이라서
	//만약 fut.get() 이 return 이 발생하기 전이라면 async 가 task 를 끝내고 return 이 발생할때까지 기다림

	//muti threading 은 thread 가 task 가 끝날때까지 기다리는 개념임( t.join() )
	



	//future and promise
	{
		std::promise<int> prom;			//int type 으로 템플릿화되어있음
		auto fut = prom.get_future();	//prom 으로부터 get_future() 를 가져오고 있음,

		auto t = std::thread([](std::promise<int>&& prom)
			{
				prom.set_value(1 + 2);	//promise 에 계산 결과를 값을 넣어주고 있음
			}, std::move(prom));
		

		cout << fut.get() << endl;		//prom 이 set_value 를 통해 결과값을 받아주기 전까지 fut 가 기다림
		t.join();			//thread 이기 때문에 join() 으로 기다려줘야함, fut.get() 보다 위에 있어도 결과 변화 없음
	}

	//std::future 를 async 에서뿐만 아니라 thread 에서도 사용할 수 있음, 대신 std::promise 를 먼저 선언해야함
	//이런 구조가 조금 복잡하기 때문에 요즘은 task-based parallelism, async 를 선호함
	//대신 익숙해지면 편함, 최근 multi threading 코드를 보면 이런 future and promise 가 자주 나옴

	//auto t 는 thread 를 받고 있고 future 를 받기 위한게 필요해서 prom 을 거쳐감
	//prom 에 어떤 값을 넣어주면 future 가 발동됨
	
	//람다 함수에 prom 을 r value reference 로 parameter 로 넣어줌
	//promise 는 복사가 안됨, 그래서 한번만 사용되어야 하기 때문에 r value reference 로 넣어주는것
	//l value reference 로 넣어주면 에러발생
	//prom 을 r value reference 로 넣어주기 위해 std::move() 를 이용하여 r value 로 만듦

	//thread 대신에 async 를 넣을 수도 있지만 그럴거면 promise 를 만들 이유가 없음




	//thread 와 async 비교
		//thread 는 join() 을 통해 대기해야 함, 없으면 먼저 main() 이 끝나는 문제 발생
		//async 는 join() 이 없어도 문제가 생기지 않음, 소멸자가 끝나는걸 알아서 대기해줌
		//async 가 future 랑 연결이 되어있지 않을때는 그냥 sequential 인것처럼 진행됨

	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});


		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;		//main thread 로 흐름이 돌아옴
	}
	//async 와 thread 일때 작동하는 방식이 다름

	//f1 f2 가 async 일때
	/*Main function
	async1 start
	async2 start
	async2 end
	async1 end*/

	{
		auto f1 = std::thread([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});


		auto f2 = std::thread([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		f1.join();
		f2.join();

		std::cout << "Main function" << endl;		//main thread 로 흐름이 돌아옴
	}
	//join() 이 없을때
	/*Main function
	async2 startasync1 start*/	//출력 에러
	//f1 과 f2 가 살아있는데 main() 이 끝나서 os 가 에러로 판단
	
	//join() 이 있으면 문제가 사라짐
	/*async1 start
	async2 start
	async2 end
	async1 end
	Main function*/


	//future 로 받지 않을때
	{
		std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});


		std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;		//main thread 로 흐름이 돌아옴
	}
	/*async1 start
	async1 end
	async2 start
	async2 end
	Main function*/
	//async 가 future 랑 연결이 되어있지 않을때는 그냥 sequential 인것처럼 진행됨



	return 0;
}