//�ܾ��ϱ� assert

//debug ��忡���� �۵�, release ��忡�� �۵�����
//assert �� �߻��ϸ� ��� ������ �߻����� �˷���
//assert �� runtime �� üũ����
//static_assert �� compiletime �� üũ���ְ� ������ ���� �� ����

#include <iostream>
#include <cassert> // asser.h
#include <array>

using namespace std;

void printvalue(array<int, 5>& my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1); // ||�� ��ĥ���� ������ ��Ȯ�ϰ� ���� �������� �˰��ϱ� ���� �ɰ�

	cout << my_array[ix] << endl;
}



int main()
{
	//assert(false); //debug ��忡���� �۵�, release ��忡�� �۵�����

	//cpp ������ property page�� C/C++\Preprosessor ���� Preprocessor Definitions �� NDEBUG �� �Ǿ������� �۵�����

	int number = 5;

	//number should be 5 //��� �ּ��� ����дٸ� �ǿ뼺�� ����
	assert(number == 5); //number �� �ݵ�� 5 �̵��� assert �� �ɾ������




	array<int, 5> my_array{ 1,2,3,4,5 };

	//cout << my_array[5] << endl; //my_array[5]�� �����ϸ� runtime error 
	printvalue(my_array, 4);


	//static_assert
	//assert()�� runtime �� üũ������ static_assert() �� compiletime �� üũ

	int x = 5;

	assert(x == 5); // x �� �����ϱ� rutime �� �����ǵ�  assert() ����

	//static_assert(x == 5);// x�� �߰��� �޶��� �� ������ ������

	const int y = 5;

	assert(y == 5);

	static_assert(y == 5, " y should be 5"); //assert() �� �ٸ��� ������ ���� �� ����, ������ error �޼������� ���





	return 0;
}