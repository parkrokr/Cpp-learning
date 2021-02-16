// 파일의 임의 위치 접근하기

//더 다양한 기능들은 reference manual 참고

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>	//exit()
#include <sstream>

using namespace std;

int main()
{
	const string filename = "ch18_07_my_file.txt";

	//make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	//read the file
	{
		ifstream ifs(filename);

		ifs.seekg(5); //ifs.seekg(5, ios::beg);		//5 byte 이동한 다음에 읽어들여라
		cout<<(char)ifs.get()<<endl;					//f

		ifs.seekg(5, ios::cur);				//현제 커서위치(읽어들이는위치) 에서 5 byte 이동해서 읽어라
		cout<< (char)ifs.get() << endl;					//f를 읽은 다음 5 칸이라 l 이 읽어짐


		//ifs.seekg(-5, ios::end);			//마지막으로부터 거꾸로 5 byte

		//ifs.seekg(0, ios::end);			//end 로부터 0 byte, 즉 마지막
		//cout << ifs.tellg() << endl;			//tellg()는 현재위치를 알려줌,알파벳26 에서 endl 까지 27 라서 28이 출력됨


		string str;
		getline(ifs, str);				//커서위치로부터 마지막까지 읽어옴

		cout << str << endl;				//mnopqrstuvwxyz
	}


	//파일을 열어서 읽기도 하고 쓰기도 하기
	{
		//그냥 fstream 으로 초기화 하면 됨
		fstream iofs(filename);
		
		//fstream iofs(filename, ios::in | ios::out);
		//이렇게 플래그를 설정해도 되지만 대부분의 경우 없어도 in,out 작동됨
		

		iofs.seekg(5);						//5 byte 이동
		cout << (char)iofs.get() << endl;	//read		//f가 출력됨

		iofs.seekg(5);						//5 byte 이동
		iofs.put('A');						//write			//파일을 보면 f가 있어야 될 자리에 A 가 덮어써져있음
	}



	return 0;
}
