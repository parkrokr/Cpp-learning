//std::string �� ���̿� �뷮

//std::vector ���� ���̿� �뷮�� ������ ���, std::string �� ��������
//vector ó�� reserve() �� ���� �̸� ������ Ȯ���� �� ����

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("012345678");

	cout << my_str.size() << endl;		//9

	//c style ���ڿ����� �ڿ� null character �� �ϳ� ���������� 
	//string ������ ���� ����, 
	
	//string ���ο��� ���̸� ���� ������ �־ ���ڿ��� �������� �ȳ������� null character �� ã�� �ʿ䰡 ����

	
	cout << std::boolalpha;				//true false �� ������ �ٲ�
	cout << my_str.empty() << endl;		//������� �Ⱥ������ üũ��, ������ �Ⱥ�������� false


	string my_str_("");					//null char �� �ϳ� ���� ����, const char[1]
	cout << my_str_.empty() << endl;	//true, �������, c style ���ڿ��� �ٸ��� null char �� �������� ����

	// "" �� null char �� ���ִ� ���� ���� ���ڿ�( const char[1] ) �̶�
	//c style ó�� ���ڿ� �迭 char my_str[] �� ������ const char* my_str �� �ٷ�� 
	//null character �ϳ��� ���������
	//std::class ���� null character �� ������� �ʱ� ������ string my_str_("") �� size �� 0 �� ��




	//capacity �뷮
	string my_str_s("01234567");
	
	cout << std::boolalpha;
	cout << my_str_s.length() << endl;			//8
	cout << my_str_s.size() << endl;			//8
	cout << my_str_s.capacity() << endl;		//15


	//capacity �� �����Ϸ��� os ��Ȳ�� ���� �ٸ�
	//string �� vector ó�� ���� �����Ͱ� �߰��� ���ɼ� ������ �������̸� �޸𸮸� ���Ҵ� ���� �������� ��
	//new �� delete �� �ּ������� ������ �ϱ� ���� ������ �뷮�� �δ°���
	
	
	//capacity �� �ø��� ���� ���( ������ �ø��� ���� ���)
	my_str_s.reserve(1000);						//reserve() �� 1000���� �뷮 Ȯ��
	//������ 1000���� �¾ƶ������� ����, �ּ��� 1000���� ��ƴ޶��� ����



	cout << my_str_s.max_size() << endl;		//���ڰ� ����� ���°�, capacity �� max ��
	
	//�������� ��Ȳ�� ���� max_size �� ���� �޶���(x64 ���� �� �ö�)

	
	return 0;
}