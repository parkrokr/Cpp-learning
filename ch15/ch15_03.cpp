// 이동 생성자( Move Construcotrs ) 와 이동 대입 ( Move assignment )


//move 를 해줄수 있는 상황이면 move 를 해줌, 복사는 최후의 수단으로 작동


#include "ch15_03_Timer.h"
#include "ch15_03_AutoPtr.h"
#include "ch15_03_Resource.h"


AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(1000000));
	cout << 2 << endl;
	return res;
}



int main()
{
	using namespace std;
	
	streambuf* orig_buf = cout.rdbuf();

	//Time 로 시간을 측정할때 cout log(또는 파일 출력) 가 있으면 로그 출력때문에 시간이 많이 걸림
	//cout.rdbuf(NULL);	//disconnect cout from buffer

	Timer timer;

	{
		AutoPtr<Resource> main_res;
		cout << 1 << endl;
		main_res = generateResource();		//함수가 return 해서 들어오는 값은 r-value,즉 다시 사용할 일이 없음
		cout << 3 << endl;
	}
	

	cout.rdbuf(orig_buf);
	timer.elapsed();

	
	/* Release 모드일때 결과: return 할때 복사, RVO 참고
	* 
	AutoPtr default construcotr
	1
	Resource length construcetd
	AutoPtr default construcotr
	2
	AutoPtr copy assignment			//deep copy
	Resource default constructed
	Resource copy assignment
	AutoPtr destructor
	Resource destroyed
	3
	AutoPtr destructor
	Resource destroyed
	*/
	


	//move construtor, assignment 일때 더 시간이 적게 걸림
	//deep copy 가 되고 안되고 의 차이임
	//resource 의 copy assignment나 constructor 가 호출되는 부분이 없음


	/*REalese 모드에서  a.m_ptr = nullptr; 해줬을때
	AutoPtr default construcotr
	1
	Resource length construcetd
	AutoPtr default construcotr
	2
	AutoPtr move assignment			//deep copy 하는 부분이 없음 
	AutoPtr destructor
	3
	AutoPtr destructor
	Resource destroyed
	*/


	//debug 모드에선 return 할때 생성자가 호출됨, release 모드에선 호출되지 않음, 컴파일러가 최적화(RVO) 
	//예제는 resource 를 한번만 생성해서 사용하고 있는데 a.m_ptr = nullptr 가 없으면 
	//두번 지우려고 함, release 모드에선 그냥 진행하지만 debug 모드에선 런타임 에러

	//복사 생성자와 대입연산자를 주석처리 않해도 & 와 && 가 오버로딩이 가능하기 때문에 
	//우리가 원하는 move 생성자와 대입연산자로 잘 작동함


	return 0;
}
