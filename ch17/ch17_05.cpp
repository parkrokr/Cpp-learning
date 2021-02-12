// std::string	����, ��ȯ, �����̱� ( append ) , ����

//���� �Լ����� �����ε��Ǿ� �־ �ʿ��ϸ� ã�� ���� ��
//�����Ǿ����� ������� ���¼ҽ������� ���� �����Ǿ� ����
//��κ��� ��� std::algorithm �� �����ϸ� �ذ��

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//�ʱ�ȭ �ϴ� �������� �����
	string str1("one");

	//���������� �����Ǵ� ���� ��κ��� ����� ��
	string str2;
	str2 = str1;
	str2 = "two";

	cout << str2 << endl;	//two
	
	//assign()
	//assign() �� return type �� string & ��, �ڱ��ڽſ� ���� ref ��ȯ
	//iterator �� ��밡��
	str2.assign("two");		
	str2.assign("two",2);	//���� 2���ڸ� ������, ch17_02 ����
						
	cout << str2 << endl;	//tw



	//swap()
	string str3("three");
	string str4("four");

	cout << str3 << " " << str4 << endl;		//three four

	std::swap(str3, str4);

	cout << str3 << " " << str4 << endl;		//four three

	str3.swap(str4);		//string �� swap() �� ������ ����

	cout << str3 << " " << str4 << endl;		//	three four



	//append() 
	//�ڿ��ٰ� �����̴� �Լ�
	//�����ε��� �Լ����� ����
	//string �� �� �� ����
	str2.assign("two").append(" ").append("three ").append("four");		//chainning ����

	cout << str2 << endl;	//two three four

	//����ó�� ��� ����
	str2 += " five";		
	str1 = str2 + " six";

	cout << str1 << endl;	//two three four five six
	cout << str2 << endl;	//two three four five


	//push_back() 
	//str2.push_back("push");	//�̷��� ���ڿ��� ����
	str2.push_back('A');		//vector ó�� �۵��ؼ� ���� �ϳ����� ���� �� ����
	
	cout << str2 << endl;




	//instert()
	string str("aaaaa");

	str.insert(2, "bbb");	//"bbb" ��ſ� string �� ���� ��

	cout << str << endl;	//aabbbaaa




	return 0;
}