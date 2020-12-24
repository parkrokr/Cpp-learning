//�޸� ���� �Ҵ�(Dynamic Memory Allocation)  new �� delete

#include <iostream>

using namespace std;

int main()
{
	//int array[1000000];
	//stack overflow �߻���
	//���α׷����� �������� �Ҵ��ϴ� �޸𸮴� stack �� �� , stack �� ����� ����
	//�������� �Ҵ�Ǵ� �޸𸮴� hip�� �� , ����� ŭ
	//->���� �Ҵ��� ����ؾ� hip�� ���� �޸𸮸� ũ�� ���� �� ����
	//�޸𸮰� �����Ǵ� ������ ������ �߻� �� ���� ����


	//������ ����ϴ� ���
	//int var = 7;


	//�ٸ� ���
	//new int �� os���� int ����� ���� �޸𸮸� �޾ƿ� ������ �� �޸� �ּҸ� �˷���
	//�����ͷ� �޾ƾ� ��
	int* ptr = new int;
	int* ptr2 = ptr;

	//�޸𸮸� �Ҵ� �޾ƾ� �ϴµ� �� ���� ���� ����(�ٸ� ���α׷��� �޸𸮸� �� ���� �־ ���)
	//new �� ������ �����ѵ� ���;� ��
	//std::nothrow �� ���� ������ ����Ű�� �ʰ� ��Ƽ�� ����
	//int* ptr = new(std::nothrow)int{ 7 };


	*ptr = 7;

	//�����ͷ� �޸� �ּҸ� �޾ƿ��鼭 ���ÿ� �ʱ�ȭ�� �� ���� ����
	//int* ptr = new int{ 7 };
	//int* ptr = new int(7);

	if (ptr) //if���� ���� �� �����ϰ� �� �� ����
	{
		cout << ptr << endl;  //�ּ�
		cout << *ptr << endl;  //7
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	//os���� �޸� �ݳ��ϱ�  
	//�����Ͱ��� ���� �޸𸮸� ����ؾ� �ϴ� ��� �ݳ����� ������ ��ǻ�Ͱ� �������� ����
	//delete ptr; �� ������ ���α׷��� �������� os�� �޸𸮸� ȸ���ذ�
	delete ptr;
	ptr = nullptr;


	// ptr2 = nullptr; ���� *ptr2 �ϸ� ������ �߻��� ->�Ĳ������ų� ����Ʈ�����͸� ����ϰų�


	//������ �� �� �ִ� ���
	/*cout << "After delete" << endl;
	cout << ptr << endl; 
	cout << *ptr << endl;*/

	//delete ptr ���Ŀ��� ptr�� ����� �ּҰ��� ���� �� ���� ����
	//(���� �������� ���������� ���� �� ȯ�濡�� ���� �ȵ�)

	//�����ϱ� ���� delete ptr ������ ptr = nullptr; �Ǵ� ptr = 0; �Ǵ� ptr = NULL; ó�� �ּҸ� �����


	//ptr �� �������� �ʰ� �ǹ̰� ���������� de-referencing �� �ϰ� �ϴ� �ڵ�
	cout << "After delete" << endl;
	if (ptr != nullptr)  //if(ptr) �� ���ϼ��� ����
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}





	//memory leak 
	while (true)
	{
		int* l_ptr = new int;
		cout << l_ptr << endl;

		delete l_ptr; // delete �� ���� ������ ��� �޸𸮸� ������ 
	}



	//new �� delete �� ����(os���� ���� �;� �ϱ� ������)
	//new �� delete�� ���� �Ƚ�� ����, ��� c++���� new �� delete�� ����
	//�޸𸮸� ���� ������ �� �ֱ� ������ ����ȭ�� ����

	return 0;
}