//객체지향 프로그래밍과 클래스 Object Oriented Programming (OOP) , Class

//structure 에는 data 만
//class 에는 data 와 기능를 묶은것, 객체 object
//class 에는 access specifier 가 들어감

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//친구들에 대해 정리해두고 원할때 친구에 대해서 출력하는 프로그램
// Friend : name, address, age, height, wheght, ...

//void print(const string& name, const string& address, const int& age,
//	const double& height, const double& weight)
//{
//	cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
//}

//structur 안에 들어있는 변수들을 member 라고 부름
//struct Friend
//{
//	string	name;
//	string	address;
//	int		age;
//	double	height;
//	double	weight;
//
//	//print() 도 structure 의 member 가 되는것
//	//같은 member 이기 때문에 직접 data에 접근할 수 있음
//	void print()
//	{
//		cout << name << " " << address << " " << age << " " << height <<
//			" " << weight << endl;
//	}
//};


//다른 친구들을 출력하기 위해서 또 다시 치기가 힘드니 함수 parameter 를 structure 로 받기
//매개변수가 다르기 때문에 오버로딩 가능
//fr.을 하는게 반복되는 일임, print() 를 structure 에 넣어주기
//void print(const Friend &fr)
//{
//	cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height <<
//		" " << fr.weight << endl;
//}


class Friend
{
public: // access specifier 접근 지정자 (public, private, protected)

	//member 라는걸 알리기 위해 m_ 앞에 붙이기
	//최근 구글 스타일에선 뒤에 _ 붙이기
	//앞에 _ 붙이는 스타일도 있음
	string	m_name;
	string	address_;
	int		_age;
	double	height;
	double	weight;

	void print()
	{
		cout << m_name << " " << address_ << " " << _age << " " << height <<
			" " << weight << endl;
	}
};


int main()
{
	
	/*string	name;
	string	address;
	int		age;
	double	height;
	double	weight;
	
	print(name, address, age, height, weight);*/


	//struct 에 넣어버리면 데이터를 묶을 수 있음

	// uniform initialization
	//Friend jj{ "jack jack",  "uptown",2,30,10 };

	//coppy initialization
	/*Friend jj;
	jj.name = "jack jack";
	jj.age = 2;
	jj.address = "uptown";*/

	//print
	//print(jj.name, jj.address, jj.age, jj.height, jj.weight);


	//다른 친구들을 출력하려면 또다시 코드를 쳐야함
	//print() 의 parameter를 structure 로 받기
	//print(jj);


	//fr. 을 치는게 반복됨, print() 를 structure 안에 넣어 member 가 되게 하기
	//print() 가 직접적으로 Friend 데이터에 접근할 수 있음

	//jj.print(); //jj가 print()를 하는것처럼 보이기에 프로그래머가 이해하고 설계하기가 더 자연스러움




	//Friend 처럼 date 와 기능이 묶여 있는걸 object 라고 부름
	//structure 에도 기능( 함수) 를 넣을 수 있지만 
	//보다 더 많은 기능, 기법들을 다룰 수 있게 만든 것이 class 임

	//단순한 기능말 할때는 class 대신에 structure 를 써도 됨
	//하지만 일반적으로 sturcture 는 data 를 묶을때만 쓰고
	//기능을 넣을때는 class 를 사용함

	//c 에서는 structure 에 기능을 넣을 수 없음

	//date 와 기능을 묶은 개념이 객체, object
	//객체를 프로그래밍 언어로서 구현하는 단어가 class 



	//class 를 정의하는거만으로는 메모리를 사용하지 않음
	//이름을 쓰고 선언해야 메모리를 차지함

	Friend jj{ "jack jack",  "uptown", 2, 30, 10 };
	jj.print();
	// instanciation		메모리를 갖도록 정의해주는 것
	// instace			object 를 구현하기 위해 만든 class 의 변수

	//instanciation 을 해줘야 실재로 존재함
	//JJ의 주소는 찍을 수 있지만 Friend_class 의 주소는 찍을 수 없음






	//더 많은 친구들의 데이터를 저장
	/*vector<string>	name_vec;
	vector<string>	addr_vec;
	vector<int>		age_vec;
	vector<double>	height_vec;
	vector<double>	weight_vec;

	print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);*/

	//위에처럼 각각 만드려니 힘듬
	
	vector<Friend> my_friends;
	my_friends.resize(2); // 2명 저장 가능

	//print
	//my_friends[0].print();
	//my_friends[1].print();  //친구가 많아지면 하나하나 못침

	//for 문으로 print
	for (auto& ele : my_friends)
		ele.print();



	return 0;
}
