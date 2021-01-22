//���� ���� Association

//������ ������ �޸� Ȯ���ϰ� ������� �ְ� �ǰ� �ΰ� �Ǵ��� ��Ȯ���� ���� ���
//�Ѵ� �� �ϼ��� ���ϼ��� ����

//���ΰ� ���θ� ����ϴ� ����, �뵵 �ܿ� ����,�ٸ� Ŭ������ ���� �� ���� ,���ΰ� ���θ� �������� ����,��/�� ����

//�����ϱ� �������� �� ����

//class ���� ����� �� ��� ������ ����� ����� ���Ǹ� cpp ���Ͽ� ������ ���漱���� �� ���
//��ŷ���� �߻��� ������ ��Ʊ� ������ ���漱���� ���� ������� �ʰ� �� class ��� ����ؼ�
//����� �����ϴ� �ٸ� Ŭ������ ����⵵ ��

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor;	//forward declaration 
//class Patient �� class Doctor�� m_name �� �ִ����� �𸣱� ������ 
//meetDoctors() �� body �� ������ �Ȼ��� ���� �߻�

//���� �˾ƾ� �ϱ� ������ ������ ����
//�ڵ尡 ���������� body �� ����ִ��� ã�� �� ���� �ϵ� �߻�
//������ �������� �� ����ϴ°� ����, �� �� �ۿ� ���� �ϵ� ����
//���漱���� �Ǿ������� association ����� ������ �� ����

//���ΰ� ���ο� ������ ����μ� ������ ����

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors; 
	//�����͸� �Ⱦ��� �ǻ糪 ȯ���� id�� int�� �ο��ؼ� id �� �ǻ糪 ȯ�ڸ� ã�� ��ĵ� ���� 

public:
	Patient(string name_in)
		:m_name(name_in)
	{}

	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctors();
	/*{
		for (auto& ele : m_doctors)
		{
			cout << "Meet doctor : " << ele->m_name << endl;
		}
	}*/
	//class Patient �� class Doctor�� m_name �� �ִ����� �𸣱� ������ 
	//meetDoctors() �� body �� ������ �Ȼ��� ���� �߻�

	friend class Doctor;
};


class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;

	Doctor* doctor; //Reflexive Assiciation(�ݻ��� ���ް���)
	//�ǻ簡 �ǻ�μ� �ǻ縦 �� ���� ���� ����, ������ ���� ��������

public:
	Doctor(string name_in)
		:m_name(name_in)
	{}

	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatients()
	{
		for (auto& ele : m_patients)
		{
			cout<<m_name << " Meet patient : " << ele->m_name << endl;
		}
	}

	friend class Patient;  // getters �� ����� �ͺ��� friend �ϸ� member variable �� �����ϰ� ���� �� ����
};

void Patient::meetDoctors()
{
	for (auto& ele : m_doctors)
	{
		cout <<m_name <<" Meet doctor : " << ele->m_name << endl;
	}
}

int main()
{
	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");


	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// patients meet doctors
	p1->meetDoctors();
	p2->meetDoctors();

	// doctors meet patients
	d1->meetPatients();
	d2->meetPatients();


	//delete
	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;





	return 0;
}

