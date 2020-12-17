#include "teacher.h"
#include"orderfile.h"
#include<vector>
Teacher::Teacher()
{
}

Teacher::Teacher(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录" << endl;
	cout << "------------------" << endl;
	cout << "1、查看所有预约" << endl;
	cout << "2、审核预约" << endl;

	cout << "0、注销登录" << endl;
	cout << "------------------" << endl;
	cout << "请选择您的操作" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "、";
		cout << "预约日期：" << of.m_orderData[i]["date"];
		cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderData[i]["stID"];
		cout << " 姓名：" << of.m_orderData[i]["stName"];
		cout << " 机房号：" << of.m_orderData[i]["room"];
		string status = " 状态：";
		//1 申请中 2 预约成功 -1 预约失败 0 取消
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "预约失败";
		}
		else {
			status += "预约取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>b;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			b.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：" << of.m_orderData[i]["date"];
			cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学号：" << of.m_orderData[i]["stID"];
			cout << " 姓名：" << of.m_orderData[i]["stName"];
			cout << " 机房号：" << of.m_orderData[i]["room"];
			cout << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回：" << endl;
	int select = 0;
	int ret = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= b.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "请输入审核结果:" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[b[select - 1]]["status"] = "2";
				}
				else {
					of.m_orderData[b[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "审核完毕！" << endl;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
