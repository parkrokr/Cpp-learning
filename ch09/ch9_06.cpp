//첨자 연산자 ( [] subscript operator ) 오버로딩하기

//member function 으로만 가능한 연산자들
// = , [] , () ,->

//assert 를 써야 runtime error 를 막을 수 있음
//[]는 보통 많이 쓰려고 만드는 거기 때문에 if 문 보다는 assert 를 써서 performace 를 높임

//포인터를 쓸때 de-referecing 해서 쓰기

// std::vector 는 연산자 오버로딩이 잘 되어있음

#include<iostream>
#include<cassert>  //to use assert

using namespace std;

class IntList
{
private:
	//std::array 나 std::vector 를 쓸수도 있지만 동적할당을 할때 메모리가 제대로 잡혀 있어야함
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	/*void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}*/

	//첨자 연산자 오버로딩
	//값을 읽고 바꾸기 위해 참조로 반환,  l value 여야 하니까 (주소를 가지고 있어야하니까) 참조로 반환
	int& operator [] (const int index)  //int 말고 다른 data type 도 들어올 수 있음
	{
		//assert 를 쓰는게 좋음
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	//const 버전의 오버로딩
	const int& operator[] (const int index) const
	{
		//assert 를 쓰는게 좋음
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

};


int main()
{
	//IntList my_list;
	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl;

	//my_list.getList()[3] = 10;
	//cout << my_list.getList()[3] << endl;  //() 가 있으니 번거로움

	IntList my_list;
	my_list[3] = 10;
	cout << my_list[3] << endl;


	//const 버전에서 호출해야할수도 있음
	const IntList my_new_list;
	//my_new_list[3] = 10;  //값을 바꾸려고 하기 때문에 불가능
	cout << my_new_list[3] << endl;



	//주의사항 : 포인터를 쓸때
	IntList* list = new IntList;
	
	//list->operator[](3) = 10;
	
	//실수로 list[3] 을 할 경우 에러 발생(의도가 다름)
	//list[3] = 10; not ok
	//list[3] = IntList  //list 의 array 이기 때문에 다른 문제가 됨


	//정상적인 방법
	(*list)[3] = 10;


	return 0;
}
