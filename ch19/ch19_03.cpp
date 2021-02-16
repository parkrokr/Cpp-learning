//std::thread �� ��Ƽ������( multithreading ) �� ����

//������ cpu ���� ���Ǵ� multi-core ��, �츮�� ���������� ���� ���α׷��� ������� �����ھ ��������
//�ϳ��� ���μ������� �������� �۾��ϴ°� ������
//C++11 ���� ���Ե� std::thread �� �̿��� ��Ƽ�������� ����

//Process : os �� �츮�� �ۼ��� ���η��� �����ų�� �����ϴ� ����
//�ϳ��� process �� �������� thread ���� ������ �� ����

//multi processing �� �ϳ��� ���α׷��� ����� �� ���α׷��� �������� thread �� ����
//�������� �ھ ���ÿ� Ȱ���ؼ� ������ ������ ���
//cpu �ϳ��� �ھ� �ϳ��� �ִ� ���� ���κ��忡 cpu �� �������� �ȾƼ� multi processing �� �ϱ⵵ ����
//ȿ���� ���̱� ���� ��ũ��ũ�� �̿��� �������� pc �� ������ �� pc �� �ִ� �ھ���� ���ÿ�
//Ȱ���ϴ� ����� ����(�л� ó��), �л�ó���� pc �� ���� ����� �ֱ� ������ �޸𸮸� �������� ����,
//����� �Ҷ� �������� �ΰ����� ������尡 �߻��ϴµ� ��ȿ�������� �־���

//multithreading �� �ϳ��� cpu �� �������� �ھ �ִ� ��� �� �ھ���� Ȱ���ؼ� ���ÿ�
//�������� �۾��� �����ϴ°��� �ǹ���
//mulitprocessing ���� ȿ���� ����, �뼼
//�������� thread ���� �޸𸮸� ������, ���α׷��Ӹ� ���ϰ� ���ִ� ���ÿ� �糯�� ��

//��Ƽ�ھ� cpu ���� �ڵ����� ȿ���� �����ִ°��� �ƴϰ� ���α׷��Ӱ� multithreading �� �ϵ��� ����
//���α׷����� �ؾ���


//main() �� �����ϴ� thread �� Main Thread ��� �θ�(�ֵ� thread�� ����, �쿬�� �Ѵ� �̸��� main �̴��� ����)

//�������� thread �鿡�� ���� ������ ��Ű�� ������ multi threading ���� ���α׷����� �ϰ� �ǰ�
//main thread �� �������� thread ���� �����ų �� ����

//main thread �� �ΰ����� thread ���� ������ų�� ���������� ������Ŵ, ��������� ���ÿ� ��� ���� ��� ǥ���ϴ�
//���� ������ �ȵ� 
//main thread �� ���쿡�� ������ �ڽ� thread ���� �ٽ� �ڽ� thread �� ������ ���� ����


//���� ��� 3000���� �۾��� �Ѵٸ� thread 0 �� 1000��, thread 1 �� 1000��, thread 2 �� 1000 ���� 
//������ �۾��� �� ����
//thread ���� ���� ������ ���α׷��ΰ�ó�� �۵���
//�� thread �� ���� ���������� main thread ���� �� �� ����
//������� ���� ���������� �� �� ����

//���� ������ �ھ��� �ι������� processor ������ ��
//Utilization(�̿��) �� ���� pc ���� cpu �� ���ǰ� �ִ� ����


#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;	//mutual exclusion ��ȣ ����, ���� ���ǵ帮�� ��

int main()
{
	//�츮�� ���⿣ �ƹ� �۾��� ���ϰ� ������ �۾������ڿ��� ���� cpu �̿���� ���� �ö󰡴°��� �� �� ����
	//while (true) {}
	

	//�츮�� �̶����� ������ main() �ϳ��� ������( exe ������ �ϳ� �����Ű��) process �� �ϳ��� �����
	//process �ϳ��� �����ϴ°��� cpu �� logical processor �ϳ��� �����
	//logical processor �� �� Ȱ���ϸ� cpu �� 100% Ȱ���Ҽ� �ִٴ°��� multi threading


	//�۾������ڰ� �ƴ϶� std::thread �� �̿��� �ھ� ���� ��� ����
	cout << std::thread::hardware_concurrency() << endl;

	//���α׷��� ��� ��ǻ��, �� ��� �ھ ���� cpu ���� ������ ���� �� �� ���� ������
	//std::thread::hardware_concurrency()�� ���� �ھ� ������ ������ �޾Ƽ� ������ų thread ������
	//���� �� �� ����


	cout << std::this_thread::get_id() << endl;	//main() �� ����Ǵ� this thread �� id ���




	const int num_pro = std::thread::hardware_concurrency();

	cout << std::this_thread::get_id() << endl;

	//thread �� �����ϰ� �������� �ֱ�, �Լ�������, std::function, ���� �Լ� �� �� �� ����
	std::thread t1 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;		//main()�� �����Ų thread �� �ٸ�
		while (true) {}});	//���� �Լ� ����
	

	//�����Ű�� while(true) �� ���ѷ������� �ϴµ� ������ �߻��ǰ� ����
	
	//main() �� � thread ���� �۵��� ��, �� thread ���� �ٸ� thread �� �۵���Ŵ
	//���� ���� thread �� �����ִ� thread �� ������� �۵��ϰ� ��
	//������ ���� �����Ų thread �� �۵��� �ϸ鼭 ������ thread �� �ǻ�����ؾ� �ϴµ�
	//main() �� ��������, �̰��� ���� ���� join() ���
	//������ �۵��ϴ� ����� t1 �� ���������� ��ٸ�



	//�������� thread

	//t1, t2, t3 �� ���ÿ� ����ǰ� ����(���ü�(concurrency)) 
	//cout �� ������ ���ؼ� ������ ��µǰ� ����
	//cpu ��뷮�� �ö�, while �� �ϳ��ۿ� ��� �������� thread �� ���ÿ� ����ǰ� �־ ��뷮�� �ö�

	std::thread t2 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;		
		while (true) {}});

	std::thread t3 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});
	


	//�� ���� thread ���,vector ���
	
	vector<std::thread> my_threads;
	my_threads.resize(num_pro);			
	//�Ϲ������� �ϵ��� ������ �ִ� ���μ����� �� �ϰ� thread �� ���� ���ߴ°��� �Ϲ���������
	//���α׷��� ������ ���� thred ������ �����ϱ⵵ ��

	for (auto& e : my_threads)
		e = std::thread([]() {
					cout << std::this_thread::get_id() << endl;
					while (true) {}});

	//thread �� ���Ƽ� cpu �� 100% �̿�ǰ� ����

	//�۾��� �� �й��ؼ� ������ ȿ�������� �� �� ����
	//�׷��� ��� ������ ���ķ� ó���� ���� ����
	//�׷��� �Ϲ������� multi threading ���� �����ϰ� ���� �� ����




	//�̷��� ��� thread �� join() �ϴ°��� �Ϲ���
	//���빰�� while(true) �� t2 ���� ������ �ȵ�(t1 ���� �ɸ�)
	//t1.join();
	//t2.join();
	//t3.join();


	for (auto& e : my_threads)
		e.join();

	



	//���ڰ� ������ ����:

	//���������� ����
	auto work_func = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //100 milliseconds ���� �޽�
			//�����δ� �� �۾����� ���⼭ �����ų �� ����

			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
		}
	};

	//���������� ����
	work_func("JackJack");
	work_func("Dash");


	//������ thread, ���������� ����ǰ� ����
	//JackJack �� ����Ǵ� ���� Dash �� ������ �ȵǰ� ���� -> ��ȿ����
	/*
	JackJack 19724 is working 0
	JackJack 19724 is working 1
	JackJack 19724 is working 2
	JackJack 19724 is working 3
	JackJack 19724 is working 4
	Dash 19724 is working 0
	Dash 19724 is working 1
	Dash 19724 is working 2
	Dash 19724 is working 3
	Dash 19724 is working 4
	*/


	//multi threading
	auto work_func2 = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); //100 milliseconds ���� �޽�
			//�����δ� �� �۾����� ���⼭ �����ų �� ����


			mtx.lock();		//�ѹ��� �ϳ��� thread �� ���� �ڵ带 �۵���Ű�� ��, �ٸ� thread �� ������ ���
			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();	//�۵��� ������ Ǯ�������
		}
	};

	std::thread t1 = std::thread(work_func2, "JackJack2");
	std::thread t2 = std::thread(work_func2, "Dash2");


	//t1 �� t2 �� ���� �ϰ��ִµ��� main() �� ���� ���������� �ȵǴϱ� join()
	t1.join();
	t2.join();


	//����� ���������� JackJack2 �� ���ϰ� �ִµ��� Dash2 �� ���� ���ϴ°��� �� �� ����
	//�������� ���� ���ÿ� ó���Ѵٴ� �鿡�� ����� �۵��ϰ� ����
	/*
	JackJack2 10156 is working 0
	Dash2 9796 is working 1
	JackJack2 10156 is working 1
	JackJack2 10156 is working 2
	Dash2 9796 is working 2
	Dash2 9796 is working 3
	JackJack2 10156 is working 3
	JackJack2 10156 is working 4
	Dash2 9796 is working 4
	*/

	//�������� sleep �ϰ� �ִ� �κ�(������ ����� �ɼ��� ����) �� ���� �ص� ��������
	//����� �Ҷ���ŭ�� �����Ƹ鼭 ����� �ϰ� ����
	//std::mutex ���

	//cout << name << " " << std::this_thread::get_id() << " is working " << i << endl; �� ���ؼ�
	//mutual exclusion ����(lock() �� �ɾ���, ������ unlock())

	//���ϴ� ��� ������� �� ��µǰ� ����
	/*
	Dash2 11120 is working 0
	JackJack2 5764 is working 0
	JackJack2 5764 is working 1
	Dash2 11120 is working 1
	Dash2 11120 is working 2
	JackJack2 5764 is working 2
	JackJack2 5764 is working 3
	Dash2 11120 is working 3
	Dash2 11120 is working 4
	JackJack2 5764 is working 4
	*/

	//�� thread �� sleep ���� �����ٰ� ���� ������ ���� mtx.lock() ���� �ͼ� ��Ź���
	//�׷� �ٸ� thread �� ������, ����� �� ������ unlonk() �� �ϸ� �ٸ� thread �� �ͼ�
	//�ᱸ�� �����ϰ� Ǯ���ְ� ����

	//unlock() �� �����ָ� �������, ���� ���� lock guard, std::atomic ���� �� �ٷ�� ��



	return 0;
}

