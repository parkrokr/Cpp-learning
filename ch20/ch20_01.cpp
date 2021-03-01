//����� ��Ʃ����� ��������(profiling) �ϱ�

//���� ����: debug ��忡�� ���, cpu usage, memory usage üũ, breakpoint ���� ���

//Performance profiler : release ��忡�� ���, ���� �����ս��� �� ������ ȯ�濡�� �������Ϸ��� �����°�
//���귮�� ���� ���� hotspot ã�� ����, ����ȭ�� ���� �Ǿ��ֱ� ������ debug ��庸�� �ڼ��� ����� ���� ���� ����


//���� ������ ���� ����ϰ� �����ս� �������Ϸ��� �����


#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>	//std::inner_proudct

using namespace std;

void func1()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000; ++i)
		sum += i;

	cout << sum << endl;
}

//func1() ���� ���귮�� 1000�� ����
void func2()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1000'000'000; ++i)
		sum += i;

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}

int main()
{
	//cpu �������ϸ�
	//��� ������ ���� ���� cpu ��뷮�� �����ϴ��� ã��
	run();
	//func1 �� 0.1 %, func2() �� 99.72 %  ����ߴٴ°��� Diagnostic Tools ����
	//Record CPU Profile �� ���� �� �� ����

	//��� ���� hot spot(������ �Ǵ°�) ���� ã�Ƴ��� profiler �� ������ ���� ��
	//���α׷��� sill ������ �ƴ϶� �˰��� �������� ����ȭ�� �ϴ°��� ���� ���α׷���


	//�޸�(��) �������ϸ�
	int* d = new int[10000];
	float* f = new float[100];

	delete[] d;
	delete[] f;

	//cpu �������ϸ��� �޸� �������ϸ��� ���ÿ� �����ų���� ������
	//���ÿ� ������ ��Ȯ���� ������ ���� ����
	//�����ϰ� �Ҷ��� ���ε��� �����°��� �����

	//heap profiling �� �ѵδ� ���� ����
	//	cpu usage �� �����Ҷ� ������ �ֱ� ������ ����ų�� �ְ� ����(��κ��� ��� ū ������ ����)

	//break point ���� memory usage �� Take Sanpshot �� ���� �޸� ��뷮�� �˾Ƴ� �� ����
	//count diff �� ���� ���� ���� �� ���̰� ������� �� �� ����



	//19.6 ��Ƽ ������ ���� ���

	//release ��忡�� �������ϸ� �ϴ°͵� �߿���, ����� ��忡�� ����׸� �ϱ� ���� ���������� ���ԵǾ� �־�
	//���� release ���� �����ս��� ���̰� ����
	//���ܵ����� �ƴ� Performance profiler ���(release ��忡���� ��밡��)
	//cpu sampling ���(��õ)
	//�������ᰡ �Ǿ �������ϸ��� ��

	//inclusive samples �� �Լ��� �Լ��� ȣ���Ҷ� �� �����ϰ� exclusive samples �� �ι�° ȣ��Ǵ� �Լ��� ��

	//������ ���� ������ ���� �����

	
	
	return 0;
}