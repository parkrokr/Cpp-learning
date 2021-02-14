// 기본적인 파일 입출력

//파일 입출력은 예외처리나 예상되는 오류에 대해서 신중하게 처리할 필요가 있음

//아스키 포멧으로 데이터를 다 저장하면 엄청 느려지게 됨
//binary 파일을 메모장같은 문서 프로그램으로는 확인을 못함
//그래서 이런 binary 입출력 파일을 다룰때는 디버깅에 신경을 써야함

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		//exit()
#include <sstream>

using namespace std;

int main()
{
	//아스키 포멧 파일 저장, 읽기
	//"ch18_06_my_first_file.dat" 지금은 파일의 확장자명이 .dat 지만 보통 아스키 포멧에서는 .txt 를 많이 사용함

	//writing
	if (true)
	{
		//output file stream

		//생성자의 paramter 로 파일명을 넣기
		ofstream ofs("ch18_06_my_first_file.dat");		
			//my_first_file.dat란 파일이 없으면 만들어줌
			//존재한다면 그 파일을 열수도 있고 지워버리고 새로 만들수도 있음
			//ios::app (append), ios::binary 같은 플래그를 사용해 출력을 조정할 수 있음

		//ofstream ofs("ch18_06_my_first_file.dat", ios::app); //append 모드
			//파일이 이미 존재할경우 그 뒤에 이어서 작업함, Line 1\n Line 2 가 계속 덧붙여짐

		
		//ofs.open("my_first_file.dat");		//이렇게 별도로 open() 으로 열 수 있음
												

		if (!ofs)		//파일을 열지 못하면 경고를 띄움
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}
		//파일 입출력은 예외처리나 이렇게 예상되는 오류에 대해서 신중하게 처리할 필요가 있음

		
		//지금까지 사용해온 stream 의 사용방식 그대로 파일 출력을 할 수 있음
		//아스키 저장
		ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;
		//이렇게 output operator 를 사용하게 되면 아스키 포멧에 맞춰서 text 모드로 저장이 됨
		//메모장으로 열어볼수있음, 열어보면 Line 1 \n Line 2 로 출력이 되어있는걸 볼 수 있음


		//binary 저장

		//binary 로 저장할때는 데이터가 어디까지인지 알 수 없음
		//어떤 데이터가 몇개만큼 저장이 될지 미리 약속을 해서 알고 있어야됨

		//데이터가 몇개인지 저장을 해서 약속하고 있음
		/*const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));	// num_data를 char* 로 캐스팅해서 write() 에 넣고 있음

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));	//10개의 data 를 저장하고 있음 (0부터 9까지 숫자를 저장)
		*/



		//출력할 data 를 문자열 하나에 담아두고 저장하는 경우도 있음
		/*stringstream ss;
		ss << "line 1" << endl;
		ss << "line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)&str_length, sizeof(str_length));	//string 의 size 넣기
		ofs.write(str.c_str(), str_length);*/



		//ofs.close();		//not necessary, 대부분의 경우 영역 안에서 코딩하기 때문에 영역 밖을 벗어나면
							//자동으로 소멸자가 파일을 닫아줌
	}



	//reading
	if (true)		//if 문 쓴건 예제 정리를 위해서 사용한 것
	{
		//input file stream

		ifstream ifs("ch18_06_my_first_file.dat");		//file 이름을 정확하게 넣어줘야함
		//정확한 이름이 아니면 밑에 if 문을 들어가 문구 출력후 강제로 나감
		//이름이 사소하게 틀리는 것 때문에 시간을 많이 잡아먹기도 함, 꼼꼼하게 확인하는 습관 들이기

		if (!ifs)
		{
			//열지 못하면 오류 발생
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		//아스키 읽기
		while (ifs)		//끝까지 다 읽으면 ifs 가 false 를 반환함
		{
			std::string str;
			getline(ifs, str);		//한줄씩 읽어옴

			std::cout << str << endl;
		}

		//메모장으로 "ch18_06_my_first_file.dat"을 직접 열어서 직접 Hello World 를 추가해도
		//파일이 잘 읽어짐




		//binary 읽기
		/*
		//먼저 num_data 를 읽어서 data 가 몇개 있는지 확인을 함
		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		//읽어들이기
		for (unsigned int i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));		//read() 로 읽고 있음

			std::cout << num << endl;				//제대로 읽었는지 출력
		}
		*/



		//어떤 경우엔 문자열 하나에 담아두고 저장하고 읽기도 함
		//string 의 size 를 미리 읽어들이고 data 를 읽기
		/*unsigned str_len = 0;
		ifs.read((char*)&str_len, sizeof(str_len));

		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;*/

	}

	return 0;
}