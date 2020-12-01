//������ Enumerated Types

#include<iostream>
#include<typeinfo>
#include <string>

//���⿡ ���� ���ط��� int�� ��ȯ�ϴ� �Լ�
int computeDamage(int weapon_id)
{
	if (weapon_id == 0) // sword
	{
		return 1;
	}
	if (weapon_id == 1) // hammer
	{
		return 2;
	}

	// . . .

	//�Ǽ��� �������� ���
}


// ������
enum Color // user-defined data types
{
	COLOR_BLACK, // 0 , COLOR_BLACK = -3, �� �ϸ� COLOR_RED�� -2 �� ������ �ϳ��� ���ڰ� �ö�
	COLOR_RED,   // 1
	COLOR_BLUE = 5,
	COLOR_GREEN = 5,//COLOR_BLUE��  COLOR_GREEN�� �Ѵ� �������� �����ϸ� ������ �� ���� ��
	COLOR_SKYBLUE// ,�� �������ٿ� ��� ��,������ ��� �ȵǾ���
	//BLUE,
};
// { } ������ ; ���� ��

enum Feeling
{
	HAPPY, // ���� �빮�ڷ� ħ
	JOY,
	TIRED,
	BLUE, //enum�� ���� ����ó�� �۵��ϱ� ������ �ٸ� {}���� ������ ��
};

// enum class �� c++ 11 �� ����




int main()
{
	using namespace std;

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED }; // Ư���� ���� �޶� ������ �ʿ䰡 ����

	Color my_color = COLOR_BLACK;

	cout << my_color << " " << COLOR_BLACK << endl;
	cout << COLOR_RED << endl;


	// �������� ���ڸ� �Ҵ��Ҽ� ������ �Ǽ��� ���� ���ڸ� �Ҵ��ϸ� ������ ���� �� ����
	if (COLOR_BLUE== COLOR_GREEN)
	{
		cout << "Equal" << endl;
	}
	//�⺻ �Ҵ� �� ���ڸ� ���°� ����


	//���������� ������ ó�������� ����ó�� ����� �Ұ���
	int color_id = COLOR_RED;

	// Color my_color1 = color_id; //�Ұ���
	//Color my_color1 = 5; //int �� �ٷ� �ִ°� �Ұ���, �ʿ��� ��� casting �� ����
	Color my_color1 = static_cast<Color>(5);

	cout << color_id << endl;


	//�Է�
	//cin >> my_color; �ٷ� �޴°� �Ұ���

	//��ȸ�ؼ� �޴°� ����
	int in_number;
	cin >> in_number;

	if (in_number == 0) my_color = COLOR_BLACK;
	if (in_number == COLOR_BLUE) my_color = COLOR_BLUE;
	if (in_number == static_cast<Color>(0)) my_color = static_cast<Color>(0);
	// . . .
	
	cout << my_color << endl;

	
	//string ���� �ް���� ���
	string str_input;

	getline(cin, str_input);

	if (str_input == "COLOR_BLACK") 
		my_color = static_cast<Color>(0);

	//�������� ����, ����̱� ������ �Ǽ��� �� ����



	//������ enum�� �ٸ������� ���� ���� ��� forward declatraion ���� header ���� �ȿ� �� �־�ΰ� include �ؼ���



	return 0;
}