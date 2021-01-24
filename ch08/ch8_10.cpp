//���� static ��� ����

//static ��� ������ class �ȿ��� �ʱ�ȭ ����, �ܺ� ���Ϸ� ������ cpp ���Ͽ� ����, ����� �θ� ������ ���� �߻�
//static const ��� ������ class �ۿ��� �ʱ�ȭ ����

#include <iostream>

using namespace std;

//�Լ��� �ϳ��� ȣ��ɶ����� s_id �� 1�� ����
//�����ѹ��� �����Ҷ� ���� ����ϴ� ���
int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

class Something
{
public:
	int m_value = 1;
	
	static int s_value; //static ��� ������ static int m_value_static = 1; ������� �ʱ�ȭ ����
	
	static const int s_value_const = 1; //class �ۿ��� �ʱ�ȭ ����, �ۿ��� ���� ���ٲ�
	
	static constexpr int s_value_constexpr = 1; //constexpr�� compile time �� �����Ǿ�� ��

};

int Something::s_value = 1; //�ܺη� ���� define in cpp, ����� �θ� ������ ���� �߻�
//����� ������ �ߺ����� ������ �߻�

//int Something::s_value_const = 1;  //const �̱� ������ ���� ���ٲ�

int main()
{
	//�Լ�
	cout << generateID() << endl; //1
	cout << generateID() << endl; //2
	cout << generateID() << endl; //3


	//��� ����
	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl;
	cout << &st2.m_value << " " << st2.m_value << endl;


	
	//static ��� ����

	//s_value �� instance �� ��� �ּҰ� ����
	cout << &Something::s_value << " " << Something::s_value << endl;


	st1.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;

	//�ּҿ� s_value �� ����  st1, st2 �Ѵ� ����


	cout << &Something::s_value << " " << Something::s_value << endl;
	
	Something::s_value = 1024; //������ �̷��� �ٲ� �� ����

	cout << &Something::s_value << " " << Something::s_value << endl;


	//s_value �� instance �� ��� ���� ������ ������ (static �̱� ������)


	return 0;
}