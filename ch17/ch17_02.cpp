//std::string �� �����ڵ�� ����ȯ

//��������� ����ȯ ������ ���ݱ��� �ٷ���� �Ŷ��� ���� �ٸ�

#include <iostream>
#include <string>
#include <vector>
#include <sstream>	//string stream

using namespace std;

//�Է����� ���� �� string ���� �ٲ㼭 ��ȯ�ϴ� �Լ�
template <typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;

	osstream << x;				//x�� ���� output string stream �� �־���
	return osstream.str();		//osstream �� �ִ� ����(x) �� string ���� �ٲ���
}


//FromString
template <typename T>
bool FromString(const std::string& str, T& x)		//�����߳� ���߳Ĵ� �˷��ֱ� ���� bool type return
{
	std::istringstream isstream(str);		//input string stream �� str �� �ʱ�ȭ
	
	return (isstream >> x) ? true : false;	//x �� isstream ���� ����ְ� ���ǿ����ڸ� �Ἥ ��ȯ
}

int main()
{
	//const char* my_string = "my string";			//c style string
	//std::string my_string;						//�ƹ��͵� �ȵ����� �⺻������ ȣ���
	std::string my_string("my string");				//c style ���ڿ��� �ʱ�ȭ
	

	//std::string second_string(my_string);			//���� ������ ��
	//std::string second_string(my_string,3);		//�տ� 3���� ©��							string
	//std::string second_string(my_string, 3, 2);		//�տ� 3���� ©���� �� ���� 2���ڸ� ������	st
	
	//std::string second_string(5,'A');				//'A' �� 5�� ���						AAAAA



	//std::iterator �� �̿��ؼ� �ʱ�ȭ �ϱ�
	std::vector<char> vec;
	for (auto e : "Today is a good day.")
		vec.push_back(e);

	//std::string second_string(vec.begin(), vec.end());		//Today is a good day.
	

	//std::find() ���	 'g' �� ã��, 'g' �ձ��� ��µ�	Today is a 
	std::string second_string(vec.begin(), std::find(vec.begin(), vec.end(),'g'));
	//vec.begin() �ڸ��� �־ ���뵵 ����

	std::cout << my_string << std::endl;
	std::cout << second_string << std::endl;





	//���ڷ� �ٲٱ�
	//ToString, FromString

	//std::string my_str(4);					//�ȵ�, 4 �� �����̱� ������ ���ڿ��� ���ٲ��ְ� ����
	
	string my_str(std::to_string(1004));		//std::to_string(), ������ ���ڿ��� �ٲ���, 1004 �� ���ڿ���
	
	my_str += std::to_string(128);				//1004128

	//������ ����Ҷ� ���� �ڿ� ���ڸ� �ٲ㰡�� �������� ����Ҷ� �ſ� ������
	//�ð������� �ִµ� �پ��ϰ� �� �� ����


	int i = std::stoi(my_str);					//std::stoi,���ڿ��� ������, string to inteager

	float f = std::stof(my_str);				//std::stof, return type �� float


	cout << my_str << endl;
	cout << i << endl;
	cout << f << endl;




	//�Է����� ���� �� string ���� �ٲ㼭 ��ȯ�ϴ� �Լ�
	std::string my_new_str(ToString(3.141592));

	cout << my_new_str << endl;

	//FromString
	double d;

	if (FromString(my_new_str, d))
		cout << d << endl;
	else
		cout << "Cannot convert string to double" << endl;

	
	
	//���ڷ��� �ٲ� �� ����
	//string �� �ִ°� �׻� �ٸ� type ���� �ٲܼ��� ����

	//���� my_new_str �� "Hello" �� ���� ���ڿ��̶�� double �� ���ٲ�
	//FromString() ���� isstream �� �ִ� ���빰�� double �� ������´µ� ��ȯ�� �ȵǰ� fale �� return ��

	return 0;
}