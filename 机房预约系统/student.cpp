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
	cout << "��ӭѧ������" << this->m_Name << "��¼" << endl;
	cout << "------------------" << endl;
	cout << "1������ԤԼ" << endl;
	cout << "2���鿴�ҵ�ԤԼ" << endl;
	cout << "3���鿴����ԤԼ" << endl;
	cout << "4��ȡ��ԤԼ" << endl;
	cout << "0��ע����¼" << endl;
	cout << "------------------" << endl;
}

void Student::applyOrder()
{
	cout << "��һ~���忪�ţ�" << endl;
	cout << "��������ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date;
	int interval;
	int room;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "���������������룡" << endl;
	}
	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "���������������룡" << endl;
	}
	cout << "��ѡ�������" << endl;
	cout <<vCom[0].m_ComId<< "�Ż�������Ϊ"<< vCom[0] .m_MaxNum<< endl;
	cout << vCom[1].m_ComId << "�Ż�������Ϊ" << vCom[1].m_MaxNum << endl;
	cout << vCom[2].m_ComId << "�Ż�������Ϊ" << vCom[2].m_MaxNum << endl;
	while (true) {
		cin >>room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "���������������룡" << endl;
	}
	cout << "ԤԼ�ɹ�������У�" << endl;

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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"];
		cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stID"];
		cout << " ������" << of.m_orderData[i]["stName"];
		cout << " �����ţ�" << of.m_orderData[i]["room"];
		string status = " ״̬��";
		//1 ������ 2 ԤԼ�ɹ� -1 ԤԼʧ�� 0 ȡ��
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "ԤԼʧ��";
		}
		else {
			status += "ԤԼȡ��";
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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		//stringתint
		//string����.c_str()תconst char*
		//����atoi(const char*)תint
		if (this->m_Id == atoi(of.m_orderData[i]["stID"].c_str())) {
			cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ�" << of.m_orderData[i]["room"];
			string status = "״̬��";
			//1 ������ 2 ԤԼ�ɹ� -1 ԤԼʧ�� 0 ȡ��
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "ԤԼʧ��";
			}
			else {
				status += "ԤԼȡ��";
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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������ȡ���ļ�¼��" << endl;
	vector<int>b;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		//stringתint
		//string����.c_str()תconst char*
		//����atoi(const char*)תint
		//�ж��������
		if (this->m_Id == atoi(of.m_orderData[i]["stID"].c_str())) {
			//ɸѡ״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				b.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"];
				cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " �����ţ�" << of.m_orderData[i]["room"];
				string status = "״̬��";
				//1 ������ 2 ԤԼ�ɹ� -1 ԤԼʧ�� 0 ȡ��
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
					cout << status << endl;
				}
			}

		}
	}
	cout << "����ȡ����¼��0�����أ�" << endl;
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
				cout << "��ȡ��" << endl;
				break;
			}
		}
		cout << "��������!" << endl;
	}
	system("pause");
	system("cls");
}
