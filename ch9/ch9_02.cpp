//입출력 연산자( << , >> ) 오버로딩하기

#include <iostream>
#include <fstream>  //to use file output

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		:m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	/*void print()
	{
		cout << m_x << " " << m_y << " " << m_z;
	}*/



	//output stream overloading
	//file 출력에 그대로 쓸 수 있음

	//멤버 함수로 구현 못함, 첫번째 parameter 가 Point class 가 아니라 ostream 이기 때문)
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		//cout 대신 out 를 쓰는것처럼 구현
		//멤버함수가 아니기 때문에 point. 해줘야됨
		out << "(" << point.m_x << "  , " << point.m_y << "  , " << point.m_z << ")";

		return out;  // chaining 하기 위해
	}


	//in stream
	friend std::istream& operator >> (std::istream& in, Point& point)  //입력받으려는 Point& point를 const 로 하면 에러발생
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in;
	}


};

int main()
{
	//ouput stream
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	/*p1.print();
	cout << " ";
	p2.print();
	cout << endl;*/  
	//번거로움

	//오버로딩이 되어있으면
	cout << p1 << " " << p2 << endl;


	//file 로 출력
	ofstream of("out.text");

	of << p1 << " " << p2 << endl;

	of.close();



	//input stream
	cin >> p1 >> p2;
	cout << p1 << " " << p2 << endl;

	//file 로 입력
	ifstream inf ("input.text");

	inf >> p1 >> p2;

	cout << p1 << " " << p2 << endl;

	inf.close();

	return 0;
}