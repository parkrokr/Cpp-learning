//����� ������( << , >> ) �����ε��ϱ�

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
	//file ��¿� �״�� �� �� ����

	//��� �Լ��� ���� ����, ù��° parameter �� Point class �� �ƴ϶� ostream �̱� ����)
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		//cout ��� out �� ���°�ó�� ����
		//����Լ��� �ƴϱ� ������ point. ����ߵ�
		out << "(" << point.m_x << "  , " << point.m_y << "  , " << point.m_z << ")";

		return out;  // chaining �ϱ� ����
	}


	//in stream
	friend std::istream& operator >> (std::istream& in, Point& point)  //�Է¹������� Point& point�� const �� �ϸ� �����߻�
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
	//���ŷο�

	//�����ε��� �Ǿ�������
	cout << p1 << " " << p2 << endl;


	//file �� ���
	ofstream of("out.text");

	of << p1 << " " << p2 << endl;

	of.close();



	//input stream
	cin >> p1 >> p2;
	cout << p1 << " " << p2 << endl;

	//file �� �Է�
	ifstream inf ("input.text");

	inf >> p1 >> p2;

	cout << p1 << " " << p2 << endl;

	inf.close();

	return 0;
}