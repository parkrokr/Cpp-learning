//���� ���� Composition

//#include <iostream>  Monster.h ���� iostream �� include �ϰ� �ֱ� ������ ��� �� �� ����
#include "ch10_02_Monster.h"

using namespace std;



int main()
{
	//Monster mon1("Sansan", 0, 0);
	Monster mon1("Sansan",Position2D(0,0));

	cout << mon1 << endl;
	//Monster.h �� Position2D.h �� output �����ڿ� �ִ� endl�� �ߺ��Ǵ� �����ְ� ���� main ������ endl ��

	//while (1)  //game loop
	{
		//event
		//mon1.moveTo(1, 1);
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}


	//mon1 �� m_location �� mon1 �� ���������� �ٸ� �͵�( m_name ) �� ���ؼ� ������ ���ϰ�
	//�� �ʿ䵵 ����

	//Monster �� m_location �� ���� Positin2D �� ����ϴ°� composition �̶�� ��
	//m_laction �� Monster �� �Ϻδ�

	//sub class �� ������ ���� ����°� ����( m_x, m_y �� ���� ���� Position2D class ����)

	//moveTo�� �Ҷ� Monster �� set() �� ���ָ� �Ǳ� ������ �ȿ� ��� �۵��ϴ��� ��
	//����� �������ְ�, ���� class(����� ������ ���� class) �� �� ������ �˰�
	//��� �ϴ����� �Ⱥ��̴°� ����

	//Position2D ������ class �� ���� class �� �� ��� ����, �̷��� �� �����ϴ°� ���� �ܰ迡��
	//�ǹ����� �̷��� ���� �ڵ���� ���� ����

	//Position2D class ��ü�� �ٸ��������� ������ �� �� ������ Monster::m_location ��
	//�ٸ� ������ ������(�ʿ䰡) ����

	//mon1 �� ������� mon1.m_lacation �� ���� �����, class �� ����� ���縦 ���� �����ؾ���

	//Monster class �� �۾��� �Ҷ��� Positin2D class �� ���� ���� �ִ��� �˰� ���������
	//Position2D class �� �۾��� �Ҷ��� Monster class �� ���� �ִ��� ��
	//�˾ƾ� �ȴٸ� ���� �߸��Ȱ�(���谡 �߸���)
	return 0;
}