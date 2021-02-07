//std::unique_ptr

// �����Ͱ� ����Ű�� �������� �������� �Ѱ����� ���� ��� ����ϴ� ����Ʈ ������

//unique_ptr �� Ư�� : ���縦 ����
//res2 = res1;  //���縦 ����

//���� ���ƾ� �ϴ°�!
// �ΰ� �̻� �������� �ִ°�, �ٽ� ������� �õ��ϱ�

#include <iostream>
#include <memory>		//to use std::unique_ptr
#include "ch15_05_Resource.h"

using namespace std;

auto doSomething()
{
	//�������� ������� return �� �� ����

	/*auto res1 = std::make_unique<Resource>(5);
	return res1;*/

	//return std::unique_ptr<Resource>(new Resource(5));

	return std::make_unique<Resource>(5);	//���� ����
	//unique_ptr �� ���������� move semantics �� ����ϱ� ������ �������� Ȯ���ϰ� �Ѿ,����(copy �� ȣ�����)
}


//void doSomething2(std::unique_ptr<Resource>& res)		//���� ��ȣ�ϴ� ��Ÿ��
//auto doSomething2(std::unique_ptr<Resource> res)	//l-value ref �� �ƴ϶� value �� �ް���� ���
void doSomething2(Resource * res)	 //�����͸� �Ѱ��ִ� ���, unique_ptr�� get() ���
{
	res->setAll(10);

	//return res;  
	//l-value ref �� �ƴ϶� value �� ������� �������� �Ѱܹ޾����� �Լ��� ������ ������� ������ 
	//�ٽ� res1 ���� �������� �����ֱ� ���� return ( move �� �޾Ҵٰ� move �� ������)
}


int main()
{
	{
		Resource* res = new Resource(1000000);

		//early return or throw

		//delete res;	//delete �� ������� �ʾ� �Ҹ��ڰ� ȣ����� �ʰ� ����
		//unique �����͸� ����ϸ� �ڵ����� ó������
	}


	//unique_ptr ���
	{
		//std::unique_ptr<Resource> res = new Resource(1000000);
		std::unique_ptr<Resource> res(new Resource(1000000));  //�� ����� ����


		//no delete
	}
	//delete �� ������ ������ ����� �˾Ƽ� �Ҹ��ڸ� ȣ���ϰ� ����


	
	{
		std::unique_ptr<int> upi(new int);		//�⺻ �ڷ������� ��� ����

		//std::unique_ptr<Resource> res1(new Resource(5));
		
		// ptr �� �־ �ʱ�ȭ�� ��ų ���� ����
		//auto* ptr = new Resource(5);
		//std::unique_ptr<Resource> res1(ptr);


		//�����ϴ� ��� :		std::make_unique ���
		//auto res1 = std::make_unique<Resource>(5);	
		  //std::make_unique<Resource> �� ��ġ resource �ΰ�ó�� ������ ȣ�� ����

		auto res1 = doSomething();  //�Լ����� return �Ǿ ���� ���


		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;	

		//res1, res2 �� �������̱� ������ nullptr ���� �ƴ����� bool �� cast �ؼ� �˼� ����

		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;		//res1�� Ȯ���� �ʱ�ȭ�� �Ǿ��� ������ nullptr �ƴ�
		cout << static_cast<bool>(res2) << endl;		//res2 �� �ʱ�ȭ �ȵ�, nullptr ��


		//unique_ptr �� Ư�� : ���縦 ����
		//res2 = res1;  //���縦 ����
		//�������� �Ѱ����� �־�� �ϱ� ������ ���簡 �ȵ�, copy semantics �� ����� ����, move semantics �� ����
		//�������� unique
		res2 = std::move(res1);


		cout << boolalpha;
		cout << static_cast<bool>(res1) << endl;		//res1 �� �������� ����
		cout << static_cast<bool>(res2) << endl;		//res2 �� �������� ����(�����ϰ�, unique �ϰ�)

		
		if (res1 != nullptr)res1->print();
		if (res2 != nullptr)res2->print();				//(*res2).print();

		//unique_ptr �� ������ÿ����� ->, de-referencing������ * �� �����ε��� �Ǿ��־ ��� ����
	}



	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();		//1 1 1 1 1

		//doSomething2(res1);		//�Լ��� paramter �� �ִ� ���, l-value ref �� �ְ� ����
		

		//���� l-value ref �� �ƴ϶� value �� �޴� ��� ���� �ڵ�� ���� �ȵ�, unique �ϱ� ������ copy �� �ź���
		//�׷��� �ݵ�� �־�� �ڴٸ� std::move() �� �ֱ�, �̷��� �ϸ� res1 �� �������� ����
		//�Լ� �ȿ��� res1 �� ���� �޾Ƽ� ��� �ٲٰ� ��µ� ����������
		//��������ó�� �۵��� �Լ��� ������ �Ҹ��, res1 �� ���ѱ�� print() �۵��� ����Ŵ
		//�ٽ� res1 �� ����ϰ� ������ �Լ��κ��� �ٽ� ���������� ��
		//���� �޾����� ��µ� ��
		//�ֱ� ������ ���鿡�� �̷� �����޴� ������ ���ϴ� ������ ������ �ִٰ� ��(���̽�)
		//c++ ���� �̷��� �������� �ְ� �ٽ� �����޴°ͺ��� �׳� l-value ref �� ���°� ����
		//res1 = doSomething2(std::move(res1));


		//�����͸� �ѱ涧
		//unique_ptr �ȿ� get() �� ����, �����͸� ��ȯ��
		doSomething2(res1.get());


		res1->print();		//10 10 10 10 10
	}




	//���� ���ƾ� �ϴ°�!
	// �ΰ� �̻� �������� �ִ°�, �ٽ� ������� �õ��ϱ�
	{
		Resource* res = new Resource;

		//res �����Ϳ� ���� �������� �ΰ����ٰ� �ַ��� �ϰ� ����, ���߿� �ι� ������� �õ��ϱ� ������ ���� �߻�
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);	//x


		//delete �� �߰��� �ϴ� ��� ����� �ٽ� �� ������� �ϱ⶧���� �ϸ� �ȵ�
		delete res;		//x
	}

	return 0;
}