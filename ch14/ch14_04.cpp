//std::exception �Ұ�


//std::exception �� �θ�Ŭ������ ��û���� ���� �ڽ� Ŭ�������� �����Ǿ�����
//��κ��� ���ܰ� �߻��ϴ� ��츦 �� �����ص�

//cppreference ����


#include <iostream>
#include <exception>  //exception class
#include <string>

using namespace std;

// std::exception �� ��ӹ޴� exception class 
// std::exception ���� ���� �߿��ϰ� �˾ƾ� �ϴ� �Լ��� what() ��
//���� ���� ���� Ŭ������ �ٸ� �ڽĵ� ó�� �۵��ϱ⸦ ���ϸ� what() �� �������̵� �ϴ°��� �߿���
// noexcept �� c++11 �̻��� �����Ϸ����� �� Ű���尡 ������
//noexcept �����ڴ� ������ Ÿ�ӿ� ������ �ƹ� ���ܵ� ������ ������ true �� ��ȯ��
//��� ���⼭�� ���ܸ� ������ �ʰڴٴ� �ǹ�
class CustomException : public std::exception
{
public:
	const char* what() const noexcept override  //override Ű����� ���� ��� ����,what() �� virtual ��
	{
		return "Custom exception";
	}
};



int main()
{
	try
	{
		//std �� ����Ҷ� ���ο� �̹� �����Ǿ� �ִ� throw �� catch
		std::string s;
		s.resize(-1);  //�Է����� ��ƿ��� ���̰� �̻��� ��� ���ο��� ���ܸ� ������ �̹� �����Ǿ�����


		//std::exception �� �����ٰ� ����ϰ� ������
		//throw std::runtime_error("Bad thing happened");  //exception �� �ڽ�Ŭ������ �ϳ��� ���� ���� �� ����
		
		
		//std::exception �� ��ӹ޴� exception class 
		//throw CustomeException();
	}
	catch (std::length_error& exception)
	{
		//exception �� �ڽ� Ŭ������ �ϳ��� length_error �� catch
		cerr << "Length_Error" << endl;
		cerr << exception.what() << endl;
	}
	catch (std::exception& exception)
	{
		//s.resize() �� ���� ���ܰ� ��Ȯ�ϰ� ���� �˰���� ���
		cout<<typeid(exception).name()<<endl;
		//�ڽ� Ŭ������ �̸��� ��µ�( class std::length_error )

		
		cerr << exception.what() << endl;  //what() �� ���ڿ���
		
		//reseiz() �� -1 �� �� ��� �����÷ο찡 �߻��ؼ� "string too long" �� ��µ�
	}



	//s.resize() �� ���� ���ܰ� ��Ȯ�ϰ� ���� �˰���� ��� �ٸ� ���
	//���ۿ��� reference manual �˻�
	//���� ��� std::basic_string::resize
	//�� �Լ��� � ���ܸ� �߻���ų ���� �ִ��� �� ���� ����


	return 0;
}