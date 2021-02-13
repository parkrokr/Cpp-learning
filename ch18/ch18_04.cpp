// �帧 ���� (stream states ) �� �Է� ��ȿ�� ( input validation ) ����

//�Է��� ��ȿ���� ����, �����ϴ� ����� �ְ� �Ϲ������� ���Խ��� ����ϴ� ����� ����

#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printCharacterCalssification(const int& i)
{
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl;
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;

	//cctype �� �������
	//return type �� int ��
	//0 �� �ƴϸ� true, 0�̸� false �� �����϶�� reference manul �� ���ǰ� �Ǿ�����
	//����� �Ҷ� bool �� casting �ؼ� ����� �ϰ� ����
}


//ios stream �� � �������� Ȯ���ϴ� �Լ���
	//ios �� ������ ���� �θ� Ŭ����, �� ��Ʈ���� �ܼ�,���� ��Ʈ���� �������� ����� �� ����
	//cout �� c �� printf ���� ��ٰ� ���� �� ������ �ܼ�, ���� ����¿��� �ϰ��ǰ� ����� �� ����
	//c ������ ������¿��� fprintf �� ����ؾ� �ϳ� c++ ������ cout �ڵ带 ������ ���� ��¿��� ��밡��
void printStates(const std::ios& stream)		
{
	cout << boolalpha;
	cout << "good()="<<stream.good() << endl;		//���°� ������,good() �� return type �� bool 
	cout << "eof()=" << stream.eof() << endl;		//end of file �ΰ�,������ �� �о��°��� üũ
	cout << "fail()=" << stream.fail() << endl;		//�����ϸ� true, ���� �����̸� false	
	cout << "bad()=" << stream.bad() << endl;		//�����͸� �аų� ���ٰ� �������� falg ����

	//reference manul ����

	//return type �� bool �̶� ����ϰ� �� �� ����

	//std::ios::rdstate  �������¸� ��Ʈ�÷��׷� ��ȯ��
	//goodbit, eofbit, failbit, badbit
}

bool isAllDigit(const string& str)
{
	//�Է¹޴� string �� isdigit() �� �̿��ؼ� ���ϴ� �������� �ѱ��ھ� ��

	bool ok_flag = true;

	for(auto e : str)
		if (!std::isdigit(e))
		{
			ok_flag = false;		//�ѱ��ڶ� digit �� �ƴϸ� flase 
			break;
		}

	return ok_flag;
}

void classifyCharacters(const string& str)
{
	for (auto e : str) //�ѱ��ھ� �� ��
	{
		cout << e << endl;
		std::cout << "isdigit " << std::isdigit(e) << endl;		//�������� ��
		std::cout << "isblank " << std::isblank(e) << endl;		//�������� ��
		std::cout << "isalpha " << std::isalpha(e) << endl;		//���ĺ����� ��
	}
}


int main()
{
	while (true)
	{
		//int i;
		char i;

		cin >> i;					//���ڰ� ���;� �ϴµ� ���ڰ� ������ ������ ����
									//�̶� stream �� � �������� Ȯ���ϴ� �Լ����� ����

		printStates(cin);			//�Ʒ��� ��Ʈ�÷��׸� �̿��ϴ� ������� �� ���� ���̴� ����

		//������ �� ��������
			//good() = true
			//eof() = false
			//fail() = false
			//bad() = false
		 //int �� �ƴ϶� double �� ���°�� ������ �Ǳ� ������ good �̶�� ��

		//������ ������ �ʾ�����(���ڰ� ��������)
			//good() = false
			//eof() = false
			//fail() = true
			//bad() = false

		//double �� int �� �ִ°� ������� ���� ������ ���ڰ� ���ð��� ���ڰ� ������ ������� ����




		//std::ios::rdstate  �������¸� ��Ʈ�÷��׷� ��ȯ��
		//goodbit, eofbit, failbit, badbit
		
		//state �� flag �� �޾ƿͼ� mask �� �̿��ؼ� üũ
		//�̷� ��ĵ� ������ ����ó�� �Լ��� ����� �� ���, ��� c++ �� ���� ����
		cout << boolalpha;
		cout << bitset<8>(cin.rdstate()) << endl;	//good �Լ� ��ſ� rdstate ȣ��,������ ���¸� ��Ÿ���� int �� return
		cout << bitset<8>(istream::goodbit) << endl;	//goodbit �� mask ��, goodbit ���
		cout << bitset<8>(istream::failbit) << endl;	//fialbit �� mask ��, failbit ���
		cout << !bool((cin.rdstate() & istream::failbit) != 0) << endl;	
		
		// rdstate() �� �о�� flag �κ��� failbit mask �� �̿��ؼ� ���� ���¸� ����
		// & �� �ؼ� 0 �� �ƴ϶�� fail, good �� ȣ���Ϸ��� �տ� !�� ����
		//goodbit �� cin �� ���������� ������ �������� 00000000 �̶� ���������� ���� failbit �� �̿���
		//���������� �����ϰ� ����

		//�̷� �ڵ�� c ���� ���� ����,�����ս� ������ ���� ���� ������ ����
		//�����ս������� ���ٰ� ������ ���� ������������ �˼��� ����
		//�̷� �ڵ尡 ������ ������ ������ ������ �ؾ��ϱ� ������ ���ݴ� �ð��� �ɸ��� ������ ����
		

		//cin.rdstate() == std::istream::goodbit;		//�̷��� �����ϴ� ����� ����
		//��� �ǰ� �ȵǴ����� �־��� ȯ�濡�� �׽�Ʈ �غ��� �ɼ��� ����
		


		//state �ܿ� ���� �Է°��� ���� ���ϴ� ���������� �����ϴ� �Լ�
		//i�� char �� �����ؼ� �ް� ����
		printCharacterCalssification(i);
		/*
		a
		isalnum true
		isblank false
		isdigit false
		islower true		//�ҹ��ڴϱ� true
		isupper false

		A
		isalnum true
		isblank false
		isdigit false
		islower false
		isupper true

		1024
		isalnum true
		isblank false
		isdigit true		//���ڴϱ� true
		islower false
		isupper false


		//cin ���� ������ �Է��� �������� ��� ������ ��ĭ�� ���о����� isblank �� �� �������� ������
		*/


		cin.clear();
		cin.ignore(1024, '\n');			//�տ��� �Է¹��� ���۸� ���� ����, \n ���� 1024 ���� ������
		cout << endl;
	}


	//���ϴ� ���·� ���Դ��� Ȯ���ϴ� �Լ�
	//���� ������ �ѱ��ھ� �� ���ϴ� ���
	//���� ������ ���� ǥ����( regular expression ) �� ���� ������

	//�Է��� string ���� �޾Ҵ��� ����
	
	cout << boolalpha;
	cout << isAllDigit("1234") << endl;		//���� ����			treu
	cout << isAllDigit("a1234") << endl;	//���ڰ� �ϳ� ������	false


	classifyCharacters("1234");
	classifyCharacters("a 1234");

	//�ڵ��� ��ȭ��ȣ ���� ������ �ִ� �Է��� ��� 
	//if �� ���� isAllDigit() ���� �����ϴ� ����� �ְ�
	//���Խ� ���� ����� ����

	//�߼��� ���Խ��� ����ϴ� ���, �����α׷��ֿ��� ���Խ��� ���� �����

	return 0;
}