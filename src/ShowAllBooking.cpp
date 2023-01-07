#include "ShowAllBooking.h"

void ShowAllBooking::loop()
{
	system("cls");
	const vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "�����"}, { 1,"��ȡ��" }, { 2,"δͨ��" }, { 3,"ԤԼ�ɹ�" } };
	map<int, string>itv = { {1, "����"}, { 2,"����" } };
	for (auto& i : allItem) {
		cout << " ���ڣ�" << i->day
			<< " ʱ��Σ�" << itv[i->interval]
			<< " ��ţ�" << i->userID
			<< " ������" << i->userName
			<< " ������" << i->roomID
			<< " ״̬��" << sta[i->state]
			<< endl;
	}
	system("pause");
	exit();
}
