// 템플릿을 부분로 특수화하기 Partial Specialization

//template parameter 가 여러개인 경우 모두 다가 아닌 부분적으로 특수화

//멤버함수는 직접 특수화 하기가 조금 번거로움
//편하게 하는 방법 : 클래스 상속 받기
//기존 클래스를 _BASE 로 만들고 기존 이름과 같은 클래스가 상속받게 만든후
//그 클래스를 특수화 시키고 필요한 함수를 오버라이딩
//상속을 받는 방법으로 구현하는게 전체를 특수화 하는것보다 편함
//전체를 특수화 하려면 다른 함수들도 반복적으로 구현해야됨(전 강의의 클래스 특수화처럼 그냥 새로운 클래스를 만드는꼴)
//상속을 사용하면 클래스 내부에 print() 만 있어도 상속을 받았기 때문에 다른 함수들도 사용 할 수 있음


//template parameter를 모두 특수화 하여 '완전 특수화'를 할때만 멤버 함수를 클래스 바깥에서 특수화 가능
//예제를 완전 특수화 하려면 char, 3 같이 구체화 해야하지만 size 는 구체화 하면 안되기 때문에
//class 만 특수화 하는 부분특수화 를 하려고 하는것, 그리고 멤버함수를 클래스 밖에서 특수화 할때
//부분특수화는 허용되지 않음(함수의 오버로딩을 복잡하게 해서인것으로 추측?)



#include <iostream>
using namespace std;

// class T 에 대해 템플릿화가 되어있고 int size(Non-type parameter) 에 대해서 템플릿화가 되어있음
template <class T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}


	//밖에 있던 print() 를 멤버함수로 만들기

	//template <typename T, int size>		//위에 있으니 있을필요 없음
	void print()							//StaticArray<T, size>& array 도 받을 필요 없음
	{
		for (int count = 0; count < size; ++count)
		{
			//std::cout << array[count] << ' ';
			std::cout << (*this)[count] << ' ';
		}
		std::cout << endl;
	}
};


//print() 함수를 멤버함수로 넣고 싶음
/*
//함수도 템플릿화가 되어있음
template <typename T, int size>
void print(StaticArray<T, size>& array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count] << ' ';
	std::cout << endl;
}

//typename T 랑 int size 중에서 typename T 만 특수화
template <int size>
void print(StaticArray<char, size>& array)
{
	for (int count = 0; count < size; ++count)
		std::cout << array[count]; //char type 에 대해서 빈칸을 출력하지 않기
	std::cout << endl;
}
*/


//멤버함수를 특수화 할때 기존 클래스를 _BASE 로 만들고 그 클래스를 상속받는 클래스를 만듬(기존의 이름이랑 동일한)
//상속을 쓰는 이유는 template 을 통째로 특수화 하는것보단 편하기 때문

template <class T, int size>
class StaticArray :public StaticArray_BASE<T, size>
{
};

//class 가 char type 인 경우에 대해서만 별도로 상속을 한번 더 받음
template <int size>
class StaticArray<char,size> :public StaticArray_BASE<char, size>
{
public:
	//print() 를 오버라이딩
	void print()							
	{
		for (int count = 0; count < size; ++count)
		{
			std::cout << (*this)[count];	// << ' ' 제거
		}
		std::cout << endl;
	}
};
//상속을 받았기 때문에 print() 말고 다른 함수들을 다시 구현해줄 필요가 없음



int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	//print(int4);  //print() 를 멤버함수로 만들기 전
	int4.print();
	//1 2 3 4   //빈칸 하나씩 잘 출력되고 있음


	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';
	//. . .

	strcpy_s(char14.getArray(), 14, "Hello, World");

	//print(char14);  ////print() 를 멤버함수로 만들기 전
	char14.print();
	//특수화 전 : H e l l o ,   W o r l d  ?  
	//문자열을 출력하는데 비어있는곳이 문제가 됨
	//print() 의 << ' '; 부분이 문제되는곳임
	//char type 에 대해선 print() 를 할때 빈칸이 없었으면 좋겠음 -> 특수화
	
	//typename T 랑 int size 중에서 typename T 만 특수화를 해줘야됨(size 에 들어갈수 있는게 너무 많음)


	//print() 를 멤버함수로 넣은후 다시 빈칸이 살아남
	//멤버함수는 특수화 하기가 조금 번거로움
	//편하게 하는 방법 : 클래스 상속 받기
	//먼저 StaticArray 를 StaticArray_BASE 로 만들고(여기까지만 하면 기존에 선언된 인스턴스를 사용못함)
	//StaticArray_BASE를 상속받는 StaticArray 를 만듬


	return 0;
}
