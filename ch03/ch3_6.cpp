// �� ������ Logical Operators

#include<iostream>


int main()
{
	using namespace std;

	//logicla NOT
	bool b = true;

	cout << !b << endl; 


	int x1 = 5;
	int y1 = 7;

	if (x1 != y1) // !(x == y)���� !�� == ���� �켱������ ���� (!x)==y �� �νĵ�
	{
		cout << " x1 does nt equal y1" << endl;
	}
	else
		cout << " x1 equals y1 " << endl;

	
	//logicl AND
	bool a1 = true;
	bool b1 = false;

	cout << (a1 && b1) << endl;

	bool hit = true;
	int health = 10;
	if (hit == true && health < 20)
	{
		cout << "die" << endl;
	}
	else
		health -= 20;
	
	//logical OR
	bool x2 = true;
	bool y2 = false;

	cout << (x2 || y2) << endl;

	
	int v = 1;

	if (v = 0 || v == 1)
		cout << "v is 0 or 1" << endl;

	

	// short circuit evaluation
	int x3 = 2;
	int y3 = 2;

	// && �� ������ false �� �������� ������� ����
	if (x3 == 1 && y3++ == 2)
	{
		//do something
	}
	
	cout << y3 << endl;



	// De Morgan's Law
	bool x = true;
	bool y = false;
	
	!(x && y);
	!x || !y;

	!(x || y);
	!x && !y;

	// XOR 
	// false false   false
	// false true    true
	// true	 false   true
	// true  true    false

	cout << (x != y) << endl;
	
	if (x != y)// bool ���̾�� �� int �� ��� static cast �� bool type �� �ٲ���
	{
		// do something
	}


	// && �� ||���� �켱������ ����

	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v3;
	bool r2 = (v1 || v2) && v3;
	bool r3 = v1 || (v2 && v3); // ( ) ����

	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;

	return 0;
}