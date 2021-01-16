//실행 시간 측정하기

//sorting 하는데 걸리는 시간을 측정
//실제 배포를 할때 동작하는 실제 시간을 측정하고 싶을때는 Debug 모드가 아니라 Release 모드로 해야됨

//프로그램의 실행 시간은 매우 많은 요소들에 영향을 받기 때문에 최적화가 어려운 것이다
//시간은 적어도 3번은 측정해봐야함


#include<iostream>
#include<vector>
#include<algorithm> //to use sort
#include<random>
#include<chrono>	//시간 재주는 library

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now(); 
	//Timer 가 만들어지는 시간을 clock_t::now()로 측정해 start_time 이라는 member variable 로 초기화

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();
		//elapsed() 가 호출이 되면 현재시간을 end_time 에 넣어줌

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
		//end_time 에서 start_time 을 빼고 '초' 로 바꿔서 출력
	}

};

int main()
{
	random_device rnd_device; //시드값 설정
	mt19937 mersenne_engine{ rnd_device() }; //시드값 전달


	vector<int> vec(10);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;


	std::shuffle(begin(vec), end(vec), mersenne_engine); //순서를 섞어줌

	for (auto& e : vec)cout << e << " ";
	cout << endl;


	Timer timer;  //시간 측정 시작

	std::sort(begin(vec), end(vec));  //sort

	timer.elapsed();  //측정된 시간 출력


	//sort가 잘 되었나 결과 확인
	for (auto& e : vec)cout << e << " ";
	cout << endl;




	//10개는 너무 작아서 시간 측정하는 의미가 별로 없음
	vector<int> vec2(100000);

	std::shuffle(begin(vec2), end(vec2), mersenne_engine);

	Timer timer2;  

	std::sort(begin(vec2), end(vec2)); 

	timer2.elapsed();

	return 0;
}