//std::string 의 길이와 용량

//std::vector 에선 길이와 용량이 별도로 운영됨, std::string 도 마찬가지
//vector 처럼 reserve() 를 통해 미리 공간을 확보할 수 있음

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("012345678");

	cout << my_str.size() << endl;		//9

	//c style 문자열에선 뒤에 null character 가 하나 숨어있지만 
	//string 에서는 붙지 않음, 
	
	//string 내부에선 길이를 직접 가지고 있어서 문자열이 끝났는지 안끝났는지 null character 를 찾을 필요가 없음

	
	cout << std::boolalpha;				//true false 로 나오게 바꿈
	cout << my_str.empty() << endl;		//비었는지 안비었는지 체크함, 지금은 안비어있으니 false


	string my_str_("");					//null char 이 하나 들어가고 있음, const char[1]
	cout << my_str_.empty() << endl;	//true, 비어있음, c style 문자열과 다르게 null char 를 보관하지 않음

	// "" 은 null char 만 들어가있는 내용 없는 문자열( const char[1] ) 이라서
	//c style 처럼 문자열 배열 char my_str[] 나 포인터 const char* my_str 로 다루면 
	//null character 하나가 저장되지만
	//std::class 에는 null character 가 저장되지 않기 때문에 string my_str_("") 의 size 는 0 이 됨




	//capacity 용량
	string my_str_s("01234567");
	
	cout << std::boolalpha;
	cout << my_str_s.length() << endl;			//8
	cout << my_str_s.size() << endl;			//8
	cout << my_str_s.capacity() << endl;		//15


	//capacity 는 컴파일러나 os 상황에 따라 다름
	//string 도 vector 처럼 새로 데이터가 추가될 가능성 때문에 가급적이면 메모리를 재할당 하지 않으려고 함
	//new 와 delete 를 최소한으로 쓰려고 하기 위해 여분의 용량을 두는것임
	
	
	//capacity 를 늘리고 싶은 경우( 여분을 늘리고 싶은 경우)
	my_str_s.reserve(1000);						//reserve() 로 1000까지 용량 확보
	//정학히 1000으로 맞아떨어지진 않음, 최소한 1000까진 잡아달라의 느낌



	cout << my_str_s.max_size() << endl;		//글자가 몇개까지 들어가는가, capacity 의 max 값
	
	//여러가지 상황에 따라 max_size 의 값은 달라짐(x64 에선 더 올라감)

	
	return 0;
}