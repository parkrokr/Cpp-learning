// 암시적 형변환(Implicit Type C0nversion (coersion)) 과
// 명시적 형변환(Explicit Type Conversion (casting) )

#include <iostream>
#include <typeinfo> // typeid()를 사용하기 위해 필요함
#include <iomanip>

int main()
{
	using namespace std;


	// typeid( )안에 dadta literal 이나 변수명을 집어넣고 .name() 함수를 호출하면 어떤 type인지 출력해줌
	cout << typeid(4.0).name() << endl;

	int a = 123;
	cout << typeid(a).name() << endl;
	

	//암시적 형변환(Implicit Type Conversion (coersion))
	
	//암시적 형변환 은 프로그래머가 형변환을 해달라 라고 요청하지 않는경우
	// 컴파일러가 알아서 강제로 형변환을 시켜버리는것
	// int a = 123.0 하는 경우 컴파일러가 double 을 int 로 변환함
	// int a = (int)123.0; 같은 경우 명시적 형 변환

	
	
	//numeric promotion 작은 것을 큰 것으로  
	float f = 1.0f; //double 이 float 보다 큼(메모리)
	double d = f;  // numeric promotion

	//정밀도가 떨어지는 문제는 없음
	//ex) int -> long , char -> int , int -> float


	
	
	//numeric conversion 큰 것을 작은 것으로 , type이 바뀌는 것 
	double b = 3;
	short s = 2;

	
	//문제가 생길 수 있음
	int i = 30000;
	char c = i; //char 범위가 255 까지고 singed 경우-128~ 127 까지기 때문에 i를 다 담을 수 없음

	//변수 c를 char type으로 출력하면 결과를 보기 힘들끼 때문에 명시적 형변환 static_cast 를 사용함
	cout <<static_cast<int>(c) << endl; // 48
	
	//double 의 정밀도가 높기 때문에 데이터의 손실이 일어날 수 있음  possible loss of data
	double d1 = 0.123456789;
	float f1 = d1;
	cout << std::setprecision(12) << d1 <<"\n" << f1 << endl;

	//정수형을 실수형으로 바꿀때도 최대한 비슷하게 바꿔줌
	int i2 = 1234;
	float f2 = i2;
	cout << std::setprecision(12) << i2 << "\n" << f2 << endl;
	// 이때도 possible loss of data 경고가 뜸. 그 이유는 float가 int 보다 표현 범위가 넓고
	//그렇기 때문에 모든 int 는 float의 범위 안에 있지만 모든 int 값을 float가 정확하게 표현할 수 있는것은 아니다
	//그래서 float로 최대한 비슷한 값으로 바꾸지만 정확도는 떨어지기 때문에(정수에 근사하는 실수) 경고가 뜨는 것이다.

	// 암시적 형변환을 할때 float나 double 뒷부분의 소숫점 부분은 버림됨
	float f3 = 3.14f;
	int i3 = f3;
	cout << std::setprecision(12) << f3 << "\n" << i3 << endl;



	//작은 값을 넣을때는 문제가 생기지 않을수도 있음
	int i1 = 2;
	char c1 = i1;
	cout << static_cast<int>(c1) << endl; // 이땐 문제가 없음

	


	// unsigned 는 조심해야함
	// unsigned 끼리 계산한걸 unsigned에 넣으려고 함
	cout << 5 - 10 << endl;
	cout << 5u - 10 << endl; // u 는 unsigned
	cout << 5 - 10u << endl;
	cout << 5u - 10u << endl;

	
	//형변환에도 우선순위가 있음
	//int 보다 작은거(4byte 이하)는 int로 바껴짐
	//우선순위가 높은건 낮은것으로 안바뀜, unsigned int 를 int로 안바꿈
	//int, unsigned int, long , unsigned long,
	//long long, unsigned long long, float, double, long double(highest)


	
	
	// 명시적 형변환(Explicit Type Conversion (casting) )
	int x = int(4.0);   //c++ style
	int x1 = (int)4.0;  //c	  style
	int x2 = static_cast < int>(4.0); //아직까진 기능상 차이는 없음

	return 0;
}
