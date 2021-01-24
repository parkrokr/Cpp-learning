//상속의 기본 [1/2] Inheritance ( is-a relationship )

//public: 으로 하면 상속 구조를 생각하지 않고 구현할 수 있지만 캡슐화엔 맞지 않음

#include <iostream>
using namespace std;

class Mother
{
private:		//캡슐화는 되었지만 자식 class 도 접근 불가능
//public:		//자식 class 가 접근할 수 있지만 아무나 밖에서 접근할 수 있기 때문에 캡슐화가 아님
//protected:	//캡슐화는 하면서(private 유지) 자식 class 는 접근 가능
	int m_i;


public:
	Mother(const int& i_in)
		: m_i(i_in)
	{
		std::cout << "Mother constructor " << std::endl;
	}
	//그냥 생성자를 구현하면 에러 발생(C2512), 기본 생성자가 이 생성자를 구현하면서 사라짐
	//Child class 가 생성될때 내부적으로 Mother class 의 생성자를 같이 호출함
	//Child class 가 상속 받았다고 전부 한꺼번에 오는게 아니라 층층이 단계별로 옴
	

	//기본 생성자를 그냥 하나 만들기도 함
	Mother()
		:m_i(0)
	{}


	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}

};


//Mother class 를 상속받은 Child class
class Child : public Mother //
{
	//Mother class 에 있는것들을 기본적으로 다 사용할 수 있음

private:
	double m_d;

public:
	//생성자는 메모리가 할당될때 초기화 하는거지, 할당이 되고 복사해서 넣는게 아님
	//밑에 초기화가 안되는 이유는 Child class 가 생성될때 m_in의 메모리 가 없어서임
	Child(const int& i_in, const double& d_in)
		//:m_in(i_in), m_d(d_in) //Mother 에서 public: 으로 지정해도 안됨
		:Mother(i_in),m_d(d_in) //Child class 가 i_in 을 Mother class 에 넣어주면서 생성자가 호출(좀 더 우아한 방법)
	{
		//편하게 해결하는 방법 : initializer list 안쓰기
		//Mother::setValue(i_in);
		//m_d = d_in;

		// :Mother(i_in),m_d(d_in) 를 쓰면 위에 처럼 initilizer list 안쓰기를 안해도 됨
	}


	void setValue(const double& d_in)//setValue() 가 int 와 double 둘다 받게 하거나, 이름으로 구분하거나
	{
		m_d = d_in;
	}

	//setValue() 가 int 와 double 둘다 받게 하기
	void setValue(const int& i_in, const double& d_in)
	{
		//m_i = i_in; //m_i 는 Mother class 의 member variable
		//private:	불가능,
		//public:	가능, 자식 class 말고도 밖에도 아무나 접근할 수 있음
		//protected:캡슐화를 유지하면서(밖에서 접근 불가능), 자식 class 는 접근할 수 있음 


		//그냥 private: 을 쓰고 싶을때
		//setValue(i_in); //Mother class 에 있는 setValue() 가져와 쓰기, 하지만 Child의 setValue() 랑 겹침
		Mother::setValue(i_in); //Mother class 에 있는 setValue() 라고 지정해주기

		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

//Derived class ,상속을 받는 class, Mother class 로부터 많은 class 들을 유도해서 만들 수 있음
class Daughter : public Mother  //Daughter class is derived from Mother class 라고도 표현함
{
	
};

class Son : public Mother
{

};

int main()
{
	Mother mother;
	mother.setValue(512);
	cout << mother.getValue() << endl;

	//부모 class , generalized class 
	//자식 class , derived class  , 여러 class 가 있고 일반화된 요소들을 뽑아서 만드는 것

	//Mother class 를 상속받은 Child class
	//Mother class 에 있는것들을 기본적으로 다 사용할 수 있음


	//자식 class 생성자를 구현하지 않았을때
	//Child child; //생성자 만드는것이 조금 복잡함
	//child.setValue(128); //Mother 에선 int 지만 Child 에선 double 이라 double 로 뜸
	//child.Mother::setValue(1024); //이런식으로도 호출 가능


	//자식 class 생성자 구현 후
	Child child(1024, 128.0);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	
	return 0;
}