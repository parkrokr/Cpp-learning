//소멸자 Destructor

//생성자 : 생성될때 호출되는 함수 <-> 소멸자 : 변수가 영역을 벗어나서 사라질때(소멸될때) 호출되는 함수

//vector 내부도 이렇게 만들어져 있음
//class 내부에서 new 로 메모리를 만들고 있다면 소멸자 같은 곳에서 반드시 delete 로 지워주기

#include <iostream>

using namespace std;


class Simple
{
public:
	int m_id;

	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	//소멸자,  parameter 없음
	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
		//cout << "constructor" << endl;
	}

	int getLength(){ return m_length; }
	
	int size(){ return m_length; } //m_length 를 unsigned 로 할 수 있지만 강의코드라 단순

	//delete 할때 편한 소멸자
	~IntArray()
	{
		if(m_arr != nullptr) //더 안전한 방법 : nullptr 일때도 delete 하려고 하면 문제 발생
			delete[]m_arr;
	}

	//delete 를 할때 delter 가 nullptr을 검사하는 코드가 있지만 장기적인 관점과 퍼포먼스에
	//매우 민감한 경우 nullptr 을 지우려고 시도하는 자체가 구현에 문제가 있다는것임
	//실무에서 nullptr 검사없이 delete 를 쓰려 한다면 차라리 smart pointer 를 써서
	//delete 를 안쓰는게 더 현대적 이지만 공부하는 과정에선 런타임에 포인터가 nullptr
	//인지 아닌지 예측할 수 있는 코드를 작성하는게 장기적으로 좋음
};


int main()
{
	//Simple s1(0);
	//Simple s2(1);

	/*Constructor 0
	Constructor 1
	Destructor 1
	Destructor 0*/

	//소멸은 생성의 반대 순서로 실행된다(스택처럼) 
	//멤버 변수의 안전한 소멸을 위해 반대로 소멸되는것 같음?

	//동적 할당
	Simple *s1 = new Simple(0);
	Simple s2(1);

	delete s1;  //Destructor 0	

	/*Constructor 0
	Constructor 1
	Destructor 0		
	Destructor 1*/


	//소멸자는 instance 가 메모리에서 해제될 때 내부에서 자동으로 호출됨.
	//동적할당으로 만들어진 경우 영역을 벗어나도 자동으로 메모리가 해제되지 않기
	//때문에(delete 안하면 메모리 누수) delete로 메모리를 해제할 때에만 소멸자가 호출됨
	//소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 권장되지 않음


	//소멸자는 delete 할때 유용함
	while (true)
	{
		IntArray my_int_arr(100); //delte 없으면 memory 누수 일어남
		//delete ... 프로그래머가 IntArray 사용할때마다 delete 를 일일히 해주는게 번거로움  -> 소멸자 사용
	}


	//이렇게 구현하는게 불안하면 vector 사용
	//vector 안에 이런 방식이 구현되어 있음

	return 0;
}