#include "CancelBooking.h"
void CancelBooking::loop()
{
	system("cls");
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	vector<BookingItem*>list;

	cout << "��ǰ��ȡ����ԤԼ�У�\n";
	int j = 0;
	for (int i = 0; i < allItem.size(); i++) {
		BookingItem* item = allItem[i];
		if (item->userID == data->m_curID->IDnum && (item->state == 0 || item->state == 3)) {
			++j;
			cout << j << '.'
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
	exit();
}
