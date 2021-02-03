// ���� ó���� �⺻ Exception Handling

//���� ���α׷��Ӷ�� �������� ��Ȳ�Ӹ� �ƴ϶� ����������(��������) ��Ȳ������ ���������� �۵��� �� �ְ� �ؾ���


//throw �ϴ� type �� ���ؼ� catch �� �ϰ� ���� �´� catch �� ������ casting �ؼ� ������ ���� �ʰ� 
//��Ÿ�ӿ����� �߻�


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


//���α׷��� ���������� �۵��ϴ��� üũ�ϴ� ���
//compile time �Ǵ� debut �Ҷ� �̸� �غ��ϴ� ������� assert ���� ���� ����


//�־��� ���ڿ����� Ư���� ���ڸ� ã�� �Լ�
int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
		if (string[index] == ch)
			return index;
	
	return -1; //no match 
	//index ���� ���� �� ���� ���� return
	//�� �Լ��� ȣ���ϴ��ʿ��� ������ ������ -1 �� �´ٴ°� �˰��־�� ��
}

//x �� y �� ����, y �� 0�� ��� �����⸦ �� �� ����, ���н� bool ���� return
//paramter �� �׳� result �� ������ ����� ����, ��������
double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;  //������ �� 0.0 �� ����ϸ� �ȉ�
	}

	success = true;
	return static_cast<double>(x) / y;
}

int main()
{
	bool success;	//������ flag ������ �ϳ� ����
	double result = divide(5, 3, success);	//ȣ���� �Ҷ� flag ������ �־���

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	
	//! �� ���� üũ�ϱ⵵ ��
	//file ����¿� ���ؼ� �ڿ� ����
	//input_file �� �ʱ�ȭ�� �ϰ� üũ�� ��
	//���ϰ� ���Ǵ� ����
	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << endl;


	//�̷� ��ĵ��� ���⿡ ������� ������ ���������� c++ ���� �̷� ������� �����
	//ù��°�� �����ս� ������
	//�ι�°�� ������ ��ü�� ������ ������

	// ����ó���� ������ �ణ �ٸ�
	// throw-try-catch �� �̷������ ����ó���� ���� ����� ������ ��ü�Ϸ��� ���� �ƴ�
	// ���������� ���� ����� �������� ����ó���� �ϰ� �Ǹ� �������� ���� ����
	// �����ս��� ������ �߿��� ��� ����ó���� ������ ���ɼ��� �ִ°����� ������� ����
	// ������ �м��� �ϴµ� ���� �����Ͱ� ����ִ� �Է������� ���� �������� ���� ������ �ϸ� �ȵ�
	// �׷� ��� ����ó�� �Ϲ����� ���α׷��� ���� �ȿ��� ó���ϴ°� ����
	
	//����ó���� ����ϰ� ���Ǵ� ���� ������ ������ �� ���� ���� ���� �������� ���
	//���� ���� ��� ��Ʈ��ũ ȯ��, ���� �����Ҽ� ���� �ϵ��� ���� �������� ���߾� ��
	//���� �� �� ���� ������ �Ͼ�� �۾��� ������ ������ ���� ����ϴ� ��찡 ����
	
	//�о߿� ���� �Ⱦ��� �оߵ� ����, ��ſ� ��� �ϴ� �оߴ� ���� �� �����ؾߵ�



	//���� ó���� try, catch, throw �� �̷���� ����
	//try �� �õ�, �õ��ϴٰ� ������ �� ������ throw �� �ؼ� ���ܸ� ����
	//catch �� ������ error �� �޾Ƽ� ó��

	//try, catch, throw
	double x;
	cin >> x;

	try
	{
		//������ ���� �� �ִ� �κ��� try �ȿ� �־���
		//sqrt �� ���� ���ڰ� 0���� ������� ���� �� ����

		if (x < 0.0)throw std::string("Negative input"); //���� �߻��� ���ڿ��� �����޽����� ������

		cout << std::sqrt(x) << endl;  //�Էµ� x �� �����̸� �׳� �����ϸ� ��
	}
	catch (std::string error_message) //catch ���� �����޽����� ���è
	{
		//do something respond
		cout << error_message << endl;
	}


	//���ǻ��� :
	//auto casting �� �ȵ� implicit(�Ͻ���) ����ȯ�� �ȵ�, ���� �����ϰ� ó����
	
	//���� throw ���� �׳� ���ڿ�,const char* �� �����µ� catch ���� string ���� �ް� �ִ°��
	//�Լ�ȣ���Ҷ� argument �� ���ڿ� �־������� �˾Ƽ� string ���� �ٲ��־���
	//�����ϸ� runtime error �߻�
	//throw �� ������ �����µ� �ƹ��������� ������ �޾����� ���Ѱ���

	try
	{
		// something happend
		
		
		//throw - 1;

		//throw 1.0; //double �� ������ �޾��� catch �� ����(double �� int �� ���� casting ������) 

		//throw "My error message ";

		throw std::string("My error message ");
	}
	catch (int x)
	{
		cout << "Catch inteager " << x << endl;
	}
	catch (double x)  //double �� �޾��ִ� catch �� ������ runtime error
	{
		cout << "Catch double " << x << endl;
	}
	catch (const char* error_message)
	{
		cout << "Char * " << error_message << endl;
	}
	catch (std::string error_message)
	{
		cout << "std::String" << error_message << endl;
	}

	//throw �ϴ� type �� ���ؼ� catch �� �ϰ� ���� �´� catch �� ������ casting �ؼ� ������ ���� �ʰ� 
	//��Ÿ�ӿ����� �߻�


	return 0;
}