// 표준 템플릿 라이브러리 (Standard Template Libraries ) 와 컨테이너 ( Containers ) 소개


//C++ std 와 STL 의 차이?
//사용하는 입장에선 큰 차이는 없음, namespace 가 std 로 되어있긴 함
// STL 은 Containers, Iterators, Algorithms, Functions(많이 다루진 않음) 위주로 구성되어 있음
//나머지는 std , 예를 들어 멀티쓰레딩 할때 사용하는 std::thread 는 STL 이 아님

// reference manual 보면서 필요할때 찾아가면서 쓰기( cppreference.com )

//사용하는 컨테이너 이름하고 헤더이름이 대부분 겹침  ex) std::vector, #include<vector>
//오픈소스를 가져다 쓴다면 대부분 이런 헤더들이 include 되어있는 경우가 많음

//예전에는 std, STL 을 신뢰하지 않는 경우가 많았으나 트렌드는 가져다 쓰는걸 권장함

//학부생때는 직접 구현해보는게 중요함



//sequencial containers
	//vector 
		//vector 에는 push_front() 가 없음, push_back() 를 효율적으로 쓰기 위해 만든게 vector
	//deque
		//deque 는 push_front(), push_back() 을 효율적으로 쓰기 위해 만듬


//associative_containers
	//set
		//원소가 중복되지 않음, 같은 원소가 있다면 새로 추가하지 않고 무시해버림
		//set 의 경우 insert() 로 집어 넣음

	//multiset 
		//중복이 허용이 됨
		//Hello Hello World  //? wht not Hello World Hello ?

	//map : key/value
		//iterate 할때 first 가 key 이고 second 가 value 임
		//key 가 정렬된 순서로 출력됨

	//mulitmap : duplicated keys
		//set, mulitset 과 마찬가지로 insert() 로 넣고 있음
		//C++14 까진 pair<char,int>('a', 10 ) 처럼 명확하게 template parameter 를 지정해 줘야됨
		//C++17 부터 pair('a', 10)
		//pair 자체가 여러개가 들어갈 수 있음
		// count() 는 key에 대해서 원소가 몇개 있는지 세줌


//container_adapters
	//stack
		//push() 는 복사해서 넣음, push adds a copy, 사용자 정의형을 넣을때는 차이가 남
		//emplace constructs a new object, 새로운 객체를 만들어서 집어넣음
		//top() 은 가장 위에 있는걸 반환, pop 는 가장 위에 있는걸 하나 제거

	//queue
		//stack 과 반대, stack 은 늦게 추가되는게 pop 되지만 queue 는 먼저 추가된게 pop 됨

	//Priority queue
		//sorting 을 해줌
		//사용자 정의 자료형을 넣을때는 크기비교연산자를 오버로딩 해줘야됨




#include <iostream>
#include <vector>
#include <deque>
#include <set>		//multi_set 포함
#include <map>		//multi_map 포함
#include <string>
#include <stack>
#include <queue>

using namespace std;

//sequencial containers
void sequence_containers()
{
	//vector
	{
		vector<int> vec;	//#include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);		//push_back() 으로 집어넣기

		for (auto& e : vec)			//for each 를 사용해 출력
			cout << e << " ";
		cout << endl;
	}


	//deque
	//vector 는 주로 뒤에서 자료를 더하는걸 목표로 하고있음
	// array 가 있을때 뒤쪽에 capacity 가 크게 잡혀있는 상황에서 뒤에만 
	// 추가하는것이 효율성이 높아짐(vector 를 stack 처럼 사용하기 참고)
	//deque 는 자료구조가 앞에도 넣을수 있고 뒤에도 넣을 수 있음
	{
		deque<int> deq;		//#include <deque>
		for (int i = 0; i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i);		//vector 에는 push_front() 가 없음
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << endl;
	}
	// 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
	//push_fornt()        | push_back()


	//vector 에는 push_front() 가 없음, push_back() 를 효율적으로 쓰기 위해 만든게 vector 임
	//deque 는 push_front(), push_back() 을 효율적으로 쓰기 위해 만듬
}


//associative_containers
void associative_containers()
{
	//set
	//원소가 중복되지 않음, 같은 원소가 있다면 새로 추가하지 않고 무시해버림
	//컨테이너마다 집어넣는 방식이 다름( ex) vector 는 push_back, deque 는 push_back,push_front)
	//set 의 경우 insert() 로 집어 넣음
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		//"Hello" 를 두번 넣으면 size 가 3이 아니라 2 가 나옴

		cout << str_set.size() << endl;		//2

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;						//Hello World
	}


	//multiset : duplication is allowed
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		//중복이 허용이 됨, size 가 3이 나옴

		cout << str_set.size() << endl;		//3

		for (auto& e : str_set)
			cout << e << " ";				//Hello Hello World  //? wht not Hello World Hello ?
		cout << endl;
	}


	//map : key/value
	//웹프로그래밍에서 json 을 사용할때 그 구조가 이렇게 생김
	{
		map<char, int> map;		//문자 와 정수를 대응시킴

		map['c'] = 50;	//'c' 를 먼저 넣기
		map['a'] = 10;			//문자 'a' 가 key 이고, 정수 10 이 value 
		map['b'] = 20;
		//map['c'] = 50;

		cout << map['a'] << endl;	//10

		map['a'] = 100;				//'a' 인 key 가 없으면 만들어서 넣고, 있으면 값을 갱신함

		cout << map['a'] << endl;	//100


		//iterate 할때 first 가 key 이고 second 가 value 임
		//지금 char 와 int 가 std::pair(), 즉 쌍으로 저장되고 있음
		for (auto& e : map)
			cout << e.first << " " << e.second << " ";		//a 100 b 20 c 50
		cout << endl;

		//'c' 를 먼저 넣어도 정렬된 순서로 출력되고 있음
	}


	//mulitmap : duplicated keys
	//set, mulitset 과 마찬가지로 insert() 로 넣고 있음
	{
		multimap<char, int> map;

		//C++17 부터 가능한 문법
		//C++14 까진 pair<char,int>('a', 10 ) 처럼 명확하게 template parameter 를 지정해 줘야됨
		map.insert(std::pair('a', 10));
		map.insert(std::pair('b', 10));
		map.insert(std::pair('c', 10));
		map.insert(std::pair('a', 100));		//pair 자체가 여러개가 들어갈 수 있음


		// count() 는 key 'a' 에 대해서 원소가 몇개 있는지 세줌
		cout << map.count('a') << endl;			//2	

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;

		// a 10 a 100 b 10 c 10
	}

}


//container_adapters
//stack, queue , priorty queue
void container_adapters()
{
	//stack
	{
		cout << "Stack" << endl;

		std::stack<int> stack;
		
		stack.push(1);			//push() 는 복사해서 넣음, push adds a copy, 사용자 정의형을 넣을때는 차이가 남
		
		stack.emplace(2);		//emplace constructs a new object, 새로운 객체를 만들어서 집어넣음
		stack.emplace(3);

		//top() 은 가장 위에 있는걸 반환, pop 는 가장 위에 있는걸 하나 제거
		cout << stack.top() << endl;	// 3
		stack.pop();					//위에 있는걸 하나 제거
		cout << stack.top() << endl;	// 2
	}


	//queue
	//stack 과 반대, stack 은 늦게 추가되는게 pop 되지만 queue 는 먼저 추가된게 pop 됨
	{
		cout << "Queue" << endl;

		std::queue<int> queue;

		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << " " << queue.back() << endl;	// 1 3
		queue.pop();											// 가장 먼저 들어온 1 이 사라짐
		cout << queue.front() << " " << queue.back() << endl;	// 2 3
	}


	//Priority queue
	//sorting 을 해줌
	//사용자 정의 자료형을 넣을때는 크기비교연산자를 오버로딩 해줘야됨
	{
		cout << "Priority queue" << endl;

		std::priority_queue<int> queue;		//사용자 정의 자료형을 넣을때는 크기비교연산자를 오버로딩 해줘야됨

		//for-each 를 이런식으로도 사용 가능
		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			queue.push(n);

		for (int i = 0; i < 10; ++i)
		{
			cout << queue.top() << " ";
			queue.pop();
		}
		//9 8 7 6 5 4 3 2 1 0
	}

}


int main()
{
	//constainers

	//sequence_containers, associative_containers, container_adapters

	sequence_containers();

	associative_containers();

	container_adapters();


	return 0;
}

