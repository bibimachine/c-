#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<map>
#include"globalFile.h"
class OrderFile {
public:
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>> m_orderData;


};