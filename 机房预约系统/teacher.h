#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

class Teacher :public Identity {
public:
	Teacher();
	//有参构造
	Teacher(int id,string name,string pwd);
	//菜单界面
	virtual void operMenu();
	
	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();
	
	int m_Id;
};