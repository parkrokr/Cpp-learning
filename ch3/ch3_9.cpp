// 비트 플래그, 비트 마스크 Mask

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	
	// item 개수만큼 flag를 만드는 방법

	// 게임을 만들때 아이템이 4개가 있다
	bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	bool item4_flag = false;
	// . . .


	// event! item1 get
	item1_flag = true;

	// die! item2 los
	item2_flag = false;

	// item3를 가지고 있으면 event가 발생한다
	if (item3_flag == true)
	{
		// event
	}

	//item3를 가지고 있고 item4를 가지고 있지 않은 경우
	if (item3_flag == true && item4_flag == false)
	{
		item3_flag = false; // item3 los
		item4_flag = true;  // item4 get
	}


	//invokeEvent(item1_flag, item2_flag, item3_flag, ...);  //parmeter 개수만큼 넣어줘야함

	
	
	// bool type 변수 8개 대신에 1 byte 하나를 이용해 표현
	// 각 비트에 대해서 flag를 미리 하나 설정해 줘야함
	
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
	// option이 너무 많이지는걸 방지하고 싶을떄
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