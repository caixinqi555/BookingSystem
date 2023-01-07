#include "CheckBooking.h"

void CheckBooking::loop()
{
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "checking"}, { 1,"cancelled" }, { 2,"denied" }, { 3,"OK" } };
	map<int, string>itv = { {1, "AM"}, { 2,"PM" } };
	bool checkingFlag = true;
	while (1) {
		system("cls");
		cout << "Booking to be checked:\n";
		vector<BookingItem*>list;
		int idx = 1;
		for (int i = 0; i < allItem.size(); i++) {
			BookingItem* item = allItem[i];
			if (item->state == BookingItem::checking) {
				cout << idx << '.'
					<< " date:" << item->day
					<< " interval:" << itv[item->interval]
					<< " ID:" << item->userID
					<< " name:" << item->userName
					<< " roomID:" << item->roomID
					<< " status:" << sta[item->state]
					<< endl;
				list.push_back(item);
				idx++;
			}
		}
		if (list.size() == 0) {
			cout << "No booking to be checked!\n";
			break;
		}
		idx = getOpr("choose which booking to be checked:(0 for exit)\n", 0, list.size());
		if (idx == 0) {
			break;
		}
		int check = getOpr("choose either to pass or not:\n1.yes\n2.no\n", 1, 2);
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
