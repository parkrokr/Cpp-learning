// std::shared_ptr 

// 소유권을 여러곳에서 공유할 수 있음, 최종적으론 메모리 누수를 지워줌
//unique_ptr 보단 조금더 덜 엄격하게 사용할 수 있음
//자기 자신이 몇번 이나 공유되는지 셈( Reference counting )
//자유롭게 쓰다가 결국 어디선 지워짐(delete 를 안해서 생기는 메모리 누수는 안일어남)

//new 보다 make_unique, make_shaerd 를 사용하는것이 좋음(특히 함수 parameter 로 넣을때)

#include <iostream>
#include "ch15_06_Resource.h"


using namespace std;


//스마트 포인터를 paramter 로 받는 함수
void soSomething(std::unique_ptr<Resource> res)
{
}

int main()
{
	//스마트 포인터를 함수 paramter 로 받는경우 위험할 수 있음
	//new 를 여기서 호출하는 경우 문법적으론 맞지만 위험함
	//완벽하게 생성이 되고 넘어가는게 아니고 new 가 중간에 껴서 애매해져버림
	//컴파일러마다 다르지만 좋진 않음
	//std::make_unique 사용하는것이 좋음
	//shared_ptr 에서도 마찬가지로 make_shared 를 쓰는것이 좋음
	
	//soSomething(std::unique_ptr<Resource>(new Resource(100000)));		//위험함
	soSomething(std::make_unique<Resource>(100000));

	



	//ptr1 에 넣기 위한 res 를 만들고 있음, 선호되는 방식은 아님
	//Resource* res = new Resource(3);  
	//res->setAll(1);
	{
		//std::shared_ptr<Resource> ptr1(res);  //shared_ptr 에 res 를 넣으면서 간접적으로 초기화 하기
		
		//아래에서 발생할 수 있는 문제 때문에 스마트 포인터를 초기화 할때는 간접적으로 초기화하는 방식보단
		auto ptr1 = std::make_shared<Resource>(3);  //make_shared 를 통해 직접 초기화 하는 방식을 선호
		ptr1->setAll(1);
		ptr1->print();


		//shared_ptr 특징은 자기가 가르키고 있는 주소의 포인터가 몇군데에서 공유(share) 를 하고있는지 셈
		//ptr1 이 가진걸로 ptr2 로 만드니 몇개째인지 셀수 있음(안에 데이터가 있음)
		{
			//std::shared_ptr<Resource> ptr2(ptr1);

			auto ptr2 = ptr1;	//make_shared 로 만들어서 res 가 없는 경우
			//소유권을 그냥 copy 해서 넣어주는것 처럼 보이지만 내부적으로 make_shared 에서 만든 Resource
			//에 대한 소유권을 몇군데에서 가지고 있는지 기록을 하고있기 때문에 마지막 shared_ptr 이 
			//소멸될때 Resource 를 지움, 그 전에는 안지움




			//문제가 될수 있는 방법
			//std::shared_ptr<Resource> ptr2(res);	//res 로 직접 만들고 있음
			
			//ptr1을 통하지 않고 만들고 있음, ptr1 은 res 의 소유권이 자기 말고 또 다른곳에도 있다는것을
			//알 방법이 없음, inner block 를 나가면서 ptr2 가 사라지면서 res 도 지워지지만
			//outter block 를 나가면서 ptr1 이 사라지면서 이미 지워진 res 를 다시 지우려고 하기 때문에 
			//문제가 발생함


			ptr2->setAll(3);
			ptr2->print();

			cout << "Going out of the block" << endl;
		}

		//블록을 벗어나서 ptr2 가 사라져도 ptr1 은 여전히 res1 에 대한 소유권을 가지고 있음
		ptr1->print();

		cout << "Going out of the outter block" << endl;
	}
	//블록을 벗어나면서 ptr1 이 사라지고 res도 같이 지움


	

	return 0;
}