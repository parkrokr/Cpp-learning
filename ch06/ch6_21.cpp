//std::vector

//std::array 는 array 대신에 쓰기 편하고 std::vector 는 동적할당배열보다 쓰기 편함
//vector 는 메모리를 따로 지울 필요가 없음, 블록 밖을 나갈때 자동으로 사라짐  
//new 와 delete 를 사용하지 않아도 leak 이 되지 않음, 프로그래머의 부담이 적어짐


//vector<bool> 은 좀 다름, bool의 크기는 1 byte(8 bit) 이지만 vectro<bool> 은 1 bit 만 사용함( true false 를 저장하는데 1 bit 면 충분하다고 생각해서 최적화 되어있음)

//vector<bool> vector_b(true);		//을 만들었을때
//bool boo =vector_b[0];		//이건 가능하지만 
//bool *ptr_boo = &vector_b[0]		//불가능, bool type 과 vector<bool>의 크기가 다르기 때문에 &vetor<bool>의 주소값은 bool* 과 다른 형식임



//vector<int> v = { 1, 2, 3};          // int형 백터 생성 후 1, 2, 3 으로 초기화
//vector<int> v[10];                   // int타입 벡터 배열(크기 : 10) 생성
//vector<int> v[] = {{ 1, 2}, {3, 4}}; // int형 백터 배열 생성(행은 가변이지만 열은 고정)
//vector<vector<int>> v;               // 2차원 백터 생성(행과 열 모두 가변)
//vector<int> v(5);                    // 5개의 원소를 0으로 초기화
//vector<int> v(5, 3);                 // 5개의 원소를 3으로 초기화
//vector<int> v2(v);                   // 벡터 v를 복사하여 벡터v2 생성

//v.size();   //vector의 원소 갯수
//v.capacity; //vector의 물리적 크기

//v.push_back(10);  // 마지막 위치에 숫자 10 추가
//v.insert(2,10);   // index 2의 위치에 숫자 10 추가
//v.insert(2,3,4)   //2번쨰 위치에 3개의 4값을 추가

//v.pop_back();                        // 마지막에 넣은 값 제거
//v.erase(vec.begin()+10);             // index 10의 값을 제거
//v.erase(vec.begin(), vec.begin()+5);  // index 0~5의 값을 제거
//v.clear();                           //모든 값 제거


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
