#include "CancelBooking.h"
void CancelBooking::loop()
{
	system("cls");
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "checking"}, { 1,"cancelled" }, { 2,"denied" }, { 3,"OK" } };
	map<int, string>itv = { {1, "AM"}, { 2,"PM" } };
	vector<BookingItem*>list;

	cout << "booking that can be cancelled:\n";
	int j = 0;
	for (int i = 0; i < allItem.size(); i++) {
		BookingItem* item = allItem[i];
		if (item->userID == data->m_curID->IDnum && (item->state == 0 || item->state == 3)) {
			++j;
			cout << j << '.'
				<< " date:" << item->day
				<< " interval:" << itv[item->interval]
				<< " ID:" << item->userID
				<< " roomID:" << item->roomID
				<< " status:" << sta[item->state]
				<< endl;
			list.push_back(item);
		}
	}
	int idx = getOpr("please choose booking item to be cancelled:\n", 1, list.size());
	list[idx - 1]->state = BookingItem::cancelled;
	system("pause");
	exit();
}
