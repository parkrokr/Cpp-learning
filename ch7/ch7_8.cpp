//�Ű������� �⺻��  Default Parameters

//�Ű������� �������� ������ �Ź� ��� �Ű������� ���� �־��ִ°� ���ŷο� �� ����
//default ���� ������ ���ϴ� ��� ���ڸ� �����ϴ� ���� �����ϴ� ����

// ���ʿ� �⺻�Ű������� ������ �� �����ʿ� �ݵ�� �⺻�Ű������� �־����
// ����� �����߸� �и��� ��� �Ѱ������� �⺻�Ű����������� �ؾ���
// dafault ���� �Լ� �����ε��Ҷ��� ������ ��

#include <iostream>
#include <string>

using namespace std;

//x�� ���� ���� ������ 0�� ����
void print(int x = 0)  //Default Parameters, Optional parameter, Default arguments 
{
	cout << x << endl;
}


//�������� ������ �� ����
//�׷��� ���ʿ� �⺻�Ű������� ������ �� �����ʿ� �ݵ�� �⺻�Ű������� �־����

//void print_new(int x, int y = 10, int z)  //�Ұ���
//void print_new(int x, int y, int z = 3)  //����
void print_new(int x = 10, int y = 20 , int z = 3)
{
	cout << x << " " << y << " " << z << endl;
}


//����� ���Ǹ� �и��Ѱ��(����� ������ �ִ� ��� ����)
//����� ������ �Ѱ������� �⺻�Ű����������� �ؾ���(���� ���𿡼� ������(�ַ� ������Ͽ� ���ִ�))
//���� ���� ���ǵǾ����� �߻��ϴ� ��ȣ�� ������ ��õ���� �ϰ��� �����Ϸ��� ����

//void print_new(int x = 10, int y = 20, int z = 3)		//declaration���� ���ǰ� �Ǿ��ִٸ�

//void print_new(int x, int y, int z)					//definition ���� ����� ��
//{
//	cout << x << " " << y << " " << z << endl;
//}



//�Լ� �����ε��� ������ ���
void print_other(std::string str) {}
void print_other(char ch = ' ') {} // default parameter �� ����

//������ ���
void function(int x){}  //ambiguos
void function(int x, int y = 20) {}

int main()
{
	print(10);	// 10
	print();	// 0, default parameter�� �������� ������ ������ ���� �߻�

	//�⺻�Ű������� �������� ���
	print_new();
	print_new(100);				//x �� ���
	print_new(100, 200);		//x, y �� ���
	print_new(100, 200, 300);	//x, y, z ���


	//�Լ� �����ε��� ������ ���
	print_other(); //ch �� �⺻�Ű������� �����Ǿ��� ������ char Ÿ���� �Ű������� ���� �����ε��� �Լ��� ����

	//������ ���
	//function(10); //ambiguous call to overloaded function

	//y�� �⺻�Ű����� ������ �����ϸ� ������
	//y�� �⺻�Ű������� �����ϰ� ������ �տ��ִ� �⺻�Ű������� ���� ������ ������ �ִ�
	//�ٸ� �Լ��� �����ε��� �� ����

	return 0;
}