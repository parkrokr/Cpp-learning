#pragma once


#include<iostream>
#include<vector>
#include<algorithm> 
#include<random>
#include<chrono>

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

		std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
		//end_time 에서 start_time 을 빼고 '초' 로 바꿔서 출력
	}

};