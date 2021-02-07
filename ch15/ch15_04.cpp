// std::move

#include "ch15_04_AutoPtr.h"
#include "ch15_04_Resource.h"
#include <vector>
#include <string>

using namespace std;


//std::swap �� ������ �̸��� �ٲ㼭 ����
template<class T>
void MySwap(T& a, T& b)
{
	/*T tmp = a;
	a = b;
	b = tmp;*/

	//move semantics �̿��ؼ� swap
	//move �� ���൵ ������ �߻����� �ʴ� ��� ���
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}


int main()
{
	{
		AutoPtr<Resource> res1(new Resource(1000000));

		cout << res1.m_ptr << endl;

		//AutoPtr<Resource> res2 = res1;
		AutoPtr<Resource> res2 = std::move(res1);

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}
	//move �� �ƴ϶� copy semantics �� ���� ����
	//�ּҸ� ���� ���� �ϳ��� ���� ���縦 �ؼ� �ְ� ����

	//move semantics �� ����ϰ� ������ std::move ���̱�
	//std::move() �� �ϸ� �ȿ� ����ִ� l-value �� r-value �� �ٲ���
	//r-value �� �ٲ��ָ� r-value �� ����ϴ� �����ڸ� �����(move ������ ȣ���)
	//move �� ���� ����� ���� �����Ͱ� move �߱� ������ res1 �� nullptr �� ��
	//res2 �� heap �� �ִ� �޸𸮸� ��°�� �Ѱܹ���

	//���� ������ �ִ� �����ͷ� ���� �Ϸ��� res2 �� �����ؾ��� res1 ���δ� ���̻� ���� ����
	//�Ű��� �Ŀ� res1 ���� �۾��� �Ѵٸ� ���α׷����� å����


	{
		AutoPtr<Resource> res3(new Resource(3));
		res3->setAll(3);

		AutoPtr<Resource> res4(new Resource(5));
		res4->setAll(5);

		res3->print();		//3 3 3
		res4->print();		//5 5 5 5 5

		MySwap(res3, res4);

		res3->print();		//5 5 5 5 5
		res4->print();		//3 3 3
	}
	//MySwap() ���� move seantics �� ����ϸ� ���� �����ڰ� ȣ����� ����
	//move �� ��ü�ؼ� ����


	//MySwap() �� move �� �ؼ� ������ �߻����� �ʴ� ���� move �� ���ذ���
	//�Ϲ����� ��� move �� ���ָ� ������ �߻��� �� ����( �������� �ٽ� ����,����� ���ϴϱ�)
	//�׷��� r-value refernece �� ������ move semantics �� �����ϴ°�(r-value �� ������ �� ������ϱ�
	//move �� �ؼ� �ű���� ������ ���)
	//�� �𸣰� move �� ����ϸ� ������ ����ų �� ����


	//AutoPtr �ȿ� move semantics �� �����߱� ������ std::move �� ���� ������ �� ����
	//Ŭ������ ���鶧 ��ɵ��� �����ؾ� std::move �� ���� move semantics �� �� �� ����
	
	
	//std ���� move semantics �� ���Ǵ� �����Ǿ�����

	//std::vector
	{
		vector<string> v;
		string str = "Hello";

		v.push_back(str);			//str �� l-value(����) �� �ް� ����, copy semantics �� �ϰڴٴ� �ǹ�

		cout << str << endl;					//Hello
		cout << v[0] << endl;					//Hello  ���簡 �Ǿ ��

		v.push_back(std::move(str)); //r-value ref �� �ް� ����, move semantics

		cout << str << endl;					//�ƹ��͵� ��� �ȵ�,move ���༭ ����
		cout << v[0] << " " << v[1] << endl;	//Hello Hello
	}
	//���������� r-value �� ���� pushback() �� ������ �����Ǿ�����

	

	//std::string ������ move semantics �� �����Ǿ�����
	//MySwap �� ���θ� ��� �����ϴ°��� ���� string ������ ���� ȣ��Ǵ����� �޶���
	//copy semantics �� ��� tmp �� "abc" �� �����־�����
	//move semantics �� ��� tmp �� b�� move ���ְ� �����
	{
		std::string x{ "abc" };
		std::string y{ "de" };

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;

		MySwap(x, y);

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}

	return 0;
}