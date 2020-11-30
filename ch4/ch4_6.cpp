// ���ڿ� �Ұ� std::string

#include<iostream>
#include<string> //std::string �� ����ϱ� ���� �ʿ���
#include <limits> // 32767 ���� magic number�� ���� �ʱ� ���� �ʿ�

using namespace std;

int main()
{
	cout << "Hello, World" << endl;
	//const char [13] �̶�� ��, Hello, World�� 12��������
	//�ڿ� ���ڿ��� �����ٴ� �� �˷��ִ� �ѱ��ڰ� ������


	// ���α׷��Ӱ� ���ϱ� ���� ����ϴ� ���, ����� ���� �ڷ��� , �����Ϸ��� ���� ������ include �������
	const string my_hello = "Hello, World!"; 
	//const string my_hello("Hello, World"); coppy initialization
	//const string my_hello{ "Hello, World" }; definition initilaization

	cout << my_hello << endl;

	// �⺻������ ����ϴ� ���,�⺻ �ڷ���
	const char my_strs[] = "Hello, World"; 
	
	
	string my_ID = "123"; 
	// 123 ó�� ������ ������, ������ ���ڿ��� �Ͻ��� ����ȯ �ϴ� ����� ����
	// 123���� ������ built in data ���� string �� std �̱� ������ built in �� �ƴϱ� ������
	// ���� �����ܰ��� ��ɵ��� ������ �ֱ� ������ �ٷ� �ٲܼ� ����


	//�̸������̸� �Է¹޴� �ڵ�
	cout << "Your age ? : ";
	//int age;
	//cin >> age;
	//std::cin.ignore(32767, '\n');
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 32767���� magic number�� �Ⱦ��� ����

	string age;
	getline(cin, age);


	cout << "Your name ? : ";
	string name;
	//cin >> name;
	std::getline(std::cin, name);

	
	cout << name << " " << age << endl;
	
	//cin �� ������ a b ó�� �߰��� ��ĭ�� ������ �տ� a ���� ó���� �ް� �ڿ� b�� enter�� �ؿ��� ����
	//getline �� enter�� ���������� �Է��� ����(line ������)

	//int �� ���� age�� �ް� cin���� ������ enter�� �������� ���ۿ� �ִ� ������ �ؿ��� �ٽ� �޴� ������ �߻�
	//���ۿ� �ִ� ������ �ѹ� ������ ��
	//std::cin.ignore(32767, '\n'); -> \n�� ���������� 32767���� ���ڸ� �����ض�(2byte value max)

	//std::numeric_limits<std::streamsize>::max() 
	//��ſ� 32767�� �׳� ���ų� cin �ϴ� �κ��� ���̺귯���� ����� ����� ����


	
	//append ���ڿ� ���ϱ� 
	string a("Hello, ");
	string b("World");
	string hw = a + b; //append, +�����ڰ� string �ȿ� �����Ǿ��ֱ� ����

	hw += " I'm good";

	cout << hw << endl;

	//���� ����
	string h("Hello, World");

	cout << h.length() << endl; // . �� ���� string �ȿ� �ִ� legth() �Լ��� �ҷ���

	//���ڿ� �������� ���ڿ��� ���� �˸��� null character�� ��������
	// c style ���ڿ��� c++�� ����ϴ� string �� ���̰� ����

	return 0;
}
