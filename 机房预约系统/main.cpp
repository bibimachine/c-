#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include "globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

//�������Ա�Ӳ˵�
void managerMenu(Identity * &manager){
	while (true)
	{
		//�����Ӳ˵�
		manager->operMenu();

		//תΪ����ָ���Ե�������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//����ѧ���Ӳ˵�
void studentMenu(Identity*& student) {
	while (true)
	{
		//�����Ӳ˵�
		student->operMenu();

		//תΪ����ָ���Ե�������ӿ�
		Student* st = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			st->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			st->showMyorder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			st->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			st->cancelOrder();
		}
		else {
			delete st;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void TeacherMenu(Identity*& teacher) {
	while (true)
	{
		//�����Ӳ˵�
		teacher->operMenu();

		//תΪ����ָ���Ե�������ӿ�
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//�鿴ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->validOrder();
		}
		else {
			delete teacher;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼
void LoginIn(string FileName, int type) {
	Identity* person = NULL;
	//���ļ�
	ifstream ifs;
	ifs.open(FileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
	}

	//������Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "�����������ǣ�" << endl;
	cin >> pwd;

	//�����֤
	if (type == 1)//ѧ��
	{
		//ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//�����Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;
}




int main() {
	while (true) {
		cout << "=======��ӭ��������ԤԼϵͳ=======" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "----------------" << endl;
		cout << "   1.ѧ������   " << endl;
		cout << "     2.��ʦ     " << endl;
		cout << "    3.����Ա    " << endl;
		cout << "     0.�˳�     " << endl;
		cout << "----------------" << endl;
		cout << "����������ѡ��";

		int select = 0;
		cin >> select;


		switch (select)
		{
		case 1:   //ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:   //��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:    //�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:    //
			cout << "�������������ѡ��"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}