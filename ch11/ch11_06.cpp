//������ ( Derived ) Ŭ������ ���ο� ��� �߰��ϱ�

#include <iostream>
using namespace std;

class Base
{
//private:
protected:
	int m_value;

public:
	Base(int value)
		:m_value(value)
	{

	}

};


class Derived : public Base
{
public:
	Derived(int value)
		:Base(value)
	{
	}

	//Base �� �ִ� ���� �ǵ帮���� �Ҷ�
	//protected �� �ٲ��ֱ�
	void setValue(int value)
	{
		Base::m_value = value; //�̰͸� ������� ���⿡ ������ �ʿ䰡 ����
		//do some work with the variables defined in Derived
	}
};


int main()
{
	//�ڽ� Ŭ�������� �θ� Ŭ������ ��������� �ǵ帮�� ���� ���
		//1. ��������� protected: �� �ؼ� ������ �� �ְ� ���ֱ�
		//2. private: ���� �״�� �ΰ� getters() �� ���� �����ϱ� 
			// 2���� ��� ����Ŭ������ �Լ��� �ѹ� ���ľ� �Ǳ� ������ �����ս��� �� ������ �� ����
			// ���� ���� ����� ��� �ڵ��ϴ°� �������� ���ŷο� �� ����

	//�׶��׶� ��Ȳ�� ���� �� �����ϱ�

	return 0;
}
