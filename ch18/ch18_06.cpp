// �⺻���� ���� �����

//���� ������� ����ó���� ����Ǵ� ������ ���ؼ� �����ϰ� ó���� �ʿ䰡 ����

//�ƽ�Ű �������� �����͸� �� �����ϸ� ��û �������� ��
//binary ������ �޸��尰�� ���� ���α׷����δ� Ȯ���� ����
//�׷��� �̷� binary ����� ������ �ٷ궧�� ����뿡 �Ű��� �����

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		//exit()
#include <sstream>

using namespace std;

int main()
{
	//�ƽ�Ű ���� ���� ����, �б�
	//"ch18_06_my_first_file.dat" ������ ������ Ȯ���ڸ��� .dat ���� ���� �ƽ�Ű ���信���� .txt �� ���� �����

	//writing
	if (true)
	{
		//output file stream

		//�������� paramter �� ���ϸ��� �ֱ�
		ofstream ofs("ch18_06_my_first_file.dat");		
			//my_first_file.dat�� ������ ������ �������
			//�����Ѵٸ� �� ������ ������ �ְ� ���������� ���� ������� ����
			//ios::app (append), ios::binary ���� �÷��׸� ����� ����� ������ �� ����

		//ofstream ofs("ch18_06_my_first_file.dat", ios::app); //append ���
			//������ �̹� �����Ұ�� �� �ڿ� �̾ �۾���, Line 1\n Line 2 �� ��� ���ٿ���

		
		//ofs.open("my_first_file.dat");		//�̷��� ������ open() ���� �� �� ����
												

		if (!ofs)		//������ ���� ���ϸ� ��� ���
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}
		//���� ������� ����ó���� �̷��� ����Ǵ� ������ ���ؼ� �����ϰ� ó���� �ʿ䰡 ����

		
		//���ݱ��� ����ؿ� stream �� ����� �״�� ���� ����� �� �� ����
		//�ƽ�Ű ����
		ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;
		//�̷��� output operator �� ����ϰ� �Ǹ� �ƽ�Ű ���信 ���缭 text ���� ������ ��
		//�޸������� ���������, ����� Line 1 \n Line 2 �� ����� �Ǿ��ִ°� �� �� ����


		//binary ����

		//binary �� �����Ҷ��� �����Ͱ� ���������� �� �� ����
		//� �����Ͱ� ���ŭ ������ ���� �̸� ����� �ؼ� �˰� �־�ߵ�

		//�����Ͱ� ����� ������ �ؼ� ����ϰ� ����
		/*const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));	// num_data�� char* �� ĳ�����ؼ� write() �� �ְ� ����

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));	//10���� data �� �����ϰ� ���� (0���� 9���� ���ڸ� ����)
		*/



		//����� data �� ���ڿ� �ϳ��� ��Ƶΰ� �����ϴ� ��쵵 ����
		/*stringstream ss;
		ss << "line 1" << endl;
		ss << "line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)&str_length, sizeof(str_length));	//string �� size �ֱ�
		ofs.write(str.c_str(), str_length);*/



		//ofs.close();		//not necessary, ��κ��� ��� ���� �ȿ��� �ڵ��ϱ� ������ ���� ���� �����
							//�ڵ����� �Ҹ��ڰ� ������ �ݾ���
	}



	//reading
	if (true)		//if �� ���� ���� ������ ���ؼ� ����� ��
	{
		//input file stream

		ifstream ifs("ch18_06_my_first_file.dat");		//file �̸��� ��Ȯ�ϰ� �־������
		//��Ȯ�� �̸��� �ƴϸ� �ؿ� if ���� �� ���� ����� ������ ����
		//�̸��� ����ϰ� Ʋ���� �� ������ �ð��� ���� ��ƸԱ⵵ ��, �Ĳ��ϰ� Ȯ���ϴ� ���� ���̱�

		if (!ifs)
		{
			//���� ���ϸ� ���� �߻�
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		//�ƽ�Ű �б�
		while (ifs)		//������ �� ������ ifs �� false �� ��ȯ��
		{
			std::string str;
			getline(ifs, str);		//���پ� �о��

			std::cout << str << endl;
		}

		//�޸������� "ch18_06_my_first_file.dat"�� ���� ��� ���� Hello World �� �߰��ص�
		//������ �� �о���




		//binary �б�
		/*
		//���� num_data �� �о data �� � �ִ��� Ȯ���� ��
		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		//�о���̱�
		for (unsigned int i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));		//read() �� �а� ����

			std::cout << num << endl;				//����� �о����� ���
		}
		*/



		//� ��쿣 ���ڿ� �ϳ��� ��Ƶΰ� �����ϰ� �б⵵ ��
		//string �� size �� �̸� �о���̰� data �� �б�
		/*unsigned str_len = 0;
		ifs.read((char*)&str_len, sizeof(str_len));

		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;*/

	}

	return 0;
}