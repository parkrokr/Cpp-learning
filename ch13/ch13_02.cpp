//Ŭ���� ���ø� (Templates)

#include "ch13_02_MyArray.h"
#include "ch13_02_MyArray.cpp"

int main()
{
	//MyArray my_array(10);  
	//���ø�ȭ �� �����߻�
	//parameter T �� argument �� �ȵ��� �߻�

	MyArray<char> my_array(10);
	//MyArray<double> my_array(10);
	// . . .


	//�ʱ�ȭ
	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();


	//print() �� body �� class ������ ���� �ٽ� cpp ���Ϸ� �� ���
	//main.cpp ���� �������� �Ҷ� MyArray.cpp���� � type ���� instantiation ���� �𸣱� ������
	//��ŷ ���� �߻�

	//#include "ch13_02_MyArray.cpp" �ϸ� ������ ������
	//�̷��� �ذ��ϸ� ���߿� ������Ʈ ����� Ŀ���� ū ������ ��
	//cpp �� include �ϴ� ���¼ҽ��� ���°� �ƴ϶� ���� �ȵǴ°Ŷ�� �ܾ��� ��������
	//������ ���� �ʱ�! �ſ� �������� ����, ���� ������ ���

	//����� �ذ����� MyArray.cpp ���� print() �� body �� ������ �Ҷ�
	//Ư���� data type ���� ������ �ؾ��Ѵٰ� �˷��ֱ�
	// explicit instantiaion

	//fucntion template �Ҷ� �����Ϸ��� �ڵ����� instantiation �� �����
	//MyArray.h �� body �� �������� �ڵ����� ������
	//cpp �� �������� ���� ����ߵ�

	return 0;
}