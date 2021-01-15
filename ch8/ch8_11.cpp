//����(static) ��� �Լ�

//static ��� �Լ��� Ư�� instace �� ������� ���ɼ� ����(������ ����), this �� ��� ����
//non-static ��� �Լ��� Ư�� instace �� ���ӵǾ ����
//static ��� ������ �����ڿ��� �ʱ�ȭ�� ����(c++ ���� �����ڸ� static ���� ����)
//inner class �� ����ϸ� static ��� ���� �ʱ�ȭ ����

#include <iostream>

using namespace std;

class Something
{
	//inner class �� ����ϸ� static ��� ���� �ʱ�ȭ ����
public:
	class _init
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};

private:
	static int s_value;  //���� class �� ��� instance ���� ������ ����(����)
	int m_value;

	//inner class �� ����ϸ� static ��� ���� �ʱ�ȭ ����
	static _init s_initializer;

public:
	Something()
		:m_value(123)  //s_value(1024) //static ��� ������ �����ڿ��� �ʱ�ȭ�� ����
	{}

	//static ��� ������ �����ڿ��� �ʱ�ȭ �Ƿ��� �����ڰ� static �̸� ������ c++���� �Ұ�����
	//inner class �� ����ϸ� ����
	


	static int getValue()
	{
		return s_value; 

		//��������
		//return this->s_value;		//this �� ����
		//return m_value;			//this �� �����ٴ°��� this�� �����ؾߵǴ� ���� ����( m_value)
	}

	
	//�Ϲ����� ��� �Լ�
	int temp()
	{
		return this->s_value; //this �� ����Ѵٴ� ���� Ư�� instace �� �ּҸ� �޾Ƽ� ���
	}
};

int Something::s_value = 1024;  //�ʱ�ȭ, private: �� static ��������� ���� ������ �ȸ���
Something::_init Something::s_initializer;  //1234 �� �ٽ� �ʱ�ȭ

int main()
{
	//cout << Somthing::s_value << endl; // private : �� ���� ����

	Something s1;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl; // private : �� ���� ����
	
	//Somthing �� instace �� ��������� ������ ������ �����ϰ� ������ ������� instace ��
	//s_value �� ���� �ּҰ��� ����


	//Ư�� instance �� ������� ����� �����ϴ� ����� ����� ������
	//getValue() �� static ���� �����ϸ� ����
	cout << Something::getValue() << endl;


	//����Լ��� �ּҸ� ������ �� ����
	//Member Funcion Pointer
	Something s2;


	//non-static member function		//Ư�� instace�� ����Ǿ�� �����ų �� �ִ� ������ ����

	//int (Somthing:: * fptr1)() = s1.temp;  �ȵ�
	//&s1.temp; &(s1.temp);, (s1.temp) �� �ȵ�							


	//m_value �� s1 �� s2 �� ���� �ּҰ� �ٸ����� �Լ��� ����

	//Member Funcion Pointer		
	int (Something:: * fptr1)() = &Something::temp;  

	//��� �Լ��� �����ʹ� ����ȯ�� ������ ����, ���� �Լ� ������ ���԰� �ٸ��� &�� �ݵ�� �ٿ������

	//���
	cout <<(s2.*fptr1)() << endl;
	//����Լ��� �����ʹ� �����ų�� �����ų�� s2��� instance�� �����͸� �Բ� �־���� ���� ����

	//non-static ��� �Լ��� instance �� ���ӵǾ� �ֱ� ������ intace �� this �����Ͱ� �־�� �۵�����
	//cout<<(*fptr1)()<<endl; �Ұ���



	//static member function		//Ư�� instace �� ������� �����ų �� �ִ� ������ ����

	//int (Somthing:: * fptr2)() = &Somthing::getValue;   //�ȵ�
	int (*fptr2)() = &Something::getValue; //Ư�� instace �� ������� �����ų �� �ִ� ������ ����

	cout << fptr2() << endl;  //Ư�� instace �� ������ص� ������ ��






	return 0;
}