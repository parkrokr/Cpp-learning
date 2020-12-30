//포인터 연산과 배열 인덱싱 Indexing

#include<iostream>

using namespace std;

int main()
{
	int value = 7;
	int* ptr = &value;

	//10진수로 보기위해 int 로 캐스팅 하는 대신 unsinged int pointer type 사용
	//int 형이라 한칸에 4
	cout << uintptr_t(ptr-1) << endl; 
	cout << uintptr_t(ptr) << endl;
	cout << uintptr_t(ptr+1) << endl;
	
	//doubl형
	double d_value = 7.0;
	double* d_ptr = &d_value;

	//double 은 8 byte 라 8
	cout << uintptr_t(d_ptr - 1) << endl;
	cout << uintptr_t(d_ptr) << endl;
	cout << uintptr_t(d_ptr + 1) << endl;
	


	//포인터 변수를 선언할때 data type 도 같이 선언하는 이유 :
	//de-referencing 할때 어떤 type으로 값을 가져와야할지 알기 위해
	//포인터 연산을 할때 (short 형에선 +1이 2바이트, int 형에선 4바이트이고 double 형에선 8바이트)


	//int 형 array 에서도 4씩 증가함 (주소가 이웃해 있음)
	int array[] = { 9,7,5,3,1 };

	ptr = array;  //*ptr = array 하면 에러 발생, *ptr 은 de-referencing 한 거기 때문
	//배열의 주소가 들어있는 포인터는 인덱스로 접근할 수 있음

	//iterate 하기
	for (int i = 0; i < 5; ++i)
	{
		//cout << array[i] << " " << (uintptr_t) & array[i] << endl;
		cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl;
	}


	//문자열
	char name[] = "jackjack";

	const int n_name = sizeof(name) / sizeof(char);

	char* c_ptr = name;

	for (int i = 0; i < n_name; ++i)
	{
		//cout << *(name + i);
		cout << *(c_ptr + i);
	}
	cout << endl;

	//문자열 출력을 while 과 break 를 사용하여 null character 빼고 출력하기, ++ptr

	while (*c_ptr != '\0')
	{
		cout << *c_ptr++;
	}

	c_ptr = name;
	while (1)
	{
		if (*c_ptr == '\0')break;
		cout << *c_ptr++;
	}

	return 0;
}
