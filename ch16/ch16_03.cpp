//STL �˰��� ( Algorithms ) �Ұ�

//�ſ� �����, move,sort ��� �ſ� ����
//min, max, clamp ������ ������ �����ؼ� ������ ������ std �� ������ ��
//�ڷᱸ������ ���� �������� ���� ������ ��

//����� ���� �ڷ����� ����Ҷ��� �񱳿����ڸ� �����ε��ؾ� ���� ��ɵ��� ����� �� ����(ch09_04)

//�����̳ʸ��� ��Ȳ�� ���ݾ� �ٸ�, algorithm ���� sort() �� ���� ��� �����̳ʷ� ���� ã���� ���� ���� ����
//list �� ������ ���̴� �ڷᱸ������
//vector ���� insert() �� ���ݴ� ���� '��' �ְ� list ���� insert() �� ���ݴ� ���� '��' ����, �׻��� �ƴ�


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int> container;
	//list<int> container;	//list ������ ���� �Ȱ��� �۵������� sort(), reverse() �� �ڱ� Ŭ������ �������

	for (int i = 0; i < 10; ++i)
		container.push_back(i);



	//min ã��
	auto itr = min_element(container.begin(), container.end());		//begin �� end ���̿��� ã��
	cout << *itr << endl;		//0


	//max ã��
	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;		//9

	cout << endl;



	//Ư���� ���� ã��
	itr = find(container.begin(), container.end(), 3);		//3�� ��ġ ã��, iterator �� 3�� ��ġ�� ����Ű�� ����

	container.insert(itr, 128);		//���� 3�� ��ġ�� 128 �� ���� 3 �� �ڷ� �и�


	//���
	for (auto& e : container) cout << e << " ";
	cout << endl;
	//0 1 2 128 3 4 5 6 7 8 9


	//sort
	sort(container.begin(), container.end());
	//container.sort();		//list �� sort() �� �ڱ� Ŭ���� �ȿ� �������

	//���
	for (auto& e : container) cout << e << " ";
	cout << endl;
	//0 1 2 3 4 5 6 7 8 9 128


	//reverse	���� ������
	reverse(container.begin(), container.end());
	//container.reverse();	//list �� reverse() �� �ڱ� Ŭ���� �ȿ� �������

	//���
	for (auto& e : container) cout << e << " ";
	cout << endl;
	//128 9 8 7 6 5 4 3 2 1 0


	return 0;
}