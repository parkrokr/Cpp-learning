//����� �Լ� ȣ�� Recursive Function Call

#include <iostream>

using namespace std;

//�Է��� ���ڷκ��� 1�� �پ��鼭 ����ϴ� �Լ�
void countDown(int count)
{
	cout << count << endl;

	if(count > 0)  //���� ���� : 0 ���� ����ϰ� �Լ����� �ϳ��� ������ ����
		countDown(count - 1);  // �ڱⰡ �ڱ⸦ ȣ��

	//��͸� �Ҷ��� �ݵ�� ���� ������ �־����
	//��Ͱ� �ʹ� ������ stack overflow �� �� ����
	//stack overflow �� �ʹ� ����Ǹ� ch7_11 �� ���� vector�� stack ó�� ����ϴ� ����� ����
}

// �ڵ�� �޸𸮿� ����Ǿ� �ְ� �Լ� ȣ���Ҷ��� �ּҷθ� ȣ���ϱ� ������
// �ڱ� �ڽŵ� ȣ�� �� �� �ִ°� ����


//���ڸ� ���س����� �Լ�
int sumTo(int sumto)
{
	if (sumto <= 0)
		return 0;
	else if (sumto <= 1)
		return 1;
	else
		return sumTo(sumto - 1) + sumto; // sumto + (sumto -1) + (sumto -2) + . . .

	//�̷��� ����ؼ� ���°� �ӽ÷� ������ �����ϸ� ����� �Ҷ� ���� ����
	/*else
	{
		const int sum_munus_one = sumTo(sumto - 1);
		return sum_minus_one + sumto;
	}*/
}


//�Ǻ���ġ ����
// 0 1 1 2 3 5 8 13 21
int fibonacci(int n) // n��° �Ǻ���ġ�� ��ȯ
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
	
}


int main()
{
	//�Է��� ���ڷκ��� 1�� �پ��鼭 ����ϴ� �Լ�
	countDown(5);

	//���ڸ� ���س����� �Լ�
	cout << sumTo(10) << endl;

	//�Ǻ���ġ ����
	cout << fibonacci(10) << endl; // 10��° �Ǻ���ġ ��



	//Recursive ���
		// ���� �����ϱ� �� ����
		// Iteration�� �޸� stack�� ����ؾ� �ϱ� ������ ȣ���Ҽ� �ִ� depth �� ��踶�� �ٸ��� �Ѱ谡 ����
		// �����ս��� �߿��� �ڵ忡�� ��� ���ϴ°� ���� �� ����


	//Iterative �ݺ�
		// �����ϸ� Recursion �� Iteration ���� �ٲ㼭 ����


	return 0;
}