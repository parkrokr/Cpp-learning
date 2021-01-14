//��ü���� ���α׷��ְ� Ŭ���� Object Oriented Programming (OOP) , Class

//structure ���� data ��
//class ���� data �� ��ɸ� ������, ��ü object
//class ���� access specifier �� ��

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ģ���鿡 ���� �����صΰ� ���Ҷ� ģ���� ���ؼ� ����ϴ� ���α׷�
// Friend : name, address, age, height, wheght, ...

//void print(const string& name, const string& address, const int& age,
//	const double& height, const double& weight)
//{
//	cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
//}

//structur �ȿ� ����ִ� �������� member ��� �θ�
//struct Friend
//{
//	string	name;
//	string	address;
//	int		age;
//	double	height;
//	double	weight;
//
//	//print() �� structure �� member �� �Ǵ°�
//	//���� member �̱� ������ ���� data�� ������ �� ����
//	void print()
//	{
//		cout << name << " " << address << " " << age << " " << height <<
//			" " << weight << endl;
//	}
//};


//�ٸ� ģ������ ����ϱ� ���ؼ� �� �ٽ� ġ�Ⱑ ����� �Լ� parameter �� structure �� �ޱ�
//�Ű������� �ٸ��� ������ �����ε� ����
//fr.�� �ϴ°� �ݺ��Ǵ� ����, print() �� structure �� �־��ֱ�
//void print(const Friend &fr)
//{
//	cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height <<
//		" " << fr.weight << endl;
//}


class Friend
{
public: // access specifier ���� ������ (public, private, protected)

	//member ��°� �˸��� ���� m_ �տ� ���̱�
	//�ֱ� ���� ��Ÿ�Ͽ��� �ڿ� _ ���̱�
	//�տ� _ ���̴� ��Ÿ�ϵ� ����
	string	m_name;
	string	address_;
	int		_age;
	double	height;
	double	weight;

	void print()
	{
		cout << m_name << " " << address_ << " " << _age << " " << height <<
			" " << weight << endl;
	}
};


int main()
{
	
	/*string	name;
	string	address;
	int		age;
	double	height;
	double	weight;
	
	print(name, address, age, height, weight);*/


	//struct �� �־������ �����͸� ���� �� ����

	// uniform initialization
	//Friend jj{ "jack jack",  "uptown",2,30,10 };

	//coppy initialization
	/*Friend jj;
	jj.name = "jack jack";
	jj.age = 2;
	jj.address = "uptown";*/

	//print
	//print(jj.name, jj.address, jj.age, jj.height, jj.weight);


	//�ٸ� ģ������ ����Ϸ��� �Ǵٽ� �ڵ带 �ľ���
	//print() �� parameter�� structure �� �ޱ�
	//print(jj);


	//fr. �� ġ�°� �ݺ���, print() �� structure �ȿ� �־� member �� �ǰ� �ϱ�
	//print() �� ���������� Friend �����Ϳ� ������ �� ����

	//jj.print(); //jj�� print()�� �ϴ°�ó�� ���̱⿡ ���α׷��Ӱ� �����ϰ� �����ϱⰡ �� �ڿ�������




	//Friend ó�� date �� ����� ���� �ִ°� object ��� �θ�
	//structure ���� ���( �Լ�) �� ���� �� ������ 
	//���� �� ���� ���, ������� �ٷ� �� �ְ� ���� ���� class ��

	//�ܼ��� ��ɸ� �Ҷ��� class ��ſ� structure �� �ᵵ ��
	//������ �Ϲ������� sturcture �� data �� �������� ����
	//����� �������� class �� �����

	//c ������ structure �� ����� ���� �� ����

	//date �� ����� ���� ������ ��ü, object
	//��ü�� ���α׷��� ���μ� �����ϴ� �ܾ class 



	//class �� �����ϴ°Ÿ����δ� �޸𸮸� ������� ����
	//�̸��� ���� �����ؾ� �޸𸮸� ������

	Friend jj{ "jack jack",  "uptown", 2, 30, 10 };
	jj.print();
	// instanciation		�޸𸮸� ������ �������ִ� ��
	// instace			object �� �����ϱ� ���� ���� class �� ����

	//instanciation �� ����� ����� ������
	//JJ�� �ּҴ� ���� �� ������ Friend_class �� �ּҴ� ���� �� ����






	//�� ���� ģ������ �����͸� ����
	/*vector<string>	name_vec;
	vector<string>	addr_vec;
	vector<int>		age_vec;
	vector<double>	height_vec;
	vector<double>	weight_vec;

	print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);*/

	//����ó�� ���� ������� ����
	
	vector<Friend> my_friends;
	my_friends.resize(2); // 2�� ���� ����

	//print
	//my_friends[0].print();
	//my_friends[1].print();  //ģ���� �������� �ϳ��ϳ� ��ħ

	//for ������ print
	for (auto& ele : my_friends)
		ele.print();



	return 0;
}
