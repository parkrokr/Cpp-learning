// ������ �켱������ ���չ�Ģ Operator Precedence and Associativity

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x = 4 + 2 * 3; // add(4, mult(2,3)) �Լ��� ǥ���ϴ� �ͺ��� �ξ� ����
	cout << x << endl;
	
	
	// Unary plus, Unary minus �� Associativity �� Left-to-right
	int y = 1 - 2 + -3; // �տ� +�� minus ������, �ڿ� +�� Unary minus (1-2)+(-3)
	cout << y << endl;
	
	
	// �켱������ ��Ȯ�ϰ� �ϰ� ������ ( ) ���
	// �켱������ ���չ�Ģ ǥ�� ��Ű�� ����
	
	
	// ^ �� ���п��� ���� �ŵ����� �����ڰ� �ƴ�
	// pow operator �� return ���� double
	int z = std::pow(2, 3);
	cout << z << endl;
	
	return 0;
}