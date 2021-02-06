//������-�� ����  R-value References

#include <iostream>

using namespace std;

int getResult()
{
	return 100 * 100;
}

//paramter �� l-value reference
void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

//paramter �� r-value reference
void doSomething(int&& ref)
{
	
	cout << "R-value ref" << endl;
}


int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;		//const �̱� ������ ���� ���� ������ �� ����
	const int cy = getResult();

	//L-value, �޸� �ּ�,������ ������ ����
	//R-value, ������ ������ �����
	
	//�޸� �ּҸ� ������ �ִ� L-value �� ������ �־ ��� ����� ����
	//getResult() �� ��ȯ�ϴ� R-value �� y �� �ְ� ����


	//L-value references
	//L-value �� ������ �� �ִ� reference �� &�� �ϳ� ����
	//l-value references ���� �ּҸ� ������ �ִ� ����(modifialble l-value) �� ������ �� ����
	int& lr1 = x;		//Modifiable l-values
	
	//������ �������� �ȵǴ� �ڵ�
	  //l-value references(�ڱ��ڽ�) �� const �� �ƴҰ�� const �� ���� �� ����
	  //l-value reference �ϱ� l-value �� ���� reference �� �ǰ� r-value �� ���ؼ� ���� �� ����
	//int &lr2 = cx;	//Non-modifiable l-values
	//int &lr3 = 5;		//R-values


	//const l-value reference
	const int& lr4 = x;		//Modifiable l-values
	const int& lr5 = cx;	//Non-modifiable l-values
	const int& lr6 = 5;		//R-values
	//r-value �� �־ �Ǵ� ����: const �̱� ������ �޸� �ּҿ� ������� ������ ���ϴϱ�
	//�������� �ɺ��� ����� ����



	//R-value references
	// & �� �ΰ��� ����, logical-and �� ��� ����
	//r-value �� ���� �� ����
	//�� ����� ���� ���� �� ����,Non-modifiable l-value�� Ȥ�ó� �����ؼ� �ǵ帱��� ������
	//r-value reference �� ���������� �͵��� move �� �ؼ� �ٸ������� �Űܵ� �ƹ��� ã�� ����
	//�ݴ�� l-value �� x �� ���빰�� move �Ұ�� �ٽ� x �� ���ؼ� ������ �� ������ �浹�� ���� 

	//int &&rr1 = x;		//Modifiable l-values
	//int &&rr2 = cx;		//Non-modifiable l-values
	int&& rr3 = 5;			//R-values
	int&& rrr = getResult();

	//const int &&rr4 = x;	//Modifiable l-values
	//const int &&rr5 = cx;	//Non-modifiable l-values
	const int&& rr6 = 5;	//R-values

	
	//rr3 �� 5(�Ǵ� class �� �ν��Ͻ�,��ü) �� �����ϰ� ���� �ٲ� �� �ִ�(����ϰڴ�)
	cout << rr3 << endl;	//��°���
	rr3 = 10;				//�����ؼ� ���� �ٲٱ⵵ ����
	cout << rr3 << endl;	//�ٲ� ���� ��� ����




	// L/R-value reference parameters
	//�����ε��Ҷ�(l-value ref �� r-value ref �� �ٸ��ٰ� ��������)

	doSomething(x);				//modifiable l-value
	
	//doSomething(cx);			//cx �� const �̱� ������ const l-value reference �� �޾ƾߵ�

	doSomething(5);				//r-value 
	doSomething(getResult());	//r-value



	//r-value ref �� �޾����� ���� �ȿ��� ref �� ����ִ� �����͵��� move �ؼ� �����͵� ��
	//������ �ٸ������� ����� ���� ���� ������ move semantics �� ����

	//l-value ref �� �޾����� ���°� �޸� �ּҸ� ������ �ִ� ������,  �ۿ����� �����ϰ� ����� �����ϱ� 
	//������ move semantics �� ������ ������ �ۿ��� doSomething() �Լ��� ȣ���� �Ŀ� �Ѱܺ��� ������
	//�ٽ� �����Ϸ��� �ϸ� ������ ����, l-value �� ���ؼ� doSomething() �� move semantics �� ����� �� ����
	//������ �ϴ� ��쵵 ������ Ư���� ���, �Ϲ������� �浹�� ����Ŵ


	return 0;
}