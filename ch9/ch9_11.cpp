//대입 연산자 오버로딩, 깊은 복사( Deep copy ) vs 얕은 복사 ( Shallow copy )

//얕은 복사
//기본 복사 생성자가 해준것 : m_data에 있던 메모리 주소값 복사
//동적 할당된 메모리가 연관되어있을 경우 큰 문제 발생

//깊은 복사
//복새 생성자가 포인터 주솟값을 복사하지 않고 메모리를 다시 할당받고 있음
//값들을 다시 복사해주고 있음


//std::string 그냥 사용 또는 상속을 받아 추가 구현
//member variable 에 std::string data 하나 만들어 쓰기(퍼포먼스는 약간 떨어질 수 있지만 코드 잘짜면 큰차이 안남)

//최근엔 std::string 을 class 안에 넣는 방법을 주로 사용하지만 이런 문제들이 발생할 수도 있다는걸 알아야됨


#include <iostream>
#include <cassert>

using namespace std;

class MyString
{
//private:  //일반적으로 private, 주소를 찍기 위해 public 으로 구현
public:
	char* m_data = nullptr;  //문자열의 주소를 저장하기 위한 포인터
	int m_length = 0;

	std::string data; //std::stdring 을 사용하면 이런 문제들을 피해서 구현할 수 있음
public:
	MyString(const char* source = "")
	{
		assert(source); //문자열이 비진 않았는지

		m_length = std::strlen(source) + 1;  //문자열이 몇글자 인지 알아내고 '\0'을 추가하기 위해 +1
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)  //값을 하나하나 복사
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';  //마지막에 \0 을 넣어 문자열 마지막이라는것을 표시
	}

	//복사생성자
	//source 가 복사해주고 반드시 사라진다는 보장이 있으면 메모리를 안지우고 source 의 메모리를 써도 됨
	//그런 경우가 있음
	//복사생성자를 구현하지 못했지만 얕은 복사는 막아야 할 경우
	//MyString(const MyString& source) = delete; 해서 막기(차선책)
	MyString(const MyString& source)
	{
		cout << "Copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr) //source.m_data 가 메모리를 갖고있을경우
		{
			m_data = new char[m_length]; //새로 메모리 할당받기

			for (int i = 0; i < m_length; ++i) //새 메모리에 source.m_data 복사하기
				m_data[i] = source.m_data[i];  //source 의 메모리가 가지고 있던 내용들을 복사
		}
		else
			m_data = nullptr;  //nullptr 대신 0 넣는 경우도 있지만 최신은 nullptr

	}


	//대입 연산자
	MyString& operator = (const MyString& source)
	{
		//shallow copy   
		//복사만 해주고 끝남(기본 복사 생성자가 생긴 형태)
		/*this->m_data = source.m_data;
		this->m_length = source.m_length;*/


		cout << "Assignment operator " << endl;

		//prevent self-assignment 복사생성자와 달리 대입연산자는 가능한 문제(hello = hello)
		//아무것도 못하게 막기
		if (this == &source) 
			return *this;

		//생성자는 자기가 처음 생성되는것이기 때문에 이전에 동적할당된 메모리를 갖고있지 않음
		//대입 연산자라면 이미 메모리를 가지고 있을 수 있음  -> 지워버림
		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }


	//소멸자
	~MyString()
	{
		delete[] m_data;  //사라질때 memory leak 을 막기 위해 delete ( 반드시 필요한 조치 )
	}
};

//이부분이 복사생성자와 대입연산자에서 복사되고 있으니 함수로 만들어서 빼기도 함
//m_length = source.m_length;
//
//if (source.m_data != nullptr)
//{
//	m_data = new char[m_length];
//
//	for (int i = 0; i < m_length; ++i)
//		m_data[i] = source.m_data[i];
//}
//else
//m_data = nullptr;


int main()
{
	//동적 메모리 할당을 사용하는 경우 복사 생성자를 만들거나 대입연산자를 오버로딩할때 주의해야함
	//최근엔 그리 어렵지 않고 container 를 사용함


	MyString hello("hello");

	cout << (int*)hello.m_data << endl;  //cout 에 문자열 주소가 들어오면 문자열을 출력하기 때문에 (int*)로 cast
	cout << hello.getString() << endl;



	//scope 를 정의하고 안에서 local variable 을 또 만듬
	{
		//copy 가 생성되고 있기 때문에 대입연산자가 아닌 복사생성자가 호출됨(구현 안했으면 기본 복사 생성자)
		MyString copy = hello;  
		cout << (int*)copy.m_data << endl;  //copy.m_data 와 hello.m_data 의 주소가 같음
		cout << copy.getString() << endl;
	}
	//copy 에서 주소값만 복사해서 가지고 있음(기본 복사생성자를 컴파일러가 만들어줬고 new 를 호출하지 않았음)
	//heap 에는 hello 에서 new 로 할당받은 메모리 하나밖에 없음
	//copy 가 scope 에서 벗어나면서 delete 로 지워버림
	//copy 는 사라졌지만 hello 의 주소도 같이 지워져버렸기 때문에


	cout << hello.getString() << endl;
	//이상한 값이 출력됨




	//얕은 복사
	//기본 복사 생성자가 해준것 : m_data에 있던 메모리 주소값 복사
	//동적 할당된 메모리가 연관되어있을 경우 큰 문제 발생


	//깊은 복사
	//복새 생성자가 포인터 주솟값을 복사하지 않고 메모리를 다시 할당받고 있음
	//값들을 다시 복사해주고 있음



	//복사생성자가 호출되는 경우와 대입 연산작 호출되는 경우
	//복사 생성자 호출
	MyString str1 = hello; 
	//MyString str1(hello); 기능상 같지만 이렇게 하면 덜 헷갈림

	//대입 연산자 호출
	MyString str2;
	str2 = hello;
	return 0;
}