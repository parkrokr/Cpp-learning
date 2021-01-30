//클래스 템플릿 (Templates)

#include "ch13_02_MyArray.h"
#include "ch13_02_MyArray.cpp"

int main()
{
	//MyArray my_array(10);  
	//템플릿화 후 에러발생
	//parameter T 에 argument 가 안들어가서 발생

	MyArray<char> my_array(10);
	//MyArray<double> my_array(10);
	// . . .


	//초기화
	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();


	//print() 의 body 를 class 밖으로 빼고 다시 cpp 파일로 뺀 경우
	//main.cpp 에서 컴파일을 할땐 MyArray.cpp에선 어떤 type 으로 instantiation 할지 모르기 때문에
	//링킹 에러 발생

	//#include "ch13_02_MyArray.cpp" 하면 실행이 되지만
	//이렇게 해결하면 나중에 프로젝트 사이즈가 커지면 큰 문제가 됨
	//cpp 를 include 하는 오픈소스가 없는건 아니라서 절대 안되는거라고 단언은 못하지만
	//가급적 하지 않기! 매우 권장하지 않음, 아주 안좋은 사례

	//깔끔한 해결방법은 MyArray.cpp 에서 print() 의 body 를 컴파일 할때
	//특정한 data type 으로 컴파일 해야한다고 알려주기
	// explicit instantiaion

	//fucntion template 할때 컴파일러가 자동으로 instantiation 을 해줬고
	//MyArray.h 에 body 가 있을때도 자동으로 해줬음
	//cpp 에 가있을땐 직접 해줘야됨

	return 0;
}