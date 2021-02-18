//�۾� ( Task ) �۾� ��� �񵿱� ���α׷��� async, future, promise

//async �� future �� ������ �Ǿ����� �������� �׳� sequential �ΰ�ó�� �����

#include <iostream>
#include <future>		//async, future, promise
#include <thread>

using namespace std;

int main()
{
	// multi - threading	(thread-based parallelism)
	{
		int result;
		std::thread t([&] {result = 1 + 2; });		//thread �� �����ϰ� ����
		t.join();
		cout << result << endl;
	}
	//�������� ���
	//�ֱٿ��� thread �� ������ �� �ִ� ������ ������ �����ؼ� �� ������������
	//���������� scope �� �а� ��� �� �ȿ� �ִ� ����(result) �� ���� thread ���� �����ϴ°��� �Ϲ���
	//thread ���ַ� ���α׷����� ��



	// task-based parallelism
	{
		//std::future<int> fut = ...
		auto fut = std::async([] {return 1 + 2; });
		cout << fut.get() << endl;
	}
	//std::thread ��ſ� std::async �� �����, async(�񵿱���)
	//return �� ��, ��ġ return value �� fut �� �޴°�ó�� ����
	//1+2 ��ſ� �ð��� �� �����ɸ��� �۾��� �Ҷ� �ٷ� return value �� �޴°� ����
	//async(�񵿱���) �ϰ� main thread �� ����Ǵ°Ͱ� ������ �ȿ��� �۾��� �̷����
	//async �� thread �� �ٷ� �� �ִ� �ɼ��� �� ����, �Ϲ������� thread ���� async �� ��ȣ��


	//thread-based ���� thread�� �����ϰ� �����ϰ� � ���� ���� �������ִ°Ϳ� �� ������ ����
	
	//task-base ���� � ��,�۾��� �� ���ΰ��� ���ַ� ���α׷��� ��
		//return ���ִ� ���� ����(�ٷ�) ���� �� �ִ°��� �ƴ�(������ ����)

	//�׷��� auto fut �� std::future �� ���� 
	//std::future<int> fut = ... �� �۾�(�� �������� 1+2 ) �� ������ int �� �޾ƿ��ڴٴ� �ǹ�(��ġ int result)
	//int result �� thread �ۿ� �־ � ���� ������ �� �� ������
	//std::future �� async �� ����Ǵ� task �� ��Ȯ�ϰ� ���յǴ� ����

	//fut.get() �� return type �� ��Ȯ�ϰ� int ��, return ���ִ� ���� int type �̶�
	//���� fut.get() �� return �� �߻��ϱ� ���̶�� async �� task �� ������ return �� �߻��Ҷ����� ��ٸ�

	//muti threading �� thread �� task �� ���������� ��ٸ��� ������( t.join() )
	



	//future and promise
	{
		std::promise<int> prom;			//int type ���� ���ø�ȭ�Ǿ�����
		auto fut = prom.get_future();	//prom ���κ��� get_future() �� �������� ����,

		auto t = std::thread([](std::promise<int>&& prom)
			{
				prom.set_value(1 + 2);	//promise �� ��� ����� ���� �־��ְ� ����
			}, std::move(prom));
		

		cout << fut.get() << endl;		//prom �� set_value �� ���� ������� �޾��ֱ� ������ fut �� ��ٸ�
		t.join();			//thread �̱� ������ join() ���� ��ٷ������, fut.get() ���� ���� �־ ��� ��ȭ ����
	}

	//std::future �� async �����Ӹ� �ƴ϶� thread ������ ����� �� ����, ��� std::promise �� ���� �����ؾ���
	//�̷� ������ ���� �����ϱ� ������ ������ task-based parallelism, async �� ��ȣ��
	//��� �ͼ������� ����, �ֱ� multi threading �ڵ带 ���� �̷� future and promise �� ���� ����

	//auto t �� thread �� �ް� �ְ� future �� �ޱ� ���Ѱ� �ʿ��ؼ� prom �� ���İ�
	//prom �� � ���� �־��ָ� future �� �ߵ���
	
	//���� �Լ��� prom �� r value reference �� parameter �� �־���
	//promise �� ���簡 �ȵ�, �׷��� �ѹ��� ���Ǿ�� �ϱ� ������ r value reference �� �־��ִ°�
	//l value reference �� �־��ָ� �����߻�
	//prom �� r value reference �� �־��ֱ� ���� std::move() �� �̿��Ͽ� r value �� ����

	//thread ��ſ� async �� ���� ���� ������ �׷��Ÿ� promise �� ���� ������ ����




	//thread �� async ��
		//thread �� join() �� ���� ����ؾ� ��, ������ ���� main() �� ������ ���� �߻�
		//async �� join() �� ��� ������ ������ ����, �Ҹ��ڰ� �����°� �˾Ƽ� �������
		//async �� future �� ������ �Ǿ����� �������� �׳� sequential �ΰ�ó�� �����

	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});


		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;		//main thread �� �帧�� ���ƿ�
	}
	//async �� thread �϶� �۵��ϴ� ����� �ٸ�

	//f1 f2 �� async �϶�
	/*Main function
	async1 start
	async2 start
	async2 end
	async1 end*/

	{
		auto f1 = std::thread([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});


		auto f2 = std::thread([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		f1.join();
		f2.join();

		std::cout << "Main function" << endl;		//main thread �� �帧�� ���ƿ�
	}
	//join() �� ������
	/*Main function
	async2 startasync1 start*/	//��� ����
	//f1 �� f2 �� ����ִµ� main() �� ������ os �� ������ �Ǵ�
	
	//join() �� ������ ������ �����
	/*async1 start
	async2 start
	async2 end
	async1 end
	Main function*/


	//future �� ���� ������
	{
		std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});


		std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;		//main thread �� �帧�� ���ƿ�
	}
	/*async1 start
	async1 end
	async2 start
	async2 end
	Main function*/
	//async �� future �� ������ �Ǿ����� �������� �׳� sequential �ΰ�ó�� �����



	return 0;
}