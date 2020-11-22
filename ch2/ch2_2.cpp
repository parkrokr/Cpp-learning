// ������ Integers

#include <iostream>
#include <cmath>
#include <limits>

int main() 
{
	using namespace std;

	short      s = 1;  // 2 bytes = 2 * 8 bits = 16 bits
	//int		   i = 1;  // 4 bytes
	long       l = 1;  // 4 bytes
	long long ll = 1;  // 8 bytes

	
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	

	// ��ȣ�� ǥ���ϱ� ���� -1, 0�� �����ϱ� ������ -1
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl; 
	
	cout << std::numeric_limits<short>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl;

	
	s = std::numeric_limits<short>::max();
	cout << "max " << s << endl;
	s = s + 1; //32768 (++s,s++)
    cout << "32768? "<< s << endl; // overflow

	s = std::numeric_limits<short>::min();
	cout << "min " << s << endl;	
	s = s - 1;
	cout << "-32768? " << s << endl; // overflow


	unsigned int j = -1;
	
	// overflow
	cout << j << endl; // �����Ϸ��� warning, error �ȶ����


	cout << 22/4<< " "<< (float)22/4 << endl;


	return 0;
}