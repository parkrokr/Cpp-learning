//���� ��� Multiple Inheritance

//��쿡 ���� ������ �߻��� �� ����(���̾Ƹ�� ���)
//�Լ��� �ߺ��Ǿ����� ������ �߻��� �� ����(� Ŭ�����κ��� ��ӹ޾Ҵ��� �������ָ� �ذ��)

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

//USBDevice ��  NetWorkDevice �� ��ӹ��� class
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
	//�����ڸ� ���鶧�� �� ������ �� ����
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id),NetworkDevice(net_id)
	{}

	//��쿡 ���� id �� �ϳ��� �޾Ƽ� �ʱ�ȭ�� �Ҽ��� ����
	//��쿡 ���� �����Ҽ��� �Ұ����Ҽ��� ����( id �� ���� �ٸ� ���)
	/*USBNetworkDevice(long id)
		: USBDevice(id), NetworkDevice(id)
	{}*/
};

//���̾Ƹ�� ���
class A
{};

class B1 : public A
{};

class B2 : public A
{};

class C : public B1, public B2
{};
//A�� �Ѱ� �Ǵ� �Ѱ��̻��� �纻�� C �� ���� ��
//�������� ������ �߻��� �� ����

int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	//�Լ��� �ߺ��ɶ� ������ ����   
	//my_device.getID();  //ambiguity error

	//�ذ���  � class �κ��� �޾Ҵ��� �������ָ� ��
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

	return 0;
}