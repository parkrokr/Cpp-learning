//���� Ŭ������ ���

//���ܸ� ������ �⺻�ڷ����� �ƴ� ��������� �ڷ���, �� ���� Ŭ������ ����ϴ� ���
//����Ŭ�������� ����� �Ҷ� ������ ��


//���ܸ� �����Ŀ� catch �ؼ� �ϴ� �۾����� �Լ��� Ŭ������ ���� ���Ǹ� �ϰ� ������ ����Ŭ���� ���

//����� ����Ҷ� catch �� ������ ���� �ڽ� Ŭ������ ������ �ڽ� Ŭ���� catch �� ��ƾ� �ϴµ�
//�θ�Ŭ������ ���� ������� �θ�Ŭ�������� ��ƹ���, �ذ�å�� �ڽ� Ŭ���� catch �� ���� ���ֱ�

//���ܸ� �� ������� �ۿ���(������ ��� main()) ���� �ٽ� ó���� �ؾ��ϰų� �ϰ���� ���
//�ٽ� ���ܸ� ������ �� (Re-throw)

//throw; �� ���ڸ��� �״�� �ٽ� ������ 
//throw e; �� �޾Ƽ� ������ ��ü�߸� ������ �Ͼ

#include <iostream>

using namespace std;


class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException :public Exception
{
public:
	void report()  //report() �� �������̵� �ϰ� ����
	{
		cerr << "Arrary exception" << endl;
	}
};



class MyArray
{
private:
	int m_data[5];

public:
	int& operator [] (const int& index)
	{
		//��� �Լ� �ȿ��� throw �� �� �� ����
		//if (index < 0 || index >= 5)throw - 1;  
		
		//�̷��� �⺻�����θ� ���ܸ� �����ٸ� ǥ������ ���ϴ°� ����
		//���ܸ� �����Ŀ� catch �ؼ� �ϴ� �۾����� �Լ��� Ŭ������ ���� ���Ǹ� �ϰ� ������ ����Ŭ���� ���


		//Exception class �� �ϳ� ���� ����
		//if (index < 0 || index >= 5)throw Exception();
		

		//����� ����Ҷ� ���ǰ� �ʿ���
		//ArrayException �� throw
		if (index < 0 || index >= 5)throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];  //0,1,2,3,4 �� ���� �ϴ� �ڸ��� 100�̶�� ū���� ����,���ܰ� throw �ɰ���
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	//ArrayException �� �޴� catch �� �߰�����
	//�θ�Ŭ������ �ڽ�Ŭ�������� ���� ��� ��츦 ���ϱ� ���� ���� ����
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();

		//�׷��� � ��� �ۿ��� �� ó���� �ϰ� ���� ��찡 ����
	    //catch �� �Ѱ��� �ٽ� ���� �� ����(Re-throw)
		throw e;
		//���⼭ �ٽ� �����ٰ� �ؼ� doSomething() ���� catch ���� ����
	}
	//Exception class �� �޾��ִ� catch �� �ϳ� �־�ߵ�
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}
	/*
	//ArrayException �� �޴� catch �� �߰�����
	//�θ�Ŭ������ �ڽ�Ŭ�������� ���� ��� ��츦 ���ϱ� ���� ���� ����
	catch (ArrayException& e)
	{
		e.report();
	}
	*/
}


void doSomething_new()
{
	MyArray my_array;

	try
	{
		my_array[100];  
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (Exception& e)
	{
		cout << "doSomething_new()" << endl;
		e.report();

		//�θ� Ŭ������ ���ؼ��� ����ó���� �ϰ� ��ü���� ������ re-throw �� �ϰ� 
		//�ۿ��� �޾Ƽ� ó���� �ϰ� ���� ���

		//throw e;		//e �� ������ ��(main() ���� �θ�Ŭ������ ��ƹ���)
		throw;			//�Ȱ��� re-throw �̱� ������ �׳� �޾Ƽ� �ٷ� ��������
	}
	
}

int main()
{
	//doSomething();


	//Exception class �� ����� ArrayException class �� throw �Ҷ� �����Ű��
	//ArrayException�� �޾��ִ� catch �� ���⶧���� Exception �� �޴� catch�� ����ְ�(��� ������ ��°� ����)
	//Exception �� report �� ���� (��ü �߸� ���� ����)

	//ArrayException �� �޴� catch �� �߰����ָ� ������ Exception report �� ����
	//warning C4286: 'ArrayException &': is caught by base class ('Exception &')
	//Exception �� ���� catch �ع����� �ڽ�Ŭ������ catch �� �ȵ�
	//�ذ�å : �ڽ�Ŭ���� catch �� ���� ��ƹ����� ���� ����



	//doSomthing() �� main() �� ���� ȣ��Ǿ� ������ ���� ����
	//main() ���� try catch �����
	//doSomething() ���� �� ��ƹ��� (�� ���ǿ� �ݴ�)
	try
	{
		doSomething();
	}
	//doSomething() ���� ���ܸ� �� ��ƹ��ȱ� ������ �� catch �� ���õǰ� ����
	//�׷��� � ��� �ۿ��� �� ó���� �ϰ� ���� ��찡 ����
	//catch �� �Ѱ��� �ٽ� ���� �� ����(Re-throw)
	//re-throw �� �ϰ� �Ǹ� �ٱ���(������ main()) �� �ִ� catch ���� �ѹ� �� �޾���
	catch (ArrayException & e)  
	{
		cout << "main()" << endl;
		e.report();
	}



	//�θ� Ŭ������ ���ؼ��� ����ó���� �ϰ� ��ü���� ������ re-throw �� �ϰ� 
	//�ۿ��� �޾Ƽ� ó���� �ϰ� ���� ���
	//doSomething() ���� Exception ���� �޾Ƽ� ������ ������ ó�� ���ܸ� ������
	//ArrayException (�ڽ� Ŭ����)���� ������ ������ main() ���� �������� �ڽ�Ŭ������ �ޱ⸦ �����
	//throw; �� �ƴ϶� throw e; �� �ϸ� ��ü�߸��� �Ͼ �ڽ�Ŭ������ ���ް� �θ�Ŭ������ �޾ƹ���
	//throw; �� ������ ��ü�߸��� �߻����� �ʰ� �ڽ�Ŭ������ ��ƹ���
	try
	{
		doSomething_new();
	}
	catch (ArrayException& e)
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}