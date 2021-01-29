//��ü �߸� (Object slicing) �� reference_wrapper

//����� ������ ������ �ڽ� Ŭ������ ������ �� ���� ����
//���� ���� �θ��� ��ü�� ���� ū �ڽ� Ŭ������ ��ü�� ������ �����ϸ� 
//�ڽ�Ŭ�������� �ִ� �������� ������� ��(��ü �߸�)
//reference_wrapper �� �̸� ������ �� ����

//������ �����͸� ������� �ʰ� �θ�Ŭ������ �ڽ�Ŭ������ ������� �ع����� �θ�Ŭ������ �ִ� ���� ���� ���󰡹���

//std::vector<Base> �� push_back() �� �Ҷ� slicing �� �Ͼ
//Base �� �����͸� ����ص� ������
//������ ����ϰ� ������ reference_wrapper �� ����ؾ���(Base& ���� ������ ���Ϳ� ��� ����)

#include <iostream>
#include <vector>
#include <functional> //to use std::refernece_wrapper<>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 1;
	//m_i�� �Ⱥ������� �߰� �Ǿ�����

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	Base& b = d;

	b.print();  //I'm derived

	// Base b =d; �� �ϸ� ���簡 �Ǿ����,
	// Derived �� �� ���� ������ ��� �ֱ� ������ m_j �� ��������(slicing)
	//�������� ����� b.print(); �� ����� I'm base ��
	// Derived �� ����� �߰� �������� ���󰡱� ������ Base �� �ִ� �Լ��鸸 ������ ������
	// �ǵ������� slicing�� ����ϴ� ���� ���� ���� �������� �����Ϸ��ٰ� �Ǽ��Ѱ� �Ϲ���
	// �ǵ��� ��� �ּ��� ���ܵα�

	doSomething(d);//I'm derived �� 

	//�ǵ����̵� �Ǽ��� doSomething( Base & b) ���� &�� ���������� ���簡 �Ǿ����
	//�������� ����� I'm base �� ��µǾ����


	//�ʺ��� ���� �ϴ� �Ǽ�
	vector<Base> my_vec;
	//Base b;
	Derived d;

	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto& ele : my_vec)
		ele.print();
	//�Ѵ� I'm base ��µ�
	//�ι�° push_back() �� d �� �־����� push_back �� �ϴ� �������� slicing �� �߻���
	
	
	//vector<Base&> my_vec; �� �õ������� ����ȵ�, ���Ϳ��� ������ ���� �� ����
	
	
	//�����ʹ� ��
	vector<Base*> my_vetptr;
	my_vetptr.push_back(&b);
	my_vetptr.push_back(&d);

	for (auto& ele : my_vetptr)
		ele->print();
	//I'm Base
	//I'm Derived ��� �� ��


	//������ ���� ������ ������ ���� ����, vector<Base&> �̷� �ǵ��� ����ϰ� ����
	//std::reference_wrapper�� ����ϸ� my_vetref �� Base �� reference �� �����ϴ� ���Ͱ� ��
	vector<reference_wrapper<Base>> my_vetref;
	my_vetref.push_back(b);
	my_vetref.push_back(d);

	for (auto& ele : my_vetref)
		ele.get().print(); //reference �κ��� ������ �ν��Ͻ��� �޾ƿ;��ϱ� ������ .get() �� �ؾ���

	return 0;
}