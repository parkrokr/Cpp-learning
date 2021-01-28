//���� (Pure) ���� �Լ�, �߻� (Abstract) �⺻ Ŭ����, �������̽� (Interface) Ŭ����

//body �� ���� �����Լ��� ���� ���� �Լ� ��� ��, �ڽ�Ŭ�������� �ݵ�� �������̵带 �������
//���� ���� �Լ��� ���Ե� Ŭ������ �߻� Ŭ���� ��� ��
//���� ���� �Լ��θ� �̷���� Ŭ������ �������̽� Ŭ���� ��� ��

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;
public:
	Animal(std::string name)
		:m_name(name)
	{}

public:
	string getName() { return m_name; }

	//pure virtual function
	virtual void speak() const = 0; //body �� ���� �ڿ� = 0 �� ���� �Լ��� ���� ���� �Լ� ��� ��
	
    /*virtual void speak() const
	{
		cout << m_name << " ??? " << endl; 
	}*/
};

//���� ���� �Լ��� ������ body �� ���� �� �� ����
//���� ����,�����غ��� ȣ�� �� �� ����
//void Animal::speak() const
//{
//	cout << m_name << " ??? " << endl;
//}

class Cow :public Animal
{
public:
	Cow(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Mooo " << endl;
	}
};


//�������̽� Ŭ���� : ��� ��� �Լ����� ��� ���� ���� �Լ���
//�ڱⰡ �� ������ ���Ǹ� ���ϰ� ����~�� �ؾ��Ѵٴ� ����
//����� �Ҷ� �̷�~ ��ɵ��� �������̶�� �����Ҽ� �ִ� �߰��(�������̽�) ����

class IErrorLog		//�������̽��� �����Ҷ��� �տ� I �� ���̴°� ����
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

//�ؿ� �� Ŭ�������� reportError() �� �ݵ�� ������ ��
class FileErrorLog :public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog :public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

//�������̽� Ŭ������ parameter �� �ް� �ִ� �Լ�
//IErrorLog �� reportError() �� �ִٴ� �͸� �˰� ����
void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!");
}

int main()
{
	//Animal ani("Hi");  //�߻� �Լ��� �� ��ü��, �ν��Ͻ��� ���� �� ����, Animal::speak() �� ���������Լ���
	//ani.speak();		//������� ������ �Լ��� ȣ���� ���� ����

	//���������Լ��� �θ�Ŭ������ �����Ҷ��� �θ�Ŭ���������� �𸣰����� �ڽ�Ŭ�������� '�ݵ��' �����϶� �� �ǹ�
	
	//�������� ����� ����Ҷ� �Ϲ����ΰ� �θ�Ŭ������ �ΰ� �ڽ�Ŭ�������� ��Ȱ���ϰų� �� Ưȭ �Ȱ��� 
	//������� �������̵��� ������ ���������Լ��� ������ �ٲ���ٰ� �� �� ����


	//Cow �� speak() �� ���� ���
	//Cow cow("hello"); //����, ���������Լ� Animal::speak() �� �������̴��� ����
	//�� �ڽ�Ŭ�������� speak()�� �������̵� ���ϸ� ���� �� ����(�����ϰ� ����)



	//�������̽� Ŭ����
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	//�������̽� Ŭ������ parameter �� �޴� �Լ�

	doSomething(file_log);			//"Writing error to a file"
	doSomething(console_log);		//"Printing error to a console"
	//�ǵ��� ��� �־��� ��� ����� �ϰ� ����


	return 0;
}