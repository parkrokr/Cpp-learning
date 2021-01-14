//Ŭ����(class)�� const

//class �� instance �� const �� ����������� const member function �� ����� ����
//instance �� �Լ��� ���ڷ� �޴� �Լ��� ���鶧 parameter �� const reference �� �ؾ� 
//��������ڰ� ȣ����� �ʰ�, ���簡 �Ͼ�� ����

#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
	int m_value = 0;
	
	void setValue(int value) { m_value = value; } //const �Լ��� ���ٲ�, m_value �� �ٲٷ��� �õ��ϰ� �־
	
	//int	 getValue() { return m_value; }
	//����Լ��� const �� ����� : �Լ� �ȿ��� m_value �� ���� �ٲ��� �ʴ´�
	int	 getValue() const
	{
		return m_value; 
	}

	Something()
	{
		cout << "constructor" << endl;
	}

	//copy constructor �� ��������
	Something(const Something& st_in)
	{
		m_value = st_in.m_value;

		cout << "copy constructor" << endl;
	}
};

//���� ������ ȣ����
void print(Something st)
{
	cout << &st << endl;

	cout << st.getValue() << endl;
}

//���� ���ϰ� ������ ������
void print_ref(const Something& st) //parameter �� const reference �� �ٲ���
{
	cout << &st << endl;

	cout << st.getValue() << endl;
}


class Something_new
{
public:
	string m_value = "default";

	//const ������ �����ε��� �� �� ����
	const string& getValue() const  //����Լ��� const�� ����� ��� return �� const �� ����°� �Ϲ���
	{
		cout << "const version" << endl;
		return m_value;
	}

	string& getValue()
	{ 
		cout << "non-const version" << endl;
		return m_value; 
	}
};

int main()
{
	//const �� �⺻������ ����� ����� ������ �����

	//const Something something;  //member variable �� const �� ����� �Ͱ� ���� ȿ��
	//something.setValue(3);	//m_value �� ���� ���ٲ�


	//getValue() ���� m_value �� ���� �ٲٷ��� ���� ������ const ������ ������ ����
	//�����Ϸ��� m_value ���� �ٲ�� �ȹٲ��� �Ǵ����� �ʰ� ����Լ��� const �� �ƴϳķ� �Ǵ���
	//cout << something.getValue() << endl;


	//class �� instance �� const �� ����������� const member function �� ����� ����
	//�Լ��� ����������� const �� ������ ��� �� �ִ°� ����(����뿡 ������)



	//copy constructor
	Something something_new;

	cout << &something_new << endl; //print() �ȿ��� ȣ��Ǵ� st �� �ּ� �� : ���� �ٸ�

	print(something_new); 

	//�����ڰ� ȣ���
	//&something_new ���
	//print() �� ��
	//���� ������ ȣ��
	//copy �Ϸ��� ���� something_new�� ������
	//"copy constructor" ���
	//print() �� ���� m_value �� �� ����� something_new �� �ּ� �� m_value ��� 


	// ���簡 �� ���� <- �ּҰ� �ٸ�


	//���縦 �ϰ� ���� ������
	print_ref(something_new);
	//const reference �� parameter �� �߱� ������ st �� �޾ƿ� something_new �� 
	//���⼭ ���� somthing_new �� ����  
	//�׷��� ������ ���� �����ڵ� ȣ����� �ʰ� something_new �� �ּҵ� ����
	//�ſ� ȿ����



	//const ������ �����ε��� �� �� ����
	//return type ������ �����ε��� �Ұ��� ������ const �����δ� ������
	Something_new smthing;
	smthing.getValue() = 10; //non-const version

	const Something_new smthing2;
	smthing2.getValue(); //const version  : = 1004 ó�� assingment �Ұ���

	return 0;
}