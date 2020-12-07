// �迭 Array �� �������� ���� [2 0f 2]

#include<iostream>

using namespace std;

void doSomething(int students_scores[])  //int students_scores[20]�� ������ �迭�� �ƴ� ��������, �׷��� []���� �� ��
{
	cout << "doSomething" << endl;
	cout << (int)&students_scores << endl; //�迭�� �ּҰ��� �����ϴ� ������ ������ �ּҰ� ���
	cout << (int)&students_scores[0] << endl; //�迭�� �ּҰ��� ������(������ ������ ����Ǿ� �ִ�) �� ���
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << "size in doSomething " << sizeof(students_scores) << endl; //4, pointer size

	//x64���� sizeof(students_scores)�� 4�� �ƴ� 8 -> x86���� �����ͺ��� ũ�Ⱑ 4bytes, x64���� 8bytes
	//x64 ���� �ּҰ� overflow ��, int ��� long long �Ǵ� size_t�� ��ȯ�ϸ� ��
}



int main()
{
	const int num_students = 20;
	
	int students_scores[num_students] = { 1,2,3,4,5 }; //fixed-size array , num_students �� const �� ������
	//[ ]�ȿ� ���� type �� int���� �� �ʿ�� ����, ������ �̱⸸ �ϸ� �� short,char type �� ��� ����

	cout << (int)&students_scores << endl; //students_scores[0]�� �ּҶ� ���� �ּҸ� ���
	cout << (int)&students_scores[0] << endl;
	cout << (int)&students_scores[1] << endl; //students_scores[0]�� 4 (4 bytes, int) ����
	cout << (int)&students_scores[3] << endl;

	cout << "size in main " << sizeof(students_scores) << endl; //80


	//array �� �Լ� parameter �� �ֱ�
	doSomething(students_scores);
	
	// �б� ���� 10������ ����ϱ� ���� �ּҸ� int�� ����ȯ, x64������ (long long) ����,
	// x86, x64 ��� �� �۵��ϴ� ��Ƽ�÷��� �ڵ忡�� (size_t) ����

	//doSomething(students_scores) �� (int)&students_scores ���� main �� (int)&students_scores ���� �ٸ�



	//�迭�� �̸�(�ĺ���, identifier, �ν���)�� ���������� �ּҷ� ���
	cout << (int)students_scores << endl;
	cout << (int)&students_scores << endl;
	//�׷��� ������ �ּ� ������ & �� ���� �ʾƵ� �ּҸ� ���� �� ����
	//�迭�� �ּҷ� �����͸� �ְ�޴°��� ���ҵ��� ���� �����ϴ°��� �ξ� ȿ�����̶� ������ �̷��� ���ǰ� ��

    
	//�Լ��� �Ű������� �޴� �迭�� ������ �迭�� �ƴ� ��������. �ٸ� �迭�� ������ ����� ���̴� ��°���
	//���ݴ� ��ü���� �����ֱ� ���� �̷��� ����� �� �ִ� �� ����

	
	//�迭�� ���� -> �̸� ��ü�� �ּ�, &������� �ʾƵ� �ּҸ� ������ �� ����
	//�Լ��� parameter �� �迭�� �ּҰ��� ����, �迭�� ���� ���Ҹ� �����ؼ� �������� ���� �ƴ�
	//�Լ� ������ students_scores �� �迭�� �ƴϰ� ������ ����(�ּҰ� ����)�̱� ������ 
	//�ٸ� �ּҰ�(������ ������ �ּ�)�� ����

	return 0;
}
