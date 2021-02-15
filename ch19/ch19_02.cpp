// �Լ����� �������� ���ϰ� ��ȯ�ϱ� C++17

#include <iostream>
#include <tuple>

using namespace std;


//�⺻������ �Լ��� �ϳ��� ���� return ��
//��ȸ�ϴ� ������� return type �� structure �� class �� ���� ����ϴ� ����� ����
//�Ǵ� std::tuple �� ����ϴ� ����� ����



tuple<int, int>my_func()	//int �ΰ��� return
{
	return tuple<int, int>(123, 456);
}


//�� ���ϰ� ����
auto my_func2()				//auto ���
{
	//return tuple<int, int, int>(123, 456, 789);		//���⼭ ��� ��� return ���� ����

	return tuple(123, 456, 789,10);						//C++17 ���� <int, int, int> �� ��� ��
}


int main()
{
	tuple<int, int> result = my_func();		//tuple �� �ޱ�

	cout << get<0>(result) << " " << get<1>(result) << endl;



	//�� ���ϰ� �ޱ�						//auto ���
	auto result2 = my_func2();

	cout << get<0>(result2) << " " << get<1>(result2) << endl; 
	//return ���� �ϳ� �� �þ��� ������ get<2>(result2)�� �߰�����ߵ�



	//�� ���ϰ� �ޱ�						//result �ϳ��� �ƴ϶� ������ �ޱ�
	auto [a, b, c, d] = my_func2();			//���� a,b,c,d �� �����ϸ鼭 �޴°Ŷ� ����

	cout << a << " " << b << " " << c << " " << d << endl;


	return 0;
}