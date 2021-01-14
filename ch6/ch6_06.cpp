//C언어 스타일의 배열 문자열

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	//배열과 똑같은 방식을 처리할 수 있음 단지 데이처 처리 type 이 문자형일 뿐임

	char myString[] = "string"; // 마지막에 \0(null character) 들어있음 , "string"은 6 이지만 myString 은 7 이다

	cout << sizeof(myString) / sizeof(myString[0]) << endl;

	for (int i = 0; i < 7; ++i)
	{
		cout << myString[i] << '\t' << (int)myString[i] << endl;
	}


	//cin 으로 읽기
	char my_String[255];

	//cin >> my_String;

	// 빈칸을 입력하고 싶을때    (빈칸과 null character 는 다름)
	cin.getline(my_String, 255);

	//my_String[4] = '\0'; //4번째 글자 이후 출력 x , cout 은 null character이 나오기 전까지 출력하기 때문

	cout << my_String << endl;

	int ix = 0;
	while (1)
	{
		if (my_String[ix] == '\0')break;

		cout << my_String[ix] << " " << (int)my_String[ix] << endl;
		++ix;
	}


	//전통적인 C style 문자열
	char source[] = "Copy this!";
	char dest[50]; 


	//문자열 복사
	//strcpy(dest, source); // destination의 size 가 부족하면 runtime error 발생함

	strcpy_s(dest, 50, source); //destination memory size랑 똑같이 parameter를 입력해야함, _s 는 secured 의미


	cout << source << endl;
	cout << dest << endl;


	//strcat()  //한 문자열 뒤에다 어떤 문자열을 붙여주는것
	//strcmp()  //두 문자열이 동일한지 비교를 하는것

	strcat(dest, source);

	cout << source << endl;
	cout << dest << endl;


	// * strcmp function 은 같으면 0, 다르면 -1 return  
	cout << strcmp(source, dest) << endl;

	//strcat(),strcmp() 구현해보기
	
	//strcat()
	
	char a[] = "Hello World";
	char b[] = "Hello World";
	int count(0);
	const int c_width = (sizeof(a) / sizeof(a[0]))+ (sizeof(b) / sizeof(b[0]))-1;
	char c[c_width];

	int i = 0;
	int j = 0;

	while (a[i] != '\0')
	{
		c[i] = a[i];
		++i;
	}
	while (b[j] != '\0')
	{
		c[i] = b[j];
		++i;
		++j;
	}

	//print c
	for (int i = 0; i < c_width; ++i)
	{
		cout << c[i];
	}
	cout << endl;


	//strcmp()

	//char a[] = "Hello World";
	//char b[] = "Hello World";

	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); ++i)
	{
		if (a[i] == b[i])
		{
			if (i+1 == sizeof(a) / sizeof(a[0]))
			{
				cout << 0 << endl;
			}
		}
		else
		{
			cout << -1 << endl;
			break;
		}
	}

	return 0;
}
