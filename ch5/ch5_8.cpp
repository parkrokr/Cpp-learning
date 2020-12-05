// break, continue

//break �� swith ������ �ʼ�

#include<iostream>

using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
			break;

		if (ch == 'r')
			return;
	}

	cout << "Hello" << endl;
}

int main()
{
	//break


	//while ������ break
	int count = 0;
	while (true)
	{
		cout << count << endl;
		if (count == 10)break;
		count++;
	}

	//�Լ����� break
	breakOrReturn(); // b �Է½� Hello ���, r �Է½� �Լ��� �׳� return �ؼ� ��������

	//for ������ break
	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
		if (i == 5)break;
	}

	//break�� ���� ���� �� ����
	//���α׷� ������ Ư�� Ű�� ������ ���� �� �ְԵ� © �� ����


	//break�� ���°� ���� �ɾ��ִ°ͺ��� ���Ҽ��� ����
	
	//Ư�� Ű�� �Է¹޾����� ������ �ڵ�
	count = 0;
	bool escape_flag = false; //flag�� �ϳ� ������ �����

	while (!escape_flag)
	{
		char ch; //���߿� ������ class �� ���鶧�� ������ ���ִ°� ������ �ɼ� ����
		cin >> ch;

		cout << ch << " " << count++ << endl;

		if (ch == 'x')
			escape_flag = true;
	}

	//escape_flag �� �Ⱦ��� ���
	/*while (true)
	{
		char ch;
		cin >> ch;
		cout << ch << " " << count++ << endl;
		if (ch == 'x')break;
	}*/



	//continue

	//Ȧ���� ���
	//if�� { }�� ����� ���, continue �� ���� ����� ����

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 1)cout << i << endl; 
	}

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)continue; //continue �� ������ �Ǹ� �Ʒ��κ��� �����Ű���ʰ� �ٽ� ���� �ö�

		cout << i << endl;
	}

	
	//continue�� do/while �� ���ɶ��� ���� �ָ����� �� ����
	count = 0;
	
	do
	{
		if (count == 5)
			continue;

		cout << count << endl;

		//count++  // while( ) ���� �ƴ� do �� ���������ڰ� ������ continue ������ ������ �ȵ� -> ���ѷ���
	} 
	//while (count <10)
	while (++count < 10);   //while �ȿ� ���������ڸ� ���� �� ����


	return 0;
}