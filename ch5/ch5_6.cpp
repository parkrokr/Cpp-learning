// �ݺ��� do-while

//while �� �ٸ��� �ݵ�� �ѹ��� ����
//Ư�� �˰��򿡼� ���� �� ����

#include<iostream>

using namespace std;

int main()
{
	// 1,2,3,4 �߿� �ϳ��� �����ϰ� �� �ܴ� �ٽ� �Է��� �޴� �ڵ�
	
	int selection; // must be declared outside do/while loop, do ���ο� ����Ǹ� while �� ������ �� ����

	do
	{
		cout << "1. add" << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;
		cin >> selection;
	} while (selection <= 0 || selection >= 5); // do/while �� �� while �ڿ� ; ������

	cout << "You selected " << selection << endl;

	return 0;
}