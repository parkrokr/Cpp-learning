// string stream ���ڿ� �帧

//���ڿ� �帧�� ���� ������ �ϴ� string stream

#include <iostream>
#include <sstream>		//sring stream

using namespace std;

int main()
{
	//stream �� �ڽĵ�

	{
		stringstream os;

		// << : insertion operator, >> : extraction operator	 ����� �ְ� ���� ����
		os << "Hello, World";
		os << "Hello, World2" << endl;;		//�����̴� ����, endl �� stringstream �� ��

		//os.str("Hello, World");			// ���ۿ� �ִ� ������ ���� Hello, World �� �ٲ����(�����ִ��� ����)
		os.str("Hello, World\n");			// �ٹٲ� \n �� stream �� ���Ե� �� ����


		//�̾ƿ���
		string str;

		//os >> str;						//��ĭ�� ������ �߶����, ��ġ cin>>a>>b; �Ҷ� �������� �����ϵ���
		str = os.str();						//stream�� ��°�� ������,str() �� stream �� ��ü�� ��ȯ��
		cout << str << endl;

		cout << os.str() << endl;			//os.str() �� ���� cout ���� ����ϴ� ����� ����
	}


	//����
	
	//���ڸ� ���ڿ��� �ٲ㼭 �Է�
	{
		stringstream os;

		os << "12345 67.89";					//��ĭ�� �߰��� �ϳ� ����, ���ڸ� ���ڿ��� �Է¹ް� ����

		string str1;
		string str2;

		os >> str1 >> str2;						//��ĭ������ ����� ���� �� ����

		cout << str1 << "|" << str2 << endl;	//12345|67.89

		//12345 67.89 �� ��ĭ�� ������ str1 �� �� ������ 1234567.89| �� ��µ�
	}
	
	//���ڸ� �Է�
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;

		//os << i << d;							//��ĭ�� ��� str1 �� �� ������ 1234567.89| �� ��µ�
		os << i << " " << d;					//��ĭ�� �߰��ؼ� �и��� �Ǿ� 12345|67.89 �� ��µ�

		string str1;
		string str2;

		os >> str1 >> str2;						//��ĭ���� ���� ���ϸ� str1 �� �� ������

		cout << str1 << "|" << str2 << endl;	
	}

	//���ڷ� �ޱ�
	{
		stringstream os;

		int i = 12345;
		double d = 67.89;
		os << i << " " << d;

		//os << "12345 67.89";					//���ڿ� �־��൵ ���ڷ� �ٽ� ���� �� ����

		int i2;
		double d2;

		os >> i2 >> d2;

		cout << i2 << "|" << d2 << endl;		//12345|67.89
	}


	//stringstram ����, str(), clear()
	{
		stringstream os;
		os << "12345 67.89";	

		os.str("");								//��ĭ���� ��ü��, ������
		os.str(string());						//"" ��ſ� string(), ū ���̴� ����
		
		os.clear();								//state ���� �ʱ�ȭ, clear() �� stream �� ������� ����


		cout << os.str() << endl;				//�ƹ��͵� ��� �ȵ�

		os << "Hello";							//���� �ٽ� �߰��ϱ�
		cout << os.str() << endl;				//Hello

		//str() �� paramter �� ������( str("") )�� �Է¹��������� ���۸� �����
		//paramter �������� stream �� ���빰�� ������ string ��ü�� return ��
	}



	return 0;
}