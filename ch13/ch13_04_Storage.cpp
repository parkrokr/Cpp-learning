#include "ch13_04_Storage.h"

template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}

//main.cpp �� �� Storage.cpp �� ���ؼ� �𸣰� �ֱ� ������
//Ư��ȭ�� ���ؼ� �𸣰� ����

//�ذ��ϴ� ���:
//�׳� ����� �α�		(��� �¸�: ����� �� ���Ƶּ� ������Ͽ� �� �����Ǿ� ����)

//main.cpp ���� cpp ������ include 
//�ᱹ�� ����� �аŶ� ���� ��

//����� �ϳ��� ���°� �ƴ϶� ����� �ɰ��� ����� ����