//STL 알고리즘 ( Algorithms ) 소개

//매우 방대함, move,sort 등등 매우 많음
//min, max, clamp 같은건 옛날엔 구현해서 썼지만 요즘은 std 로 가져다 씀
//자료구조에서 배우는 내용으로 많이 구현이 됨

//사용자 정의 자료형을 사용할때는 비교연산자를 오버로딩해야 밑의 기능들을 사용할 수 있음(ch09_04)

//컨테이너마다 상황이 조금씩 다름, algorithm 에서 sort() 이 없을 경우 컨테이너로 가서 찾으면 있을 수도 있음
//list 와 벡터의 차이는 자료구조에서
//vector 에서 insert() 가 조금더 느릴 '수' 있고 list 에서 insert() 가 조금더 빠를 '수' 있음, 항상은 아님


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int> container;
	//list<int> container;	//list 에서도 거의 똑같이 작동하지만 sort(), reverse() 는 자기 클래스에 들어있음

	for (int i = 0; i < 10; ++i)
		container.push_back(i);



	//min 찾기
	auto itr = min_element(container.begin(), container.end());		//begin 과 end 사이에서 찾음
	cout << *itr << endl;		//0


	//max 찾기
	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;		//9

	cout << endl;



	//특정한 원소 찾기
	itr = find(container.begin(), container.end(), 3);		//3의 위치 찾기, iterator 가 3의 위치를 가르키고 있음

	container.insert(itr, 128);		//원래 3의 위치에 128 이 들어가고 3 은 뒤로 밀림


	//출력
	for (auto& e : container) cout << e << " ";
	cout << endl;
	//0 1 2 128 3 4 5 6 7 8 9


	//sort
	sort(container.begin(), container.end());
	//container.sort();		//list 는 sort() 가 자기 클래스 안에 들어있음

	//출력
	for (auto& e : container) cout << e << " ";
	cout << endl;
	//0 1 2 3 4 5 6 7 8 9 128


	//reverse	순서 뒤집기
	reverse(container.begin(), container.end());
	//container.reverse();	//list 는 reverse() 가 자기 클래스 안에 들어있음

	//출력
	for (auto& e : container) cout << e << " ";
	cout << endl;
	//128 9 8 7 6 5 4 3 2 1 0


	return 0;
}