// '�̵�' ( Move semantics ) �� �ǹ̿� ����Ʈ ������ ( Smart pointers ) �Ұ�

//c++ ���� ���� ���ŷο� ���� new �� delete �� ���� ���� �޸𸮸� �����Ҵ��ؾ� �ϴ°�
//�̴� ����Ʈ �����͸� ���� ���κ� �ذ�Ǿ���

#include <iostream>
#include <string>
#include "ch15_01_Resource.h"
#include "ch15_01_AutoPtr.h"

using namespace std;

// RAII : resource acquisition is initialization  ������ ���簡 ������ å������ �Ѵ�

void doSomething()
{
	try
	{
		Resource* res = new Resource;

		//work with res

		 //delete �� �ϱ����� early return �� �� ��� 
		if (true)
		{
			delete res;  //�ݺ��� �ȿ��� delete �� �ϰ� ������ ¥�� ��, ������ ���ŷο�� ����������
			//return;
			throw - 1; //throw �ϸ鼭 ���ÿ� delete �� �Ҽ� ��� ������ �� �� ����(������ �Ǵµ� �Ҹ��� �ȵ�)
		}


		delete res; //new �� ������ delete ����� �Ѵٴ°��� RAII ��� ��, ���� Ŭ���� �ȿ� �����
		//�ʺ� ���α׷��Ӱ� �Ǽ��� �ƿ� delete �� ȣ������ ������ ������ ����, �ͼ������� ��
		//���ݴ� ������ ���� ���ǹ��� �ɾ��µ� early return �� �ϰ� �Ǵ� ���

		//�������� ����� ������ ���� ����� ������, �ֱ��� ����� ����Ʈ �����͸� ����ϸ�
		//�ݺ��� �ȿ�����, �ۿ����� delete �� �����൵ �˾Ƽ� ������
	}
	catch (...)
	{

	}
	return;
}

void doSomething_new()
{
	try
	{
		//Resource *res = new Resource;			//dull pointer
		//Autoptr<Resource> res = new Resource;	//smart pointer
		
		AutoPtr<Resource> res(new Resource);	//������ �� ����
		//assignment ���� �ʱ�ȭ�̴ϱ� �̰� �� �����,�����ڿ� �ٷ� paramter �� �־���
		
		//Autoptr<Resource> *res ó�� �����ͷ� ������ �ʿ䰡 ����, res �� Autoptr<Resource> Ÿ���� ��ü�� 
		//����Ű�� ��������, Resource Ÿ���� �ּҰ� ��, *res �� �ϸ� Ÿ���� �ȸ����� (�������� �����Ͷ�)
		//��ġ int* a �� double �� �ּҸ� �ִ� ��


		return;		//early return �Ǵ� ��쿡�� �� �۵���

	

		//work with res
		if (false)
		{
			throw - 1; //exception
		}

		//delete res;
	}
	catch(...)
	{

	}
}

int main()
{

	doSomething();
	//�� �Լ��� ȣ���ϸ� �� �Լ� �ȿ��� � Resource �� �����Ҵ��ؼ� �޾ƿ���
	//�����͸� ���ؼ� �۾��� �� �� return �ؼ� ����, ������ ���� delete �� �������

	//�������� �޸𸮸� �Ҵ�ް� ������ �ڱⰡ ������ å������ ���� �����͸� dull pointer �̶�� �θ�

	//�޸� ������ ���α׷��ӿ��� �������� ���ܳ����� ���α׷��� ���忡�� ���ŷο�
	//�ϳ��ϳ� �Ű� ���Ⱑ ���ŷο���


	//���� �����ϱ� ���� �׻� ������ �ڵ����� ���� �� �ִ� �߰����� Ŭ������ ����� ����� ����
	doSomething_new();
	//delete �� �ּ�ó���ص� �����ڿ� �Ҹ��ڰ� �� ȣ���
	//thorw �ص� �Ҹ��ڸ� �˾Ƽ� ȣ���ϰ� ����,ȥ�� �� ������
	//����Ʈ �����Ͱ� �̷������� �˾Ƽ� �� �����ش�


	//������������ �Ѱ�
	{
		// int i; int *ptr1(&i); int *ptr2 = nullptr;  //�̷� ������ �����ϸ� ��

		AutoPtr<Resource> res1(new Resource);	
		AutoPtr<Resource> res2;		//�޸𸮸� ���� ������ ����, �׳� �����ͷθ� ������,�ʱ�ȭ �ȵ�

		cout << std::boolalpha;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

		res2 = res1;		//������ �ɼ� �ִ� �κ�, ����
		//�⺻ ���� �����ڰ� ���縸 ���ְ� ����, res1�� res2 ��� new Resource �� ���� �ּҸ� ����

	
		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;


		//��Ÿ�ӿ��� �߻�
		//Resource �� �ѹ��� ������, ���� ���� ���Ŀ��� �Ѵ� ���� �ּҸ� ������ �ϰ� ����
		//������ ������ ����鼭 res1 �� ��������, �̹� ������ �޸𸮸� res2 �� �Ǵٽ� ������� ��
		//�ϳ��� �޸� �ּҿ� ���� �������� �Ѵ� �������� �ϴ°��� ����
		//�ڷᱸ���� sorting ���� ����� �� ������� �Ҷ� runtime error �� ���� �߻���

		//�ذ� ���: �������� �׻� �ϳ��� ���� �ϴ°�
		//res2 �� �����Ҷ� res1 �� �������� �Ѱ��ֱ�, res1�� ������ ��Ż, �������� �̵�(move)
		//���������, ���Կ����ڿ����ε��� ������ ����(move) �����ϱ�
		//�̷��� �ϸ� res1�� �������� �������� nullptr �̱� ������ delete �� �Ҽ��� ����

		//res2 = res1 ó�� �������� ���� �ϴ°��� move semantics ��� �θ�
	}


	//syntax vs semantics
	//syntax ���忡�� ������ �´��� �ȸ´���, �������� �Ǵ��� �ȵǴ����� �߿���
	//semantics ���忡�� ���������� �ǹ̰� ������ ��, ���� �������� ���� + ��ȣ���� �ǹ̰� �ٸ�
	int x = 1, y = 2;
	x + y;

	string str1("Hello"), str2("World");
	str1 + str2;  //append

	//���α׷��� ��� ���񿡼� �ڼ��ϰ� ���

	//�Ȱ��� ���� �����ڸ� ���� paramter �� �ִ°ǵ�(���������� ������)
	//�޴��ʿ� ���� ��� ��������� semantics �� ���� �޶���
	
	// value sematics		(copy semantics)
	// reference semantics	(pointer)
	// move sematics		(move)

	//AutoPtr Ŭ������ ��������ڿ� ���Կ����ڴ� copy semantics �� �����Ѱ��� �ƴ϶� move semantics �� �����Ѱ���



	//�������� ���(�Ҹ��ڿ��� delete, move semantics ����)�� �����Ǿ�����
	
	//res1 �� �Լ��� paramter �� �ѱ� ��� �������� �� �Լ� �ȿ� �ִ� AutoPtr �� �Ѿ��
	//�� �Լ��� ������ �Ҹ�Ǿ������ �ۿ��� ������ �� ���Ե�, �̷� �������� �ڿ������� �ذ��ϴ°�
	//����Ʈ �����Ϳ��� �˾ƾ� �� �������
	
	
	//�������� RAII �� ����Ʒ� ���α׷��Ӱ� ���� å���� ���� ����� �߾���
	//�׷��� ���ݴ� ������ ��쿡�� ���α׷��Ӱ� ���ϰ� �޸� ������ �ڵ����� �� �� �ְ�
	//����Ʈ �����Ͱ� ������ �Ǿ���



	return 0;
}