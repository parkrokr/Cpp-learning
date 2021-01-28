//���� �Ҹ���

//�����ڴ� �ڽ�Ŭ�������� ���� �ڽ��� �����ڸ� ��������� �Ҹ��ڴ� ���� �Ҹ��ڸ� ����ϴ°��� ����
//�ڽ� Ŭ�������� �����Ҵ��� �� ��� �Ҹ��ڿ��� �޸𸮸� �ݳ��ؾ� �ϰ�
//�θ� Ŭ������ �ϳ��� �ڽ� Ŭ������ ���������� �� �ֱ� ������ �������� ������ ���
//���ﶧ �θ�Ŭ������ �̿��ؼ� ����°� �Ϲ���(�θ�Ŭ������ ����� �ڽ� Ŭ������ ���� ��������)

#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	~Derived() override // ~Base() �տ� virtual �� ����� override �� ������
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
	Derived derived1(5);

	//�ڽ� Ŭ������ �Ҹ��ڰ� ���� ȣ��ǰ� �״����� �θ�Ŭ������ �Ҹ��ڰ� ȣ���
	//������ ȣ�� ���� �ݴ�


	//�������� ����ϴ� ���
	//�ڽ�Ŭ������ �������κ��� ����������� �𸣴� ��찡 ��κ�
	//���ﶧ�� base �����͸� �̿��ؼ� ����°��� �õ��ϴ� ��찡 ����
	//base class �� �ϳ����� derived class �� ��κ� ����������

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base;

	//����ȭ�� ���� ���� ��� base �� �Ҹ��ڸ� ȣ��ǰ� derived �� �Ҹ��ڴ� ȣ���� ���� �ʱ�
	//������ momory leak �� �Ͼ �� ����

	return 0;
}