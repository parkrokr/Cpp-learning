#include "ch13_02_MyArray.h"

//이왕 print() 의 definition 을 class 밖으로 뺐으니 cpp 파일로 옮기면?
//링킹 에러 발생!

template<typename T>		
void MyArray<T>::print()	
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}


//MyArray.cpp 에서 print() 의 body 를 컴파일 할때 특정한 data type 으로 컴파일 해야한다고 알려주기

// explicit instantiaion
//template void MyArray<char>::print();
//template void MyArray<double>::print();

//print() 말고 다른것도 cpp 로 옮길때 각각에 대해서 구현해주면 번거로움
//class 자체를 instactiation
template class MyArray<char>;
template class MyArray<double>;