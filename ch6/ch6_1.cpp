// �迭 Array �� �������� ���� [1 of 2]

#include<iostream>

using namespace std;

struct Rectangle //����ü�� �迭�� �� �� ����
{
	int length;
	int width;
};

enum StudentName //enum �� �迭�� ���� �� �� ����
{
	JACKJACK,		// = 0
	DASH,			// = 1
	VIOLET,			// = 2
	NUM_STUDENTS,	// = 3
};


int main()
{
	//�������� ������ �����ϴ� ���
	int jackjack_score;
	int dash_score;
	int violet_socer;
	// . . .

	//�̸��� �� ����־ ������ ����

	int student1_score; //jackjack
	int student2_score; //dash
	// . . .

	//������ �������� for ���� ���� ����



	//�迭

	int one_student_score; // 1 variable
	int student_scores[5]; // 5 int

	//5�� int �� �޸𸮸� �ѹ��� ������

	cout << sizeof(one_student_score) << endl;  // 4 bytes
	cout << sizeof(student_scores) << endl;		// 4*5 = 20 bytes

	// ������ ���� ������ 1���� �� �޸𸮸� �ѹ��� �� ���� ���� ����


	// assignement

	one_student_score = 100;

	student_scores[0] = 100; //1st element is 100,  1st element's index is 0
	student_scores[1] = 80;  //2nd element
	student_scores[2] = 90;  //3rd element
	student_scores[3] = 50;  //4th element
	student_scores[4] = 0;   //5th element

	//student_scores[5] = 30;  //6th elemnt , 5���� �����߱� ������ ������

	//�ٸ� ������ array �� 0���� ������

	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	//cout << student_scores[5] << endl;   //runtime error �߻�! ����� �� ���� ���� 

	
	//��� ���� �ڵ�

	cout << (student_scores[0] + student_scores[1]) / 2.0 << endl;
	// �Ϲ����� int ����ϴ°Ͱ� �����ϰ� �� �� ����


	//����ü�� �迭�� �� �� ����

	cout << sizeof(Rectangle) << endl; //8

	Rectangle rect_arr[10];

	cout << sizeof(rect_arr) << endl; //���߿� �迭�� �Լ� parameter �� ����Ҷ� sizeof()�� ������ �� �� ����

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;


	//array �� �ʱ�ȭ �ϴ� ���

	int my_array[5] = { 1,2,3,4,5 };
	//int my_array[5] = { 1,2, };		// �ʱ�ȭ ���Ѱ� 0���� �ʱ�ȭ��
	//int my_array[] = { 1,2,3,4,5 };	// ������ ��Ȯ�� ��� �����Ϸ��� �˾Ƽ� �Ҵ���
	//int my_array[5]{ 1,2,3,4,5 };		//uniform initilization ó�� = ��� �ʱ�ȭ ����, c++11���� ����

	cout << my_array[0] << endl;
	cout << my_array[1] << endl;
	cout << my_array[2] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;


	//enum �� �迭�� ���� �� �� ����

	cout << my_array[JACKJACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;

	//student ���� �ڷḦ �����Ҷ� enum ���� ����̸� �����ϴ°� �������� ����
	//student �� ����� ���� �𸣰� �̸��� �ٲ� ���� �ֱ� ������ �ٸ� ����� �����(class �� ����)

	//NUM_STUDENTS == 3 �ΰ��� �̿��� �� ����, ������  ���ϰ� ���� �� ����
	int students_scores[NUM_STUDENTS];

	students_scores[JACKJACK] = 0;
	students_scores[DASH] = 100;


	//[]�� �־� ����� array�� size �� compiletime �� ������ �Ǿ����

	int num_students = 0;
	cin >> num_students;

	//int students_scores_[num_students]; //num_students �� runtime �� �����Ǳ� �����̴�
	// array�� length(size) �� compiletime �� �ݵ�� ������ �Ǿ��־����

	//num_students �� const�� �����ϰ� cin���� �ȹ����� ��� ����

	//c style ���� #define NUM_STUDENTS 100000 ������ ū ���ڷ� ������
	//c++ style ���� ���� ����� �������� ���� (���� �Ҵ�) 

	return 0;
}