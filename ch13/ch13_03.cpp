//�ڷ����� �ƴ� ���ø� �Ű����� Non-type Parameters


//Non-type paramter �� compile time �� �����Ǿ� �־�� ��

//Non-type parameter �� ����Ҷ� �Լ��� cpp �� ����� 
//���ü� �ִ� ���ڿ� ���ؼ� ���� explicit instantiation �� ����� �ϱ� ������
//Non-type parameter �� ���� ��� boyd �� ���� ������� ��

//�̷� ����� �� ���Ǵ� ���� �޸� ���� �������� 
//�˰����� �����Ҷ� 2�����϶��� �, 3�����϶��� � �̷������� ����

#include "ch13_03_MyArray.h"

using namespace std;

int main()
{
	//std::array�� ����������� std::array<double,100> ó�� �ڷ����� data�� � ��������
	//template �� paramter �� �־���

	//std::vector<double> my_array; my_array.resize(100);
	//���� ��� vector �� compile time �� 100 �� �������� �־ ��
	//�׷��� double �̶�� data type �� instantiation �Ҳ���°� compile time�� �˷��� �־���� ��

	//MyArray �� 100, �ڷ����� �ƴ�(Non-type)�� parameter �� �ֱ�
	//100 �� ���� compoile time �� �����ǰ� ����(�Ǿ��־�� ��)
	//100�̶� ���ڰ� ������ ������ �Ǹ� �������� �ȵ�
	
	int i = 100;
	//MyArray<double, i> my_array;  //���� �ȵ�
	//template �⺻ ������ ����� �ڵ��� �����൵ ��쿡 ���缭 �������� ���ε��� ���ִ°�
	//�׷��� ������ �ϱ� ���� ������ ���־�� ��. const int i = 100 �ؼ� i �� ������ ������ �׳� 100 �ְ�


	MyArray<double, 100> my_array;

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();


	//�̷� ����� �� ���Ǵ� ���� �޸� ���� �������� 
	//�˰����� �����Ҷ� 2�����϶��� �, 3�����϶��� � �̷������� ����

	return 0;
}
