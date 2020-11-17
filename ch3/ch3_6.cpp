// 논리 연산자 Logical Operators

#include<iostream>


int main()
{
	using namespace std;

	//logicla NOT
	bool b = true;

	cout << !b << endl; 


	int x1 = 5;
	int y1 = 7;

	if (x1 != y1) // !(x == y)에서 !이 == 보다 우선순위가 높아 (!x)==y 로 인식됨
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

	// && 는 왼쪽이 false 면 오른쪽을 계산하지 않음
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
	
	if (x != y)// bool 형이어야 함 int 일 경우 static cast 로 bool type 로 바꿔줌
	{
		// do something
	}


	// && 가 ||보다 우선순위가 높음

	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v3;
	bool r2 = (v1 || v2) && v3;
	bool r3 = v1 || (v2 && v3); // ( ) 권장

	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;

	return 0;
}