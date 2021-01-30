#include "ch13_02_MyArray.h"

//�̿� print() �� definition �� class ������ ������ cpp ���Ϸ� �ű��?
//��ŷ ���� �߻�!

template<typename T>		
void MyArray<T>::print()	
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}


//MyArray.cpp ���� print() �� body �� ������ �Ҷ� Ư���� data type ���� ������ �ؾ��Ѵٰ� �˷��ֱ�

// explicit instantiaion
//template void MyArray<char>::print();
//template void MyArray<double>::print();

//print() ���� �ٸ��͵� cpp �� �ű涧 ������ ���ؼ� �������ָ� ���ŷο�
//class ��ü�� instactiation
template class MyArray<char>;
template class MyArray<double>;