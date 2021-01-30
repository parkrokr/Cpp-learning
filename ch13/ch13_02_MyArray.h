#pragma once
#include <iostream> 
#include <assert.h> //for assert()



//일반화 시키기  

//template 의 매개변수가 class 가 아닐수 있기 때문에 typename 이 좀더 일반적
//typename 대신에 class 를 써도 문제 생긴적은 거의 없다
//T를 변수명처럼 생각하면 되고 함수를 일반화하기 이해서 변수에 대해서 정의하는것처럼 
//입력으로 들어오는걸 매개변수라 하듯이
//템플릿화(templatize) 할때 어떠한 type 에 대한 매개변수라고 생각할 수 있음


template<typename T>		
class MyArray
{
private:
	int m_length;
	//int* m_data;
	//int 만 담지 말고 double, float, bool, . . . 을 담게 일반화

	T* m_data;


public:
	MyArray()
	{
		m_length = 0;
		m_data = nullptr;
	}

	MyArray(int length)
	{
		//m_data = new int[length];
		m_data = new T[length];
		m_length = length;
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	//int& operator[](int index)
	T & operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
		//index 를 받으면 그 index 에 해당하는 int 형 data 를 참조로 반환
		//템플릿화 시킨후 T 로 바꿔주기(기존엔 int 가 나가고 있었기 때문에)
	}

	int getLength()
	{
		return m_length;
	}

	void print();

	//헤더에 class 안에 코드가 다 있는게 길어져서 class 밖으로 빼기 위해 move definition location 을 함
	/*void print()  
	{
		for (int i = 0; i < m_length; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}*/
};


//move definition loacation 을 했지만 그냥 MyArray.h 로 들어옴

//이 클래스가 템플릿화가 되지 않았었다면
//밑에 처럼 되었겠지만
//void MyArray::print()
//{
//	. . .
//}


//하지만 template 이기 때문에
/*template<typename T>		//template paramter 가 들어있고
void MyArray<T>::print()	//여기도 template paramter 가 들어있음
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}*/

//이왕 definition 을 뺐으니 cpp 파일로 옮기면?
//링킹 에러 발생!


//링킹 에러 자체가 컴파일러에서 어디서 에러가 발생했는지 알려주지 않기 때문에 어려운 측면이 있음

//main() 있는 cpp 에서 include "MyArray.h"를 하면 내용물이 전부 main.cpp 로 복사해서 붙여넣기
// 한것처럼 작동함

//MyArray<char> my_array(10); 을 하면 MyArray 라는 class 를 char type 에 대해서
// instantiation를 해야되는구나 까지 컴파일러가 인지함

//print() 라는 멤버함수의 body 를 컴파일 할때는  MyArray.cpp 에서 컴파일을 함

//main.cpp 에서는 MyArray.h 만 include 하기 때문에 MyArray.cpp 에 있는 내용을 모름
//그래서 MyArray.cpp 에 있는 함수를 instantiation 을 할때 char type 으로 해야된다는걸 모름


//정리: main.cpp 에서 컴파일을 할땐 MyArray.cpp에선 어떤 type 으로 instantiation 할지 모름
