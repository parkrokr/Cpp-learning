// ���� ǥ���� �Ұ� regular expressions

//�����α׷��ֿ��� ���� ���
//�̸��� �ּ�, �ڵ��� ��ȣ �� �پ��� ���ĵ��� ������ �� ����

#include <iostream>
#include <regex>		//c++11 ���� regular expressions �� ������ ������

using namespace std;

int main()
{
	//regex re("\\d*");		// �տ� \ �ϳ��� �ڿ� \ �� ��¥��� �ǹ�, \d �� ���ڳĸ� �Ǻ�
							//���� �ϳ��� �Ǻ�, �������� �ְ� ������ 
							//\\d+ ( 1�� �̻� �Է� ) �Ǵ� \\d* ( �Է��� �ȹ޾Ƶ� ������ ), �Ѵ� ������ �Էµ�

	//regex re("[ab]");		//[] �ȿ� �ִ� a �� b �� ������,a ok, b ok, ab not ok, a �� b������ ��������
							//������ �ȸ���
	
	//regex re("[[:digit:]]{3}");	//[[:digit:]] �κ��� \d �� ���� ������ ��, {3} �� 3���� ���缭 �ްڴ�
									//123456789 ó�� 3���̻� �Է����� ��� no match ��� �߱� ������
									// 123 456 789 �� ��� �ް� ����

	//regex re("[A-Z]+");		//A ���� Z ���� �Է¹ް� ������ 1���̻��̸� ok


	//regex re("[A-Z]{1,5}");		//A ���� Z ���� �ּ� 1��, �ִ� 5���� �ްڴ�


	regex re("([0-9]{1})([-]?)([0-9]{1,4})");	//[-]?��  - �� �־ �ǰ� ��� �ǰ� �ǹ�


	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))			//regex_match �� ������ �Է��� ��Ģ�� string �� �´��� �ȸ´��� �Ǵ�
			cout << "Match" << endl;
		else
			cout << "No match" << endl;


		// print matches
		//sregex_iterator �� �̿��� match �ϴ� �κи� ���
		//reference manual ����
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();

			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";		//match �Ǵ� �κи� ���
			}
			cout << endl;
		}
		cout << endl;


	}





	return 0;
}