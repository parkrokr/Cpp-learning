//제휴 관계 Association

//구성과 공유와 달리 확실하게 어느쪽이 주가 되고 부가 되는지 명확하지 않은 경우
//둘다 주 일수도 부일수도 있음

//서로가 서로를 사용하는 입장, 용도 외엔 무관,다른 클래스에 속할 수 있음 ,서로가 서로를 관리하지 못함,양/단 방향

//구현하기 복잡해질 수 있음

//class 들을 헤더로 뺄 경우 선언을 헤더에 남기고 정의를 cpp 파일에 빼지만 전방선언을 할 경우
//링킹에러 발생시 추적이 어렵기 때문에 전방선언을 거의 사용하지 않고 두 class 모두 사용해서
//기능을 수행하는 다른 클래스를 만들기도 함

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor;	//forward declaration 
//class Patient 는 class Doctor에 m_name 이 있는지는 모르기 때문에 
//meetDoctors() 의 body 를 밑으로 안빼면 에러 발생

//서로 알아야 하기 때문에 동등한 관계
//코드가 복잡해지면 body 가 어디있는지 찾을 수 없는 일도 발생
//구성과 공유보단 덜 사용하는게 보통, 쓸 수 밖에 없는 일도 있음
//전방선언이 되어있으면 association 관계로 추측할 수 있음

//서로가 내부에 상대방을 멤버로서 가지고 있음

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors; 
	//포인터를 안쓰고 의사나 환자의 id를 int로 부여해서 id 로 의사나 환자를 찾는 방식도 있음 

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
	//class Patient 는 class Doctor에 m_name 이 있는지는 모르기 때문에 
	//meetDoctors() 의 body 를 밑으로 안빼면 에러 발생

	friend class Doctor;
};


class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;

	Doctor* doctor; //Reflexive Assiciation(반사적 제휴관계)
	//의사가 의사로서 의사를 또 만날 수도 있음, 구현이 좀더 복잡해짐

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

	friend class Patient;  // getters 를 만드는 것보다 friend 하면 member variable 에 접근하게 해줄 수 있음
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

