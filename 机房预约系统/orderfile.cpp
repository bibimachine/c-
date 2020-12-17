#include "orderfile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;  //����
	string interval; //ʱ���
	string stID; //ѧ�����
	string stName; //ѧ������
	string roomId; //������
	string status; //ԤԼ״̬
	this->m_Size = 0; //��¼����

	while (ifs >> date && ifs >> interval && ifs >> stID && ifs >> stName && ifs >> roomId && ifs >> status) {
		string key;
		string value;
		map<string, string>m;
		
		//���ڽ�ȡ
		int pos = date.find(":");
		key = date.substr(0, pos);
		value = date.substr(pos + 1, date.size() - pos-1);
		m.insert(make_pair(key, value));

		//ʱ��ν�ȡ
		pos = interval.find(":");
		key = interval.substr(0, pos);
		value = interval.substr(pos + 1, interval.size() - pos-1);
		m.insert(make_pair(key, value));

		//��Ž�ȡ
		pos = stID.find(":");
		key = stID.substr(0, pos);
		value = stID.substr(pos + 1, stID.size() - pos-1);
		m.insert(make_pair(key, value));

		//������ȡ
		pos = stName.find(":");
		key = stName.substr(0, pos);
		value = stName.substr(pos + 1, stName.size() - pos-1);
		m.insert(make_pair(key, value));

		//������ȡ
		pos = roomId.find(":");
		key = roomId.substr(0, pos);
		value = roomId.substr(pos + 1, roomId.size() - pos-1);
		m.insert(make_pair(key, value));

		//ԤԼ״̬��ȡ
		pos = status.find(":");
		key = status.substr(0, pos);
		value = status.substr(pos + 1, status.size() - pos-1);
		m.insert(make_pair(key, value));

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stID:" << this->m_orderData[i]["stID"] << " ";
		ofs << "stName:" << this->m_orderData[i]["stName"] << " ";
		ofs << "room:" << this->m_orderData[i]["room"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] <<endl;
	}

	ofs.close();
}
