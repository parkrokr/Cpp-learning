// std::shared_ptr 

// �������� ���������� ������ �� ����, ���������� �޸� ������ ������
//unique_ptr ���� ���ݴ� �� �����ϰ� ����� �� ����
//�ڱ� �ڽ��� ��� �̳� �����Ǵ��� ��( Reference counting )
//�����Ӱ� ���ٰ� �ᱹ ��� ������(delete �� ���ؼ� ����� �޸� ������ ���Ͼ)

//new ���� make_unique, make_shaerd �� ����ϴ°��� ����(Ư�� �Լ� parameter �� ������)

#include <iostream>
#include "ch15_06_Resource.h"


using namespace std;


//����Ʈ �����͸� paramter �� �޴� �Լ�
void soSomething(std::unique_ptr<Resource> res)
{
}

int main()
{
	//����Ʈ �����͸� �Լ� paramter �� �޴°�� ������ �� ����
	//new �� ���⼭ ȣ���ϴ� ��� ���������� ������ ������
	//�Ϻ��ϰ� ������ �ǰ� �Ѿ�°� �ƴϰ� new �� �߰��� ���� �ָ���������
	//�����Ϸ����� �ٸ����� ���� ����
	//std::make_unique ����ϴ°��� ����
	//shared_ptr ������ ���������� make_shared �� ���°��� ����
	
	//soSomething(std::unique_ptr<Resource>(new Resource(100000)));		//������
	soSomething(std::make_unique<Resource>(100000));

	



	//ptr1 �� �ֱ� ���� res �� ����� ����, ��ȣ�Ǵ� ����� �ƴ�
	//Resource* res = new Resource(3);  
	//res->setAll(1);
	{
		//std::shared_ptr<Resource> ptr1(res);  //shared_ptr �� res �� �����鼭 ���������� �ʱ�ȭ �ϱ�
		
		//�Ʒ����� �߻��� �� �ִ� ���� ������ ����Ʈ �����͸� �ʱ�ȭ �Ҷ��� ���������� �ʱ�ȭ�ϴ� ��ĺ���
		auto ptr1 = std::make_shared<Resource>(3);  //make_shared �� ���� ���� �ʱ�ȭ �ϴ� ����� ��ȣ
		ptr1->setAll(1);
		ptr1->print();


		//shared_ptr Ư¡�� �ڱⰡ ����Ű�� �ִ� �ּ��� �����Ͱ� ������� ����(share) �� �ϰ��ִ��� ��
		//ptr1 �� �����ɷ� ptr2 �� ����� �°���� ���� ����(�ȿ� �����Ͱ� ����)
		{
			//std::shared_ptr<Resource> ptr2(ptr1);

			auto ptr2 = ptr1;	//make_shared �� ���� res �� ���� ���
			//�������� �׳� copy �ؼ� �־��ִ°� ó�� �������� ���������� make_shared ���� ���� Resource
			//�� ���� �������� ������� ������ �ִ��� ����� �ϰ��ֱ� ������ ������ shared_ptr �� 
			//�Ҹ�ɶ� Resource �� ����, �� ������ ������




			//������ �ɼ� �ִ� ���
			//std::shared_ptr<Resource> ptr2(res);	//res �� ���� ����� ����
			
			//ptr1�� ������ �ʰ� ����� ����, ptr1 �� res �� �������� �ڱ� ���� �� �ٸ������� �ִٴ°���
			//�� ����� ����, inner block �� �����鼭 ptr2 �� ������鼭 res �� ����������
			//outter block �� �����鼭 ptr1 �� ������鼭 �̹� ������ res �� �ٽ� ������� �ϱ� ������ 
			//������ �߻���


			ptr2->setAll(3);
			ptr2->print();

			cout << "Going out of the block" << endl;
		}

		//����� ����� ptr2 �� ������� ptr1 �� ������ res1 �� ���� �������� ������ ����
		ptr1->print();

		cout << "Going out of the outter block" << endl;
	}
	//����� ����鼭 ptr1 �� ������� res�� ���� ����


	

	return 0;
}