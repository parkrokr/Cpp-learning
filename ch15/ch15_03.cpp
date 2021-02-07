// �̵� ������( Move Construcotrs ) �� �̵� ���� ( Move assignment )


#include "ch15_03_Timer.h"
#include "ch15_03_AutoPtr.h"
#include "ch15_03_Resource.h"


AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(1000000));
	cout << 2 << endl;
	return res;
}



int main()
{
	using namespace std;
	
	streambuf* orig_buf = cout.rdbuf();

	//Time �� �ð��� �����Ҷ� cout log(�Ǵ� ���� ���) �� ������ �α� ��¶����� �ð��� ���� �ɸ�
	//cout.rdbuf(NULL);	//disconnect cout from buffer

	Timer timer;

	{
		AutoPtr<Resource> main_res;
		cout << 1 << endl;
		main_res = generateResource();		//�Լ��� return �ؼ� ������ ���� r-value,�� �ٽ� ����� ���� ����
		cout << 3 << endl;
	}
	

	cout.rdbuf(orig_buf);
	timer.elapsed();

	
	/* Release ����϶� ���: return �Ҷ� ����, RVO ����
	* 
	AutoPtr default construcotr
	1
	Resource length construcetd
	AutoPtr default construcotr
	2
	AutoPtr copy assignment			//deep copy
	Resource default constructed
	Resource copy assignment
	AutoPtr destructor
	Resource destroyed
	3
	AutoPtr destructor
	Resource destroyed
	*/
	


	//move construtor, assignment �϶� �� �ð��� ���� �ɸ�
	//deep copy �� �ǰ� �ȵǰ� �� ������
	//resource �� copy assignment�� constructor �� ȣ��Ǵ� �κ��� ����


	/*REalese ��忡��  a.m_ptr = nullptr; ��������
	AutoPtr default construcotr
	1
	Resource length construcetd
	AutoPtr default construcotr
	2
	AutoPtr move assignment			//deep copy �ϴ� �κ��� ���� 
	AutoPtr destructor
	3
	AutoPtr destructor
	Resource destroyed
	*/


	//debug ��忡�� return �Ҷ� �����ڰ� ȣ���, release ��忡�� ȣ����� ����, �����Ϸ��� ����ȭ(RVO) 
	//������ resource �� �ѹ��� �����ؼ� ����ϰ� �ִµ� a.m_ptr = nullptr �� ������ 
	//�ι� ������� ��, release ��忡�� �׳� ���������� debug ��忡�� ��Ÿ�� ����

	//���� �����ڿ� ���Կ����ڸ� �ּ�ó�� ���ص� & �� && �� �����ε��� �����ϱ� ������ 
	//�츮�� ���ϴ� move �����ڿ� ���Կ����ڷ� �� �۵���


	return 0;
}