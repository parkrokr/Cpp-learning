//std::exception 소개


//std::exception 은 부모클래스로 엄청나게 많은 자식 클래스들이 구현되어있음
//대부분의 예외가 발생하는 경우를 다 구현해둠

//cppreference 참고


#include <iostream>
#include <exception>  //exception class
#include <string>

using namespace std;

// std::exception 를 상속받는 exception class 
// std::exception 에서 가장 중요하게 알아야 하는 함수는 what() 임
//직접 만든 예외 클래스가 다른 자식들 처럼 작동하기를 원하면 what() 을 오버라이드 하는것이 중요함
// noexcept 는 c++11 이상의 컴파일러부턴 이 키워드가 들어가야함
//noexcept 연산자는 컴파일 타임에 문구가 아무 예외도 던지지 않으면 true 를 반환함
//적어도 여기서는 예외를 던지지 않겠다는 의미
class CustomException : public std::exception
{
public:
	const char* what() const noexcept override  //override 키워드는 빼도 상관 없음,what() 은 virtual 임
	{
		return "Custom exception";
	}
};



int main()
{
	try
	{
		//std 를 사용할때 내부에 이미 구현되어 있는 throw 를 catch
		std::string s;
		s.resize(-1);  //입력으로 들아오는 길이가 이상할 경우 내부에서 예외를 던지게 이미 구현되어있음


		//std::exception 만 가져다가 사용하고 싶을때
		//throw std::runtime_error("Bad thing happened");  //exception 의 자식클래스중 하나를 직접 던질 수 있음
		
		
		//std::exception 를 상속받는 exception class 
		//throw CustomeException();
	}
	catch (std::length_error& exception)
	{
		//exception 의 자식 클래스중 하나인 length_error 를 catch
		cerr << "Length_Error" << endl;
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception)
	{
		//s.resize() 가 던진 예외가 정확하게 뭔지 알고싶은 경우
		cout<<typeid(exception).name()<<endl;
		//자식 클래스의 이름이 출력됨( class std::length_error )

		
		cerr << exception.what() << endl;  //what() 은 문자열임
		
		//reseiz() 에 -1 이 들어갈 경우 오버플로우가 발생해서 "string too long" 이 출력됨
	}



	//s.resize() 가 던진 예외가 정확하게 뭔지 알고싶은 경우 다른 방법
	//구글에서 reference manual 검색
	//예를 들어 std::basic_string::resize
	//이 함수가 어떤 예외를 발생시킬 수도 있는지 다 적혀 있음


	return 0;
}