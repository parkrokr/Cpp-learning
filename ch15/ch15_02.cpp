//오른쪽-값 참조  R-value References

#include <iostream>

using namespace std;

int getResult()
{
	return 100 * 100;
}

//paramter 가 l-value reference
void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

//paramter 가 r-value reference
void doSomething(int&& ref)
{
	
	cout << "R-value ref" << endl;
}


int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;		//const 이기 때문에 이후 값을 수정할 수 없음
	const int cy = getResult();

	//L-value, 메모리 주소,공간을 가지고 있음
	//R-value, 문장이 끝나면 사라짐
	
	//메모리 주소를 가지고 있는 L-value 에 복사해 넣어서 계속 사용해 나감
	//getResult() 가 반환하는 R-value 를 y 에 넣고 있음


	//L-value references
	//L-value 를 참조할 수 있는 reference 는 &를 하나 붙임
	//l-value references 에는 주소를 가질수 있는 변수(modifialble l-value) 를 대입할 수 있음
	int& lr1 = x;		//Modifiable l-values
	
	//문법상 컴파일이 안되는 코드
	  //l-value references(자기자신) 이 const 가 아닐경우 const 를 넣을 수 없음
	  //l-value reference 니까 l-value 에 대한 reference 만 되고 r-value 에 대해선 가질 수 없음
	//int &lr2 = cx;	//Non-modifiable l-values
	//int &lr3 = 5;		//R-values


	//const l-value reference
	const int& lr4 = x;		//Modifiable l-values
	const int& lr5 = cx;	//Non-modifiable l-values
	const int& lr6 = 5;		//R-values
	//r-value 를 넣어도 되는 이유: const 이기 때문에 메모리 주소와 상관없이 수정을 안하니까
	//이정도는 심볼릭 상수로 쳐줌



	//R-value references
	// & 가 두개가 있음, logical-and 와 상관 없음
	//r-value 만 받을 수 있음
	//곧 사라질 값만 담을 수 있음,Non-modifiable l-value도 혹시나 접근해서 건드릴까봐 못담음
	//r-value reference 로 가르켜지는 것들은 move 를 해서 다른곳으로 옮겨도 아무도 찾지 않음
	//반대로 l-value 인 x 의 내용물을 move 할경우 다시 x 를 통해서 접근할 수 없으니 충돌이 생김 

	//int &&rr1 = x;		//Modifiable l-values
	//int &&rr2 = cx;		//Non-modifiable l-values
	int&& rr3 = 5;			//R-values
	int&& rrr = getResult();

	//const int &&rr4 = x;	//Modifiable l-values
	//const int &&rr5 = cx;	//Non-modifiable l-values
	const int&& rr6 = 5;	//R-values

	
	//rr3 만 5(또는 class 의 인스턴스,객체) 에 접근하고 값을 바꿀 수 있다(사용하겠다)
	cout << rr3 << endl;	//출력가능
	rr3 = 10;				//대입해서 값을 바꾸기도 가능
	cout << rr3 << endl;	//바꾼 값을 출력 가능




	// L/R-value reference parameters
	//오버로딩할때(l-value ref 와 r-value ref 는 다르다고 인정해줌)

	doSomething(x);				//modifiable l-value
	
	//doSomething(cx);			//cx 는 const 이기 때문에 const l-value reference 로 받아야됨

	doSomething(5);				//r-value 
	doSomething(getResult());	//r-value



	//r-value ref 로 받았을땐 영역 안에서 ref 에 담겨있는 데이터들을 move 해서 가져와도 됨
	//어차피 다른곳에서 사용할 수가 없기 때문에 move semantics 가 가능

	//l-value ref 로 받았을땐 들어온게 메모리 주소를 가지고 있는 변수고,  밖에서도 접근하고 사용이 가능하기 
	//때문에 move semantics 로 가져와 버리면 밖에서 doSomething() 함수를 호출한 후에 넘겨보낸 변수를
	//다시 접근하려고 하면 문제가 생김, l-value 에 대해선 doSomething() 이 move semantics 를 사용할 수 없음
	//강제로 하는 경우도 있지만 특별한 경우, 일반적으론 충돌을 일으킴


	return 0;
}