// ǥ�� ���ø� ���̺귯�� (Standard Template Libraries ) �� �����̳� ( Containers ) �Ұ�


//C++ std �� STL �� ����?
//����ϴ� ���忡�� ū ���̴� ����, namespace �� std �� �Ǿ��ֱ� ��
// STL �� Containers, Iterators, Algorithms, Functions(���� �ٷ��� ����) ���ַ� �����Ǿ� ����
//�������� std , ���� ��� ��Ƽ������ �Ҷ� ����ϴ� std::thread �� STL �� �ƴ�

// reference manual ���鼭 �ʿ��Ҷ� ã�ư��鼭 ����( cppreference.com )

//����ϴ� �����̳� �̸��ϰ� ����̸��� ��κ� ��ħ  ex) std::vector, #include<vector>
//���¼ҽ��� ������ ���ٸ� ��κ� �̷� ������� include �Ǿ��ִ� ��찡 ����

//�������� std, STL �� �ŷ����� �ʴ� ��찡 �������� Ʈ����� ������ ���°� ������

//�кλ����� ���� �����غ��°� �߿���



//sequencial containers
	//vector 
		//vector ���� push_front() �� ����, push_back() �� ȿ�������� ���� ���� ����� vector
	//deque
		//deque �� push_front(), push_back() �� ȿ�������� ���� ���� ����


//associative_containers
	//set
		//���Ұ� �ߺ����� ����, ���� ���Ұ� �ִٸ� ���� �߰����� �ʰ� �����ع���
		//set �� ��� insert() �� ���� ����

	//multiset 
		//�ߺ��� ����� ��
		//Hello Hello World  //? wht not Hello World Hello ?

	//map : key/value
		//iterate �Ҷ� first �� key �̰� second �� value ��
		//key �� ���ĵ� ������ ��µ�

	//mulitmap : duplicated keys
		//set, mulitset �� ���������� insert() �� �ְ� ����
		//C++14 ���� pair<char,int>('a', 10 ) ó�� ��Ȯ�ϰ� template parameter �� ������ ��ߵ�
		//C++17 ���� pair('a', 10)
		//pair ��ü�� �������� �� �� ����
		// count() �� key�� ���ؼ� ���Ұ� � �ִ��� ����


//container_adapters
	//stack
		//push() �� �����ؼ� ����, push adds a copy, ����� �������� �������� ���̰� ��
		//emplace constructs a new object, ���ο� ��ü�� ���� �������
		//top() �� ���� ���� �ִ°� ��ȯ, pop �� ���� ���� �ִ°� �ϳ� ����

	//queue
		//stack �� �ݴ�, stack �� �ʰ� �߰��Ǵ°� pop ������ queue �� ���� �߰��Ȱ� pop ��

	//Priority queue
		//sorting �� ����
		//����� ���� �ڷ����� �������� ũ��񱳿����ڸ� �����ε� ����ߵ�




#include <iostream>
#include <vector>
#include <deque>
#include <set>		//multi_set ����
#include <map>		//multi_map ����
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
			vec.push_back(i);		//push_back() ���� ����ֱ�

		for (auto& e : vec)			//for each �� ����� ���
			cout << e << " ";
		cout << endl;
	}


	//deque
	//vector �� �ַ� �ڿ��� �ڷḦ ���ϴ°� ��ǥ�� �ϰ�����
	// array �� ������ ���ʿ� capacity �� ũ�� �����ִ� ��Ȳ���� �ڿ��� 
	// �߰��ϴ°��� ȿ������ ������(vector �� stack ó�� ����ϱ� ����)
	//deque �� �ڷᱸ���� �տ��� ������ �ְ� �ڿ��� ���� �� ����
	{
		deque<int> deq;		//#include <deque>
		for (int i = 0; i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i);		//vector ���� push_front() �� ����
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << endl;
	}
	// 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
	//push_fornt()        | push_back()


	//vector ���� push_front() �� ����, push_back() �� ȿ�������� ���� ���� ����� vector ��
	//deque �� push_front(), push_back() �� ȿ�������� ���� ���� ����
}


//associative_containers
void associative_containers()
{
	//set
	//���Ұ� �ߺ����� ����, ���� ���Ұ� �ִٸ� ���� �߰����� �ʰ� �����ع���
	//�����̳ʸ��� ����ִ� ����� �ٸ�( ex) vector �� push_back, deque �� push_back,push_front)
	//set �� ��� insert() �� ���� ����
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		//"Hello" �� �ι� ������ size �� 3�� �ƴ϶� 2 �� ����

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

		//�ߺ��� ����� ��, size �� 3�� ����

		cout << str_set.size() << endl;		//3

		for (auto& e : str_set)
			cout << e << " ";				//Hello Hello World  //? wht not Hello World Hello ?
		cout << endl;
	}


	//map : key/value
	//�����α׷��ֿ��� json �� ����Ҷ� �� ������ �̷��� ����
	{
		map<char, int> map;		//���� �� ������ ������Ŵ

		map['c'] = 50;	//'c' �� ���� �ֱ�
		map['a'] = 10;			//���� 'a' �� key �̰�, ���� 10 �� value 
		map['b'] = 20;
		//map['c'] = 50;

		cout << map['a'] << endl;	//10

		map['a'] = 100;				//'a' �� key �� ������ ���� �ְ�, ������ ���� ������

		cout << map['a'] << endl;	//100


		//iterate �Ҷ� first �� key �̰� second �� value ��
		//���� char �� int �� std::pair(), �� ������ ����ǰ� ����
		for (auto& e : map)
			cout << e.first << " " << e.second << " ";		//a 100 b 20 c 50
		cout << endl;

		//'c' �� ���� �־ ���ĵ� ������ ��µǰ� ����
	}


	//mulitmap : duplicated keys
	//set, mulitset �� ���������� insert() �� �ְ� ����
	{
		multimap<char, int> map;

		//C++17 ���� ������ ����
		//C++14 ���� pair<char,int>('a', 10 ) ó�� ��Ȯ�ϰ� template parameter �� ������ ��ߵ�
		map.insert(std::pair('a', 10));
		map.insert(std::pair('b', 10));
		map.insert(std::pair('c', 10));
		map.insert(std::pair('a', 100));		//pair ��ü�� �������� �� �� ����


		// count() �� key 'a' �� ���ؼ� ���Ұ� � �ִ��� ����
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
		
		stack.push(1);			//push() �� �����ؼ� ����, push adds a copy, ����� �������� �������� ���̰� ��
		
		stack.emplace(2);		//emplace constructs a new object, ���ο� ��ü�� ���� �������
		stack.emplace(3);

		//top() �� ���� ���� �ִ°� ��ȯ, pop �� ���� ���� �ִ°� �ϳ� ����
		cout << stack.top() << endl;	// 3
		stack.pop();					//���� �ִ°� �ϳ� ����
		cout << stack.top() << endl;	// 2
	}


	//queue
	//stack �� �ݴ�, stack �� �ʰ� �߰��Ǵ°� pop ������ queue �� ���� �߰��Ȱ� pop ��
	{
		cout << "Queue" << endl;

		std::queue<int> queue;

		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << " " << queue.back() << endl;	// 1 3
		queue.pop();											// ���� ���� ���� 1 �� �����
		cout << queue.front() << " " << queue.back() << endl;	// 2 3
	}


	//Priority queue
	//sorting �� ����
	//����� ���� �ڷ����� �������� ũ��񱳿����ڸ� �����ε� ����ߵ�
	{
		cout << "Priority queue" << endl;

		std::priority_queue<int> queue;		//����� ���� �ڷ����� �������� ũ��񱳿����ڸ� �����ε� ����ߵ�

		//for-each �� �̷������ε� ��� ����
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

