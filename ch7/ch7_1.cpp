//�Ű����� (Parameter)�� ����(Argument)�� ����


//�Ű������� �Լ��� � ����� �ϴ����� �������ִ� ���
//arguments (actual parameters)  ���� , �� �Ű�����, �� ����

#include <iostream>

using namespace std;


int foo(int x, int y);

int foo(int x, int y) //x�� y �� ��ġ ���� ���� ���� 
{
	return x + y;
}// x and y are destroyed here


int main()
{
	int x = 1, y = 2;

	//�Լ��� �۵��Ҷ� �ʿ��Ѱ� x,y �� ������ '��' �� �ʿ���

	foo(6, 7); //6, 7 : arguments (actual parameters)  ���� , �� �Ű�����, �� ����
	// foo �� x y���� '��'�� ���� �Ǳ� ������ 6,7�� �� �� ����
	
	foo(x, y + 1);
	//x �ȿ� ����ִ� 1�̶�� ���� argument�� foo() �� �Ű����� x�� ���޵�
	//3�̶�� ���� argumnet �� foo()�� �Ű����� y�� ���޵�

	//�׻� x�� y �� �ִ� ���� ������ �Ǵ°� �ƴ�
	//���� ���� ����,�ּҿ� ���� ����,������ ���� ���� �� ����

	return 0;
}