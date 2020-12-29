//For-each 반복문

#include<iostream>
#include<limits>  // to use std::numeric_limits
#include<algorithm> //to use std::max
#include<vector>

using namespace std;

int main()
{
	 int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	//array 내용물을 몇갠지 세보고 싶지 않지만 돌려봐야 할때

	//값을 바꾸고 싶을때
	
	//밑에 코드는 값이 안바뀜  함수 parameter 로 넣느거랑 비슷함
	for (int number : fibonacci)
		number = 10;

	//change array values  
	for (int& number : fibonacci) //ref 사용
		number = 10;

	//흔하게 사용하는 방법
	//for(auto& number : fibonacci) //auto 사용
	//	number = 10;



	//출력
	//for (int number : fibonacci)
	for (const auto &number : fibonacci)  //출력하는 코드에선 값을 잘 안바꾸니까 const 
		cout << number << " ";
	cout << endl;



	//최댓값 찾기
	int other_fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	int max_number = std::numeric_limits<int>::lowest();
	//max_number 초기값이 89이하면 최대값 89를 올바르게 찾을 수 있지만, 일반적인 경우에서 numeric_limits 사용

	for (const auto& n : other_fibonacci)
		max_number = std::max(max_number, n); //둘중에 큰걸 대입해라
	
	cout << max_number << endl;




	//array를 동적할당하면 for-each를 사용할 수 없음
	//대신에 vector 를 사용
	//std::vector 은 동적할당을 쉽게 사용하기 위한것

	vector<int> fibonacci_vector = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	int max_number = std::numeric_limits<int>::lowest();
	

	for (const auto& n : fibonacci_vector)
		max_number = std::max(max_number, n); 
	cout << max_number << endl;

	return 0;
}