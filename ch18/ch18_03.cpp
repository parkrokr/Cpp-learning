// string stream 문자열 흐름

//문자열 흐름의 버퍼 역할을 하는 string stream

#include <iostream>
#include <sstream>		//sring stream

using namespace std;

int main()
{
	//stream 의 자식들

	{
		stringstream os;

		// << : insertion operator, >> : extraction operator	 흘려서 넣고 빼는 느낌
		os << "Hello, World";
		os << "Hello, World2" << endl;;		//덧붙이는 느낌, endl 도 stringstream 에 들어감

		//os.str("Hello, World");			// 버퍼에 있는 내용을 전부 Hello, World 로 바꿔버림(원래있던건 지움)
		os.str("Hello, World\n");			// 줄바꿈 \n 도 stream 에 포함될 수 있음


		//뽑아오기
		string str;

		//os >> str;						//빈칸이 있으면 잘라버림, 마치 cin>>a>>b; 할때 공백으로 구분하듯이
		str = os.str();						//stream을 통째로 가져옴,str() 은 stream 의 전체를 반환함
		cout << str << endl;

		cout << os.str() << endl;			//os.str() 를 직접 cout 으로 출력하는 방법도 있음
	}


	//숫자
	
	//숫자를 문자열로 바꿔서 입력
	{
		stringstream os;

		os << "12345 67.89";					//빈칸이 중간에 하나 있음, 숫자를 문자열로 입력받고 있음

		string str1;
		string str2;

		os >> str1 >> str2;						//빈칸때문에 나뉘어서 들어올 수 있음

		cout << str1 << "|" << str2 << endl;	//12345|67.89

		//12345 67.89 에 빈칸이 없으면 str1 에 다 들어가버려 1234567.89| 가 출력됨
	}
	
	//숫자를 입력
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		//os << i << d;							//빈칸이 없어서 str1 에 다 들어가버려 1234567.89| 가 출력됨
		os << i << " " << d;					//빈칸을 추가해서 분리가 되어 12345|67.89 가 출력됨

		string str1;
		string str2;

		os >> str1 >> str2;						//빈칸으로 구분 안하면 str1 에 다 들어가버림

		cout << str1 << "|" << str2 << endl;	
	}

	//숫자로 받기
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;
		os << i << " " << d;

		//os << "12345 67.89";					//문자열 넣어줘도 숫자로 다시 받을 수 있음

		int i2;
		double d2;

		os >> i2 >> d2;

		cout << i2 << "|" << d2 << endl;		//12345|67.89
	}


	//stringstram 비우기, str(), clear()
	{
		stringstream os;
		os << "12345 67.89";	

		os.str("");								//빈칸으로 대체됨, 지워짐
		os.str(string());						//"" 대신에 string(), 큰 차이는 없음
		
		os.clear();								//state 까지 초기화, clear() 은 stream 을 비워주지 않음


		cout << os.str() << endl;				//아무것도 출력 안됨

		os << "Hello";							//비우고 다시 추가하기
		cout << os.str() << endl;				//Hello

		//str() 이 paramter 가 있을때( str("") )는 입력받은것으로 버퍼를 덮어쓰고
		//paramter 없을때는 stream 의 내용물을 복사한 string 객체를 return 함
	}



	return 0;
}