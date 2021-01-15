//클래스(class)와 const

//class 의 instance 를 const 로 만들었을때는 const member function 만 사용이 가능
//instance 를 함수의 인자로 받는 함수를 만들때 parameter 를 const reference 로 해야 
//복사생성자가 호출되지 않고, 복사가 일어나지 않음

#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
	int m_value = 0;
	
	void setValue(int value) { m_value = value; } //const 함수로 못바꿈, m_value 를 바꾸려고 시도하고 있어서
	
	//int	 getValue() { return m_value; }
	//멤버함수를 const 로 만들기 : 함수 안에서 m_value 의 값을 바꾸지 않는다
	int	 getValue() const
	{
		return m_value; 
	}

	Something()
	{
		cout << "constructor" << endl;
	}

	//copy constructor 가 숨어있음
	Something(const Something& st_in)
	{
		m_value = st_in.m_value;

		cout << "copy constructor" << endl;
	}
};

//복사 생성자 호출함
void print(Something st)
{
	cout << &st << endl;

	cout << st.getValue() << endl;
}

//복사 안하고 보내고 싶을때
void print_ref(const Something& st) //parameter 를 const reference 로 바꿔줌
{
	cout << &st << endl;

	cout << st.getValue() << endl;
}


class Something_new
{
public:
	string m_value = "default";

	//const 유무로 오버로딩을 할 수 있음
	const string& getValue() const  //멤버함수를 const로 만드는 경우 return 도 const 로 만드는게 일반적
	{
		cout << "const version" << endl;
		return m_value;
	}

	string& getValue()
	{ 
		cout << "non-const version" << endl;
		return m_value; 
	}
};

int main()
{
	//const 는 기본적으로 상수로 만들고 싶을때 사용함

	const Something something;  //member variable 을 const 로 만드는 것과 같은 효과
	//something.setValue(3);	//m_value 의 값을 못바꿈, 바꾸려고 하기 때문에 불가능


	//getValue() 에서 m_value 의 값을 바꾸려고 하지 않지만 const 때문에 문제가 생김
	//컴파일러는 m_value 값이 바뀌고 안바뀌고로 판단하지 않고 멤버함수가 const 냐 아니냐로 판단함
	cout << something.getValue() << endl;


	//class 의 instance 를 const 로 만들었을때는 const member function 만 사용이 가능
	//함수가 복잡해질경우 const 가 가능한 경우 다 넣는게 좋음(디버깅에 유리함)



	//copy constructor
	Something something_new;

	cout << &something_new << endl; //print() 안에서 호출되는 st 와 주소 비교 : 서로 다름

	print(something_new); 

	//생성자가 호출됨
	//&something_new 출력
	//print() 로 들어감
	//복사 생성자 호출
	//copy 하려고 들어온 something_new를 복사함
	//"copy constructor" 출력
	//print() 로 들어가고 m_value 에 들어간 복사된 something_new 의 주소 와 m_value 출력 


	// 복사가 된 증거 <- 주소가 다름


	//복사를 하고 싶지 않을때
	print_ref(something_new);
	//const reference 를 parameter 로 했기 때문에 st 가 받아온 something_new 가 
	//여기서 보낸 somthing_new 와 같음  
	//그렇기 때문에 복사 생성자도 호출되지 않고 something_new 의 주소도 같음
	//매우 효율적



	//const 유무로 오버로딩을 할 수 있음
	//return type 만 다른거론 오버로딩은 불가능 하지만 const 유무로는 가능함
	Something_new smthing;
	smthing.getValue() = 10; //non-const version

	const Something_new smthing2;
	smthing2.getValue(); //const version  : = 1004 처럼 assingment 불가능

	return 0;
}
