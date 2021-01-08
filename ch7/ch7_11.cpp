//std::vector 를 스택(stack) 처럼 사용하기

//new 와 delete 가 많이 느리기 때문에 size 와 capacity 가 다르게 사용할수 있는 다른 구조를 가지고 있음
//reserve 를 이용하면 미리 메모리를 확보할 수 있음

#include<iostream>
#include<vector>

using namespace std;


void printStack(const std::vector<int>& stack)
{
	for (auto& e : stack)
		cout << e << " ";
	cout << endl;
}


int main()
{
	std::vector<int> v{ 1,2,3 };
	// 내부적으로 int *v_ptr = new int[3]{1, 2, 3}; 과 유사함(동일하진 않음)


	//vector 에는 size, capacity(용량) 이 있음

	//실제로 코드 내부에서 capacity 개수만큼 메모리를 가지고 있음
	//그중에 size 개수만큼 사용함

	//heap 에 메모리를 잡으려면 어디에 공간을 잡아야 하는지 결정할때 조금 느려지게 됨
	//heap 에 new 와 delete를 하는건 많이 느림 (가급적 안쓰는게 좋음)
	//vector 는 내부적으로 new 와 delete를 사용하기 때문에 vector 를 잘 사용하는 방법은
	//내부에서 이루어지는 new와 delete가 적게 호출되게 생각하면서 사용하기

	//for(unsigned int i = 0;i<v.size();++i)
	for (auto& e : v) //modern c++ style
		cout << e << " ";
	cout << endl;

	cout << v.size() << endl; // 3 , size 에 맞춰서 for-each 가 돔

	//resize(10)
	v.resize(10);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;  // 1 2 3 0 0 0 0 0 0 0 

	cout << v.size() << " " << v.capacity() << endl; // 10 10

	//resize(2)
	v.resize(2);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;  // 1 2 

	cout << v.size() << " " << v.capacity() << endl; // 2 10

	//size 는 달라지지만 capacity 는 유지하는것을 볼 수 있음

	
	//v[2] 에 강제로 접근 시도
	//cout << v[2] << endl; //runtime error!
	//cout << v.at(2) << endl; // abort() has been called  런타임 에러
	
	int* ptr = v.data(); //포인터를 가져올 수 있음
	cout << ptr[2] << endl;  // 3 이 출력됨

	//resize를 했을때 속도를 높이기 위해 작은쪽으로 resize를 할때 
	//메모리는 그대로 가지고 있고 resize 한것만 보여줌 그래서 capacity 는 유지되는것

	//modern c++ style
	for (auto& e : v) 
		cout << e << " ";
	cout << endl;

	//옛날 스타일
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//resize 하면 0으로 채워버림

	//capacity 만 키우기
	v.reserve(1024); // 메모리의 용량을 미리 확보해 놓겠다

	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl; //1 2  (0 이 안붙음)

	cout << v.size() << " " << v.capacity() << endl; // 2  1024

	//reserve를 하는 이유
	//원소가 추가가 될때 reserve 된 공간이 많이 남아있으면 새로 메모리를 받아오고 교체하는 작업을 하지않음
	//그래서 더 빨라짐


	//stack 처럼 사용하기
	std::vector<int> stack; 

	//stack.reserve(1024); //미리 reserve 해두면 확실히 빨라짐

	//vector 를 이용해 push 와 pop 하기
	stack.push_back(3);
	printStack(stack); // 3

	stack.push_back(5);
	printStack(stack); // 3 5
	
	stack.push_back(7);
	printStack(stack); // 3 5 7


	stack.pop_back();
	printStack(stack); //3 5

	stack.pop_back();
	printStack(stack); //3

	stack.pop_back();
	printStack(stack); // 3마저 빠져서 아무것도 출력 안됨

	//vector 를 이용해 stack 를 구현하는 이유
	//reserve를 이용하면  push_back 할때 capacity 를 늘릴 필요가 없기 때문에
	//new 와 delete를 호출할 일이 없어서 휴율이 더 좋음
	//pop_back 를 할때도 capacity를 유지한체 size 만 줄이기 때문에 효율이 더 높음

	//단점 : reserve 를 너무 크게 하면 capacity 가 너무 커서 메모리가 낭비될 수 있음


	return 0;
}