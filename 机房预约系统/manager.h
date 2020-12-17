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
	//�вι���
	Manager(string name,string pwd);
	//�˵�
	virtual void operMenu();
	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//ȥ��
	void initVector();
	//ȥ��
	bool checkRepeat(int id,int type);

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;
};