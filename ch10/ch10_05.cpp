//���� ���� Dependencies

#include "ch10_05_Worker.h"

using namespace std;


int main()
{
	Worker().doSomething();

	//Timer �� ���ؼ� Worker class �� ���� ��
	//Worker �� doSomething() body �� cpp �� �ű�� Worker.h ���� Timer.h �� include ���� �ʾƵ� ��
	//Worker.cpp ������ Timer class �� �˰� ������ ��

	//���� ����� class ���������� ���θ� ���� ��, �����ϴ� body ������ �˸� ��
	//main() ������ worker class �� �˰� ������ ��

	//���� �Լ� ȥ�� ������ ���� ���踦 �̿��ؼ� ������ ������ ���� �����غ� �� ����
	//���� ���� �� ����

	//class �� ������� ���� ������ٴ� �������� ����� ���縦 Ŭ������ �����Ѵٰ� �� ��������
	//����� ������ �ʴ� ��쵵 ����
	//���⼺�� �ܹ���, Woker class �� �ڱⰡ �ð��� �����ϴ� ����� �� �ʿ䰡 ����


}