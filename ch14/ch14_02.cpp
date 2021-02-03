// ���� ó���� ���� �ǰ��� Stack Unwinding

// �Լ��� �Լ��� ȣ���ϰ� �ٽ� �� �Լ��� �ٸ� �Լ��� ȣ���ϸ� ���ÿ� ȣ�ⱸ���� ���̰� ��
//���� ������ �Լ��� ���ܸ� �����ٸ� ������ '�ǰ���' ���鼭 ���ܸ� ��� ������ ã�� ��


//Exception �� ������� ��쿡�� ��� throw �ż� ����
//���� ��쿡 ���������� ������ �����

//catch(...)  //catch-all handlers, using ellipsis , ������, ������ ����

#include <iostream>

using namespace std;


//std::cerr , standard ouput stream for errors
//cout �̶� ���� �����, std::clog �� ����
//�������� ��ɻ� ū ���̴� ���� �α׸� ����ϴ� ü���� 3������ �ִ�
//std::cout �� buffer �� ��Ƶΰ� �ٷιٷ� ����� ���ϴ� ��쵵 ����, endl �� ���� flush �� �ٹٲ��� ��
//std::cerr �� ��� �� �ٷ� ���۸� �����(flush),flush �� endl �� ��� �۵���
//���ܴ� ������ ������ ���� cerr �� ��



//exception specifier 
//���ʿ��ϴٴ� ���ص� ���ٰ� ��, ������ �� �Ȼ����
//void last() throw(int) //�̷��� �ϸ� int type �� exception �� throw �Ҽ��� �ִ�~ �׻� �Ѵٴ°� �ƴ�
//ms visual studio ������ ã�ƺ��� � type �� �ִ����� ... ó�� ����
//void last() throw(...)  : � type �̴����� ���ܸ� ���� �� �ִ� ���ɼ��� �ִ� �Լ���

//���ǻ���: void last() throw() ó�� paramter �� ������ ���ܸ� �ȴ����ٰ� ��⸦ �ϴ²���
//�ؿ� ������ throw() �� ���̸� ���ܸ� �ȴ����� �ߴµ� ������ ��� �߻���(C4297)


void last()
{
	cout << "last " << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "End last" << endl;
}



void third()
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl;
}


void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double exception" << endl;
	}

	cout << "End second " << endl;
}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "fist caught int exception" << endl;
	}

	cout << "End first " << endl;
}



int main()
{
	cout << "Start " << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}

	

	//first, second, third, last ������ ���� last ���� -1 �� throw �ϰ� �ǰ�{"End last" ����� ����)
	//third �� �Դµ� "End third" �� ��� ����, last() ���� ������ ����ִ� ���� ������ �ٷ� ���ÿ��� �ǰ��⸦ ��
	//second �� �Դµ� catch �� ������ doube �ۿ� ���� ������ �����ϰ� �ǰ�����("End second" ������)
	//first �� �Դ��� catch int �� �־ ������ ��� �ǰ� "first caught int exception"�� ����ϰ�
	//"End first"�� �����
	//fisrt ���� ��ұ� ������ main() ���� "End main" ����� ���������� �۵���


	//���� ��� ���� �ϴ°� last() �� "End last" �� ������ �ȵƴٴ°�
	//third() ���� ������ ��������� "End third" �� ������ �ȵƴٴ°�
	//second() ���� catch �� �������� �ұ��ϰ� ��������� "End second" �� ������ �ȵƴٴ°�
	//first() ���� �޾ұ� ������ "End first" �� ���������� ������ �ƴٴ°�


	//Exception �� ������� ��쿡�� ��� throw �ż� ����
	//���� ��쿡 ���������� ������ �����


	//fisrt() �� catch(int) �� �����ٸ� main() ���� ����
	//last() ���� char type ���� ������� catch(char) �� ���� ������ runtime error  


	//������ �� ����� ���, uncaught exceptions �� �߻��� ���� ����
	//������ȣ ellipsis ��� �ϸ� � type �̵� �� ���� �� ����
	catch (...) //catch-all handlers
	{
		cerr << "main caught ellipsis exception" << endl;
	}


	cout << "End main" << endl;


	return 0;
}