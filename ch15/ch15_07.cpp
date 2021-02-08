// 순환 의존성 문제( Circular dependency issues ) 와 std::weak_ptr

//shared_ptr 을 사용할때 순환 의존성 문제가 발생할 수 있음
//객체가 사라져야 하는데 count 가 0으로 떨어지지 않아 소멸이 안되는 문제, 메모리 누수 발생할 수 있음
//weak_ptr 을 사용하면 내부에서 count 를 하지 않기 때문에 느슨하게 사용 가능
//대신에 weak_ptr 을 사용하려면 lock() 을 사용해 shared_ptr 로 바꾸고 사용해야함

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
	std::string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}


	friend bool partnerUP(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		//순환 참조
		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

		return true;
	}


	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
		//lock() 의 return 값은 shared_ptr 임
		//weak_ptr은 직접 사용할 수는 없고 lock() 을 해서 shaerd_ptr 로 바꾸고
		//그 shared_ptr 을 이용해서 작업을 할 수있음
		//순환 의존성 구조를 깨기 위해 이렇게 구현되어있음
	}


	const std::string& getName() const
	{
		return m_name;
	}

};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	//스마트 포인터를 사용하는 기본적인 이유는 메모리를 신경안써도 잘 지우기 위해서임


	//문제가 생기는 부분
	partnerUP(lucy, ricky);
	//Lucy is partnered with Ricky 까진 잘 나오지만 소멸자들이 호출되지 않고 있음
	//메모리 누수가 발생하고 있음


	//Person 자체가 shared_ptr 로 만들어져있음
	//순환 참조는 객체가 멤버로 shared_ptr 을 가지고 있을때 생길 수 있음
	//m_partner 가 shaerd_ptr 인 경우 friend bool partnerUP() 에서 순환참조를 할때
	//서로 참조를 하고 있어서 소유권을 공유하는 횟수(count) 가 +1 씩 됨
	//lucy 와 ricky 가 scope 를 벗어날때 사라져야 하지만 count 는 0 이 아니기 때문에 소멸자들이 호출되지 않고 
	//사라지지 않고 있음

	//shared_ptr 을 weak_ptr 로 바꾸면 해결됨(소멸자들이 잘 호출됨)
	//shared_ptr 을 사용하면 counting 을 하지 않음 , 사실 내부에 카운팅이 되기는 하지만 객체 생성과 소멸에 
	//영향을 주지 않음




	//weak_ptr 의 단점: weak_ptr 의 내용물을 사용하려고 할때 lock() 을 해줘야 함
	std::cout << lucy->getPartner()->getName() << std::endl;
	//lucy 를 lock() 을 해서 shared_ptr 로 바꾸고 getName() 호출하고 있음


	return 0;
}