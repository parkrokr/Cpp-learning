// STL �ݺ��� ( Iterators ) �Ұ�

//iterator �� �پ��� �����̳ʿ����� �ϰ��ǰ� ����� �� ����
//for, for-each, while �� ��Ȳ�� ���� �׶��׶� ������ ���� ����ϸ� ��
//auto �� ����ϸ� ���ϰ�, �߰����� �ڵ� ���� ����� �� ����

//�����ʹ� �ƴ����� ������ó�� ����� �� ����( *������, -> ������ �����ε� �Ǿ�����)

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//for(int i = 0;i<container.size();++i)		//vector ���� for ������ ������ ���� ����ϴ� ���


	//iterator ���
		
	//�ݺ��� ��ü�� ������ ����
	//vector<int>::iterator itr;		//�׳� iterator �� ����
	vector<int>::const_iterator itr;
	
	//container �� vector<int> �ϱ� itr �� vector<int> �� ����
	
	itr = container.begin();			//iterator �ʱ�ȭ, container.begin() �� return type �� iterator ��

	while (itr != container.end())
	{
		cout << *itr << " ";		//�ʿ��� �۾��� �� �� ����, * ������ �����ε� �Ǿ�����, 
									//�����ʹ� �ƴ����� ������ó�� ���

		++itr;		//���������� �����ε� �Ǿ�����
	}
	cout << endl;


	//�� iterator �� �ٸ� �����̳ʿ����� �ϰ��ǰ� ����� �� ����

	//�׷��� ������ ġ�Ⱑ ���ŷӴٴ� ������ ������ ��� c++ ���� ���� ������


	//for-each �� ���� ���� �߼�?
	for (auto& e : container)
		cout << e << " ";
	cout << endl;
	

	//for 
	for (auto itr = container.begin(); itr != container.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;



	//wihle ��, for ���߿� �� ������ �׶��׶� ��Ȳ�� ����


	// std::list
	//list ������ iterator �� ����ؼ� iterate �� �� ����

	// list �� vector �� ���̴� �ڷᱸ������, �ڷḦ �����ϴ� ����� ���� �ٸ�

	list<int> container_l;
	for (int i = 0; i < 10; ++i)
		container_l.push_back(i);

	for (auto itr = container_l.begin(); itr != container_l.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;




	//std::set
	//set �� �����͸� ������ insert() �� �̿���
	//iterator ������� ������

	set<int> container_s;
	for (int i = 0; i < 10; ++i)
		container_s.insert(i);			//set �̱� ������ insert() �� �����͸� ����

	for (auto itr = container_s.begin(); itr != container_s.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;




	//std::map
	//map ���� ��� tuple ���̾ߵ�
	map<int, char> container_m;
	for (int i = 0; i < 10; ++i)
		container_m.insert(make_pair(i, char(i + 65)));			//make_pair �� �־������

	for (auto itr = container_m.begin(); itr != container_m.end(); ++itr)
	{
		//cout << *itr << " "; iterator �� ����Ű�°� pair �̱� ������ ������ ����
		cout << itr->first << " " << itr->second << endl;		//iterator �� �����ʹ� �ƴ����� ������ó�� ���
	}
	cout << endl;





	return 0;
}