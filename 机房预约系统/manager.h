#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computer.h"

class Manager :public Identity
{
public:
	Manager();
	//有参构造
	Manager(string name,string pwd);
	//菜单
	virtual void operMenu();
	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//去重
	void initVector();
	//去重
	bool checkRepeat(int id,int type);

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;
};