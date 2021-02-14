// ������ ���� ��ġ �����ϱ�

//�� �پ��� ��ɵ��� reference manual ����

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>	//exit()
#include <sstream>

using namespace std;

int main()
{
	const string filename = "ch18_07_my_file.txt";

	//make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	//read the file
	{
		ifstream ifs(filename);

		ifs.seekg(5); //ifs.seekg(5, ios::beg);			//5 byte �̵��� ������ �о�鿩��
		cout<<(char)ifs.get()<<endl;					//f

		ifs.seekg(5, ios::cur);				//���� Ŀ����ġ(�о���̴���ġ) ���� 5 byte �̵��ؼ� �о��
		cout<< (char)ifs.get() << endl;					//f�� ���� ���� 5 ĭ�̶� l �� �о���


		//ifs.seekg(-5, ios::end);			//���������κ��� �Ųٷ� 5 byte

		//ifs.seekg(0, ios::end);			//end �κ��� 0 byte, �� ������
		//cout << ifs.tellg() << endl;		//tellg()�� ������ġ�� �˷���,���ĺ�26 ���� endl ���� 27 �� 28�� ��µ�


		string str;
		getline(ifs, str);					//Ŀ����ġ�κ��� ���������� �о��

		cout << str << endl;				//mnopqrstuvwxyz
	}


	//������ ��� �б⵵ �ϰ� ���⵵ �ϱ�
	{
		//�׳� fstream ���� �ʱ�ȭ �ϸ� ��
		fstream iofs(filename);
		
		//fstream iofs(filename, ios::in | ios::out);
		//�̷��� �÷��׸� �����ص� ������ ��κ��� ��� ��� in,out �۵���
		

		iofs.seekg(5);						//5 byte �̵�
		cout << (char)iofs.get() << endl;	//read			//f�� ��µ�

		iofs.seekg(5);						//5 byte �̵�
		iofs.put('A');						//write			//������ ���� f�� �־�� �� �ڸ��� A �� �����������
	}



	return 0;
}