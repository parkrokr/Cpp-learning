//std::string 의 문자 접근하기와 배열로의 변환


//my_str[100] = 'X';		//performence 가 중요한 경우 사용,예외처리 안함,사용자가 범위에 대해서 신경써줘야됨
//my_str.at(100) = 'X';		//안정성이 중요한 경우, 예외처리를 해줌 대신 performence 는 좀 떨어짐


//string 자체에는 null character 가 저장되지 않음
//c_str() 로 가져올때는 뒤에 null character 를 하나 붙여줌, 마치 c style 문자열처럼 사용할 수 있게 배려해주는것
//c_str() 과 비슷한 std::string::data 가 있음, 거의 비슷, 동의어임

//copy() 로 string 에서 c style array 로 가져올때는 null character 이 없기 때문에 
//따로 null chracter 를 하나 넣어줘야함


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string my_str("abcdefg");
	
	cout << my_str[0] << endl;		//a
	cout << my_str[3] << endl;		//d

	my_str[3] = 'Z';				//바꿔치기

	cout << my_str << endl;			//abcZefg



	//string 에서 [] 연선자 오버로딩이 되어있으면 예외처리를 안해줌
	//사용자가 신경을 써야 하고, assert 를 쓸수도 있고 at() 을 사용하면 throw 를 해주고 잡을 수 있음
	//vector 에서도 똑같음
	//std::exception  ch14_04 참고
	
	//my_str[100] = 'X';		//performence 가 중요한 경우 사용,예외처리 안함,사용자가 범위에 대해서 신경써줘야됨
	//my_str.at(100) = 'X';		//안정성이 중요한 경우, 예외처리를 해줌 대신 performence 는 좀 떨어짐

	try
	{
		//my_str[100] = 'X';				//runtime error 발생
		//예외처리의 단점중 하나가 예외처리를 하면 느려짐
		//그래서 이 표현은 예외처리를 하면 느려질까봐 예외처리를 안해준것임


		//my_str.at(100) = 'X';				//예외처리가 있는 at()
		//이때는 예외를 제대로 발생시킴

	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;			// invalid string position
	}




	//string 을 c style 문자열로 받기
	cout << my_str.c_str() << endl;			//abcZefg 출력됨

	// my_str.c_str() 이 포인터이기 때문에 이렇게 한글자만 출력 가능
	cout << my_str.c_str()[6] << endl;		//g	


	const char* arr = my_str.c_str();		// arr 에 받아서 사용하기
	cout << arr[6] << endl;					//g
	cout << arr[7] << endl;					//빈칸

	cout << (int)arr[6] << endl;			//103
	cout << (int)arr[7] << endl;			//0			즉 null character


	//string 자체에는 abcZefg 만 저장되고 null char 는 저장되지 않음
	//c_str() 로 가져올때는 뒤에 null char 를 하나 붙여줌, 마치 c style 문자열처럼 사용할 수 있게 배려해주는것
	
	//c_str() 과 비슷한 std::string::data 가 있음, 거의 비슷, 동의어임


	//c style array 로 바꾸는 다른 방법 : copy 하기

	char buf[20];				//data 를 받을 char array 를 하나 만듦

	my_str.copy(buf, 5, 0);		//my_str 에서 0 부터 5글자만 buf 로 copy, 하지만 null char 는 자동으로 안넣어줌

	buf[5] = '\0';				//null character 넣어주기

	cout << buf << endl;		//null character 안넣어주면 에러남, abcZe

	return 0;
}