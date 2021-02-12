// istream ���� �Է¹ޱ�

//cin				
	//�������� �Է��� ������,����� \n�� ����, \n �� ���ۿ� ���ܵ�, cin �� ��� ���� \n �� ���õǱ� ������
	//������ ������ ���� �Լ����� ���� ���� �����ϸ� ������ �߻�, ���ۿ� �����ִ� \n �� �޾ƹ���
	//cin.ignore() �� ���� �ذ� ���� (ingnore() �� �ѱ��ڸ� �����ϱ� ������ \n �� ���õǰ� �����۵���)

//cin.get()
	//����,\n ����, ���� �� ���ڿ��� �Է¹���
	//���ڿ��� ���� ��� cin.get(buf, n)
	//n-1 ���� �����ϰ� \n�� ���ۿ��� �Ȱ�����(���ۿ� ���ܵ�)
	//null character �� �ڵ����� ����, �ƹ��͵� �Ȱ����͵� ����
	//\n �� �Է����� �����ϰ� ���ۿ� �����־ ���� cin.get() �̳� cin.getline() ������ ���۵�
	//cin.ignore() �� ���� �ذ� ���� (ingnore() �� �ѱ��ڸ� �����ϱ� ������ \n �� ���õǰ� �����۵���)
	

//cin.getline()
	//����, \n ����, ���ڿ��� �Է¹���
	//cin.getline(buf, n);
	//n-1 �� ���� �����ϰ� \n �� ���ۿ��� �����ͼ� null character �� ����(�ƹ��͵� �Ȱ����͵� ����)
	//���ۿ� \n �� �������� �ʾƼ� ���� cin.get() �̳� cin.getline() �� ������ ���� �۵� 
	
//getline()
	//string �� ����
	//getline(cin, buf);  �ִ� ���� ���� �Է����� �ʾƵ� ��
	//cin �� ����Լ��� �ƴϱ� ������ cin.gcount() �� ī��Ʈ ���� ����


//cin.ignore(n)
	//���ۿ��� n ���� ���ڸ� ����
	//n �� default ���� 1 �̶� cin.ignore() �ϸ� 1���� ���ڸ� ������
	//cin �̳� cin.get() ���� ���ۿ� �����ִ� \n �� �����ϱ� ���ؼ� ���


//cin.peek()
	//������ �� �� �ѱ��ڸ� ����, �������� ����

//cin.unget()
	//���������� ���� ���ڸ� ���ۿ� ��ȯ

//cin.putback()
	//������ ���� �տ� ���ڸ� �÷���



#include <iostream>
#include <string>
#include <iomanip>	// input/output manipulators

using namespace std;

int main()
{
	//������ ����Ͽ� iostream
	{
		cout << "Enter a number " << endl;		//���� ���
		int i;									//���� ����
		cin >> i;								//������ ������ �Է� �ޱ�
		cout << i << endl;						//�Է� ���� ������ �ٽ� ���
	}

	//�⺻������ ��Ʈ���� ���ۿ� ����� ���� �Ϻθ� ���ݾ� �������� ���
	{
		char buf[5];

		cin >> buf;		//5�� ���� ���� �Է��ϸ� ��Ÿ�� ����, 5�� ���� ������ ���� ����

		cout << buf << endl;



		//�̷��� �׻� �����ϸ� �Է��ϱ� ������
		//setw()
		cin >> setw(5) >> buf;		//setw(5) �� �ϸ� 5���� ������ ����
		cout << buf << endl;		//abcd

		//cin ���� abcdefghjklmn ���� ���� �Է������� cin, �� input stream �� ������ �ִ� ���ۿ� ������ ����
		//���߿��� 5���� �������µ� null character ���� 5���� abcd �� ������
		//������ efghijklmn �� ���ۿ� ��������

		cin >> setw(5) >> buf;		//���ۿ� �����ִ� efghijklmn �߿��� 4��( 1���� null character) ������
		cout << buf << endl;		//efgh


		cin >> setw(5) >> buf;
		cout << buf << endl;		//ijkl


		//���ۿ� ��� ���������� �������� ���
	}


	//�ϳ��� �ޱ�
	{
		char ch;

		while (cin >> ch)		//���۷κ��� ��� �ϳ��� ������
			cout << ch;

		//Hello world �� �Է��ϸ� HelloWorld �� ��µ�(��ĭ�� �����)
		//cin �� ��ĭ�� �޾ƿ��� ����
		//���۷δ� �������� ���ۿ��� ��ĭ�� ��������, ��ĭ�� ������


		//��ĭ�� �����ϴ°� ������ ���(��ĭ���� ���е�)
		int i;
		float f;

		cin >> i >> f;						//1024 3.14 �Է� (��ĭ���� ���е�)
		cout << i << " " << f << endl;		//1024 3.14

		//��ĭ�� �����ϴ°� �ǵ������� ����� ���� ����



		//��ĭ�� �Է� �ް� ���� ���
		//cin.get() ���
		while (cin.get(ch))
			cout << ch;
		//Hello World �Է��ϸ� ��ĭ���� �� �����ͼ� Hello World �� �� �����


		//���۷� �ִ� ��쵵 ����
		//�Ѱ��� �Է¹޴°� �ƴ϶� while �� �Ⱦ�
		char buf[5];

		cin.get(buf, 5);	//���۰� �ִ� 5����,		//Hello, World �Է�
		cout << buf << endl;						//Hell		//���ۿ� ���� ��������

		//�ѹ� �� �б�
		cin.get(buf, 5);
		cout << buf << endl;						//o, W
	}


	//cin.gcount()		����ڸ� �о�鿴���� ��ȯ��
	{
		char buf[5];

		cin.get(buf, 5);									//Hello, World �Է�
		cout << cin.gcount() << " " << buf << endl;			//4 Hell		//�ִ� 5���ϱ� 4���� �о���

		cin.get(buf, 5);
		cout << cin.gcount() << " " << buf << endl;			//4 o, W
	}

	//cin.getline()		line ������ ����
	{
		char buf[5];

		cin.getline(buf, 5);								//Hello, World �Է�
		cout << cin.gcount() << " " << buf << endl;			//4 Hell

		cin.getline(buf, 5);
		cout << cin.gcount() << " " << buf << endl;			//0

		//getline() �� �� line �� �ѹ��� �� �о���̰� 5 ��� ������ �־ 4���� �о��
		//�ι�° getline() ���� ������, ù��° getline() �� ������ ��°�� �� �о�� ������
		//���۰� �������� ������ ����

	}


	//cin.getline() �� cin.get() �� ��
	{
		char buf[100];

		cin.getline(buf, 100);
		//cin.get(buf, 100);
		cout << cin.gcount() << " " << buf << endl;

		cin.getline(buf, 100);
		cout << cin.gcount() << " " << buf << endl;


		//�Ȱ��� Hello �� ������ 
		//cin.getline() �϶��� 6 Hello
		//cin.get() �϶��� 5 Hello	1

		//cin.get() �� \n �� ������ ���ڿ��� null character �� �Է��ϰ� ���ۿ� \n �� �״�� ���ܵ�
		//cin.getline() �� \n �� ������ ���ڿ��� null character �� �Է��ϰ� ���ۿ��� \n �� ����
		//cin.getline() �� c style ���ڿ��� ����
	}


	//getline()
	{
		string buf;

		getline(cin, buf);									//Hello, World
		cout << cin.gcount() << " " << buf << endl;			//0 Hello, World

		//getline() �� string �� �޴� string �� ���ǵ� �Լ���
		//getline() �� cin.getline() �� �ƴϱ� ������ cin.gcount() �� 0 ��
	}


	//cin.ignore()
	{
		char buf[1024];

		cin.ignore();		//�Է¹��� �ѱ��ڸ� ������

		cin >> buf;
		cout << buf << endl;


		cin.ignore(2);		//2���ڸ� ������

		cin >> buf;
		cout << buf << endl;
	}

	
	//cin.peek()
	{
		char buf[1024];

		//Hello �Է�

		cout << (char)cin.peek() << endl;		//H		//���ۿ��� �ѱ��ڸ� ����, �� �������� ����, ��¦ ���°�

		cin >> buf;
		cout << buf << endl;					//Hello
	}


	//cin.unget()
	{
		char buf[1024];

		cin >> buf;								//Hello �Է�
		cout << buf << endl;					//Hello

		cin.unget();

		cin >> buf;
		cout << buf << endl;					//o

		//get() �� �ݴ�, ���������� �������� �ٽ� ���ۿ� �־����
	}


	//cin.putback()
	{
		char buf[1024];

		cin >> buf;								//Hello �Է�
		cout << buf << endl;					//Hello

		cin.putback('A');						//����� ���ۿ� 'A' �������

		cin >> buf;
		cout << buf << endl;					//A		//putback() ���� ���� 'A' �ٽ� ���
	}


	return 0;
}