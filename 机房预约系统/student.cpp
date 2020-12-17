#include "student.h"
#include<fstream>
#include"globalFile.h"
#include"computer.h"
#include"orderfile.h"
using namespace std;
Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录" << endl;
	cout << "------------------" << endl;
	cout << "1、申请预约" << endl;
	cout << "2、查看我的预约" << endl;
	cout << "3、查看所有预约" << endl;
	cout << "4、取消预约" << endl;
	cout << "0、注销登录" << endl;
	cout << "------------------" << endl;
}

void Student::applyOrder()
{
	cout << "周一~周五开放！" << endl;
	cout << "输入申请时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date;
	int interval;
	int room;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入有误，重新输入！" << endl;
	}
	cout << "请输入申请预约时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误，重新输入！" << endl;
	}
	cout << "请选择机房：" << endl;
	cout <<vCom[0].m_ComId<< "号机房容量为"<< vCom[0] .m_MaxNum<< endl;
	cout << vCom[1].m_ComId << "号机房容量为" << vCom[1].m_MaxNum << endl;
	cout << vCom[2].m_ComId << "号机房容量为" << vCom[2].m_MaxNum << endl;
	while (true) {
		cin >>room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，重新输入！" << endl;
	}
	cout << "预约成功，审核中！" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval<< " ";
	ofs << "stID:" << this->m_Id << " ";
	ofs << "stName:" << this->m_Name << " ";
	ofs << "room:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

void Student::showMyorder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		//string转int
		//string利用.c_str()转const char*
		//利用atoi(const char*)转int
		if (this->m_Id == atoi(of.m_orderData[i]["stID"].c_str())) {
			cout << "预约日期：" << of.m_orderData[i]["date"];
			cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号：" << of.m_orderData[i]["room"];
			string status = "状态：";
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
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入取消的记录：" << endl;
	vector<int>b;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		//string转int
		//string利用.c_str()转const char*
		//利用atoi(const char*)转int
		//判断是自身的
		if (this->m_Id == atoi(of.m_orderData[i]["stID"].c_str())) {
			//筛选状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				b.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：" << of.m_orderData[i]["date"];
				cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房号：" << of.m_orderData[i]["room"];
				string status = "状态：";
				//1 申请中 2 预约成功 -1 预约失败 0 取消
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "预约成功";
					cout << status << endl;
				}
			}

		}
	}
	cout << "输入取消记录，0代表返回：" << endl;
	int select = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= b.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[b[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消" << endl;
				break;
			}
		}
		cout << "输入有误!" << endl;
	}
	system("pause");
	system("cls");
}
