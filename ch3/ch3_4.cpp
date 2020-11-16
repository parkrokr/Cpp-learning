// sizeof , ��ǥ ������(Comma Operator) , ����(��) ������ (Conditional Operator)

#include <iostream>

int getPrice(bool onSale)
{
	if (onSale)
		return 10;
	else
		return 100;
}

int main()
{
	using namespace std;

	// sizof opertor
	float f;

	// sizeof �����ڴ� ������ �־ �ǰ� data type �� �־ ��
	sizeof(float); // 4 bytes
	sizeof(f);

	//sizeof �� �Լ��� �ƴ� ������
	cout << sizeof(float) << endl;;
	cout << sizeof f << endl;



	//comma operator
	// for ������ ���� �����
	

	int x = 3;
	int y = 10;
	
	//int z = (++x, ++y);
	++x;
	++y;
	int z = y;

	cout << x << " " << y << " " << z << endl;

	
	int a = 1, b = 10; // comma operator �� �ƴ� arguments���� �������ִ� ��ȣ
	int c;

	// comma operator ���� �켱������ = ���ٳ���
	//c = a, b; �� (c = a) , b; �� ����

	c = (++a, a + b); //12

	cout << c << endl;


	
	//conditional operator (arithmetric if)
	// ������ ��쿣 if�� �Լ��� �ɰ��� ��찡 �б⵵ ���ϰ� debug�� ����
	
	bool onSale = true;

	const int price=(onSale == true)?10 : 100;
	
	// if���� ���� �ʹٸ� �Լ��� �и� ���Ѿ� ��
	//const int price = getPrice(onSale);

	// if ������ �Ҷ��� price �� const �� ���� �� ����
	/*if (onSale)
		price = 10;
	else
		price = 100;

	cout << price << endl;*/

	
	int i = 5;

	cout << ((i % 2 == 0) ? "even" : "odd") << endl;

	
	return 0;
}