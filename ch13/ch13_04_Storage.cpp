#include "ch13_04_Storage.h"

template<>
void Storage<double>::print()
{
	std::cout << "Double Type ";
	std::cout << std::scientific << m_value << '\n';
}

//main.cpp 가 이 Storage.cpp 에 대해서 모르고 있기 때문에
//특수화에 대해서 모르고 있음

//해결하는 방법:
//그냥 헤더에 두기		(헤더 온리: 헤더에 다 몰아둬서 헤더파일에 다 구현되어 있음)

//main.cpp 에서 cpp 파일을 include 
//결국은 헤더에 둔거랑 같은 꼴

//헤더를 하나만 쓰는게 아니라 헤더를 쪼개는 방법도 있음