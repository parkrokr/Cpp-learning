// 배열과 반복분 Array

#include<iostream>

using namespace std;

int main()
{
	//array 사용 전
	/*const int num_students = 5;
	int score0 = 84;
	int score1 = 92;
	int score2 = 76;
	int score3 = 81;
	int score4 = 56;

	int total_score = score0 + score1 + score2 + score3 + score4;

	double avg_score = static_cast<double>(total_score) / num_students;
	//double(total_score) / num_students != double(total_score / num_students);
	// 나눈 후에 캐스팅을 하면 버림되면서 정보가 소실될 수 있음
	*/


	//array 사용 후
	
	//const int num_students = 5;

	int scores[] = { 84,92,76,81,56 };

	const int num_students = sizeof(scores) / sizeof(int); // 함수 parameter 로 넘어간 array 경우 이런 방식으로 구할 수 없음

	int total_score = 0;

	for (int i = 0; i < num_students; ++i) // < 항상 중요! , = 들어가버리면 i 에 num_students값이 들억가고 runtime error 발생
	{
		total_score += scores[i];
	}

	double avg_score = static_cast<double>(total_score) / num_students;


	//최댓값 구하기 max
	int max_score = 0;

	for (int i = 0; i < num_students; ++i) 
	{
		max_score = (max_score < scores[i]) ? scores[i] : max_score;
		
		//if (max_score < scores[i])max_score = scores[i];;
	}

	cout << "max is " << max_score << endl;


	//최솟값 구하기 min
	int min_score = 100; // or max of int

	for (int i = 0; i < num_students; ++i)
	{
		min_score = (min_score > scores[i]) ? scores[i] : min_score;

		//if (min_score > scores[i])min_score = scores[i];;
	}

	cout << "min is " << min_score << endl;

	return 0;
}