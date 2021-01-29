//가상 기본 클래스 (Virtual base classes ) 와 다이아몬드 문제 ( The diamond problem )


// 가상 싱속을 하면 손자 클래스에서 직접 조상 클래스의 생성자를 호출하게 됨
// 다이아몬드 상속의 문제는 두 부모 클래스가 각각 조상클래스의 생성자를 호출해서
//조상 클래스의 인스턴스가 두개가 생긴다는 것임
// 가상 상속을 하면 부모클래스에서 조상클래스의 생성자를 호출 못하게 막아서
//자식 클래스가 조상 클래스의 생성자를 호출하도록 강제함(생성자를 호출하는 주체)

#include <iostream>
using namespace std;

//class A
//{};
//
//class B1 : public A
//{};
//
//class B2 : public A
//{};
//
//class C : public B1, public B2
//{};

//다이아몬드 모양을 예상하지만 실제로는 A 가 두개가 생김(B1과 B2가 각각 A의 생성자를 호출함)
//그래서 B1 과 B2 에 virtual 을 넣어서 가상 기본 클래스를 만듬(가상 상속)
//B1과 B2를 가상상속을 하면 B1과 B2 에선 A의 생성자를 호출하지 않음
//C가 A의 생성자를 호출하게 됨(생성자를 호출하는 주체가 되어야 함)

//밑의 예제에서 Copier 에서 PowerdDevice의 paramter 가 있는 생성자를 구현하지 않으면
//paramter 가 없는 기본생성자를 자동으로 호출하려 하지만 PowerdDevice 에는 paramter 가 없는
//생정자가 정의되어 있지 않기 때문에 에러 발생(parameter 가 있는 생성자를 구현했기 때문에
//기본생정자는 생성되지 않게 되어버려서)

class A
{};

class B1 : virtual public A
{};

class B2 : virtual public A
{};

class C : public B1, public B2
{};


//예제
class PowerdDevice
{
public:
	int m_i;

	PowerdDevice(int power)
	{
		cout << "PowerdDevice: " << power << '\n';
	}

	PowerdDevice() {}
	//PowerDevice 에 기본생성자를 구현해주면 Copier 에서 parameter 가 있는 생성자를 호출하는걸 구현하지 않아도
	//자동으로 기본생정자를 호출하기 때문에 에러가 일어나지 않음
};

class Scanner : virtual public PowerdDevice
{
public:
	Scanner(int scanner, int power)
		:PowerdDevice(power)
	{
		cout << "Scanner: " << scanner << '\n';
	}
};

class Printer : virtual public PowerdDevice
{
public:
	Printer(int printer, int power)
		:PowerdDevice(power)
	{
		cout << "Printer: " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		:Scanner(scanner, power), Printer(printer, power)
		//PowerdDevice(power) //Scanner 와 Printer 을 가상화 시킨후 PowerdDevice 의 생성자를 호출해야함
	{}
};

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PowerdDevice::m_i << endl;
	cout << &cop.Printer::PowerdDevice::m_i << endl;

	//virtual 을 붙이기 전
	//PowerdDevice 가 두번 호출되고 있음
	//m_i 도 다른 주소를 가짐
	//서로 다른 PowerdDevice 임

	//virtual 을 붙인 후
	//붙이면 Copier 에서 에러가 남
	//Copier 에 PoweredDevice 생성자를 별도로 호출해주면 됨

	//결과:
	//PowerdDevice 의 생성자가 한번만 호출되고 m_i 의 주소는 동일함

	return 0;
}
