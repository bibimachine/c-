#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include"computer.h"
class Student :public Identity
{
public:
	int m_Id;

	Student();
	//ѧ�� ���� ����
	Student(int id,string name,string pwd);
	
	//�˵�����
	virtual void operMenu();
	
	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyorder();
	
	//�鿴����ԤԼ
	void showAllOrder();
	
	//ȡ��ԤԼ
	void cancelOrder();
	
	//ע����¼

	vector<ComputerRoom> vCom;

};