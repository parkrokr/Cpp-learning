// ���� (lambda ) �Լ��� std::function

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>		//to use  for_each()
#include <functional>
using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye" << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};


int main()
{
	//���� �Լ��� �͸��Լ�, anonymous function ��� ��, ����� lambda calculous ���� ���Դٰ� ��
	//c++ �Ӹ� �ƴ϶� �ֱ� �ٸ� ���鿡���� �������� ������ ��Ÿ���� ����
	//�͸� �Լ��� �̸��� ��� ��

	auto func = [](const int& i)->void {cout << "Hello, World!" << endl; };
	
	// []										lambda-introducer 
	
	// (const int& i)							lambda-parameter-declaration	
													//�Ϲ� �Լ�ó�� paramter ����
	
	// ->void									lambda-return-type-clause		
													//return type �� ���� �ƴ϶� �ڿ� ���ϼ��� ����
													//ch4_04 auto return type ����, trailing

	// {cout << "Hello, World!" << endl; };		compound-statement
													//functin �� body �� ��


	func(123);	//�̰� func �� function pointer ó�� ����ϰ� �ִ°�

	
	//������ ������ ��ġ�� �͸��϶� ��Ÿ��
	[](const int& i)->void {cout << "Hello, World!" << endl; }(123);
	//body �ڿ� () �� �ٷ� ���̸� �����


	//����ó�� �Լ��� �����ϰ� body �� ����� ȣ���ؼ� ���� ������ ����ϰ� ���� �����ؾ��Ұ�� ���ŷο���
	//�׷��� �̷��� ����(����) �Լ��� ����ϸ� �ξ� �����ϰ� ���α׷��� �� ������
	//Gui ���õ� ���α׷����� ���� �ϴٺ��� ���� ����ϰ� ��



	// lambda-introducer
		//[] �ȿ� & �� �־�θ� ���� �ȿ��� �Լ� �ۿ� �ִ°� reference �� ������
		//[] �ȿ� = �� ������ copy �� �ؼ� ������
		//paramter �� �ƴ϶� scope �ȿ� �ִ� �������� �������� ���
	{
		string name = "JackJack";
		[&]() {std::cout << name << endl; }();
		[&name]() {std::cout << name << endl; }();	//�̷��� ����� ���� ����

		[=]() {std::cout << name << endl; }();		//name �� copy �� �ؼ� �������� ����

		//[this]() {std::cout << name << endl; }();	//class �� member �� �����Ҷ� �̷��� �� �� ����
	}


	//�̷��� ��� ����
	cout << []()->int {return 1; }() << endl;



	//STL �̶� ���� ���� ���� ����
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	//for_each �� �̿��ؼ� vector �� �ִ� ���ҵ��� �̿��ؼ� ���� �Լ��� ����Ǵ°� ����
	//�Լ��� �����ϰ� �Լ������ͷ� ����ְ� �ϸ� ���ŷο���,�̶� ���� �Լ��� ����� �� ����
	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);

	//���� �Լ��� ��� ���� ��ĺ��� �̷��� �ٷ� �������� �����, �ֱٿ��� �̹���� �����
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	//auto func2 = [](int val)->void {cout << val << endl; };	//�̷��� void �� ��� ������
	//�����Լ��� return type �� void �� ��� ������





	//std::fucntion
		//function pointer �� ü��ȭ ��Ų��
	std::function<void(int)> func3 = func2;		//void �� return type, int �� parameter type
	func3(123);									//functor(�Լ���ü) ó�� �����ų �� ����


	//std::bind		
		//	parameter �� ��� ����, return type �� std:function, �� �Լ� ������
		//	ù��° parameter ���� �Լ���ü,�Լ�������,�Լ� ref, ����Լ������� ���� ���ڿ� ���ϼ� �ִ�
		//Collable object �� �´�
		//	�ι�° parameter ���� ���ڵ��� ����, �������� �ʰ� �������� ���ڵ��� �ް� ������ std::placeholders

	//Ư�� parameter�� ���ؼ��� �����Ű�� �Ǵµ� void(int) �̷��� paramter �� �ִ°� ������ �� ����
	//std::bind() �� �Ἥ (int �� �޴�)func3 �� int�� bind ����
	//func4 �� func3 �� ���޵Ǵµ� parameter �� ����, void(void) ��
	std::function<void()> func4 = std::bind(func3, 456);
	func4();



	//std::placeholder
		//	std::function �� std::bind �� �Բ� ����Ҷ� parameter �� ��� �������� �ʰ� Ư�� parameter �� 
		//�����ؼ� ����ϰ� ���� ��� ���
		//	std::placeholders::_1 ���� _1 �� 1��° parameter �� �ǹ�,
	
	{
		//function binding
		auto f = std::bind(&goodbye, std::placeholders::_1);	
		//goodbye() �� parameter �� 1���� placeholders::_1
		//auto ��ſ� std::function �� �־ ��

		f("World");



		//member function binding
		Object instance;
		auto f2 = std::bind(&Object::hello, &instance, std::placeholders::_1); 
		//class Object �� �����ִ� ����Լ� hello() �� ����ñ� ���ؼ��� Object class �� 
		//this �����͸� ������ �ִ� instance �� �ʿ���
		
		//hello()�� ������, instance �� �����͸� �־��ְ� hello �� parameter �� �ϳ���
		//std::placeholders::_1 �� ���� ù��° parameter �� ����
		//����Լ������ʹ� ����ȯ�� ������ �ʱ� ������ &�� �ݵ�� �ٿ������

		f2(string("World"));		//string �̶��� �����ϱ� ���ؼ� string �� ��
		f2("World");				//�̷��Ը� �ص� ��
	}


	return 0;
}