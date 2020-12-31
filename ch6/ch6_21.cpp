//std::vector

//std::array 는 array 대신에 쓰기 편하고 std::vector 는 동적할당배열보다 쓰기 편함
//vector 는 메모리를 따로 지울 필요가 없음, 블록 밖을 나갈때 자동으로 사라짐  
//new 와 delete 를 사용하지 않아도 leak 이 되지 않음, 프로그래머의 부담이 적어짐



#include<iostream>
#include<vector>

using namespace std;

int main()
{
	//std::array<int, 5> array;  //사이즈를 적어줘야 함
	std::vector<int> array;	//동적 할당이 되는 메모리이기 때문에 사이즈를 반드시 적을 필요 없음

	//초기화
	std::vector<int>array2 = { 1,2,3,4,5 };
	cout << array2.size() << endl; // size 출력

	std::vector<int>array3 = { 1,2,3, };
	cout << array3.size() << endl;

	std::vector<int>array4{ 1,2,3, };  //uniform initialization 도 됨
	cout << array4.size() << endl;


	//사이즈를 그때그때 바꿀 수 있음
	vector<int> arr = { 1,2,3,4,5 };

	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	//array 에서 했던것과 동일함
	cout << arr[1] << endl;
	cout << arr.at(1) << endl;

	//vector 는 스스로의 길이를 기억하고 있음

	int* my_arr = new int[5];

	delete[] my_arr; // my_arr 의 사이즈가 몇인지 알 수가 없음

	//vector 는 size()를 통해 사이즈를 알 수 있음


	//resize 도 가능
	arr.resize(10);

	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;
	//1 2 3 4 5 0 0 0 0 0

	cout << arr.size() << endl;  //10

	//줄일수도 있음
	arr.resize(2);

	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;
	//1 2

	cout << arr.size() << endl; //2

	return 0;
}