//std::vector

//std::array �� array ��ſ� ���� ���ϰ� std::vector �� �����Ҵ�迭���� ���� ����
//vector �� �޸𸮸� ���� ���� �ʿ䰡 ����, ��� ���� ������ �ڵ����� �����  
//new �� delete �� ������� �ʾƵ� leak �� ���� ����, ���α׷����� �δ��� ������



#include<iostream>
#include<vector>

using namespace std;

int main()
{
	//std::array<int, 5> array;  //����� ������� ��
	std::vector<int> array;	//���� �Ҵ��� �Ǵ� �޸��̱� ������ ����� �ݵ�� ���� �ʿ� ����

	//�ʱ�ȭ
	std::vector<int>array2 = { 1,2,3,4,5 };
	cout << array2.size() << endl; // size ���

	std::vector<int>array3 = { 1,2,3, };
	cout << array3.size() << endl;

	std::vector<int>array4{ 1,2,3, };  //uniform initialization �� ��
	cout << array4.size() << endl;


	//����� �׶��׶� �ٲ� �� ����
	vector<int> arr = { 1,2,3,4,5 };

	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	//array ���� �ߴ��Ͱ� ������
	cout << arr[1] << endl;
	cout << arr.at(1) << endl;

	//vector �� �������� ���̸� ����ϰ� ����

	int* my_arr = new int[5];

	delete[] my_arr; // my_arr �� ����� ������ �� ���� ����

	//vector �� size()�� ���� ����� �� �� ����


	//resize �� ����
	arr.resize(10);

	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;
	//1 2 3 4 5 0 0 0 0 0

	cout << arr.size() << endl;  //10

	//���ϼ��� ����
	arr.resize(2);

	for (auto& itr : arr)
		cout << itr << " ";
	cout << endl;
	//1 2

	cout << arr.size() << endl; //2

	return 0;
}