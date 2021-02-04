//�Լ� try

//Ŭ������ �����ڿ��� �߻��ϴ� ���ܸ� ó���ϴ°͵� �߿���
//�̶� initializer list ���� �߻��ϴ� ���ܸ� ó���Ҷ� function try �� ���� �����

//�Լ� try �� �̿��� �����ڿ��� ���ܸ� ��� re-throw �� ���� ���� �ʾƵ� �ϴ°�ó��  �۵���
//�� (main()) ���� �ѹ� �� ����

//�����ڿ��� ���ܰ� �߻�(��ü�� ����� ������ �ȵǰ� ����)�� ����ó���� ���൵ ��ü�� ������ ������ 
//�ѹ� �� ���ܸ� ������
//��ü�� ����� ������ ���� ���ߴٴ� ����� ��ü�� ������ ���� �˷���� �Ѵٰ� ����?


#include <iostream>

using namespace std;




void doSomething()
{
	try
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Catch in doSomething()" << endl;
	}
}

//function try
//�Լ� body ��ü�� ���ؼ� try catch �� ���� �� ����
//���� ���� ������ �۵��� ��
void doSomething_new()
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething_new()" << endl;
}

//���� ���°� �����ڿ��� ���ܰ� �߻��� ��� ��� ���� ���� �����
class A
{
private:
	int m_x;
public:
	//A�� �����ڿ��� ���ܸ� ������ ����
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw - 1;
	}
};

class B :public A
{
public:
	B(int x)
		:A(x)
	{}

	//���ܸ� main() �� �ƴ϶� ���⼭ (B�� ������) ��� ����, �̶� function try �� �����
	B(int x)try : A(x)
	{
		// do initialization
	}
	catch (...)  //������ �߻��ϴ� ���ܵ��� ���� catch ��
	{
		cout << "Catch in B constructor " << endl;
		
		//throw;	//re-throw �� �ּ�ó���ص� main() �� �ִ� catch ���� �ѹ� �� ����,������ �ִ°�ó�� �۵���
	}

	/* ���⿡ ���ؼ� ���� try�� ��
	: A(x)
	{
		// do initialization
	}
	*/
};

int main()
{
	try
	{
		doSomething();
	}
	catch(...)
	{
		cout << "Catch in main()" << endl;
	}
	//doSomething() ���� ������ main() ���� ������ ����

	try
	{
		doSomething_new();
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	//doSomething() ���� ������ main() ���� ������ ����


	//A�� �����ڿ��� ���ܸ� ������ ����
	try
	{
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}
	//������ main() ���� catch �ϰ� ������ � ��쿣 B�� �����ڿ��� �ٷ� catch �� �ϰ����
	//�׋� �Լ� try ������ �����
	//B�� �����ڿ��� �������� throw;Ű���尡 ��� re-thorw �Ѱ�ó�� main() ���� �ѹ� �� ����
	//�Լ� try �� �����ڿ��� ����Ҷ� �߿��� Ư¡

	return 0;
}