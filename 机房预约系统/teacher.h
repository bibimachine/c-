#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

class Teacher :public Identity {
public:
	Teacher();
	//�вι���
	Teacher(int id,string name,string pwd);
	//�˵�����
	virtual void operMenu();
	
	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();
	
	int m_Id;
};