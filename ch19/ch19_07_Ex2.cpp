#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>	//std::forward


//r value reference 로 parameter 를 받는 함수를 overloading 할때는 내부적으로 move constructor 를
//사용하려는것을 의도하고 구현하는 것이기 때문에 std::move 를 사용하여 명시해줘야함

using namespace std;

class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);		//생성자에서 직접 초기화 하는것보다 초기화 하는 코드를 별도로 분리하는게 편함 
	}


	//copy constructor
	CustomVector(CustomVector& l_input)
	{
		cout << "Copy constructor" << endl;

		init(l_input.n_data);	

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	//move constructor
	CustomVector(CustomVector&& r_input)
	{
		cout << "Move constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	
	~CustomVector()
	{
		delete[]ptr;
	}



	//생성자에서 직접 초기화 하는것보다 초기화 하는 코드를 별도로 분리하는게 편함
	void init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};


void doSomething(CustomVector& vec)
{
	cout << "Pass by L-reference" << endl;
	CustomVector new_vec(vec);	//copy constructor 호출
}

void doSomething(CustomVector&& vec)
{
	cout << "Pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec));	//move constructor 호출
	//std::move 로 명시하지 않으면 l value 로 받음, vec 자체는 l value 라서 그럼
}

//템플릿화 할때 문제가 발생함
//std::forward 를 사용하여 perfect forwaring 구현
template<typename T>
void doSomethingTemplate(T&& vec)	//&& 로 받아도 std::forward 사용안하면 소용 없음(l value 로 받음)
{
	doSomething(std::forward<T>(vec));	//
}

int main()
{
	CustomVector my_vec(10, 1024);

	CustomVector temp(my_vec);	//l value 로 들어왔으니 copy constructor 호출

	CustomVector temp2(std::move((my_vec)));	//r value 로 넣어서 move constructor 호출
	//my_vec을 r value 로 바꾼다 라는 의미 보다는 실질적으로 생성할때 copy constructor 가 아니고 
	//move constructor 를 호출하겠다는 의미가 강함




	doSomething(my_vec);
	//doSomething(std::move(my_vec));	//이 경우 밑에서 my_vec 를 다시 못쓰기 때문에 이런 방법은 권장하지 않음

	doSomething(CustomVector(10, 8));	//바로 r value reference 로 넘어감, move constructor 호출



	//템플릿화 할때 문제가 발생함
	//std::forward 사용
	doSomethingTemplate(my_vec);
	doSomethingTemplate(CustomVector(10, 8));

	//데이터의 개수가 많을 경우 copy constructor 와 move constructor 의 성능 효율이 많이 차이남

	my_vec;	//doSomethingTemplate 에서 my_vec 를 l value 로 받았기 때문에 my_vec 를 사용할 수 있음

	return 0;
}