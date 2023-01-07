#include "ShowMyBooking.h"

void ShowMyBooking::loop()
{
	system("cls");
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	for (auto& i : allItem) {
		if (i->userID == data->m_curID->IDnum) {
		cout << " date:" << i->day
			<< " interval:" << itv[i->interval]
			<< " ID:" << i->userID
			<< " roomID:" << i->roomID
			<< " status:" << sta[i->state]
			<< endl;
		}
	}
	system("pause");
	exit();
}
