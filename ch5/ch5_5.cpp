//�ݺ��� while

//���ѷ���

#include<iostream>

using namespace std;

int main()
{
	// 0~1 ���� ����ϴ� �ڵ�
	/*cout << 1 << endl;
	cout << 2 << endl;
	// . . .
	cout << 9 << endl;*/

	
	cout << "While-loop test" << endl;

	//counter ����
	int count = 0;
	while (1)  //( ) ���� true �� �۵�, false �� �۵����� ����. 1�̳� true �� �־ infinite-loop
	{
		cout << count << endl;

		++count; //count++;
		// count�� while �� �ȿ��� �����ϸ� ���ѷ���, �ۿ��� ���� ����
		//���� ���ο��� �����ϰڴٸ� static ������ ����, ��ſ� ������ ���� ����

		if (count == 10) break;
	}


	//goto ���� ����� while �� ����
	skip:
	cout << count << endl;
	count++;
	if (count < 10)
		goto skip;

	
	// unsigned int �� ī���ͷ� ����ϰ� �Ǹ� overflow �߻��� ��������
	// �����ϴ� ��� ������, ������Ű�� ��� ���輺�� ����
	// ������ ������� unsigned �� ���� �� ���� ���� ����
	
	/*unsigned int counter = 10;

	while (counter >= 0)
	{
		if (count == 0)cout << "zero";
		else cout << count << " ";

		count--;
	}*/


	// ~���� �ѹ��� ����ϰ� �ϰ� ���� �ڵ�
	count = 1;

	while (count < 100)
	{
		if (count % 5 == 0)cout << "Hello" << count << endl; //5���� �ѹ��� Hello ���, % ���

		count++;
	}

	
	//while �� �ȿ� while ��

	int outer_count = 1;

	while (outer_count <= 5)
	{
		int inner_count = 1;
		while (inner_count <= outer_count)
		{
			cout << inner_count++ << " ";
		}

		cout << endl;
		++outer_count;
	}

	//�������� �����ϸ� ����

	return 0;
}