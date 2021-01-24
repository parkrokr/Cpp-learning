//구조체 struct

//다양한 요소들을 묶어서 마치 하나의 사용자 정의 자료형인것처럼 사용

#include<iostream>
#include<string>

using namespace std;

//사람에 대해서 모두 출력하는 함수
/*void printPerson(double height, float weight, int age, name . . .)
{

}*/
//많은 변수들을 매번 구현하는건 부담스러움

struct Person
{
	double height;
	float  weight;
	int	   age;
	string name;

	//초기화를 멤버에 직접 할수도 있음
	/*double height = 3.0;
	float  weight = 200.0;
	int	   age = 50;
	string name = "Mr. Incrdible";*/

	//구조체에 속해있는 함수
	//data와 기능을 묶을 수 있음
	void print()
	{
		// 멤버 선택 연산자를 쓸 필요가 업음
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}
};


/*void printPerson(Person ps)
{
	// 이 함수에서 기능하는 변수들은 Person 에 속해있는데 굳이 ps라는 parameter 를 쓸 필요가 없음
	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
	cout << endl;
}*/


//구조체 안에 구조체를 넣을 수 있음
struct Family
{
	Person me, mom, dad;
};

//함수가 구조체를 return 하게 할수도 있음
Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack Jack" };

	return me;
}

struct Employee	      //2 +(2) + 4 + 8 = 16  //(2)가 추가되는걸 padding 이라 함
{
	short	id;       //2 bytes + (2)
	int		age;	  //4 bytes
	double	wage;	  //8 bytes
	
	//멤버 type 순서를 맞춰주는게 최적화랑 프로그램 가속화에 중요함
	//struct member alignment
};


int main()
{
	/*//여러 사람을 저장할때
	double height1, height2, height3;// 배열 double height1[100]을 사용해 표현할 수 있다
	//여러 변수를 사용해야 한다는 것은 다름이 없음, weight age 들을 각각 따로 구현해 줘야함
	float weight;
	int age;
	string name;*/


	//struct 사용
	Person me{ 2.0, 100.0, 20, "Jack Jack" }; // uniform 초기화 방식이 유용함
	//구조체 멤버에 초기화가 되어있어도 me 의 초기값을 따름


	//printPerson(me); //함수가 구조체 밖에 있을 경우
	me.print();		   //함수가 구조체 안에 있을 경우
   

	//대입도 가능
	//Person me2(me);

	//단순한 경우에만 해줌
	//맴버가 복잡해지면 원하는 대로 작동하지 않을 수 있음
	Person me2;
	me2 = me;

	me2.print();
  

	//구조체 안에 있는 멤버에 접근하려면 ps 뒤에 .(member selection operator) 을 붙여야함
	//예전 초기화 방식
	/*me.age = 20;
	me.name = "Jack Jack";
	me.height = 2.0;
	me.weight = 100.0;*/
	
	
	//함수가 구조체 parameter 로 받을수도 있고 return 하게 할수도 있음
	Person me_from_func = getMe();
	me_from_func.print();


	Employee emp1;

	//sizeof()를 구조체 크기를 측정할때도 사용할 수 있음
	cout << sizeof(Employee) << endl; // 16, 14가 아님
	//short 가 2bytes 가 아니라 4bytes가 할당되어있을수도 있음
	//data structure alignment 검색

	return 0;
}
