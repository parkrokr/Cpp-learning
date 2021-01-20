//���� ������ �����ε�, ���� ����( Deep copy ) vs ���� ���� ( Shallow copy )

//���� ����
//�⺻ ���� �����ڰ� ���ذ� : m_data�� �ִ� �޸� �ּҰ� ����
//���� �Ҵ�� �޸𸮰� �����Ǿ����� ��� ū ���� �߻�

//���� ����
//���� �����ڰ� ������ �ּڰ��� �������� �ʰ� �޸𸮸� �ٽ� �Ҵ�ް� ����
//������ �ٽ� �������ְ� ����


//std::string �׳� ��� �Ǵ� ����� �޾� �߰� ����
//member variable �� std::string data �ϳ� ����� ����(�����ս��� �ణ ������ �� ������ �ڵ� ��¥�� ū���� �ȳ�)

//�ֱٿ� std::string �� class �ȿ� �ִ� ����� �ַ� ��������� �̷� �������� �߻��� ���� �ִٴ°� �˾ƾߵ�


#include <iostream>
#include <cassert>

using namespace std;

class MyString
{
//private:  //�Ϲ������� private, �ּҸ� ��� ���� public ���� ����
public:
	char* m_data = nullptr;  //���ڿ��� �ּҸ� �����ϱ� ���� ������
	int m_length = 0;

	std::string data; //std::stdring �� ����ϸ� �̷� �������� ���ؼ� ������ �� ����
public:
	MyString(const char* source = "")
	{
		assert(source); //���ڿ��� ���� �ʾҴ���

		m_length = std::strlen(source) + 1;  //���ڿ��� ����� ���� �˾Ƴ��� '\0'�� �߰��ϱ� ���� +1
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)  //���� �ϳ��ϳ� ����
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';  //�������� \0 �� �־� ���ڿ� �������̶�°��� ǥ��
	}

	//���������
	//source �� �������ְ� �ݵ�� ������ٴ� ������ ������ �޸𸮸� ������� source �� �޸𸮸� �ᵵ ��
	//�׷� ��찡 ����
	//��������ڸ� �������� �������� ���� ����� ���ƾ� �� ���
	//MyString(const MyString& source) = delete; �ؼ� ����(����å)
	MyString(const MyString& source)
	{
		cout << "Copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr) //source.m_data �� �޸𸮸� �����������
		{
			m_data = new char[m_length]; //���� �޸� �Ҵ�ޱ�

			for (int i = 0; i < m_length; ++i) //�� �޸𸮿� source.m_data �����ϱ�
				m_data[i] = source.m_data[i];  //source �� �޸𸮰� ������ �ִ� ������� ����
		}
		else
			m_data = nullptr;  //nullptr ��� 0 �ִ� ��쵵 ������ �ֽ��� nullptr

	}


	//���� ������
	MyString& operator = (const MyString& source)
	{
		//shallow copy   
		//���縸 ���ְ� ����(�⺻ ���� �����ڰ� ���� ����)
		/*this->m_data = source.m_data;
		this->m_length = source.m_length;*/


		cout << "Assignment operator " << endl;

		//prevent self-assignment ��������ڿ� �޸� ���Կ����ڴ� ������ ����(hello = hello)
		//�ƹ��͵� ���ϰ� ����
		if (this == &source) 
			return *this;

		//�����ڴ� �ڱⰡ ó�� �����Ǵ°��̱� ������ ������ �����Ҵ�� �޸𸮸� �������� ����
		//���� �����ڶ�� �̹� �޸𸮸� ������ ���� �� ����  -> ��������
		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }


	//�Ҹ���
	~MyString()
	{
		delete[] m_data;  //������� memory leak �� ���� ���� delete ( �ݵ�� �ʿ��� ��ġ )
	}
};

//�̺κ��� ��������ڿ� ���Կ����ڿ��� ����ǰ� ������ �Լ��� ���� ���⵵ ��
//m_length = source.m_length;
//
//if (source.m_data != nullptr)
//{
//	m_data = new char[m_length];
//
//	for (int i = 0; i < m_length; ++i)
//		m_data[i] = source.m_data[i];
//}
//else
//m_data = nullptr;


int main()
{
	//���� �޸� �Ҵ��� ����ϴ� ��� ���� �����ڸ� ����ų� ���Կ����ڸ� �����ε��Ҷ� �����ؾ���
	//�ֱٿ� �׸� ����� �ʰ� container �� �����


	MyString hello("hello");

	cout << (int*)hello.m_data << endl;  //cout �� ���ڿ� �ּҰ� ������ ���ڿ��� ����ϱ� ������ (int*)�� cast
	cout << hello.getString() << endl;



	//scope �� �����ϰ� �ȿ��� local variable �� �� ����
	{
		//copy �� �����ǰ� �ֱ� ������ ���Կ����ڰ� �ƴ� ��������ڰ� ȣ���(���� �������� �⺻ ���� ������)
		MyString copy = hello;  
		cout << (int*)copy.m_data << endl;  //copy.m_data �� hello.m_data �� �ּҰ� ����
		cout << copy.getString() << endl;
	}
	//copy ���� �ּҰ��� �����ؼ� ������ ����(�⺻ ��������ڸ� �����Ϸ��� �������� new �� ȣ������ �ʾ���)
	//heap ���� hello ���� new �� �Ҵ���� �޸� �ϳ��ۿ� ����
	//copy �� scope ���� ����鼭 delete �� ��������
	//copy �� ��������� hello �� �ּҵ� ���� ���������ȱ� ������


	cout << hello.getString() << endl;
	//�̻��� ���� ��µ�




	//���� ����
	//�⺻ ���� �����ڰ� ���ذ� : m_data�� �ִ� �޸� �ּҰ� ����
	//���� �Ҵ�� �޸𸮰� �����Ǿ����� ��� ū ���� �߻�


	//���� ����
	//���� �����ڰ� ������ �ּڰ��� �������� �ʰ� �޸𸮸� �ٽ� �Ҵ�ް� ����
	//������ �ٽ� �������ְ� ����



	//��������ڰ� ȣ��Ǵ� ���� ���� ������ ȣ��Ǵ� ���
	//���� ������ ȣ��
	MyString str1 = hello; 
	//MyString str1(hello); ��ɻ� ������ �̷��� �ϸ� �� �򰥸�

	//���� ������ ȣ��
	MyString str2;
	str2 = hello;
	return 0;
}