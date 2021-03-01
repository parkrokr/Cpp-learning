//비쥬얼 스튜디오로 프로파일(profiling) 하기

//진단 도구: debug 모드에서 사용, cpu usage, memory usage 체크, breakpoint 찍어사 사용

//Performance profiler : release 모드에서 사용, 실제 퍼포먼스와 더 유사한 환경에서 프로파일러를 돌리는것
//연산량이 가장 많은 hotspot 찾기 쉬움, 최적화가 많이 되어있기 때문에 debug 모드보단 자세히 보기는 힘들 수도 있음


//진단 도구를 먼저 사용하고 퍼포먼스 프로파일러를 사용함


#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>	//std::inner_proudct

using namespace std;

void func1()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000; ++i)
		sum += i;

	cout << sum << endl;
}

//func1() 보다 연산량이 1000배 많음
void func2()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000'000; ++i)
		sum += i;

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}

int main()
{
	//cpu 프로파일링
	//어느 부위가 가장 많이 cpu 사용량을 차지하는지 찾기
	run();
	//func1 이 0.1 %, func2() 가 99.72 %  사용했다는것을 Diagnostic Tools 에서
	//Record CPU Profile 을 통해 알 수 있음

	//어디가 가장 hot spot(문제가 되는곳) 인지 찾아낼때 profiler 가 도움이 많이 됨
	//프로그래밍 sill 레벨이 아니라 알고리즘 레벨에서 최적화를 하는것이 좋은 프로그래머


	//메모리(힙) 프로파일링
	int* d = new int[10000];
	float* f = new float[100];

	delete[] d;
	delete[] f;

	//cpu 프로파일링과 메모리 프로파일링을 동시에 실행시킬수는 있으나
	//동시에 돌리면 정확도가 떨어질 수도 있음
	//정밀하게 할때는 따로따로 돌리는것이 권장됨

	//heap profiling 은 켜두는 것이 좋음
	//	cpu usage 를 측정할때 영향을 주기 때문에 끄고킬수 있게 만듦(대부분의 경우 큰 영향은 없음)

	//break point 에서 memory usage 의 Take Sanpshot 을 통해 메모리 사용량을 알아낼 수 있음
	//count diff 를 통해 실행 전과 후 차이가 몇개인지도 알 수 있음



	//19.6 멀티 쓰레딩 예제 사용

	//release 모드에서 프로파일링 하는것도 중요함, 디버그 모드에선 디버그를 하기 위해 여러가지가 포함되어 있어
	//실제 release 모드와 퍼포먼스의 차이가 있음
	//진단도구가 아닌 Performance profiler 사용(release 모드에서만 사용가능)
	//cpu sampling 사용(추천)
	//강제종료가 되어도 프로파일링이 됨

	//inclusive samples 는 함수가 함수를 호출할때 다 포함하고 exclusive samples 는 두번째 호출되는 함수는 뺌

	//사용법은 진단 도구와 거의 비슷함

	
	
	return 0;
}