// �迭�� �ݺ��� Array

#include<iostream>

using namespace std;

int main()
{
	//array ��� ��
	/*const int num_students = 5;
	int score0 = 84;
	int score1 = 92;
	int score2 = 76;
	int score3 = 81;
	int score4 = 56;

	int total_score = score0 + score1 + score2 + score3 + score4;

	double avg_score = static_cast<double>(total_score) / num_students;
	//double(total_score) / num_students != double(total_score / num_students);
	// ���� �Ŀ� ĳ������ �ϸ� �����Ǹ鼭 ������ �ҽǵ� �� ����
	*/


	//array ��� ��
	
	//const int num_students = 5;

	int scores[] = { 84,92,76,81,56 };

	const int num_students = sizeof(scores) / sizeof(int); // �Լ� parameter �� �Ѿ array ��� �̷� ������� ���� �� ����

	int total_score = 0;

	for (int i = 0; i < num_students; ++i) // < �׻� �߿�! , = �������� i �� num_students���� ��ﰡ�� runtime error �߻�
	{
		total_score += scores[i];
	}

	double avg_score = static_cast<double>(total_score) / num_students;


	//�ִ� ���ϱ� max
	int max_score = 0;

	for (int i = 0; i < num_students; ++i) 
	{
		max_score = (max_score < scores[i]) ? scores[i] : max_score;
		
		//if (max_score < scores[i])max_score = scores[i];;
	}

	cout << "max is " << max_score << endl;


	//�ּڰ� ���ϱ� min
	int min_score = 100; // or max of int

	for (int i = 0; i < num_students; ++i)
	{
		min_score = (min_score > scores[i]) ? scores[i] : min_score;

		//if (min_score > scores[i])min_score = scores[i];;
	}

	cout << "min is " << min_score << endl;

	return 0;
}