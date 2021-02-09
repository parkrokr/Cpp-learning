// STL 반복자 ( Iterators ) 소개

//iterator 는 다양한 컨테이너에서도 일관되게 사용할 수 있음
//for, for-each, while 중 상황에 따라 그때그때 적절한 것을 사용하면 됨
//auto 를 사용하면 편하게, 추가적인 코딩 없이 사용할 수 있음

//포인터는 아니지만 포인터처럼 사용할 수 있음( *연산자, -> 연산자 오버로딩 되어있음)

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//for(int i = 0;i<container.size();++i)		//vector 에서 for 문으로 돌릴때 많이 사용하던 방식


	//iterator 사용
		
	//반복자 자체를 변수로 만듦
	//vector<int>::iterator itr;		//그냥 iterator 도 있음
	vector<int>::const_iterator itr;
	
	//container 가 vector<int> 니까 itr 도 vector<int> 로 만듦
	
	itr = container.begin();			//iterator 초기화, container.begin() 의 return type 이 iterator 임

	while (itr != container.end())
	{
		cout << *itr << " ";		//필요한 작업을 할 수 있음, * 연산자 오버로딩 되어있음, 
									//포인터는 아니지만 포인터처럼 사용

		++itr;		//증감연산자 오버로딩 되어있음
	}
	cout << endl;


	//이 iterator 는 다른 컨테이너에서도 일관되게 사용할 수 있음

	//그러나 일일히 치기가 번거롭다는 단점이 있지만 모던 c++ 에선 많이 좋아짐


	//for-each 를 많이 쓰는 추세?
	for (auto& e : container)
		cout << e << " ";
	cout << endl;
	

	//for 
	for (auto itr = container.begin(); itr != container.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;



	//wihle 문, for 문중에 뭘 쓸지는 그때그때 상황에 따라


	// std::list
	//list 에서도 iterator 를 사용해서 iterate 할 수 있음

	// list 와 vector 의 차이는 자료구조에서, 자료를 저장하는 방식이 많이 다름

	list<int> container_l;
	for (int i = 0; i < 10; ++i)
		container_l.push_back(i);

	for (auto itr = container_l.begin(); itr != container_l.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;




	//std::set
	//set 은 데이터를 넣을때 insert() 를 이용함
	//iterator 사용방법은 동일함

	set<int> container_s;
	for (int i = 0; i < 10; ++i)
		container_s.insert(i);			//set 이기 때문에 insert() 로 데이터를 넣음

	for (auto itr = container_s.begin(); itr != container_s.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;




	//std::map
	//map 같은 경우 tuple 형이야됨
	map<int, char> container_m;
	for (int i = 0; i < 10; ++i)
		container_m.insert(make_pair(i, char(i + 65)));			//make_pair 로 넣어줘야함

	for (auto itr = container_m.begin(); itr != container_m.end(); ++itr)
	{
		//cout << *itr << " "; iterator 가 가르키는게 pair 이기 때문에 문제가 생김
		cout << itr->first << " " << itr->second << endl;		//iterator 는 포인터는 아니지만 포인터처럼 사용
	}
	cout << endl;





	return 0;
}