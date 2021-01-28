//순수 (Pure) 가상 함수, 추상 (Abstract) 기본 클래스, 인터페이스 (Interface) 클래스

//body 가 없는 가상함수를 순수 가상 함수 라고 함, 자식클래스에서 반드시 오버라이드를 해줘야함
//순수 가상 함수가 포함된 클래스를 추상 클래스 라고 함
//순수 가상 함수로만 이루어진 클래스를 인터페이스 클래스 라고 함

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;
public:
	Animal(std::string name)
		:m_name(name)
	{}

public:
	string getName() { return m_name; }

	//pure virtual function
	virtual void speak() const = 0; //body 가 없고 뒤에 = 0 이 붙은 함수를 순수 가상 함수 라고 함
	
    /*virtual void speak() const
	{
		cout << m_name << " ??? " << endl; 
	}*/
};

//순수 가상 함수도 별도로 body 를 정의 할 수 있음
//쓸모가 없음,구현해봤자 호출 할 수 없음
//void Animal::speak() const
//{
//	cout << m_name << " ??? " << endl;
//}

class Cow :public Animal
{
public:
	Cow(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Mooo " << endl;
	}
};


//인터페이스 클래스 : 모든 멤버 함수들이 모두 순수 가상 함수임
//자기가 뭘 할지는 정의를 안하고 뭐뭐~를 해야한다는 구조
//사용을 할때 이런~ 기능들이 있을것이라고 예측할수 있는 중계기(인터페이스) 역할

class IErrorLog		//인터페이스를 구현할때는 앞에 I 를 붙이는게 관습
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

//밑에 두 클래스들은 reportError() 를 반드시 만들어야 함
class FileErrorLog :public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog :public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

//인터페이스 클래스를 parameter 로 받고 있는 함수
//IErrorLog 에 reportError() 이 있다는 것만 알고 있음
void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!");
}

int main()
{
	//Animal ani("Hi");  //추상 함수는 이 객체를, 인스턴스를 만들 수 없음, Animal::speak() 이 순수가상함수라서
	//ani.speak();		//만들수도 없으니 함수를 호출할 수도 없음

	//순수가상함수를 부모클래스에 구현할때는 부모클래스에서는 모르겠으니 자식클래스에서 '반드시' 구현하라 를 의미
	
	//이전까진 상속을 사용할때 일반적인걸 부모클래스에 두고 자식클래스에선 재활용하거나 더 특화 된것이 
	//있을경우 오버라이딩을 했지만 순수가상함수는 관점이 바뀌었다고 할 수 있음


	//Cow 에 speak() 가 없는 경우
	//Cow cow("hello"); //에러, 순수가상함수 Animal::speak() 이 오버라이더가 없다
	//즉 자식클래스에서 speak()를 오버라이드 안하면 만들 수 없음(구현하게 강제)



	//인터페이스 클래스
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	//인터페이스 클래스를 parameter 로 받는 함수

	doSomething(file_log);			//"Writing error to a file"
	doSomething(console_log);		//"Printing error to a console"
	//의도한 대로 넣어준 대로 기능을 하고 있음


	return 0;
}