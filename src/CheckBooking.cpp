#include "CheckBooking.h"

void CheckBooking::loop()
{
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	bool checkingFlag = true;
	while (1) {
		system("cls");
		cout << "����˵�ԤԼ�У�\n";
		vector<BookingItem*>list;
		int idx = 1;
		for (int i = 0; i < allItem.size(); i++) {
			BookingItem* item = allItem[i];
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
			break;
		}
		idx = getOpr("��ѡ��Ҫ��˵ļ�¼(����0�˳����)��\n", 0, list.size());
		if (idx == 0) {
			break;
		}
		int check = getOpr("��ѡ���Ƿ���׼��\n1.��׼\n2.����׼\n", 1, 2);
		if (check == 1) {
			list[idx - 1]->state = BookingItem::checked;
		}
		else {
			list[idx - 1]->state = BookingItem::denied;
		}
	}
	system("pause");
	exit();
}
