// istream 으로 입력받기

//cin				
	//공백으로 입력을 구분함,공백과 \n을 무시, \n 을 버퍼에 남겨둠, cin 만 계속 쓰면 \n 은 무시되기 때문에
	//문제가 없으나 밑의 함수들을 같이 쓰기 시작하면 문제가 발생, 버퍼에 남아있는 \n 을 받아버림
	//cin.ignore() 을 통해 해결 가능 (ingnore() 은 한글자만 무시하기 때문에 \n 이 무시되고 정상작동됨)

//cin.get()
	//공백,\n 받음, 문자 및 문자열만 입력받음
	//문자열을 받을 경우 cin.get(buf, n)
	//n-1 까지 저장하고 \n은 버퍼에서 안가져옴(버퍼에 남겨둠)
	//null character 가 자동으로 붙음, 아무것도 안가져와도 붙음
	//\n 도 입력으로 간주하고 버퍼에 남아있어서 다음 cin.get() 이나 cin.getline() 만나면 오작동
	//cin.ignore() 을 통해 해결 가능 (ingnore() 은 한글자만 무시하기 때문에 \n 이 무시되고 정상작동됨)
	

//cin.getline()
	//공백, \n 받음, 문자열만 입력받음
	//cin.getline(buf, n);
	//n-1 개 까지 저장하고 \n 을 버퍼에서 가져와서 null character 로 저장(아무것도 안가져와도 붙음)
	//버퍼에 \n 이 남이있지 않아서 다음 cin.get() 이나 cin.getline() 을 만나도 정상 작동 
	
//getline()
	//string 을 받음
	//getline(cin, buf);  최대 문자 수를 입력하지 않아도 됨
	//cin 의 멤버함수가 아니기 때문에 cin.gcount() 에 카운트 되지 않음


//cin.ignore(n)
	//버퍼에서 n 개의 문자를 무시
	//n 의 default 값이 1 이라서 cin.ignore() 하면 1개의 문자를 무시함
	//cin 이나 cin.get() 사용시 버퍼에 남아있는 \n 을 무시하기 위해서 사용


//cin.peek()
	//버퍼의 맨 앞 한글자만 읽음, 꺼내오지 않음

//cin.unget()
	//마지막으로 읽은 문자를 버퍼에 반환

//cin.putback()
	//버퍼의 가장 앞에 글자를 올려둠



#include <iostream>
#include <string>
#include <iomanip>	// input/output manipulators

using namespace std;

int main()
{
	//기존에 사용하연 iostream
	{
		cout << "Enter a number " << endl;		//정보 출력
		int i;									//변수 선언
		cin >> i;								//변수로 정보를 입력 받기
		cout << i << endl;						//입력 받은 정보를 다시 출력
	}

	//기본적으로 스트림은 버퍼에 저장된 것의 일부를 조금씩 꺼내오는 방식
	{
		char buf[5];

		cin >> buf;		//5개 보다 많이 입력하면 런타임 에러, 5개 보다 적으면 문제 없음

		cout << buf << endl;



		//이렇게 항상 조심하며 입력하긴 불편함
		//setw()
		cin >> setw(5) >> buf;		//setw(5) 을 하면 5글자 까지만 받음
		cout << buf << endl;		//abcd

		//cin 으로 abcdefghjklmn 같이 많이 입력했을때 cin, 즉 input stream 이 가지고 있는 버퍼에 내용이 들어가고
		//그중에서 5개만 가져오는데 null character 포함 5개라서 abcd 만 가져옴
		//나머지 efghijklmn 은 버퍼에 남아있음

		cin >> setw(5) >> buf;		//버퍼에 남아있는 efghijklmn 중에서 4개( 1개는 null character) 가져옴
		cout << buf << endl;		//efgh


		cin >> setw(5) >> buf;
		cout << buf << endl;		//ijkl


		//버퍼에 담고 순차적으로 가져오는 방식
	}


	//하나씩 받기
	{
		char ch;

		while (cin >> ch)		//버퍼로부터 계속 하나씩 가져옴
			cout << ch;

		//Hello world 를 입력하면 HelloWorld 가 출력됨(빈칸이 사라짐)
		//cin 은 빈칸을 받아오지 못함
		//버퍼로는 가져오나 버퍼에서 빈칸을 못가져옴, 빈칸을 무시함


		//빈칸을 무시하는게 유용한 경우(빈칸으로 구분됨)
		int i;
		float f;

		cin >> i >> f;						//1024 3.14 입력 (빈칸으로 구분됨)
		cout << i << " " << f << endl;		//1024 3.14

		//빈칸을 무시하는걸 의도적으로 사용할 수도 있음



		//빈칸을 입력 받고 싶은 경우
		//cin.get() 사용
		while (cin.get(ch))
			cout << ch;
		//Hello World 입력하면 빈칸까지 잘 가져와서 Hello World 로 잘 출력함


		//버퍼로 있는 경우도 가능
		//한개씩 입력받는게 아니라서 while 문 안씀
		char buf[5];

		cin.get(buf, 5);	//버퍼가 최대 5개다,		//Hello, World 입력
		cout << buf << endl;						//Hell		//버퍼에 아직 남아있음

		//한번 더 읽기
		cin.get(buf, 5);
		cout << buf << endl;						//o, W
	}


	//cin.gcount()		몇글자를 읽어들였는지 반환함
	{
		char buf[5];

		cin.get(buf, 5);									//Hello, World 입력
		cout << cin.gcount() << " " << buf << endl;			//4 Hell		//최대 5개니까 4개를 읽었다

		cin.get(buf, 5);
		cout << cin.gcount() << " " << buf << endl;			//4 o, W
	}

	//cin.getline()		line 단위로 받음
	{
		char buf[5];

		cin.getline(buf, 5);								//Hello, World 입력
		cout << cin.gcount() << " " << buf << endl;			//4 Hell

		cin.getline(buf, 5);
		cout << cin.gcount() << " " << buf << endl;			//0

		//getline() 은 한 line 을 한번에 다 읽어들이고 5 라는 제한이 있어서 4개만 읽어옴
		//두번째 getline() 에선 못읽음, 첫번째 getline() 이 한줄을 통째로 다 읽어가기 때문에
		//버퍼가 비어버려서 읽을게 없음

	}


	//cin.getline() 과 cin.get() 의 비교
	{
		char buf[100];

		cin.getline(buf, 100);
		//cin.get(buf, 100);
		cout << cin.gcount() << " " << buf << endl;

		cin.getline(buf, 100);
		cout << cin.gcount() << " " << buf << endl;


		//똑같이 Hello 를 넣으면 
		//cin.getline() 일때는 6 Hello
		//cin.get() 일때는 5 Hello	1

		//cin.get() 은 \n 을 만나면 문자열에 null character 를 입력하고 버퍼엔 \n 을 그대로 남겨둠
		//cin.getline() 은 \n 을 만나면 문자열에 null character 를 입력하고 버퍼에서 \n 을 지움
		//cin.getline() 은 c style 문자열을 받음
	}


	//getline()
	{
		string buf;

		getline(cin, buf);									//Hello, World
		cout << cin.gcount() << " " << buf << endl;			//0 Hello, World

		//getline() 은 string 을 받는 string 에 정의된 함수임
		//getline() 이 cin.getline() 이 아니기 때문에 cin.gcount() 가 0 임
	}


	//cin.ignore()
	{
		char buf[1024];

		cin.ignore();		//입력받은 한글자를 무시함

		cin >> buf;
		cout << buf << endl;


		cin.ignore(2);		//2글자를 무시함

		cin >> buf;
		cout << buf << endl;
	}

	
	//cin.peek()
	{
		char buf[1024];

		//Hello 입력

		cout << (char)cin.peek() << endl;		//H		//버퍼에서 한글자만 읽음, 단 꺼내오진 않음, 살짝 보는것

		cin >> buf;
		cout << buf << endl;					//Hello
	}


	//cin.unget()
	{
		char buf[1024];

		cin >> buf;								//Hello 입력
		cout << buf << endl;					//Hello

		cin.unget();

		cin >> buf;
		cout << buf << endl;					//o

		//get() 의 반대, 마지막으로 읽은것을 다시 버퍼에 넣어버림
	}


	//cin.putback()
	{
		char buf[1024];

		cin >> buf;								//Hello 입력
		cout << buf << endl;					//Hello

		cin.putback('A');						//비워진 버퍼에 'A' 집어넣음

		cin >> buf;
		cout << buf << endl;					//A		//putback() 에서 넣은 'A' 다시 출력
	}


	return 0;
}