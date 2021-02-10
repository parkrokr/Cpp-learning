//std::string 의 생성자들과 형변환

//기능적으론 형변환 이지만 지금까지 다루었던 거랑은 조금 다름

#include <iostream>
#include <string>
#include <vector>
#include <sstream>	//string stream

using namespace std;

//입력으로 들어온 걸 string 으로 바꿔서 반환하는 함수
template <typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;

	osstream << x;				//x가 뭐든 output string stream 에 넣어줌
	return osstream.str();		//osstream 에 있는 내용(x) 을 string 으로 바꿔줌
}


//FromString
template <typename T>
bool FromString(const std::string& str, T& x)		//성공했냐 못했냐늘 알려주기 위해 bool type return
{
	std::istringstream isstream(str);		//input string stream 을 str 로 초기화
	
	return (isstream >> x) ? true : false;	//x 를 isstream 으로 흘려주고 조건연산자를 써서 반환
}

int main()
{
	//const char* my_string = "my string";			//c style string
	//std::string my_string;						//아무것도 안들어갔으니 기본생성자 호출됨
	std::string my_string("my string");				//c style 문자열로 초기화
	

	//std::string second_string(my_string);			//복사 생성도 됨
	//std::string second_string(my_string,3);		//앞에 3개가 짤림							string
	//std::string second_string(my_string, 3, 2);		//앞에 3개가 짤리고 그 다음 2글자만 가져옴	st
	
	//std::string second_string(5,'A');				//'A' 가 5개 출력						AAAAA



	//std::iterator 를 이용해서 초기화 하기
	std::vector<char> vec;
	for (auto e : "Today is a good day.")
		vec.push_back(e);

	//std::string second_string(vec.begin(), vec.end());		//Today is a good day.
	

	//std::find() 사용	 'g' 를 찾음, 'g' 앞까지 출력됨	Today is a 
	std::string second_string(vec.begin(), std::find(vec.begin(), vec.end(),'g'));
	//vec.begin() 자리에 넣어서 응용도 가능

	std::cout << my_string << std::endl;
	std::cout << second_string << std::endl;





	//숫자로 바꾸기
	//ToString, FromString

	//std::string my_str(4);					//안됨, 4 는 정수이기 때문에 문자열로 못바꿔주고 있음
	
	string my_str(std::to_string(1004));		//std::to_string(), 정수를 문자열로 바꿔줌, 1004 를 문자열로
	
	my_str += std::to_string(128);				//1004128

	//파일을 출력할때 파일 뒤에 숫자를 바꿔가며 여러장을 출력할때 매우 유용함
	//시간같은걸 넣는등 다양하게 쓸 수 있음


	int i = std::stoi(my_str);					//std::stoi,문자열을 정수로, string to inteager

	float f = std::stof(my_str);				//std::stof, return type 이 float


	cout << my_str << endl;
	cout << i << endl;
	cout << f << endl;




	//입력으로 들어온 걸 string 으로 바꿔서 반환하는 함수
	std::string my_new_str(ToString(3.141592));

	cout << my_new_str << endl;

	//FromString
	double d;

	if (FromString(my_new_str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl;

	
	
	//숫자류는 바꿀 수 있음
	//string 에 있는걸 항상 다른 type 으로 바꿀수는 없음

	//만약 my_new_str 이 "Hello" 와 같은 문자열이라면 double 로 못바꿈
	//FromString() 에서 isstream 에 있는 내용물을 double 로 흘려보냈는데 변환이 안되고 fale 가 return 됨

	return 0;
}