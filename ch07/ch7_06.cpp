//�ζ��� �Լ� Inline Functions

//

#include <iostream>
using namespace std;


//int min(int x, int y)
inline int min(int x, int y) // inline �Լ� ����, �ַ� ��� ���Ͽ� �����Ҷ� ���� �����
{
	return x > y ? y : x; // x�� y �߿� �������� return 
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;

	//�̷� ���� �Լ����� ���� ���ɰ�� �Լ� ���ο��� ���� ��� �ϴ� �ð�����
	//���� �����ϰ� �����ϴ� ������ �ð��� �� �����ɸ����� ����

	//�ζ��� �Լ��� �ٲٸ� ��ġ �Լ��� �ƴѰ�ó�� �۵���
	//cout << min(5, 6) << endl; ��
	cout << ( 5 > 6 ? 6 : 5) << endl; //ó�� �۵��� 

	//�Լ� ȣ��, �������� x,y ����, ���� ������ ��� ������
	//inline Ű���带 ���̸� ������ inline �Լ��� �Ǵ°��� �ƴϰ�
	//�����Ϸ����� ���� �ϴ� ����  
	//�׷��� ��� �Լ��� inline �� �ȵɼ��� �ְ� inline Ű���带 ����ߴٰ� 
	//�ݵ�� �������� ����

	//�ֱٿ��� inline �� ���ٰ� �������� ���嵵 ���� �Ⱦ��ٰ� �Ȼ��������� ����

	//inline Ű���尡 ���� �Լ��� ���� �����Ϸ��� �װ� �� inline���� ���� ������
	//�����ϵ� ���α׷��� ũ�Ⱑ Ŀ��  -> inline�� ����� ȿ���� �������� ����

	return 0;
}