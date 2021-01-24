//std::array �Ұ�

#include<iostream>
#include<array>
#include<algorithm>  //to use std::sort

using namespace std;

void printLength(array<int, 5> my_arr)
{
	cout << my_arr.size() << endl;
}

void printLength_ref(const array<int, 5>& my_arr) //���縦 �������� ref, �� ������ ���� ���� const
{
	cout << my_arr.size() << endl;
}


int main()
{
	//�Ϲ����� array �� �Լ� parameter �� ������ ����� ���󰡴�(������) ���� �־�����
	//std::array �� �׷����� ����


	//int array[5] = { 1,2,3,4,5 };  //array �� ���������� ���� ������ ����   
	//�Ϲ����� �ܾ�� ���������� ���� �浹 �� ���� ����

	array<int, 5> my_arr = { 1,2,3,4,5 }; //size ���ڰ� �ݵ�� ������
	my_arr = { 0,1,2,3,4 };
	my_arr = { 0,1,2 };  //�������� 0���� ä����,  ������ 5���� Ŀ���� �ȵ�

	cout << my_arr[0] << endl;
	cout << my_arr.at(0) << endl;  //at �� member function�̱� ������ () 

	// [] �� at() �� ����
	//  [] �ȿ� 5���� ū ���� ���� üũ���� ������ execess �� �غ�����
	//  at() �� üũ�� �ϰ� ������ ����� ����ó���� �ߵ���Ŵ. �׷��� �ణ ������
	//  �����ս��� ���� �߿��� ���α׷����� [] ���


	//���� ��ɵ�
	
	//elements �� ��� ��������
	cout << my_arr.size() << endl;

	//�Լ� parameter �� �������� ���� ������ �״�� ������
	printLength(my_arr);
	
	//��� array �� �׷��� ����Ǳ� ������ �ð��� �ɸ� �� ����
	//ref �� ������ �̸� ���� �� ����
	printLength_ref(my_arr);


	//std::array �� std::vector ���� ǥ�ض��̺귯���� ����Ҷ� �Լ� parameter ��
	//reference , ������ �ƴϸ� �׳� ������ �����ؼ� �����ؾ� ��



	//
	my_arr = { 1, 21, 3, 40, 5 };  //������ ���׹���

	//for-each �� ����
	for (auto element : my_arr)
		cout << element << " ";
	cout << endl;

	for (auto &element : my_arr) //&�� �޾��ָ� ����Ǵ� ���� ����(������)
		cout << element << " ";
	cout << endl;


	//���� 
	//<algorithm>�� std::sort �� �������
	std::sort(my_arr.begin(), my_arr.end());  //begin ���� end ����

	cout << "after sort" << endl;
	for (auto& element : my_arr) 
		cout << element << " ";
	cout << endl;

	//���� ����
	std::sort(my_arr.rbegin(), my_arr.rend());  //reverse begin ���� reverse end ����

	cout << "after reverse sort" << endl;
	for (auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	return 0;
}