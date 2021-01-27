//다중 상속 Multiple Inheritance

//경우에 따라 문제가 발생할 수 있음(다이아몬드 상속)
//함수가 중복되었을때 문제가 발생할 수 있음(어떤 클래스로부터 상속받았는지 구분해주면 해결됨)

#include <iostream>
using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

//USBDevice 와  NetWorkDevice 를 상속받은 class
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
	//생성자를 만들때는 좀 귀찮을 수 있음
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id),NetworkDevice(net_id)
	{}

	//경우에 따라 id 를 하나만 받아서 초기화를 할수도 있음
	//경우에 따라 가능할수도 불가능할수도 있음( id 가 서로 다른 경우)
	/*USBNetworkDevice(long id)
		: USBDevice(id), NetworkDevice(id)
	{}*/
};

//다이아몬드 상속
class A
{};

class B1 : public A
{};

class B2 : public A
{};

class C : public B1, public B2
{};
//A의 한개 또는 한개이상의 사본을 C 가 갖게 됨
//여러가지 문제가 발생할 수 있음

int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	//함수가 중복될때 문제가 생김   
	//my_device.getID();  //ambiguity error

	//해결방법  어떤 class 로부터 받았는지 구분해주면 됨
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

	return 0;
}