// ���̽� ����� ( Race Condition ) , std::atomic, std::scoped_lock

//muti threading �� �ϳ��� �޸� ������ ���� thread ���� �Բ� ����ϰ� ���� �� �ֱ� ������
//�ٸ� ����ó�� ����� ���ؼ� �����ϱ� ����
//��� �� ����(���� �޸� ������ ���)�� ������ �Ǿ ������ �ɼ��� ����( ���̽� ����� )

//���ǿ��� ���������� �۵��� �ϱ� ������ ������ �߻��Ѵٴ°��� �������� ���� ���� ����

#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

//���� �޸𸮸� ���� �ϳ���� ����
//�����δ� ���� �ϳ��Ӹ� �ƴ϶� �� Ŀ���� �ڷᱸ���� ��������
//�������� thread ���� ���ÿ� ������ �� �ִٴ°��� �����ϱ� ���� �������� ����
//main() �� �־ ��, ��� ���� �Լ� ���𿡼� [&] �� �ؾߵ�
//int shared_memory(0);


//���̽� ����� �ذ��� 2: mutex lock() ���
mutex mtx;

int main()
{
	int shared_memory(0);
	//atomic<int> shared_memory(0);		//���̽� ����� �ذ��� 1: atomic ���


	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::microseconds(1));	
			//sleep_for �� ������ �������� thread ���� �ѹ��� ���� ������ ������ �Ⱥ��� ���� ����
			//�� sleep_for �� ������ ������ ������°��� �ƴ϶� ������ �Ⱥ��̴°���
			//t1 �� �����ǰ� t2 �� �����Ǳ� ���� ������ �������� -> ����ó���� �̷������ ����
			//����ó���� ��������߿� �ϳ��� ������ ������°�(���°�, debut) ��ü�� ����� ���� ����
			

			//mtx.lock();		//�ذ��� 2: mutex lock ���, ��� �ݵ�� unlock() �ؾߵ�

			//std::lock_guard lock(mtx); //�ذ��� 3
			//c++17 ���� ����, �� ���� std::lock_guard<std::mutex> lock(mtx);

			std::scoped_lock lock(mtx);	//�ذ��� 3_1

			shared_memory++;
			// shared_memory �� atomic<int> �϶� ++ �� int �� �����ڰ� �ƴϰ�
			// atomic<int> �� �����ε��� ��������(���ǰ� ���� �Ǿ�����)
			//���� : int �� ++ ���� ������
			
			//shared_memory.fetch_add(1);	//++��ſ� ����� �� ����

			//mtx.unlock();		//�ذ��� 2: lock() �� ����ϴ� ��ſ� unlock�� �ݵ�� �ؾߵ�
		}
	};

	thread t1 = thread(count_func);

	thread t2 = thread(count_func);		//t1 �� t2 �� ���ÿ� ������ �޸𸮿��� �۾��� ��

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	//1�� 1000�� ���ϴ� 1000 �� ����( thread �� �ϳ��϶� )

	//t1 �� t2 �� ���ÿ� ������ �޸�(shared_memory) �� �۾��� �ϴ� 2000�� ���ð��̶�� ������
	//������ 2000 �� ��Ȯ�ϰ� �ȳ���
	
	//cpu �� shraed_memory ���� �о -> cpu ���� ���� �ϳ� ���� -> ������ ������� shared_memory ������ ������
	//����� 3�ܰ�� �̷����
	// t1 �� cpu �� �о�帰 ���̿� t2�� ���� �ٲ������ t1 �� ��� ���� ������� �̹� �ٲ���־
	//���ϱ� �ϳ��� ����� ��


	//�ذ��ϴ� ��� 1:
	//std::atomic, �ɰ� �� ���� ��� �ǹ�, ���� 3�ܰ踦 �ѹ��� ����(������ ���ϰ�) ����
	//atomic<int> �� ����ϸ� 2000 �� ��Ȯ�ϰ� ����
	//���� : int �� ++ ���� ������, �׷��� atomic�� ���� �����ϸ� ȿ���� �ް��� ������


	//�ذ��ϴ� ��� 2:
	//mutex lock() ���, ���ÿ� �������� thread �� ���� ����, �ϳ��� thread �� ���� ����
	//unlock() �� �ݵ�� ����ߵ�
	//���α׷��Ӱ� ����� ���� �ְ�, ����ó���� �߻��Ҷ� �ǳʶۼ��� ����(�޸� �ݳ� �ȵǴ� ����ó��)
	

	//�ذ��ϴ� ��� 3:
	//std::lock_guard ���
	//std::lock_guard lock(mtx); �� C++17 ���� ����, �� ������ std::lock_guard<std::mutex> lock(mtx);
	//������ ����� ���� lock�� �ڵ����� Ǯ��
	//��κ��� ��� mutex �� ���� lock �� �Ŵ°ͺ��� lock_guard ����� ����

	//�ذ��ϴ� ��� 3_1;
	//std::scoped_lock ���		C++17 ���� ����
	//lock_guard ���� �� ������, lock_guard ���� ����


	return 0;
}