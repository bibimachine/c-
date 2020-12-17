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
	//学号 姓名 密码
	Student(int id,string name,string pwd);
	
	//菜单界面
	virtual void operMenu();
	
	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyorder();
	
	//查看所有预约
	void showAllOrder();
	
	//取消预约
	void cancelOrder();
	
	//注销登录

	vector<ComputerRoom> vCom;

};