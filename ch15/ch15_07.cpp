// ��ȯ ������ ����( Circular dependency issues ) �� std::weak_ptr

//shared_ptr �� ����Ҷ� ��ȯ ������ ������ �߻��� �� ����
//��ü�� ������� �ϴµ� count �� 0���� �������� �ʾ� �Ҹ��� �ȵǴ� ����, �޸� ���� �߻��� �� ����
//weak_ptr �� ����ϸ� ���ο��� count �� ���� �ʱ� ������ �����ϰ� ��� ����
//��ſ� weak_ptr �� ����Ϸ��� lock() �� ����� shared_ptr �� �ٲٰ� ����ؾ���

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
	std::string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}


	friend bool partnerUP(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		//��ȯ ����
		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

		return true;
	}


	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
		//lock() �� return ���� shared_ptr ��
		//weak_ptr�� ���� ����� ���� ���� lock() �� �ؼ� shaerd_ptr �� �ٲٰ�
		//�� shared_ptr �� �̿��ؼ� �۾��� �� ������
		//��ȯ ������ ������ ���� ���� �̷��� �����Ǿ�����
	}


	const std::string& getName() const
	{
		return m_name;
	}

};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	//����Ʈ �����͸� ����ϴ� �⺻���� ������ �޸𸮸� �Ű�Ƚᵵ �� ����� ���ؼ���


	//������ ����� �κ�
	partnerUP(lucy, ricky);
	//Lucy is partnered with Ricky ���� �� �������� �Ҹ��ڵ��� ȣ����� �ʰ� ����
	//�޸� ������ �߻��ϰ� ����


	//Person ��ü�� shared_ptr �� �����������
	//��ȯ ������ ��ü�� ����� shared_ptr �� ������ ������ ���� �� ����
	//m_partner �� shaerd_ptr �� ��� friend bool partnerUP() ���� ��ȯ������ �Ҷ�
	//���� ������ �ϰ� �־ �������� �����ϴ� Ƚ��(count) �� +1 �� ��
	//lucy �� ricky �� scope �� ����� ������� ������ count �� 0 �� �ƴϱ� ������ �Ҹ��ڵ��� ȣ����� �ʰ� 
	//������� �ʰ� ����

	//shared_ptr �� weak_ptr �� �ٲٸ� �ذ��(�Ҹ��ڵ��� �� ȣ���)
	//shared_ptr �� ����ϸ� counting �� ���� ���� , ��� ���ο� ī������ �Ǳ�� ������ ��ü ������ �Ҹ꿡 
	//������ ���� ����




	//weak_ptr �� ����: weak_ptr �� ���빰�� ����Ϸ��� �Ҷ� lock() �� ����� ��
	std::cout << lucy->getPartner()->getName() << std::endl;
	//lucy �� lock() �� �ؼ� shared_ptr �� �ٲٰ� getName() ȣ���ϰ� ����


	return 0;
}