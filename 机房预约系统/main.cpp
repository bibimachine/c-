#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include "globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

//进入管理员子菜单
void managerMenu(Identity * &manager){
	while (true)
	{
		//调用子菜单
		manager->operMenu();

		//转为子类指针以调用子类接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入学生子菜单
void studentMenu(Identity*& student) {
	while (true)
	{
		//调用子菜单
		student->operMenu();

		//转为子类指针以调用子类接口
		Student* st = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			st->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			st->showMyorder();
		}
		else if (select == 3)//查看所有预约
		{
			st->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			st->cancelOrder();
		}
		else {
			delete st;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void TeacherMenu(Identity*& teacher) {
	while (true)
	{
		//调用子菜单
		teacher->operMenu();

		//转为子类指针以调用子类接口
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//查看预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else {
			delete teacher;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录
void LoginIn(string FileName, int type) {
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(FileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
	}

	//输入信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码是：" << endl;
	cin >> pwd;

	//身份验证
	if (type == 1)//学生
	{
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证失败！" << endl;
	system("pause");
	system("cls");

	return;
}




int main() {
	while (true) {
		cout << "=======欢迎来到机房预约系统=======" << endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "----------------" << endl;
		cout << "   1.学生代表   " << endl;
		cout << "     2.老师     " << endl;
		cout << "    3.管理员    " << endl;
		cout << "     0.退出     " << endl;
		cout << "----------------" << endl;
		cout << "请输入您的选择：";

		int select = 0;
		cin >> select;


		switch (select)
		{
		case 1:   //学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:   //老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:    //退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:    //
			cout << "输入错误，请重新选择！"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}