//std::string �� ���� �����ϱ�� �迭���� ��ȯ


//my_str[100] = 'X';		//performence �� �߿��� ��� ���,����ó�� ����,����ڰ� ������ ���ؼ� �Ű����ߵ�
//my_str.at(100) = 'X';		//�������� �߿��� ���, ����ó���� ���� ��� performence �� �� ������


//string ��ü���� null character �� ������� ����
//c_str() �� �����ö��� �ڿ� null character �� �ϳ� �ٿ���, ��ġ c style ���ڿ�ó�� ����� �� �ְ� ������ִ°�
//c_str() �� ����� std::string::data �� ����, ���� ���, ���Ǿ���

//copy() �� string ���� c style array �� �����ö��� null character �� ���� ������ 
//���� null chracter �� �ϳ� �־������


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string my_str("abcdefg");
	
	cout << my_str[0] << endl;		//a
	cout << my_str[3] << endl;		//d

	my_str[3] = 'Z';				//�ٲ�ġ��

	cout << my_str << endl;			//abcZefg



	//string ���� [] ������ �����ε��� �Ǿ������� ����ó���� ������
	//����ڰ� �Ű��� ��� �ϰ�, assert �� ������ �ְ� at() �� ����ϸ� throw �� ���ְ� ���� �� ����
	//vector ������ �Ȱ���
	//std::exception  ch14_04 ����
	
	//my_str[100] = 'X';		//performence �� �߿��� ��� ���,����ó�� ����,����ڰ� ������ ���ؼ� �Ű����ߵ�
	//my_str.at(100) = 'X';		//�������� �߿��� ���, ����ó���� ���� ��� performence �� �� ������

	try
	{
		//my_str[100] = 'X';				//runtime error �߻�
		//����ó���� ������ �ϳ��� ����ó���� �ϸ� ������
		//�׷��� �� ǥ���� ����ó���� �ϸ� ��������� ����ó���� �����ذ���


		//my_str.at(100) = 'X';				//����ó���� �ִ� at()
		//�̶��� ���ܸ� ����� �߻���Ŵ

	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;			// invalid string position
	}




	//string �� c style ���ڿ��� �ޱ�
	cout << my_str.c_str() << endl;			//abcZefg ��µ�

	// my_str.c_str() �� �������̱� ������ �̷��� �ѱ��ڸ� ��� ����
	cout << my_str.c_str()[6] << endl;		//g	


	const char* arr = my_str.c_str();		// arr �� �޾Ƽ� ����ϱ�
	cout << arr[6] << endl;					//g
	cout << arr[7] << endl;					//��ĭ

	cout << (int)arr[6] << endl;			//103
	cout << (int)arr[7] << endl;			//0			�� null character


	//string ��ü���� abcZefg �� ����ǰ� null char �� ������� ����
	//c_str() �� �����ö��� �ڿ� null char �� �ϳ� �ٿ���, ��ġ c style ���ڿ�ó�� ����� �� �ְ� ������ִ°�
	
	//c_str() �� ����� std::string::data �� ����, ���� ���, ���Ǿ���


	//c style array �� �ٲٴ� �ٸ� ��� : copy �ϱ�

	char buf[20];				//data �� ���� char array �� �ϳ� ����

	my_str.copy(buf, 5, 0);		//my_str ���� 0 ���� 5���ڸ� buf �� copy, ������ null char �� �ڵ����� �ȳ־���

	buf[5] = '\0';				//null character �־��ֱ�

	cout << buf << endl;		//null character �ȳ־��ָ� ������, abcZe

	return 0;
}