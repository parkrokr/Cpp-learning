//�ڷ������� ���� �ٿ��ֱ� Type aliases

//����� ª�� �ٿ��ٶ� ����
//���������Ҷ� ����
//�����ʺ� �������� �÷����� �������� �ڵ��� �Ҷ� ���������� ����ϰ� ����


#include<iostream>
#include<vector>
#include<cstdint>

int main()
{
	using namespace std;

	//�ڵ� �󿡼� �ΰ��� ������ ���� �� ����
	//�ǵ��� distace_t �� ���� double�� �Ÿ���� �������� ���� ���� �޸�� �ּ�
	//distace_t�� ���� ����ϰ� �ִٰ� double�� float�� �ٲٷ��� �Ҷ� �����ϱ� ����
	typedef double distance_t;  //typedef float distance_t;

	//�����Ϸ� ���忡�� ����, ���α׷��� ���Ǹ� ���� ���
	double     my_distance; //my_distanc �� double�̴�
	distance_t home2work;   //home2work �� distace_t �̰� double �� ����� ǥ���ϰڴ�
	distance_t home2school;

	
	//�����ʺ� ���� (ch2_3) 
	// ���ο� ���� �����Ѱ��� �ƴϰ� typedef�� ���� �ִ°͵��߿� ��Ȳ�� ������ ���� ��������ذ��̴�.
	std::int8_t i(97);


	// �̷� ������ �ڷ����� ������ ���� �ִ�
	//std::vector<std::pair<std::string, int> > pairlist;
	//vector<pair<string, int> >pairlist;

	
	//typedef vector<pair<string, int> > pairlist_t; // typedef ��ſ� using �� ���� ����� ����
	using pairlist_t = vector<pair<string, int> >; 
	//assingnment �� �޸𸮰����� ���������� using�� �����Ϸ����� �̰� ��ſ� ���� ���ڴٰ� �˷��ִ� ���̴�

	vector<pair<string, int> >pairlist1;
	pairlist_t pairlist2; //�������



	return 0;
}