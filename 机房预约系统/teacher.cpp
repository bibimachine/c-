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
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼" << endl;
	cout << "------------------" << endl;
	cout << "1���鿴����ԤԼ" << endl;
	cout << "2�����ԤԼ" << endl;

	cout << "0��ע����¼" << endl;
	cout << "------------------" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}

void Teacher::showAllOrder()
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

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>b;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			b.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ�" << of.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ�ţ�" << of.m_orderData[i]["stID"];
			cout << " ������" << of.m_orderData[i]["stName"];
			cout << " �����ţ�" << of.m_orderData[i]["room"];
			cout << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0�����أ�" << endl;
	int select = 0;
	int ret = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= b.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽��:" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[b[select - 1]]["status"] = "2";
				}
				else {
					of.m_orderData[b[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}
