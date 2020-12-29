//For-each �ݺ���

#include<iostream>
#include<limits>  // to use std::numeric_limits
#include<algorithm> //to use std::max
#include<vector>

using namespace std;

int main()
{
	 int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	//array ���빰�� ��� ������ ���� ������ �������� �Ҷ�

	//���� �ٲٰ� ������
	
	//�ؿ� �ڵ�� ���� �ȹٲ�  �Լ� parameter �� �ִ��Ŷ� �����
	for (int number : fibonacci)
		number = 10;

	//change array values  
	for (int& number : fibonacci) //ref ���
		number = 10;

	//���ϰ� ����ϴ� ���
	//for(auto& number : fibonacci) //auto ���
	//	number = 10;



	//���
	//for (int number : fibonacci)
	for (const auto &number : fibonacci)  //����ϴ� �ڵ忡�� ���� �� �ȹٲٴϱ� const 
		cout << number << " ";
	cout << endl;



	//�ִ� ã��
	int other_fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	int max_number = std::numeric_limits<int>::lowest();
	//max_number �ʱⰪ�� 89���ϸ� �ִ밪 89�� �ùٸ��� ã�� �� ������, �Ϲ����� ��쿡�� numeric_limits ���

	for (const auto& n : other_fibonacci)
		max_number = std::max(max_number, n); //���߿� ū�� �����ض�
	
	cout << max_number << endl;




	//array�� �����Ҵ��ϸ� for-each�� ����� �� ����
	//��ſ� vector �� ���
	//std::vector �� �����Ҵ��� ���� ����ϱ� ���Ѱ�

	vector<int> fibonacci_vector = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	int max_number = std::numeric_limits<int>::lowest();
	

	for (const auto& n : fibonacci_vector)
		max_number = std::max(max_number, n); 
	cout << max_number << endl;

	return 0;
}