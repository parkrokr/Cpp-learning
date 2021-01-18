//÷�� ������ ( [] subscript operator ) �����ε��ϱ�

//assert �� ��� runtime error �� ���� �� ����
//[]�� ���� ���� ������ ����� �ű� ������ if �� ���ٴ� assert �� �Ἥ performace �� ����

//�����͸� ���� de-referecing �ؼ� ����

// std::vector �� ������ �����ε��� �� �Ǿ�����

#include<iostream>
#include<cassert>  //to use assert

using namespace std;

class IntList
{
private:
	//std::array �� std::vector �� ������ ������ �����Ҵ��� �Ҷ� �޸𸮰� ����� ���� �־����
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	/*void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}*/

	//÷�� ������ �����ε�
	//���� �а� �ٲٱ� ���� ������ ��ȯ,  l value ���� �ϴϱ� (�ּҸ� ������ �־���ϴϱ�) ������ ��ȯ
	int& operator [] (const int index)  //int ���� �ٸ� data type �� ���� �� ����
	{
		//assert �� ���°� ����
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	//const ������ �����ε�
	const int& operator[] (const int index) const
	{
		//assert �� ���°� ����
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

};


int main()
{
	//IntList my_list;
	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl;

	//my_list.getList()[3] = 10;
	//cout << my_list.getList()[3] << endl;  //() �� ������ ���ŷο�

	IntList my_list;
	my_list[3] = 10;
	cout << my_list[3] << endl;


	//const �������� ȣ���ؾ��Ҽ��� ����
	const IntList my_new_list;
	//my_new_list[3] = 10;  //���� �ٲٷ��� �ϱ� ������ �Ұ���
	cout << my_new_list[3] << endl;



	//���ǻ��� : �����͸� ����
	IntList* list = new IntList;
	
	//list->operator[](3) = 10;
	
	//�Ǽ��� list[3] �� �� ��� ���� �߻�(�ǵ��� �ٸ�)
	//list[3] = 10; not ok
	//list[3] = IntList  //list �� array �̱� ������ �ٸ� ������ ��


	//�������� ���
	(*list)[3] = 10;


	return 0;
}