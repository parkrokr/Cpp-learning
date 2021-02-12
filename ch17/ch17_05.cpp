// std::string	대입, 교환, 덧붙이기 ( append ) , 삽입

//많은 함수들이 오버로딩되어 있어서 필요하면 찾아 쓰면 됨
//구현되어있지 않은경우 오픈소스에서도 많이 보강되어 있음
//대부분의 경우 std::algorithm 과 결합하면 해결됨

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//초기화 하는 여러가지 방법들
	string str1("one");

	//직관적으로 생각되는 거의 대부분의 방법이 됨
	string str2;
	str2 = str1;
	str2 = "two";

	cout << str2 << endl;	//two
	
	//assign()
	//assign() 의 return type 이 string & 임, 자기자신에 대한 ref 반환
	//iterator 도 사용가능
	str2.assign("two");		
	str2.assign("two",2);	//앞의 2글자만 가져옴, ch17_02 참고
						
	cout << str2 << endl;	//tw



	//swap()
	string str3("three");
	string str4("four");

	cout << str3 << " " << str4 << endl;		//three four

	std::swap(str3, str4);

	cout << str3 << " " << str4 << endl;		//four three

	str3.swap(str4);		//string 이 swap() 을 가지고 있음

	cout << str3 << " " << str4 << endl;		//	three four



	//append() 
	//뒤에다가 덧붙이는 함수
	//오버로딩된 함수들이 많음
	//string 이 들어갈 수 있음
	str2.assign("two").append(" ").append("three ").append("four");		//chainning 가능

	cout << str2 << endl;	//two three four

	//수식처럼 사용 가능
	str2 += " five";		
	str1 = str2 + " six";

	cout << str1 << endl;	//two three four five six
	cout << str2 << endl;	//two three four five


	//push_back() 
	//str2.push_back("push");	//이렇게 문자열은 못들어감
	str2.push_back('A');		//vector 처럼 작동해서 문자 하나씩은 넣을 수 있음
	
	cout << str2 << endl;




	//instert()
	string str("aaaaa");

	str.insert(2, "bbb");	//"bbb" 대신에 string 이 들어가도 됨

	cout << str << endl;	//aabbbaaa




	return 0;
}