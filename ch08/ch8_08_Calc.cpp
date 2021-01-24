#include "Calc.h"  //���� ó�� �ϴ����� class ��������� ��Ŭ��� ����

using namespace std; //�ٸ� cpp ���Ͽ� ���� ���ֱ� ������ ���ϰ� �ᵵ ��


//�����ڵ� ���� �ű� �� ����
Calc::Calc(int init_value) 
	:m_value(init_value)
{}

Calc& Calc::add(int value) //Calc::�� ���� add() �� Calc �� �����°� �˷���� ��
{
	m_value += value;
	return *this;
}

//���� �ű��� �ʰ� Quick Actions and Refactorings �� Move Definition Location ���
//�Ϲ������� class ���� ��� �Լ��� definition �� �� ������ ��� inlining �ϰ� �ʹٰ� �����Ϸ��� ������
//inline Calc& Calc::sub(int value)
Calc& Calc::sub(int value)
{
	m_value -= value;
	return *this;
}

Calc& Calc::mult(int value)
{
	m_value *= value;
	return *this;
}

void Calc::print()
{
	
	cout << m_value << endl;
}
