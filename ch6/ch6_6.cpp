//C��� ��Ÿ���� �迭 ���ڿ�

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	//�迭�� �Ȱ��� ����� ó���� �� ���� ���� ����ó ó�� type �� �������� ����

	char myString[] = "string"; // �������� \0(null character) �������

	cout << sizeof(myString) / sizeof(myString[0]) << endl;

	for (int i = 0; i < 7; ++i)
	{
		cout << myString[i] << '\t' << (int)myString[i] << endl;
	}


	//cin ���� �б�
	char my_String[255];

	//cin >> my_String;

	// ��ĭ�� �Է��ϰ� ������    (��ĭ�� null character �� �ٸ�)
	cin.getline(my_String, 255);

	//my_String[4] = '\0'; //4��° ���� ���� ��� x , cout �� null character�� ������ ������ ����ϱ� ����

	cout << my_String << endl;

	int ix = 0;
	while (1)
	{
		if (my_String[ix] == '\0')break;

		cout << my_String[ix] << " " << (int)my_String[ix] << endl;
		++ix;
	}


	//�������� C style ���ڿ�
	char source[] = "Copy this!";
	char dest[50]; 


	//���ڿ� ����
	//strcpy(dest, source); // destination�� size �� �����ϸ� runtime error �߻���

	strcpy_s(dest, 50, source); //destination memory size�� �Ȱ��� parameter�� �Է��ؾ���, _s �� secured �ǹ�


	cout << source << endl;
	cout << dest << endl;


	//strcat()  //�� ���ڿ� �ڿ��� � ���ڿ��� �ٿ��ִ°�
	//strcmp{}  //�� ���ڿ��� �������� �񱳸� �ϴ°�

	strcat(dest, source);

	cout << source << endl;
	cout << dest << endl;


	// * strcmp function �� ������ 0, �ٸ��� -1 return  
	cout << strcmp(source, dest) << endl;

	//strcat(),strcmp() �����غ���

	return 0;
}