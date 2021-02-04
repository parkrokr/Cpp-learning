//예외 클래스와 상속

//예외를 던질때 기본자료형이 아닌 사용자정의 자료형, 즉 예외 클래스를 사용하는 방법
//예외클래스에서 상속을 할때 주의할 점


//예외를 던진후에 catch 해서 하는 작업들을 함수나 클래스로 따로 정의를 하고 싶을때 예외클래스 사용

//상속을 사용할때 catch 의 순서에 따라 자식 클래스를 던져서 자식 클래스 catch 가 잡아야 하는데
//부모클래스가 먼저 있을경우 부모클래스에서 잡아버림, 해결책은 자식 클래스 catch 를 먼저 써주기

//예외를 다 잡았지만 밖에서(예제의 경우 main()) 에서 다시 처리를 해야하거나 하고싶은 경우
//다시 예외를 던지면 됨 (Re-throw)

//throw; 는 받자마자 그대로 다시 던지고 
//throw e; 는 받아서 던지면 객체잘림 현상이 일어남

#include <iostream>

using namespace std;


class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException :public Exception
{
public:
	void report()  //report() 를 오버라이딩 하고 있음
	{
		cerr << "Arrary exception" << endl;
	}
};



class MyArray
{
private:
	int m_data[5];

public:
	int& operator [] (const int& index)
	{
		//멤버 함수 안에서 throw 를 할 수 있음
		//if (index < 0 || index >= 5)throw - 1;  
		
		//이렇게 기본형으로만 예외를 던진다면 표현하지 못하는게 많음
		//예외를 던진후에 catch 해서 하는 작업들을 함수나 클래스로 따로 정의를 하고 싶을때 예외클래스 사용


		//Exception class 를 하나 만들어서 던짐
		//if (index < 0 || index >= 5)throw Exception();
		

		//상속을 사용할땐 주의가 필요함
		//ArrayException 을 throw
		if (index < 0 || index >= 5)throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];  //0,1,2,3,4 만 들어가야 하는 자리에 100이라는 큰값을 넣음,예외가 throw 될것임
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	//ArrayException 을 받는 catch 를 추가해줌
	//부모클래스가 자식클래스보다 먼저 잡는 경우를 피하기 위해 먼저 써줌
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();

		//그러나 어떤 경우 밖에서 또 처리를 하고 싶은 경우가 있음
	    //catch 를 한것을 다시 던질 수 있음(Re-throw)
		throw e;
		//여기서 다시 던진다고 해서 doSomething() 에서 catch 하지 않음
	}
	//Exception class 를 받아주는 catch 가 하나 있어야됨
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}
	/*
	//ArrayException 을 받는 catch 를 추가해줌
	//부모클래스가 자식클래스보다 먼저 잡는 경우를 피하기 위해 먼저 써줌
	catch (ArrayException& e)
	{
		e.report();
	}
	*/
}


void doSomething_new()
{
	MyArray my_array;

	try
	{
		my_array[100];  
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		cout << "doSomething_new()" << endl;
		e.report();

		//부모 클래스에 대해서만 예외처리를 하고 구체적인 내용은 re-throw 를 하고 
		//밖에서 받아서 처리를 하고 싶은 경우

		//throw e;		//e 를 던지면 밖(main() 에서 부모클래스가 잡아버림)
		throw;			//똑같은 re-throw 이긴 하지만 그냥 받아서 바로 던져버림
	}
	
}

int main()
{
	//doSomething();
	
	//try 와 catch 는 한 쌍으로 생각하기, try 와 catch 사이에 구문 하나만 있어도 컴파일 에러가 발생함
	//doSomething() 안에서 예외를 던지고 다시 re-throw 하고 있지만 받는 catch 가 없음
	//예외를 받기 위한 catch 가 있긴 위해서 try 도 있어야 하는데 둘다 없으니 그냥 예외 발생으로 에러 발생
	


	//Exception class 를 상속한 ArrayException class 를 throw 할때 실행시키면
	//ArrayException을 받아주는 catch 가 없기때문에 Exception 을 받는 catch가 잡아주고(상속 구조라 잡는게 가능)
	//Exception 의 report 가 나옴 (객체 잘림 현상 때문)

	//ArrayException 을 받는 catch 를 추가해주면 여전히 Exception report 가 나옴
	//warning C4286: 'ArrayException &': is caught by base class ('Exception &')
	//Exception 이 먼저 catch 해버려서 자식클래스가 catch 가 안됨
	//해결책 : 자식클래스 catch 가 먼저 잡아버리게 먼저 써줌



	//doSomthing() 이 main() 에 의해 호출되어 겹으로 들어가는 구조
	//main() 에서 try catch 만들기
	//doSomething() 에서 다 잡아버림 (앞 강의와 반대)
	try
	{
		doSomething();
	}
	//doSomething() 에서 예외를 다 잡아버렸기 때문에 이 catch 는 무시되고 있음
	//그러나 어떤 경우 밖에서 또 처리를 하고 싶은 경우가 있음
	//catch 를 한것을 다시 던질 수 있음(Re-throw)
	//re-throw 를 하게 되면 바깥쪽(지금은 main()) 에 있는 catch 에서 한번 더 받아줌
	catch (ArrayException & e)  
	{
		cout << "main()" << endl;
		e.report();
	}



	//부모 클래스에 대해서만 예외처리를 하고 구체적인 내용은 re-throw 를 하고 
	//밖에서 받아서 처리를 하고 싶은 경우
	//doSomething() 에서 Exception 으로 받아서 던지긴 하지만 처음 예외를 던질때
	//ArrayException (자식 클래스)으로 던지기 때문에 main() 에서 받을때도 자식클래스로 받기를 기대함
	//throw; 가 아니라 throw e; 를 하면 객체잘림이 일어나 자식클래스가 못받고 부모클래스가 받아버림
	//throw; 로 던지면 객체잘림이 발생하지 않고 자식클래스로 잡아버림
	try
	{
		doSomething_new();
	}
	catch (ArrayException& e)
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}
