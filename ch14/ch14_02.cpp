// 예외 처리와 스택 되감기 Stack Unwinding

// 함수가 함수를 호출하고 다시 그 함수가 다른 함수를 호출하면 스택에 호출구조가 쌓이게 됨
//가장 안쪽의 함수가 예외를 던진다면 스택을 '되감아' 가면서 예외를 어디서 받을지 찾게 됨


//Exception 을 못잡았을 경우에는 계속 throw 돼서 날라감
//잡은 경우에 안정적으로 끝까지 실행됨

//catch(...)  //catch-all handlers, using ellipsis , 안전망, 최후의 보루

#include <iostream>

using namespace std;


//std::cerr , standard ouput stream for errors
//cout 이랑 거의 비슷함, std::clog 도 있음
//세가지는 기능상 큰 차이는 없고 로그를 출력하는 체널이 3가지가 있다
//std::cout 은 buffer 에 담아두고 바로바로 출력을 안하는 경우도 있음, endl 을 통해 flush 와 줄바꿈을 함
//std::cerr 은 출력 후 바로 버퍼를 비워줌(flush),flush 나 endl 이 없어도 작동됨
//예외는 일종의 에러라 보고 cerr 을 씀



//exception specifier 
//불필요하다는 견해도 많다고 함, 보통은 잘 안사용함
//void last() throw(int) //이렇게 하면 int type 의 exception 을 throw 할수도 있다~ 항상 한다는건 아님
//ms visual studio 문서를 찾아보면 어떤 type 을 넣던간에 ... 처럼 여김
//void last() throw(...)  : 어떤 type 이던간에 예외를 던질 수 있는 가능성이 있는 함수다

//주의사항: void last() throw() 처럼 paramter 가 없으면 예외를 안던진다고 얘기를 하는꼴임
//밑에 예제에 throw() 를 붙이면 예외를 안던진대 했는데 던져서 경고가 발생함(C4297)


void last()
{
	cout << "last " << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "End last" << endl;
}



void third()
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl;
}


void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double exception" << endl;
	}

	cout << "End second " << endl;
}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "fist caught int exception" << endl;
	}

	cout << "End first " << endl;
}



int main()
{
	cout << "Start " << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}

	

	//first, second, third, last 순서로 들어가서 last 에서 -1 을 throw 하게 되고{"End last" 출력을 날라감)
	//third 로 왔는데 "End third" 를 출력 안함, last() 에서 에러를 잡아주는 곳이 없으니 바로 스택에서 되감기를 함
	//second 로 왔는데 catch 가 있지만 doube 밖에 없기 때문에 무시하고 되감기함("End second" 무시함)
	//first 로 왔더니 catch int 가 있어서 에러를 잡게 되고 "first caught int exception"을 출력하고
	//"End first"를 출력함
	//fisrt 에서 잡았기 때문에 main() 에서 "End main" 출력이 정상적으로 작동함


	//주의 깊게 봐야 하는건 last() 의 "End last" 가 실행이 안됐다는거
	//third() 에서 에러를 못잡았으니 "End third" 도 실행이 안됐다는거
	//second() 에서 catch 가 있음에도 불구하고 못잡았으니 "End second" 가 실행이 안됐다는거
	//first() 에서 받았기 때문에 "End first" 는 정상적으로 실행이 됐다는거


	//Exception 을 못잡았을 경우에는 계속 throw 돼서 날라감
	//잡은 경우에 안정적으로 끝까지 실행됨


	//fisrt() 에 catch(int) 가 없었다면 main() 에서 잡음
	//last() 에서 char type 으로 던질경우 catch(char) 이 없기 때문에 runtime error  


	//에러를 다 못잡는 경우, uncaught exceptions 이 발생할 수가 있음
	//생략부호 ellipsis 사용 하면 어떤 type 이든 다 받을 수 있음
	catch (...) //catch-all handlers
	{
		cerr << "main caught ellipsis exception" << endl;
	}


	cout << "End main" << endl;


	return 0;
}