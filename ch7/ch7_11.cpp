//std::vector �� ����(stack) ó�� ����ϱ�

//new �� delete �� ���� ������ ������ size �� capacity �� �ٸ��� ����Ҽ� �ִ� �ٸ� ������ ������ ����
//reserve �� �̿��ϸ� �̸� �޸𸮸� Ȯ���� �� ����

#include<iostream>
#include<vector>

using namespace std;


void printStack(const std::vector<int>& stack)
{
	for (auto& e : stack)
		cout << e << " ";
	cout << endl;
}


int main()
{
	std::vector<int> v{ 1,2,3 };
	// ���������� int *v_ptr = new int[3]{1, 2, 3}; �� ������(�������� ����)


	//vector ���� size, capacity(�뷮) �� ����

	//������ �ڵ� ���ο��� capacity ������ŭ �޸𸮸� ������ ����
	//���߿� size ������ŭ �����

	//heap �� �޸𸮸� �������� ��� ������ ��ƾ� �ϴ��� �����Ҷ� ���� �������� ��
	//heap �� new �� delete�� �ϴ°� ���� ���� (������ �Ⱦ��°� ����)
	//vector �� ���������� new �� delete�� ����ϱ� ������ vector �� �� ����ϴ� �����
	//���ο��� �̷������ new�� delete�� ���� ȣ��ǰ� �����ϸ鼭 ����ϱ�

	//for(unsigned int i = 0;i<v.size();++i)
	for (auto& e : v) //modern c++ style
		cout << e << " ";
	cout << endl;

	cout << v.size() << endl; // 3 , size �� ���缭 for-each �� ��

	//resize(10)
	v.resize(10);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;  // 1 2 3 0 0 0 0 0 0 0 

	cout << v.size() << " " << v.capacity() << endl; // 10 10

	//resize(2)
	v.resize(2);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;  // 1 2 

	cout << v.size() << " " << v.capacity() << endl; // 2 10

	//size �� �޶������� capacity �� �����ϴ°��� �� �� ����

	
	//v[2] �� ������ ���� �õ�
	//cout << v[2] << endl; //runtime error!
	//cout << v.at(2) << endl; // abort() has been called  ��Ÿ�� ����
	
	int* ptr = v.data(); //�����͸� ������ �� ����
	cout << ptr[2] << endl;  // 3 �� ��µ�

	//resize�� ������ �ӵ��� ���̱� ���� ���������� resize�� �Ҷ� 
	//�޸𸮴� �״�� ������ �ְ� resize �Ѱ͸� ������ �׷��� capacity �� �����Ǵ°�

	//modern c++ style
	for (auto& e : v) 
		cout << e << " ";
	cout << endl;

	//���� ��Ÿ��
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//resize �ϸ� 0���� ä������

	//capacity �� Ű���
	v.reserve(1024); // �޸��� �뷮�� �̸� Ȯ���� ���ڴ�

	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl; //1 2  (0 �� �Ⱥ���)

	cout << v.size() << " " << v.capacity() << endl; // 2  1024

	//reserve�� �ϴ� ����
	//���Ұ� �߰��� �ɶ� reserve �� ������ ���� ���������� ���� �޸𸮸� �޾ƿ��� ��ü�ϴ� �۾��� ��������
	//�׷��� �� ������


	//stack ó�� ����ϱ�
	std::vector<int> stack; 

	//stack.reserve(1024); //�̸� reserve �صθ� Ȯ���� ������

	//vector �� �̿��� push �� pop �ϱ�
	stack.push_back(3);
	printStack(stack); // 3

	stack.push_back(5);
	printStack(stack); // 3 5
	
	stack.push_back(7);
	printStack(stack); // 3 5 7


	stack.pop_back();
	printStack(stack); //3 5

	stack.pop_back();
	printStack(stack); //3

	stack.pop_back();
	printStack(stack); // 3���� ������ �ƹ��͵� ��� �ȵ�

	//vector �� �̿��� stack �� �����ϴ� ����
	//reserve�� �̿��ϸ�  push_back �Ҷ� capacity �� �ø� �ʿ䰡 ���� ������
	//new �� delete�� ȣ���� ���� ��� ������ �� ����
	//pop_back �� �Ҷ��� capacity�� ������ü size �� ���̱� ������ ȿ���� �� ����

	//���� : reserve �� �ʹ� ũ�� �ϸ� capacity �� �ʹ� Ŀ�� �޸𸮰� ����� �� ����


	return 0;
}