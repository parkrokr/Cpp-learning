//����� ���α׷����� ����  Defnesive Programming

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// syntax error  ���� ����
	//ide �� ���� �����, ide�� ���� ����ְ� �����ϴ°� ������ ����
	
	//int x     // ; �� ������ ����


	// semantic error  ���� ����, �ǹ� ����, �� ����
	//�ڵ带 �ۼ��� ���α׷��� ����� ��� ����� ������ ���α׷��Ӱ� ���ؾߵ�

	int x;
	cin >> x;

	if (x >= 5) 
		cout << "x is greater than 5 " << endl; 
	// �� ���常 �������� 5�϶��� ����� �ȵž������� �ڵ�� ���� ����� �Ǳ� ������ �� ����



	// violated assumption ������ ����
	//����ڰ� ���α׷��Ӱ� �ۼ��� �Ͱ� ���� �ٸ� ������� ���α׷��� �����

	/*string hello = "Hello, my name is Jack Jack";

	int ix;
	cin >> ix;

	cout << hello[ix] << endl;*/
	// 26 �̻��� ix�� �Է��ϸ� runtime error �߻�
	//�̷� ������ �߻��ϴ°� �����ϰ� '�����'���� ���α׷���


	//'�����'���α׷���, ����� �׽�Ʈ �Ҷ� ������ ���� �������� ���, ������ġ���� �־�ߵ�
	string hello = "Hello, my name is Jack Jack";

	cout << "Input from 0 to " << hello.size() - 1 << endl; //����� ���α׷���, 26�̻� �Է����� ����� �������

	while (true)//����ڰ� ���ϴ� ���� �Է��Ҷ����� �ݺ��ؼ� �Է�
	{
		int ix;
		cin >> ix;

		//���� ���� ���� �ԷµǸ� �ٽ� �Է��ϰ� �ϱ�
		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}