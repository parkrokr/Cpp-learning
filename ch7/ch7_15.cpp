//����� �μ� Command Line Arguments

//command line ���� ����  Native Tools Command Prompt for Vs 
//�Ǵ� ������Ʈ�� Property Pages ���� Debugging, Command Arguments �Է��ϴ� ����� ����

#include <iostream>
#include <string>

using namespace std;

//argc �� main() �� ���޵Ǵ� �������� ����
//*argv[] �� main() �� ���޵Ǵ� ���� �����ͷ� ���ڿ��� array, char�� ������ �迭�� ����
//ù��° ���ڿ��� argv[0] ���� ���α׷��� ���� ��ΰ� �������


//����ڰ� �Է��� �߸����� ��� ����ó���� �Ź� �ڼ��ϰ� ����ߵ�
//������ ����ġ ���ϰ� �ȸ°� ���ü��� ����

//���� �����ϱ��� Boost ���̺귯���� ����ϴ� ����� ���� ( �� ǥ�� ���̺귯��)
//Boost.Program_options �� ����ϸ� �� ���ϰ� ����� �� ����
//�ް��� �������� Boost ���̺귯���� ����


int main(int argc, char *argv[])
{
	//���ڿ� array �� ���� ���� string ���� �ް�, �ʿ信 ���� �ٸ� �ڷ������� ��ȯ

	for (int count = 0; count < argc; ++count)
	{
		string argv_single = argv[count]; //string ���� �ٲ�

		if (count == 1)
		{
			int input_number = std::stoi(argv_single); // std::stoi() ������ �ٲ���, ���ϴ� type ���� �ٲ���
			cout << input_number + 1 << endl; // ���ϴ� ó���� �� �� ����, command arguments �� 1024 �϶� 1025 ���
		}

		cout << argv_single << endl; 
	}


	return 0;
}