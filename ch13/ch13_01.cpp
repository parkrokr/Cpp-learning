//�Լ� ���ø� (Templates)

//���ø��� �������� �ڷ����� ���ؼ� ����� �ڵ��� �ۼ��� ��������

#include <iostream>
#include "ch13_01_Cents.h"

using namespace std;

//���� �ΰ��� �޾� ū�� ��ȯ�ϴ� �Լ�
/*int getMax(int x, int y)
{
	return (x > y) ? x : y;
}*/

//double ���� ����� ����
/*double getMax(double x, double y)
{
	return (x > y) ? x : y;
}*/

//float ���� �����
/*float getMax(float x, float y)
{
	return (x > y) ? x : y;
}*/

//char Ÿ���� ��ȯ�ϴ� �͵� �����
//int �� �޴´�ſ� int & �� �޴°͵� ����� �ϴٺ���
//��ġ�� �۾��� �ݺ��ǰ� ����(������ �ݺ��ǰ� ����)
//�ڵ����� �����ϰ� �;���



//template

//typename ���� ���� T�� ���̾�, �ڷ����� �� ���� T�� ������ ��
//typename ��ſ� class �� �־ ������ �̾ӽ��� �� ���̳��� ������ ū ���̴� ����
//template<class T> 
template<typename T> 
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

//double...float...char... �̷��� �������ص� ��


int main()
{
	cout << getMax(1, 2) << endl;			//int
	cout << getMax(3.14, 1.592) << endl;	//double
	cout << getMax(1.0f, 3.4f) << endl;		//float
	cout << getMax('a', 'c') << endl;		//char

	//T �ڸ��� ���� ���� �����Ϸ��� ã�Ƴ��� ���� �������Ҷ�
	//�Լ� �����ε�ó�� �ٲ㼭 ����� �� �ְ� ����


	//user defined type �� ����� �� ����
	cout << getMax(Cents(5), Cents(9)) << endl;
	//���ø� ���õǱ� �����ϸ� �����޽����� ������
	//��� ������ �����ε� �������
	//�� ������ �����ε� �������

	//���ø� ������ ������ ���ø����� �������ֱ� ���ؼ� �ʿ��� ��ɵ��� �� �����Ǿ� �־�� ��



	//�Ϲ����� T ���� Ư���� ���ǿ� ���ؼ� ������ ����� ���� instantiation �̶�� ��
	//T�� int �϶� int �� ���� instance(����) �� �Ǵ°���

	return 0;
}