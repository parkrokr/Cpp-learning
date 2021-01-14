//�Ҹ��� Destructor

//������ : �����ɶ� ȣ��Ǵ� �Լ� <-> �Ҹ��� : ������ ������ ����� �������(�Ҹ�ɶ�) ȣ��Ǵ� �Լ�

//vector ���ε� �̷��� ������� ����
//class ���ο��� new �� �޸𸮸� ����� �ִٸ� �Ҹ��� ���� ������ �ݵ�� delete �� �����ֱ�

#include <iostream>

using namespace std;


class Simple
{
public:
	int m_id;

	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	//�Ҹ���,  parameter ����
	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
		//cout << "constructor" << endl;
	}

	int getLength(){ return m_length; }
	
	int size(){ return m_length; } //m_length �� unsigned �� �� �� ������ �����ڵ�� �ܼ�

	//delete �Ҷ� ���� �Ҹ���
	~IntArray()
	{
		if(m_arr != nullptr) //�� ������ ��� : nullptr �϶��� delete �Ϸ��� �ϸ� ���� �߻�
			delete[]m_arr;
	}

	//delete �� �Ҷ� delter �� nullptr�� �˻��ϴ� �ڵ尡 ������ ������� ������ �����ս���
	//�ſ� �ΰ��� ��� nullptr �� ������� �õ��ϴ� ��ü�� ������ ������ �ִٴ°���
	//�ǹ����� nullptr �˻���� delete �� ���� �Ѵٸ� ���� smart pointer �� �Ἥ
	//delete �� �Ⱦ��°� �� ������ ������ �����ϴ� �������� ��Ÿ�ӿ� �����Ͱ� nullptr
	//���� �ƴ��� ������ �� �ִ� �ڵ带 �ۼ��ϴ°� ��������� ����
};


int main()
{
	//Simple s1(0);
	//Simple s2(1);

	/*Constructor 0
	Constructor 1
	Destructor 1
	Destructor 0*/

	//�Ҹ��� ������ �ݴ� ������ ����ȴ�(����ó��) 
	//��� ������ ������ �Ҹ��� ���� �ݴ�� �Ҹ�Ǵ°� ����?

	//���� �Ҵ�
	Simple *s1 = new Simple(0);
	Simple s2(1);

	delete s1;  //Destructor 0	

	/*Constructor 0
	Constructor 1
	Destructor 0		
	Destructor 1*/


	//�Ҹ��ڴ� instance �� �޸𸮿��� ������ �� ���ο��� �ڵ����� ȣ���.
	//�����Ҵ����� ������� ��� ������ ����� �ڵ����� �޸𸮰� �������� �ʱ�
	//������(delete ���ϸ� �޸� ����) delete�� �޸𸮸� ������ ������ �Ҹ��ڰ� ȣ���
	//�Ҹ��ڸ� ���α׷��Ӱ� ���� ȣ���ϴ� ���� ��κ��� ��� ������� ����


	//�Ҹ��ڴ� delete �Ҷ� ������
	while (true)
	{
		IntArray my_int_arr(100); //delte ������ memory ���� �Ͼ
		//delete ... ���α׷��Ӱ� IntArray ����Ҷ����� delete �� ������ ���ִ°� ���ŷο�  -> �Ҹ��� ���
	}


	//�̷��� �����ϴ°� �Ҿ��ϸ� vector ���
	//vector �ȿ� �̷� ����� �����Ǿ� ����

	return 0;
}