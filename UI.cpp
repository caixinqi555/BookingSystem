#include "UI.h"
UI::UI(DataSystem *d):data(d){
}

void  UI::login() {
	int type;
	long long id;
	string passwd;
	system("cls");
	cout << "\t\t ------------------------- \n" ;
	cout << "\t\t|       ��ѡ���¼��ݣ�  | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        1.ѧ������       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        2.��    ʦ       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        3.�� �� Ա       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        4.��    ��       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t ------------------------- \n";
	cin >> type;



	switch (type) {
		//ѧ��
	case 1:
		system("cls");
		cout << "�������ʺţ�\n";
		cin >> id;
		cout << "���������룺\n";
		cin >> passwd;
		if (!data->verifyID(id, passwd,ID::student)) {
			cout << "�������\n";
			system("pause");
			return;
		}
		studentMenu();
		break;
		//��ʦ
	case 2:
		system("cls");
		cout << "�������ʺţ�\n";
		cin >> id;
		cout << "���������룺\n";
		cin >> passwd;
		if (!data->verifyID(id, passwd, ID::teacher)) {
			cout << "�������\n";
			system("pause");
			return;
		}
		teacherMenu();
		break;
		//����Ա
	case 3:
		system("cls");
		cout << "�������ʺţ�\n";
		cin >> id;
		cout << "���������룺\n";
		cin >> passwd;
		if (!data->verifyID(id, passwd, ID::admin)) {
			cout << "�������\n";
			system("pause");
			return;
		}
		managerMenu();
		break;
		//�˳�
	case 4:
		data->save();
		system("cls");
		cout << "��ӭ�´�ʹ�ã�\n";
		system("pause");
		exit(0);
		break;
		//���벻�Ϸ�
	default:
		cout << "���벻�Ϸ�������������!\n";
		system("pause");
		return;
		break;
	}

}
void UI::studentMenu() {
	loginFlag = true;
	while (1) {
		system("cls");
		cout << "\t\t ------------------------- \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        1.ԤԼ����       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        2.�鿴�ҵ�ԤԼ   | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        3.�鿴����ԤԼ   | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        4.ȡ��ԤԼ       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        0.ע����¼       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t ------------------------- \n";
		int type;
		cin >> type;

		switch (type) {
			//��½ԤԼ
		case 1:
			booking();
			break;
			//�鿴�ҵ�ԤԼ
		case 2:
			showMyBooking();
			break;
			//�鿴����ԤԼ
		case 3:
			showAllBooking();
			break;
			//ȡ��ԤԼ
		case 4:
			cancelBooking();
			break;
			//ע����¼
		case 0:
			loginFlag = false;
			break;
		}
		if(loginFlag==false)break;
	}

}

void UI::teacherMenu() {
	loginFlag = true;
while(1){
	system("cls");
	cout << "\t\t ------------------------- \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        1.�鿴����ԤԼ   | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        2.���ԤԼ       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        0.ע����¼       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t ------------------------- \n";
	int type;
	cin >> type;

	switch (type) {
		//�鿴����ԤԼ
	case 1:
		showAllBooking();
		break;
		//���ԤԼ
	case 2:
		checkBooking();
		break;
		//ע����¼
	case 0:
		loginFlag = false;
		break;
	}

		if (loginFlag == false)break;
	}	
}
void UI::managerMenu() {
	loginFlag = true;
	while (1) {
		system("cls");
		cout << "\t\t ------------------------- \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        1.����˺�       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        2.�鿴�˺�       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        3.�鿴����       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        4.���ԤԼ       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        0.ע����¼       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t ------------------------- \n";
		int type;
		cin >> type;

		switch (type) {
			//����˺�
		case 1:
			addAccount();
			break;
			//�鿴�˺�
		case 2:
			checkAccount();
			break;
			//�鿴����
		case 3:
			checkRooms();
			break;
			//���ԤԼ
		case 4:
			clearBooking();
			break;
			//ע����¼
		case 0:
			loginFlag = false;
			break;
		}
		if (loginFlag == false)break;
	}
}
void UI::booking() {
	system("cls");
	cout << "��������ʱ��Ϊ��һ������!\n";
	cout << "����������ԤԼ��ʱ�䣺\n";
	cout << "1����һ\n";
	cout << "2���ܶ�\n";
	cout << "3������\n";
	cout << "4������\n";
	cout << "5������\n";
	int day;
	cin >> day;
	while (day > 5 || day < 1) {
		cout << "���벻�Ϸ�������������\n";
		cin >> day;
	}

	cout<< "��ѡ��ԤԼʱ�Σ�\n";
	cout << "1.����\n";
	cout << "2.����\n";
	int interval;
	cin >> interval;
	while (interval > 2 || interval < 1) {
		cout << "���벻�Ϸ�������������\n";
		cin >> interval;
	}

	cout << "��ѡ�������\n";
	int roomID;
	cin >> roomID;
	while (roomID > 3 || interval < 1) {
		cout << "���벻�Ϸ�������������\n";
		cin >> roomID;
	}
	if (data->addBookingItem(day, interval, roomID)) {
		cout << "ԤԼ�ɹ�����ȴ���ʦ���\n";
	}
	else {
		cout << "ԤԼʧ�ܣ���ʱ���ѱ�ԤԼ\n";
	}
	system("pause");
	return;
}

void UI::showAllBooking() {
	const vector<BookingItem*> allItem=data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	for (auto& i : allItem) {
		cout << " ���ڣ�"<<i->day
			<< " ʱ��Σ�" << itv[i->interval]
			<< " ��ţ�" << i->userID
			<< " ������" << i->userName
			<< " ������" << i->roomID
			<< " ״̬��" << sta[i->state]
			<<endl;
	}
	system("pause");
}
void UI::showMyBooking() {
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta={ {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv={ {1, "����"}, { 2,"����" }};
	for (auto& i : allItem) {
		if (i->userID == data->m_curID->IDnum) {
			cout << " ���ڣ�" << i->day
				<< " ʱ��Σ�" << itv[i->interval]
				<< " ��ţ�" << i->userID
				<< " ������" << i->roomID
				<< " ״̬��" << sta[i->state]
				<< endl;
		}
	}
	system("pause");
}
void UI::cancelBooking() {
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	vector<BookingItem*>list;

	cout << "��ǰ��ȡ����ԤԼ�У�\n";
	for (int i = 0; i < allItem.size();i++) {
		BookingItem* item=allItem[i];
		if (item->userID == data->m_curID->IDnum &&(item->state==0 || item->state == 3)) {
			cout <<i+1<<'.'
				<< " ���ڣ�" << item->day
				<< " ʱ��Σ�" << itv[item->interval]
				<< " ��ţ�" << item->userID
				<< " ������" << item->roomID
				<< " ״̬��" << sta[item->state]
				<< endl;
			list.push_back(item);
		}
	}

	int idx = getOpr("��ѡ��Ҫȡ���ļ�¼��\n", 1, list.size());
	list[idx - 1]->state = BookingItem::cancelled;
	system("pause");
}

void UI::checkBooking() {
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	bool checkingFlag = true;
	while (checkingFlag) {
		cout << "����˵�ԤԼ�У�\n";
		vector<BookingItem*>list;
		for (int i = 0; i < allItem.size(); i++) {
			BookingItem* item = allItem[i];
			int idx = 1;
			if (item->state == BookingItem::checking) {
				cout << idx << '.'
					<< " ���ڣ�" << item->day
					<< " ʱ��Σ�" << itv[item->interval]
					<< " ��ţ�" << item->userID
					<< " ������" << item->userName
					<< " ������" << item->roomID
					<< " ״̬��" << sta[item->state]
					<< endl;
				list.push_back(item);
				idx++;
			}
		}
		if (list.size() == 0) {
			cout << "��ǰû�д���˵�����\n";
			checkingFlag = false;
			break;
		}
		int idx = getOpr("��ѡ��Ҫ��˵ļ�¼(����0�˳����)��\n", 1, list.size());
		if (idx == 0) {
			checkingFlag = false;
			break;
		}
		int check = getOpr("��ѡ���Ƿ���׼��\n1.��׼\n2.����׼\n", 1, 2);
		if (check == 1) {
			list[idx - 1]->state = BookingItem::checked;
		}
		else {
			list[idx - 1]->state = BookingItem::denied;
		}
		system("pause");
	}
}
void UI::addAccount() {
	int choice=getOpr("����������˺����ͣ�\n1.�����ʦ\n2.���ѧ��\n3.��ӹ���Ա\n",1,3),type=0;
	long long IDnum=0;
	if (choice == 1) {
		IDnum = getOpr("�����빤�ţ�\n", 0, 9999999999);
		type = ID::teacher;
	}
	else if (choice == 2) {
		IDnum = getOpr("������ѧ�ţ�\n", 0, 9999999999);
		type = ID::student;
	}
	else if (choice == 3) {
		IDnum = getOpr("�����빤�ţ�\n", 0, 9999999999);
		type = ID::admin;
	}
	string name;
	cout << "������������\n";
	cin >> name;
	string passwd;
	cout << "���������룺\n";
	cin >> passwd;
	data->addID(name,IDnum, passwd, type);
	cout << "��ӳɹ�\n";
	system("pause");
}
void UI::checkAccount() {
	vector<ID*> list = data->m_IDVector;
	for (auto& i : list) {
		cout << "\t�˺ţ� " << i->IDnum
			<< "\t������ " << i->name
			<< "\t���룺 " << i->passwd 
			<<"\t�˺����ͣ�" <<i->stringType()
			<< endl;
	}
	system("pause");
}
void UI::checkRooms() {

}
void UI::clearBooking() {
	data->clearBooking();
	cout << "�����ԤԼ��¼\n";
	system("pause");
}

long long UI::getOpr(const string& info, long long min, long long max)
{
	cout << info;
	int idx;
	cin >> idx;
	while (idx<min || idx>max) {
		cout << "���벻�Ϸ�������������\n";
		cin >> idx;
	}
	return idx;
}
