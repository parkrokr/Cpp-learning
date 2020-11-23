// ��Ʈ �÷���, ��Ʈ ����ũ Mask

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	
	// item ������ŭ flag�� ����� ���

	// ������ ���鶧 �������� 4���� �ִ�
	bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	bool item4_flag = false;
	// . . .


	// event! item1 get
	item1_flag = true;

	// die! item2 los
	item2_flag = false;

	// item3�� ������ ������ event�� �߻��Ѵ�
	if (item3_flag == true)
	{
		// event
	}

	//item3�� ������ �ְ� item4�� ������ ���� ���� ���
	if (item3_flag == true && item4_flag == false)
	{
		item3_flag = false; // item3 los
		item4_flag = true;  // item4 get
	}


	//invokeEvent(item1_flag, item2_flag, item3_flag, ...);  //parmeter ������ŭ �־������

	
	
	// bool type ���� 8�� ��ſ� 1 byte �ϳ��� �̿��� ǥ��
	// �� ��Ʈ�� ���ؼ� flag�� �̸� �ϳ� ������ �����
	
	const unsigned char opt0 = 1 << 0;// opt0 <- option 0
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	// opt4, 5, 6, 7

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;


	unsigned char items_flag = 0;
    cout <<"No item"<< bitset<8>(items_flag) << endl;

	// item0 on
	items_flag |= opt0;
	cout << "Item0 obtained " << bitset<8>(items_flag) << endl;

	// item3 on
	items_flag |= opt3;
	cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

	// item3 lost
	items_flag &= ~opt3;
	cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

	// has item1 ?
	if (items_flag & opt1) {cout << "Has item1 " << endl;}
	else { cout << "Not has item1" << endl; }

	// has item0 ?
	if (items_flag & opt1) { cout << "Has item0 " << endl; }
	else { cout << "Not has itme0" << endl; }

	//obtainiten 2, 3
	items_flag |= (opt1 | opt3);

	cout << bitset<8>(opt2 | opt3) << endl;
	cout << "Item1, 3 obtained " << bitset<8>(items_flag) << endl;

	
	// has item2, not has item1
	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		//lost item2, get item1
		items_flag ^= (opt2|opt1);//items_flag ^= opt1;	
	}

	cout << bitset<8>(items_flag) << endl;



	//graphics ex
	// option�� �ʹ� �������°� �����ϰ� ������
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)



	//bitmask

	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	unsigned int pixel_color = 0xDAA520; // golden rod (218, 165, 32)

	/*cout << bitset<32>(pixel_color) << endl;
	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(green_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;*/
	
	
	unsigned char blue = pixel_color & blue_mask;
	cout << "blue " << bitset<8>(blue) <<" "<<int(blue)<< endl;

	unsigned char green = (pixel_color & green_mask) >> 8;
	cout << "green " << bitset<8>(green) << " " << int(green) << endl;

	unsigned char red = (pixel_color & red_mask) >> 16;
	cout << "red " << bitset<8>(red) << " " << int(red) << endl;

	return 0;
}