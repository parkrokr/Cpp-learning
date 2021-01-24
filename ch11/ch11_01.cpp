//����� �⺻ [1/2] Inheritance ( is-a relationship )

//public: ���� �ϸ� ��� ������ �������� �ʰ� ������ �� ������ ĸ��ȭ�� ���� ����

#include <iostream>
using namespace std;

class Mother
{
private:		//ĸ��ȭ�� �Ǿ����� �ڽ� class �� ���� �Ұ���
//public:		//�ڽ� class �� ������ �� ������ �ƹ��� �ۿ��� ������ �� �ֱ� ������ ĸ��ȭ�� �ƴ�
//protected:	//ĸ��ȭ�� �ϸ鼭(private ����) �ڽ� class �� ���� ����
	int m_i;


public:
	Mother(const int& i_in)
		: m_i(i_in)
	{
		std::cout << "Mother constructor " << std::endl;
	}
	//�׳� �����ڸ� �����ϸ� ���� �߻�(C2512), �⺻ �����ڰ� �� �����ڸ� �����ϸ鼭 �����
	//Child class �� �����ɶ� ���������� Mother class �� �����ڸ� ���� ȣ����
	//Child class �� ��� �޾Ҵٰ� ���� �Ѳ����� ���°� �ƴ϶� ������ �ܰ躰�� ��
	

	//�⺻ �����ڸ� �׳� �ϳ� ����⵵ ��
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


//Mother class �� ��ӹ��� Child class
class Child : public Mother //
{
	//Mother class �� �ִ°͵��� �⺻������ �� ����� �� ����

private:
	double m_d;

public:
	//�����ڴ� �޸𸮰� �Ҵ�ɶ� �ʱ�ȭ �ϴ°���, �Ҵ��� �ǰ� �����ؼ� �ִ°� �ƴ�
	//�ؿ� �ʱ�ȭ�� �ȵǴ� ������ Child class �� �����ɶ� m_in�� �޸� �� �����
	Child(const int& i_in, const double& d_in)
		//:m_in(i_in), m_d(d_in) //Mother ���� public: ���� �����ص� �ȵ�
		:Mother(i_in),m_d(d_in) //Child class �� i_in �� Mother class �� �־��ָ鼭 �����ڰ� ȣ��(�� �� ����� ���)
	{
		//���ϰ� �ذ��ϴ� ��� : initializer list �Ⱦ���
		//Mother::setValue(i_in);
		//m_d = d_in;

		// :Mother(i_in),m_d(d_in) �� ���� ���� ó�� initilizer list �Ⱦ��⸦ ���ص� ��
	}


	void setValue(const double& d_in)//setValue() �� int �� double �Ѵ� �ް� �ϰų�, �̸����� �����ϰų�
	{
		m_d = d_in;
	}

	//setValue() �� int �� double �Ѵ� �ް� �ϱ�
	void setValue(const int& i_in, const double& d_in)
	{
		//m_i = i_in; //m_i �� Mother class �� member variable
		//private:	�Ұ���,
		//public:	����, �ڽ� class ���� �ۿ��� �ƹ��� ������ �� ����
		//protected:ĸ��ȭ�� �����ϸ鼭(�ۿ��� ���� �Ұ���), �ڽ� class �� ������ �� ���� 


		//�׳� private: �� ���� ������
		//setValue(i_in); //Mother class �� �ִ� setValue() ������ ����, ������ Child�� setValue() �� ��ħ
		Mother::setValue(i_in); //Mother class �� �ִ� setValue() ��� �������ֱ�

		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

//Derived class ,����� �޴� class, Mother class �κ��� ���� class ���� �����ؼ� ���� �� ����
class Daughter : public Mother  //Daughter class is derived from Mother class ��� ǥ����
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

	//�θ� class , generalized class 
	//�ڽ� class , derived class  , ���� class �� �ְ� �Ϲ�ȭ�� ��ҵ��� �̾Ƽ� ����� ��

	//Mother class �� ��ӹ��� Child class
	//Mother class �� �ִ°͵��� �⺻������ �� ����� �� ����


	//�ڽ� class �����ڸ� �������� �ʾ�����
	//Child child; //������ ����°��� ���� ������
	//child.setValue(128); //Mother ���� int ���� Child ���� double �̶� double �� ��
	//child.Mother::setValue(1024); //�̷������ε� ȣ�� ����


	//�ڽ� class ������ ���� ��
	Child child(1024, 128.0);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	
	return 0;
}