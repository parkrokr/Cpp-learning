//�Լ� ���ø� Ư��ȭ Specialization

//getMax() ��� ���ø�ȭ �� �Լ��� �ִµ� Ư���� ���(Ư�� data type �� ���ؼ�) instantiation 
//�� �Ǵ°�� Ư��ȭ�� �� �� ����


#include <iostream>
#include "ch13_04_Storage.h"

#include "ch13_04_Storage.cpp"		//Ư��ȭ�� ����Լ��� cpp ���Ϸ� �Ű����� �ذ���2
//cpp ������ include �ϸ� �Լ��� body �� main.cpp �� �ִ²��̰� �ᱹ�� ����� �ִ°Ŷ� ��������
//�ٸ� ������ �� �и��Ǿ� ���� ����

using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


//specialization 
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing chars " << endl;

	return (x > y) ? x : y;
}



int main()
{
	cout << getMax(1, 2) << endl;
	//getMax() �� ���°� int �̱� ������ �ڵ����� ���� type �� ���ؼ� ���带 �ϰ� ����
	//getMax<int>(1, 2)�� ����, <int> �� parameter �� int �̱� ������ �ڵ����� ã���ְ� ����

	//double �� instantiation �ϰ� ������
	cout << getMax(1.0, 2.0) << endl;
	cout << getMax<double>(1, 2) << endl;  //������ double type ���� instantiation �ϰ� ����


	//���ڳ��� ���Ҷ� ���ڳ��� ���Ѵٴ°� ����ڿ��� ����ϰ� ����
	cout << getMax('a', 'b') << endl;
	//if���� ����(compile time �� �ؾߵǱ� ������) ��� ����Ѱ� �� �� ������ �ڿ��� ����

	//specialization 
	//Ư���� type �� ���ؼ� Ư��ȭ


	//member function �� ���� Ư��ȭ


	Storage<int> nValue(5);
	Storage<double> dvalue(6.7);


	//double type �� ���ؼ� scinetific notation(������ ǥ���) �� ������ ������
	nValue.print();
	dvalue.print();


	return 0;
}