#include "manager.h"
#include <fstream>
#include"globalFile.h"
#include<algorithm>
Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	//初始化
	this->m_Name = name;
	this->m_Pwd = pwd;
	initVector();


	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
}

void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录" << endl;
	cout << "------------------" << endl;
	cout << "1、添加账号" << endl;
	cout << "2、查看账号" << endl;
	cout << "3、查看机房" << endl;
	cout << "4、清空预约" << endl;
	cout << "0、注销登录" << endl;
	cout << "------------------" << endl;
}

void Manager::addPerson()
{
	cout << "1、添加学生" << endl;
	cout << "1、添加老师" << endl;
	string filename;
	string tip;  
	string errortip;//重复错误提示

	ofstream ofs;
	int select;
	cin >> select;

	if (select == 1) {
		//添加学生
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复";
	}
	else {
		//添加老师
		filename =TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "职工号重复";
	}
	ofs.open(filename, ios::out | ios::app);

	int id;//学号/职工号
	string name;
	string pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret =checkRepeat(id, select);
		if (ret) {//有重复
			cout << errortip << endl;
			system("pause");
			system("cls");
			return;
		}
		else break;
	}


	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加
	ofs << id << ' ' << name << ' ' << pwd << endl;
	cout << "添加成功！";

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

void printStudent(Student& s) {
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher &t) {
	cout << "职工号：" << t.m_Id << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、所有学生" << endl;
	cout << "2、所有老师" << endl;

	int select = 0;//
	cin >> select;
	if (select == 1) {
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;

	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "机房编号：" << it->m_ComId << "最大容量" << it->m_MaxNum << endl;
		system("pause");
		system("cls");
	}
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功"<<endl;

	system("pause");
	system("cls");

}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) {
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	return false;
}


