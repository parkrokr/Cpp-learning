//스택과 힙 Stack and Heap

//메모리는 여러 구역(segment) 로 나눠서 사용됨

//세그먼트마다 역할이 다름

//Heap

//Stack

//Data	저장되는 순서 2
	//Data
		//initialized data segment  초기화 된 전역, 정적 변수
		//initialized global and static variables


	//Bss (Block started by symbol)
		//uninitialized data segment  0으로 초기화된(초기화되지 않은) 전역, 정적 변수
		//zero-initialized global and static variables


//Code	저장되는 순서 1
//우리가 작성한 프로그램이 저장되어 있음




//stack 

//frame 안에는 함수가 끝나면 어디로 돌아가야 하는지도 들어가 있음
//frame 이 쌓여있고 현재 실행시켜야 하는것이 가장 위에 있기 때문에 비교적 빠름

/*
#include <iostream>

int g_i = 0;  // 1. 전역변수가 먼저 메모리에 자리잡음(처음 생겼다가 늦게 사라짐)

int second(int x)  //4. 새로 생긴 frame 안에 매개변수 x가 자리잡음
{
	return 2 * x;
} //5. second() 가 끝나면 가장 위인 second()가 들어있는 frame 부터 사라짐

int first(int x)  // 3. 이 frame 안에 매개변수 x,지역변수 y가 자리잡음
{
	int y = 3;
	return second(x + y);  //4. second()를 호출했기 때문에 새로운 stack frame 이 쌓임(second()가 들어있음)
} //6. first() 가 끝나면 frame 이 제거됨

int main() // 2. Stack 안의 Stack frame 안에 main() 저장
{
	using namespace std;

	int a = 1, b;  // 2. Stack 안의 Stack frame 안에 지역변수 a,b 저장
	
	b = first(a); //3. first()의 Stack frame 이 생겨서 위에 쌓임
	cout << b << endl;

	return 0;
} //7. main() 이 끝나면 frame 이 사라짐


//8. main()이 사라지면 전역변수도 사라지고 프로그램이 끝나고 os가 모든 메모리를 수거해감
*/

//stack 의 단점
//사이즈가 좀 작음

//이런 코드를 실행시키면 array 가 너무 커서 메모리 할당을 못함
//stack이 사이즈가 작은 상황에서 큰 변수를 메모리를 잡으려고 하면 넘쳐버림(Stack Overflow!)
//큰걸 한번에 잡아서 넘칠수도 있지만 작은걸 여러번 잡아서 넘칠수도 있음(ex) 재귀 호출)

/*
int main()
{
	int array[100000];  //Stack Overflow

	return 0;
}
*/


//Heap
//동적 할당

//지역 변수들은 stack 에 저장이 되고 stack는 비교적 빠르지만 stack overflow 같은 문제가 발생할 수있음
//이를 보완하기 위해 Heap 메모리를 사용함

//Heap 은 사이즈가 큼(큰 데이터가 들어갈 수 있는 공간을 마음껏 확보할 수 있음)
//단점은 어디에 생길지 예측하기 힘듬(메모리가 어디에 들어갈지 모름)

/*
int main() // 1. main() 이 frame 에 들어감
{
	int* ptr = nullptr;  //1. 지역 변수 *ptr이 main()과 같이 frame에 들어감
	
	ptr = new int[1000000]; //2. 동적 메모리 할당을 하면 Heap에 요구하는 사이즈 만큼 메모리를 잡음
							//  그 메모리 공간의 첫 주소를 포인터에 저장함

	delete[] ptr;  //3. Heap 에 있는 메모리를 반납함


	//Heap 에 있는 메모리 자체는 os로 반납이 되었지만 ptr에는 아직 주소값이 들어가 있음
	//ptr 에 de-referencing 을 시도하면 문제가 생김
	//delete[] ptr; 이후 ptr 이 쓰일때 nullptr 을 assignment 후 사용해야 함

	return 0;
}
*/


//동적할당후 delete을 안할경우 (memory leak)
/*
void initArray() //2. initArray() , 지역변수 int *ptr2 가 있는 frame 쌓음 
{
	int* ptr2 = new int[1000]; //3. new 를 통해 Heap에 메모리를 잡음, ptr2에는 첫 주소값이 들어가있음 
	// delete []ptr 2;
} 
//4. initArray() 가 끝나고 frame이 없어지는데 delete를 안했음
//지역변수 ptr2는 사라졌지만 Heap 에는 아직 메모리가 잡혀있고 그 주소를 모름
//메모리가 잡혀있기 때문에 사용할 수 없음
//이런 일이 반복이 되면 쓸수 없는 메모리가 Heap 에 꽉 차게 됨 (memory leak)
//다른 프로그램이 사용할 메모리까지 잠식해버릴 수 있음

int main()  //1. stack 에 main() 이 있는 frame 쌓음
{
	initArray(); //2. initArray() 가 있는 frame 쌓음

	return 0;
}
*/