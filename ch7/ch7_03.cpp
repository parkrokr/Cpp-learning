//참조에 의한 인수 전달 Passing Arguments by Reference (Call by Reference)

//c++는 함수 return 값이 하나만 가능하기 때문에 매개변수를 많이 쓰는 경우가 많음
//일반적으로 입력이 앞, 출력을 참조로 뒤에 둠

//const int& x 아주 자주 쓰는 표현


#include<iostream>
#include <cmath> // sin() , cos()
#include <vector>


using namespace std;

void addOne(int& y) //call by value 였다면 밖에 영향을 끼지치 못했음
{
	cout << y << " " << &y << endl;

	y = y + 1;
}


//함수의 출력을 가져오는데 사용하기도 함
//degress 는 함수의 입력, sin_out, cos_out 는 함수의 출력으로 사용함

//degrees 는 내부에서 값이 안변하니 const, &로 하면 더 좋음
void getSinCos(const double &degrees, double& sin_out, double& cos_out) 
{
	static const double pi = 3.141592 / 180.0; //헤더로 뽑는 방법도 있음 , / 연산을 한번만 하게 
	
	const double radians = degrees * pi ;  //한번 계산되고 안바뀌는 것들을 const로
	
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}


//참조로 넘길때의 단점
//foo(6); 이 안됨 // 6은 주소가 없음(literal 이기 때문)
//void foo(int x) 로 하거나 void foo(const int &x) 로 하는 방법이 있음
//대신 const int &x는 내부에서 값이 바뀌지 않을 때만 가능

void foo(const int& x)  //const int& x 아주 자주 쓰는 표현
{
	cout << x << endl;
}


//포인터 변수를 참조로 받는 방법
void foo_ptr(int*& ptr)
{
	cout << ptr << " " << &ptr << endl;
}


//array를 parameter에 전달하는 방법

//void printElement(int(&arr)[4]) //element 개수가 명확해야함
//보통 이렇게 array를 보낼때는 정적보단 동적 array 를 보냄
void printElement(const vector<int>& arr)
{

}

int main()
{
	int x = 5;

	cout << x << " " << &x << endl;  //5

	addOne(x);

	cout << x << " " << &x << endl;  //6


	//함수의 출력을 가져오는데 사용하기도 함
	//c, c++에선 함수의 return 값이 하나지만 여러개의 값을 return 할 일이 자주 있음

	//변수를 미리 선언하고 참조로 넘겨서 output 이 여러개가 나오게 하는 방법
	double sin(0.0);
	double cos(0.0);

	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl;


	//참조로 넘길때의 단점
	//foo(6); 이 안됨 // 6은 주소가 없음(literal 이기 때문)


	//입력을 const int &x 처럼 받고 출력을 참조로 하는게 전통적인 방법
	//모던 c++에선 return value optimization 기술이 잘 도입되어 있고
	//여러개의 return type 을 구현하는것이 복잡하지 않게됨 
	//강의 19.2 C++17 함수에서 여러 개의 return값 반환하기 참고



	//포인터에 대한 참조를 보내기

	//int*& ptr 를 (int*) &ptr 로 이해해도 됨(컴파일러는 안받아줌)
	//또는 typedef int* pint; 를 통해 명확하게 해도 됨
	//이중포인터 쓸때 돌려서 쓰면 실수가 줄어들 수 있음

	x = 5;
	int* ptr = &x;

	cout << ptr << " " << &ptr << endl;
	foo_ptr(ptr);

	//이렇게 보내면 포인터 변수에 담겨있는 주소값도 같이 넘어가고 포인터 변수의 주소도 같이 넘어감



	//array를 parameter에 전달하는 방법

	//void func(const vector<int>& arr) 가 일반적임
	
	//int arr[]{ 1,2,3,4 }; //보통 이렇게 array를 보낼때는 정적보단 동적 array 를 보냄
	vector<int> arr{ 1,2,3,4 };

	 printElement(arr);
	//보통 이렇게 array를 보낼때는 정적보단 동적 array 를 보내기 때문에 별도로 class 를 만듬
	//std::array 와 std::vector 를 사용하면 보내기 더 편함


	return 0;
}