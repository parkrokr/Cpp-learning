//std::cin �� �߾���   ignore(), clear(), fail()

//fail()  : ������ �Ͼ�� 1�� ��ȯ��
//clear() : ���� �÷��� �ʱ�ȭ(���� ���� ���),cin�� �����۵� �ϰ���, ������ �ؿ� �������� ��� 1 ��ȯ


#include<iostream>

using namespace std;

int getInt()
{
	while (true)
	{
		cout << "Enter an integer number : ";
		int x;
		cin >> x;

		//�Է°��� �ʹ� ū ��� ���ۿ� ���ڰ� ��� ���� ������ ����
		//std::cin.fail()  �������� ��� true �� return ��
		if (std::cin.fail())
		{
			std::cin.clear(); //����������
			std::cin.ignore(32767, '\n'); //�����ִ� ���� ����
			cout << "Invalid number, please try again" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); //���� ����ֱ�
			return x;
		}
	}
}

//�߸��� ���ڸ� �Է��Ѱ�� �������� result ���� invalid�� �ߴ°ͺ��� �Է¹޴� ��� �߰� �ϱ�
//�߸��� ���ڸ� �Է��Ѱ�� �ٽ� �޴´� ���ٴ�
//������ ���ڸ� �Է¹޴ٰ� �´� ���ڰ� �ԷµǸ� ���´ٴ� ����� �����
char getOperator() 
{
	while (true)
	{
		cout << "Enter an operator (+,-,*,/) : ";  //TODO: more operatros *, / etc.
		char op;
		cin >> op;
		std::cin.ignore(32767, '\n');

		if (op == '+' || op == '-' || op == '*' || op == '/')
			return op; //return���� �����ִ� �Լ��� �ٷ� �����Ŵ
		else
			cout << "Invalid operator, please try agian" << endl;
	}
}

void printResult(int x, char op, int y)
{
	// case-switch ���� �ٲ㺸��

	/*if (op == '+')cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else
	{
		cout << "Invalid operator" << endl;
	}*/

	switch (op - '*')
	{
	case 0:
		cout << x * y << endl;
		break;
	case 1:
		cout << x + y << endl;
		break;
	case 3:
		cout << x - y << endl;
		break;
	case 5:
		cout << x / y << endl;
		break;

	default :
		cout << "Invalid operator" << endl;
		break;
	}
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printResult(x, op, y);


	//ó���� �Է��Ҷ� 1 2 ���� ������ �Է��ϸ� ó���� 1�� �Լ��� ���� 2�� ���ۿ� �����ִٰ�
	//���� �Լ��� ���� ���� �߻�

	//���۸� ����ֱ� ���� std::cin.ignore() ���

	return 0;
}